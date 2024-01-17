//===============================================
//
// �}�l�[�W���[�̏��� [manager.cpp]
// Author : Ibuki Okusada
//
//===============================================
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "object2D.h"
#include "player.h"
#include "input.h"
#include "debugproc.h"
#include "time.h"
#include "camera.h"
#include "light.h"
#include "object3D.h"
#include "objectX.h"
#include "Xfile.h"
#include "character.h"
#include "texture.h"
#include "meshfield.h"
#include "meshwall.h"
#include "meshcylinder.h"
#include "meshdome.h"
#include "fileload.h"
#include "edit.h"

//===============================================
// �ÓI�����o�ϐ�
//===============================================
CRenderer *CManager::m_pRenderer = NULL;		// �����_���[�̃|�C���^
CInputKeyboard *CManager::m_pInputKeyboard = NULL;	// ���̓f�o�C�X(�L�[�{�[�h)�ւ̃|�C���^
CInputMouse *CManager::m_pInputMouse = NULL;	// ���̓f�o�C�X(�}�E�X)�̃|�C���^
CDebugProc *CManager::m_pDebugProc = NULL;		// �f�o�b�O�\���̃|�C���^
CPlayer *CManager::m_pPlayer = NULL;	// �v���C���[�̃|�C���^
CCamera *CManager::m_pCamera = NULL;	// �J�����̃|�C���^
CLight *CManager::m_pLight = NULL;		// ���C�g�̃|�C���^
CTexture *CManager::m_pTexture = NULL;	// �e�N�X�`���̃|�C���^
CXFile *CManager::m_pModelFile = NULL;	// X�t�@�C�����̃|�C���^
CFileLoad *CManager::m_pFileLoad = NULL;	// �t�@�C���ǂݍ��݂̃|�C���^
CEdit *CManager::m_pEdit = NULL;		// �G�f�B�b�g�̃|�C���^

//===================================================
// �R���X�g���N�^
//===================================================
CManager::CManager()
{
	
}

//===================================================
// �f�X�g���N�^
//===================================================
CManager::~CManager()
{

}

//===================================================
// ����������
//===================================================
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// �����_���[�̐���
	if (m_pRenderer == NULL)
	{// �g�p���Ă��Ȃ��ꍇ
		m_pRenderer = new CRenderer;
	}

	//����������
	if (m_pRenderer != NULL)
	{// �g�p���Ă���ꍇ
		if (FAILED(m_pRenderer->Init(hWnd, TRUE)))
		{//�����������s�����ꍇ
			return E_FAIL;
		}
	}

	// ���̓f�o�C�X(�L�[�{�[�h)�̐���
	if (m_pInputKeyboard == NULL)
	{// �g�p���Ă��Ȃ��ꍇ
		m_pInputKeyboard = new CInputKeyboard;

		//����������
		if (m_pInputKeyboard != NULL)
		{// �g�p���Ă���ꍇ
			if (FAILED(m_pInputKeyboard->Init(hInstance, hWnd)))
			{//�����������s�����ꍇ
				return E_FAIL;
			}
		}
	}

	// ���̓f�o�C�X(�}�E�X)�̐���
	if (m_pInputMouse == NULL)
	{// �g�p���Ă��Ȃ��ꍇ
		m_pInputMouse = new CInputMouse;

		//����������
		if (m_pInputMouse != NULL)
		{// �g�p���Ă���ꍇ
			if (FAILED(m_pInputMouse->Init(hInstance, hWnd)))
			{//�����������s�����ꍇ
				return E_FAIL;
			}
		}
	}

	// �f�o�b�O�\���̐���
	if (m_pDebugProc == NULL)
	{// �g�p���Ă��Ȃ��ꍇ
		m_pDebugProc = new CDebugProc;
	}

	//����������
	if (m_pDebugProc != NULL)
	{// �g�p���Ă���ꍇ
		m_pDebugProc->Init();
	}

	// �J�����̐���
	if (m_pCamera == NULL)
	{// �g�p���Ă��Ȃ��ꍇ
		m_pCamera = new CCamera;

		// ������
		if (m_pCamera != NULL)
		{
			m_pCamera->Init();
		}
	}

	// ���C�g�̐���
	if (m_pLight == NULL)
	{// �g�p���Ă��Ȃ��ꍇ
		m_pLight = new CLight;

		// ������
		if (m_pLight != NULL)
		{
			m_pLight->Init();
		}
	}

	//�e�N�X�`���̐���
	if (m_pTexture == NULL)
	{// �g�p���Ă��Ȃ��ꍇ
		m_pTexture = new CTexture;

		// �����ǂݍ���
		if (m_pTexture != NULL)
		{
			m_pTexture->Load();
		}
	}

	// X�t�@�C�����̐���
	if (m_pModelFile == NULL)
	{// �g�p���Ă��Ȃ��ꍇ
		m_pModelFile = new CXFile;
	}

	// �O���t�@�C���ǂݍ��݂̐���
	if (m_pFileLoad == NULL)
	{// �g�p���Ă��Ȃ��ꍇ
		m_pFileLoad = new CFileLoad;

		if (m_pFileLoad != NULL)
		{
			m_pFileLoad->Init();
			m_pFileLoad->OpenFile("data\\TXT\\system.txt");
		}
	}

	// �G�f�B�b�g�̐���
	if (m_pEdit == NULL)
	{// �g�p���Ă��Ȃ��ꍇ
		m_pEdit = new CEdit;

		if (m_pEdit != NULL)
		{
			m_pEdit->Init();
		}
	}

	char aBodyScr[128] = {};
	char aLegSct[128] = {};

	// system�t�@�C���ǂݍ���
	SystemLoad(&aBodyScr[0], &aLegSct[0]);

	// �I�u�W�F�N�g����
	CMeshDome::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 5000.0f, 10.0f, 3, 10, 10);
	CMeshCylinder::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 3000.0f, 50.0f, 3, 10, 4);

	m_pPlayer = CPlayer::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, D3DX_PI, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		&aBodyScr[0], &aLegSct[0], 1);

	m_pEdit->SetBody(m_pPlayer->GetBody()); 
	m_pEdit->SetInfo(m_pPlayer->GetBody()->GetMotion()->GetKeyInfo(0, 0));

	return S_OK;
}

