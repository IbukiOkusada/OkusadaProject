//==========================================================
//
//入力デバイス処理 [input.cpp]
//Author 奥定伊吹
//
//==========================================================
#include "input.h"
#include "manager.h"
#include "debugproc.h"

#define REPEAT_TIME (15)	//リピートタイマー

// 静的メンバ変数宣言
LPDIRECTINPUT8 CInput::m_pInput = NULL;	// オブジェクトへのポインタ

//====================================================================================
//基底クラス(入力デバイス)
//====================================================================================
// コンストラクタ
//==========================================================
CInput::CInput()
{
	m_pDevice = NULL;
}

//==========================================================
// デストラクタ
//==========================================================
CInput::~CInput()
{
	m_pDevice = NULL;
}

//==========================================================
// 初期化処理
//==========================================================
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	if (m_pInput == NULL)
	{// まだ誰も使用開始していない場合

		//DirectInputオブジェクトの生成
		if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
		{// 生成失敗した場合
			return E_FAIL;
		}
	}

	return S_OK;
}

//==========================================================
//終了処理
//==========================================================
void CInput::Uninit(void)
{
	//デバイスの廃棄(+アクセス権開放)
	if (m_pDevice != NULL)
	{
		m_pDevice->Unacquire();
		m_pDevice->Release();
		m_pDevice = NULL;
	}

	//オブジェクトの廃棄
	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}

#if 0	// 純粋仮想関数なので通らない
//==========================================================
//更新処理
//==========================================================
void CInput::Update(void)
{
	
}
#endif

//====================================================================================
//派生クラス(キーボード)
//====================================================================================
// コンストラクタ
//==========================================================
CInputKeyboard::CInputKeyboard()
{
	// 値をクリアする
	for (int nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
	{
		m_aKeyState[nCntKey] = 0;
		m_aKeyStateTrigger[nCntKey] = 0;
		m_aKeyStateRelease[nCntKey] = 0;
		m_aKeyStateRepeat[nCntKey] = 0;
	}
}

//==========================================================
// デストラクタ
//==========================================================
CInputKeyboard::~CInputKeyboard()
{
	
}

//==========================================================
//初期化処理
//==========================================================
HRESULT CInputKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);

	//入力デバイス(キーボード)の生成
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}

	//データフォーマットを設定
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//データフォーマットを設定
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//キーボードへのアクセス権を取得
	m_pDevice->Acquire();

	return S_OK;
}

//==========================================================
//終了処理
//==========================================================
void CInputKeyboard::Uninit(void)
{
	CInput::Uninit();
}