//===================================================
// �I������
//===================================================
void CManager::Uninit(void)
{

	if (m_pInputKeyboard != NULL)
	{// �g�p���Ă���ꍇ
		// �I������
		m_pInputKeyboard->Uninit();

		delete m_pInputKeyboard;	// �������̊J��

		m_pInputKeyboard = NULL;	// �g�p���Ă��Ȃ���Ԃɂ���
	}

	if (m_pDebugProc != NULL)
	{// �g�p���Ă���ꍇ
		// �I������
		m_pDebugProc->Uninit();

		delete m_pDebugProc;	// �������̊J��

		m_pDebugProc = NULL;	// �g�p���Ă��Ȃ���Ԃɂ���
	}

	if (m_pRenderer != NULL)
	{// �g�p���Ă���ꍇ
		// �I������
		m_pRenderer->Uninit();

		delete m_pRenderer;	// �������̊J��

		m_pRenderer = NULL;	// �g�p���Ă��Ȃ���Ԃɂ���
	}

	// �e�N�X�`���̔p��
	if (m_pTexture != NULL)
	{// �g�p���Ă���ꍇ
		// �I������
		m_pTexture->Unload();

		delete m_pTexture;	// �������̊J��

		m_pTexture = NULL;	// �g�p���Ă��Ȃ���Ԃɂ���
	}

	// X�t�@�C�����̔p��
	if (m_pModelFile != NULL)
	{// �g�p���Ă���ꍇ
		// �I������
		m_pModelFile->Unload();

		delete m_pModelFile;	// �������̊J��

		m_pModelFile = NULL;	// �g�p���Ă��Ȃ���Ԃɂ���
	}

	// �t�@�C���ǂݍ��݂̔p��
	if (m_pFileLoad != NULL)
	{
		m_pFileLoad->Uninit();

		delete m_pFileLoad;		// �������̊J��
		m_pFileLoad = NULL;
	}

	// �G�f�B�b�g�̔p��
	if (m_pEdit != NULL)
	{
		m_pEdit->Uninit();

		delete m_pEdit;		// �������̊J��
		m_pEdit = NULL;
	}
}

//===================================================
// �X�V����
//===================================================
void CManager::Update(void)
{
	// �f�o�b�O�\���̍X�V����
	if (m_pDebugProc != NULL)
	{// �g�p���Ă���ꍇ
		m_pDebugProc->Update();
	}

	// �L�[�{�[�h�̍X�V����
	if (m_pInputKeyboard != NULL)
	{// �g�p���Ă���ꍇ
		m_pInputKeyboard->Update();
	}

	// �}�E�X�̍X�V����
	if (m_pInputMouse != NULL)
	{// �g�p���Ă���ꍇ
		m_pInputMouse->Update();
	}


	// �J�����̍X�V����
	if (m_pCamera != NULL)
	{
		m_pCamera->Update();
	}

	// �����_���[�̍X�V����
	if (m_pRenderer != NULL)
	{// �g�p���Ă���ꍇ
		m_pRenderer->Update();
	}

	// �G�f�B�b�g�̍X�V
	if (m_pEdit != NULL)
	{
		m_pEdit->Update();
	}

	if (m_pInputKeyboard != NULL)
	{// �g�p���Ă���ꍇ
		if (CObject::GetItemNumAll() <= 0)
		{// ����z�u����Ă��Ȃ��ꍇ
			m_pDebugProc->Print("�G�Ĕz�u[F3]\n");
			if (m_pInputKeyboard->GetTrigger(DIK_F3) == true)
			{
				ItemReset();
			}
		}
	}
}

//===================================================
// �`�揈��
//===================================================
void CManager::Draw(void)
{
	// �`�揈��
	if (m_pRenderer != NULL)
	{// �g�p���Ă���ꍇ
		m_pRenderer->Draw();
	}
}

//===================================================
// �����_���[�̎擾
//===================================================
CRenderer *CManager::GetRenderer(void)
{
	return m_pRenderer;
}

//===================================================
// ���̓f�o�C�X�̎擾(�L�[�{�[�h)
//===================================================
CInputKeyboard *CManager::GetInputKeyboard(void)
{
	return m_pInputKeyboard;
}

//===================================================
// ���̓f�o�C�X�̎擾(�}�E�X)
//===================================================
CInputMouse *CManager::GetInputMouse(void)
{
	return m_pInputMouse;
}

//===================================================
// �f�o�b�O�\���̎擾
//===================================================
CDebugProc *CManager::GetDebugProc(void)
{
	return m_pDebugProc;
}

//===================================================
// �v���C���[�̎擾
//===================================================
CPlayer *CManager::GetPlayer(void)
{
	return m_pPlayer;
}

//===================================================
// �A�C�e���̍Ĕz�u
//===================================================
void CManager::ItemReset(void)
{
	CObjectX::Create(D3DXVECTOR3(800.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), m_pFileLoad->GetModelFileName(0));
	CObjectX::Create(D3DXVECTOR3(800.0f, 0.0f, 300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), m_pFileLoad->GetModelFileName(1));
	CObjectX::Create(D3DXVECTOR3(800.0f, 0.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), m_pFileLoad->GetModelFileName(2));
}

//===================================================
// �J�����̎擾
//===================================================
CCamera *CManager::GetCamera(void)
{
	return m_pCamera;
}

//===================================================
// ���C�g�̎擾
//===================================================
CLight *CManager::GetLight(void)
{
	return m_pLight;
}

//===================================================
// �e�N�X�`���̎擾
//===================================================
CTexture *CManager::GetTexture(void)
{
	return m_pTexture;
}

//===================================================
// X�t�@�C�����̎擾
//===================================================
CXFile *CManager::GetModelFile(void)
{
	return m_pModelFile;
}

//===================================================
// �t�@�C���ǂݍ��݂̎擾
//===================================================
CFileLoad *CManager::GetFileLoad(void)
{
	return m_pFileLoad;
}

//===================================================
// �G�f�B�b�g�̎擾
//===================================================
CEdit *CManager::GetEdit(void)
{
	return m_pEdit;
}

//===================================================
// �G�f�B�b�g�̎擾
//===================================================
void CManager::SystemLoad(char *pBody, char *pLeg)
{
	FILE *pFile;
	char aStr[128] = {};

	// �t�@�C�����J��
	pFile = fopen("data\\system.ini", "r");

	if (pFile == NULL)
	{// �J���Ȃ������ꍇ
		return;
	}

	while (1)
	{
		//�e�L�X�g�ǂݍ���
		int nResult = fscanf(pFile, "%s", &aStr[0]);

		if (strcmp(&aStr[0], "SCRIPT_BODYFILENAME") == 0)
		{//���̃t�@�C���m�F�������m�F�ł����ꍇ
			fscanf(pFile, "%s", &aStr[0]);	// (=)
			fscanf(pFile, "%s", pBody);	// ���̃t�@�C�����ǂݍ���
		}
		else if (strcmp(&aStr[0], "SCRIPT_LEGFILENAME") == 0)
		{//�����g�t�@�C���m�F�������m�F�ł����ꍇ
			fscanf(pFile, "%s", &aStr[0]);	// (=)
			fscanf(pFile, "%s", pLeg);	// ���̃t�@�C�����ǂݍ���
		}
		else if (nResult == EOF)
		{//�t�@�C���̍Ō�܂œǂݍ���ł��܂����ꍇ
			break;
		}
	}

	// �t�@�C�������
	fclose(pFile);
}