//==========================================================
//更新処理
//==========================================================
void CInputKeyboard::Update(void)
{
	BYTE aKeyState[NUM_KEY_MAX];	//キーボードの入力情報
	int nCntKey = 0;

	//入力デバイスからデータを取得
	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
		{
			m_aKeyStateTrigger[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & aKeyState[nCntKey];	//キーボードからのトリガー情報を保存
			m_aKeyStateRelease[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & m_aKeyState[nCntKey];	//キーボードからのリリース情報を保存
			m_aKeyState[nCntKey] = aKeyState[nCntKey];	//キーボードからのプレス情報を保存
			m_aKeyStateRepeat[nCntKey] = m_aKeyStateTrigger[nCntKey];

			//リピート取得
			if (GetPress(nCntKey) == true)
			{//プレスで入力されているとき

				if (m_aRepeatCnt[nCntKey] >= REPEAT_TIME)
				{//リピートカウンターがタイマーを超えたとき
					m_aKeyStateRepeat[nCntKey] = m_aKeyState[nCntKey];
				}
				else
				{
					m_aRepeatCnt[nCntKey]++;
					m_aKeyStateRepeat[nCntKey] = m_aKeyStateRelease[nCntKey];
				}
			}

			if (GetRelease(nCntKey) == true)
			{//リリース入力されたとき
				m_aRepeatCnt[nCntKey] = 0;
			}
		}
	}
	else
	{
		m_pDevice->Acquire();	//キーボードへのアクセス権を獲得
	}

}

//==========================================================
//プレス情報を取得
//==========================================================
bool CInputKeyboard::GetPress(int nKey)
{
	return (m_aKeyState[nKey] & 0x80) ? true : false;
}

//==========================================================
//トリガー情報を取得
//==========================================================
bool CInputKeyboard::GetTrigger(int nKey)
{
	return (m_aKeyStateTrigger[nKey] & 0x80) ? true : false;
}

//==========================================================
//リリース情報を取得
//==========================================================
bool CInputKeyboard::GetRelease(int nKey)
{
	return (m_aKeyStateRelease[nKey] & 0x80) ? true : false;
}

//==========================================================
//リピート情報を取得
//==========================================================
bool CInputKeyboard::GetRepeat(int nKey)
{
	return (m_aKeyStateRepeat[nKey] & 0x80) ? true : false;
}

//====================================================================================
//派生クラス(マウス)
//====================================================================================
// コンストラクタ
//==========================================================
CInputMouse::CInputMouse()
{
	m_State = {};
	m_Trigger = {};
	m_Release = {};
	m_Repeat = {};
	m_Point = {};
}

//==========================================================
// デストラクタ
//==========================================================
CInputMouse::~CInputMouse()
{

}

//==========================================================
//マウスの初期化
//==========================================================
HRESULT CInputMouse::Init(HINSTANCE hInstance, HWND hWnd)
{
	//入力デバイスの生成
	CInput::Init(hInstance, hWnd);

	if (FAILED(m_pInput->CreateDevice(GUID_SysMouse, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}

	//データフォーマットの生成
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIMouse2)))
	{
		return E_FAIL;
	}

	//データフォーマットを設定
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//デバイスの設定
	DIPROPDWORD diprop;
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwObj = 0;
	diprop.diph.dwHow = DIPH_DEVICE;
	diprop.dwData = DIPROPAXISMODE_REL;	//相対値モードで設定

	if (FAILED(m_pDevice->SetProperty(DIPROP_AXISMODE, &diprop.diph)))
	{
		return E_FAIL;
	}

	//マウスへのアクセス権を獲得
	m_pDevice->Acquire();

	return S_OK;
}

//==========================================================
//マウスの終了
//==========================================================
void CInputMouse::Uninit(void)
{
	//入力デバイスの廃棄
	CInput::Uninit();
}

//==========================================================
//マウスの更新
//==========================================================
void CInputMouse::Update(void)
{
	DIMOUSESTATE2 MouseState;	//マウスの入力情報

	//入力デバイスからデータを取得
	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(MouseState), (LPVOID)&MouseState)))
	{
		m_State = MouseState;	//プレス情報取得

		//マウスの現在のポインタを取得する
		GetCursorPos(&m_Point);

		//スクリーン座標をクライアント座標に変換する
	}
	else
	{
		m_pDevice->Acquire(); //マウスへのアクセス権を獲得
	}
}

//==========================================================
//マウスのプレス情報取得
//==========================================================
bool CInputMouse::GetPress(int nKey)
{
	return (m_State.rgbButtons[nKey] & 0x80) ? true : false;
}

//==========================================================
//マウスのトリガー情報取得
//==========================================================
bool CInputMouse::GetTrigger(int nKey)
{
	return (m_Trigger.rgbButtons[nKey] & 0x80) ? true : false;
}

//==========================================================
//マウスのリリース情報取得
//==========================================================
bool CInputMouse::GetRelease(int nKey)
{
	return (m_Release.rgbButtons[nKey] & 0x80) ? true : false;
}

//==========================================================
//マウスのリピート情報取得
//==========================================================
bool CInputMouse::GetRepeat(int nKey)
{
	return (m_Repeat.rgbButtons[nKey] & 0x80) ? true : false;
}

//==========================================================
//マウスのカーソル移動量取得
//==========================================================
D3DXVECTOR3 CInputMouse::GetCousorMove(void)
{
	return D3DXVECTOR3((float)m_State.lX, (float)m_State.lY, (float)m_State.lZ);
}
