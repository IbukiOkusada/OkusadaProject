//===================================================
//
// ���[�V�����G�f�B�^�[�����S�� [edit.cpp]
// Author : Ibuki Okusada
//
//===================================================
#include "edit.h"
#include "manager.h"
#include "debugproc.h"
#include "input.h"
#include "character.h"
#include "player.h"
#include "model.h"

// �}�N����`
#define MAX_DEBUGPARTS	(10)

//***************************************************
// �ÓI�����o�ϐ��錾
//***************************************************
// ��ԕ\������
const char *CEdit::m_apState[] =
{
	"EDITMODE",
	"PLAYMODE",
};

// �I�𕔈ʕ\������
const char *CEdit::m_apType[TYPE_MAX] =
{
	"�㔼�g",
	"�����g",
};

//===================================================
// �R���X�g���N�^
//===================================================
CEdit::CEdit()
{
	// �l�̃N���A
	m_State = STATE_EDIT;		
	m_Type = TYPE_BODY;
	m_nIdx = 0;		
	m_nNowMotion = 0;	
	m_nNowKey = 0;
	m_Key = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
}

//===================================================
// �f�X�g���N�^
//===================================================
CEdit::~CEdit()
{

}

//===================================================
// ����������
//===================================================
void CEdit::Init(void)
{
	m_bMotion = false;
}

//===================================================
// �I������
//===================================================
void CEdit::Uninit(void)
{

}

//===================================================
// �X�V����
//===================================================
void CEdit::Update(void)
{
	CDebugProc *pDebug = CManager::GetDebugProc();

	// ����
	Controller();

	// �f�o�b�O�\��
	if (pDebug != NULL)
	{// �g�p����Ă���ꍇ
		pDebug->Print("[���[�h�ύX]       : [ F2 ] �k %s �l\n", m_apState[m_State]);
		pDebug->Print("[�ҏW���ʕύX]     : [ �R ] �k %s �l\n", m_apType[m_Type]);
		pDebug->Print("[���[�V�����ύX]   : [ ��, �� ]  �k %d / %d �l\n", m_nNowMotion, m_pBody->GetMotion()->GetNum());
		pDebug->Print("[�L�[�I��]         : [ 1, 2 ]�k %d / %d�l\n", m_nNowKey, m_pBody->GetMotion()->GetNumKey());
		pDebug->Print("[�L�[�����ύX]     : [ I, K ]  �k NUM %d �l\n", m_pBody->GetMotion()->GetNumKey());
		// ��ԕʃf�o�b�O�\��
		if (m_State == STATE_PLAY)
		{// �����Ƃ�
			pDebug->Print("[�L�[�t���[�����ύX]     : [ ��, �� ] �k %d �l\n", m_pBody->GetMotion()->GetFrame(m_nNowKey, m_nNowMotion));
			pDebug->Print("[ �ŏ�����Đ�]          : [ F4 ]\n");

			pDebug->Print("\n");

			// �t���[�����ǉ�
			pDebug->Print("+------------------------------------+\n");
			pDebug->Print("MOTION : %d\n", m_nNowMotion);
			pDebug->Print("KEY    : %d / %d\n", m_pBody->GetMotion()->GetNowKey(), m_pBody->GetMotion()->GetNumKey());
			pDebug->Print("FRAME  : %d / %d ( %d / %d )\n", 
				m_pBody->GetMotion()->GetNowFrame(), m_pBody->GetMotion()->GetFrame(m_nNowKey, m_nNowMotion),
				m_pBody->GetMotion()->GetFrame(), m_pBody->GetMotion()->GetNumFrame());
			pDebug->Print("+------------------------------------+\n");
		}
		else
		{// �쐬��
			pDebug->Print("[�|�[�Y�o�^]       : [ F3 ]\n");
			pDebug->Print("[�|�[�Y�R�s�[]     : [ F6 ]\n");
			pDebug->Print("[�|�[�Y�y�[�X�g]   : [ F7 ]\n");
			pDebug->Print("[�t�@�C�������o��] : [ F9 ] �k data\\motion_info.txt �l\n");

			// �p�[�c������
			pDebug->Print("\n+------------------------------------+\n");
			pDebug->Print("| [��][��] : �p�[�c�I��              |\n");
			pDebug->Print("+------------------------------------+\n");
			pDebug->Print("|[T][G] : X����] [B] : X�����Z�b�g  |\n");
			pDebug->Print("|[Y][H] : Y����] [N] : Y�����Z�b�g  |\n");
			pDebug->Print("|[U][J] : Z����] [M] : Z�����Z�b�g  |\n");
			pDebug->Print("+------------------------------------+\n");
			pDebug->Print(" [ �p�[�c�� : %d ]\n", m_pBody->GetNumParts());

			if (m_pBody->GetNumParts() > 0)
			{
				for (int nCnt = 0; nCnt < m_pBody->GetNumParts(); nCnt++)
				{
					if (nCnt > MAX_DEBUGPARTS)
					{
						break;
					}
					else
					{
						int nIdx = (nCnt + m_nIdx) % m_pBody->GetNumParts();
						D3DXVECTOR3 rot = m_pBody->GetParts(nIdx)->GetCurrentRotation();
						
						if (m_nIdx == nIdx)
						{
							pDebug->Print("��");
						}
						else
						{
							pDebug->Print("o");
						}

						pDebug->Print("[%d]: (%f, %f, %f)\n", nIdx,
							rot.x, rot.y, rot.z);
					}
				}
			}

			D3DXVECTOR3 pos = m_pBody->GetParts(0)->GetCurrentPosition();
			pDebug->Print("+----------------------------------------+\n");
			pDebug->Print("|[Q][A] : X���W�ړ� [Z] : X���W���Z�b�g  |\n");
			pDebug->Print("|[W][S] : Y���W�ړ� [X] : Y���W���Z�b�g  |\n");
			pDebug->Print("|[E][D] : Z���W�ړ� [C] : Z���W���Z�b�g  |\n");
			pDebug->Print("+----------------------------------------+\n");
			pDebug->Print("  [0] (%f, %f, %f)\n", pos.x, pos.y, pos.z);
			pDebug->Print("+-----------------------------+\n");
			pDebug->Print("| [ Enter ]��]�A�ړ����Z�b�g |\n");
			pDebug->Print("+-----------------------------+\n");
		}
	}
}

//===================================================
// ����
//===================================================
void CEdit::Controller(void)
{
	CInputKeyboard *pKey = CManager::GetInputKeyboard();	// �L�[�{�[�h�̃|�C���^

	if (pKey == NULL)
	{
		return;
	}

	// ��Ԑ؂�ւ�
	if (pKey->GetTrigger(DIK_F2) == true)
	{
		m_State = (STATE)(m_State ^ STATE_PLAY);

		if (m_State == STATE_PLAY)
		{
			m_bMotion = true;
		}
	}

	// ���ʐ؂�ւ�
	if (pKey->GetTrigger(DIK_3) == true)
	{
		m_Type = (TYPE)(m_Type ^ TYPE_LEG);

		// ��ނ��Ƃɕ�����
		switch (m_Type)
		{
		case TYPE_BODY:
			m_pBody = CManager::GetPlayer()->GetBody();
			break;

		case TYPE_LEG:
			m_pBody = CManager::GetPlayer()->GetLeg();
			break;
		}

		m_nIdx = 0;
		m_nNowMotion = m_pBody->GetMotion()->GetNow();
		m_nNowKey = 0;
		m_pInfo = NULL;

		D3DXVECTOR3 pos;
		D3DXVECTOR3 rot;
		pos = m_pBody->GetParts(m_nIdx)->GetCurrentPosition();
		rot = m_pBody->GetParts(m_nIdx)->GetCurrentRotation();
		m_Key = { pos.x, pos.y, pos.z, rot.x, rot.y, rot.z };
	}

	// ���[�V�����ԍ��؂�ւ�
	if (pKey->GetTrigger(DIK_LEFT) == true)
	{
		m_nNowMotion = (m_nNowMotion + m_pBody->GetMotion()->GetNum() - 1) % m_pBody->GetMotion()->GetNum();
		m_nNowKey = 0;
		m_pBody->GetMotion()->Set(m_nNowMotion);
		m_Key = m_pBody->GetMotion()->GetKey(m_nNowKey, m_nNowMotion, m_nIdx);
	}
	else if (pKey->GetTrigger(DIK_RIGHT) == true)
	{
		m_nNowMotion = (m_nNowMotion + 1) % m_pBody->GetMotion()->GetNum();
		m_nNowKey = 0;
		m_pBody->GetMotion()->Set(m_nNowMotion);
		m_Key = m_pBody->GetMotion()->GetKey(m_nNowKey, m_nNowMotion, m_nIdx);
	}

	// �L�[�ԍ��؂�ւ�
	if (pKey->GetTrigger(DIK_1) == true)
	{
		m_nNowKey = (m_nNowKey + m_pBody->GetMotion()->GetNumKey() - 1) % m_pBody->GetMotion()->GetNumKey();
		m_pBody->GetMotion()->SetKey(m_nNowKey);
		m_Key = m_pBody->GetMotion()->GetKey(m_nNowKey, m_nNowMotion, m_nIdx);
	}
	else if (pKey->GetTrigger(DIK_2) == true)
	{
		m_nNowKey = (m_nNowKey + 1) % m_pBody->GetMotion()->GetNumKey();
		m_pBody->GetMotion()->SetKey(m_nNowKey);
		m_Key = m_pBody->GetMotion()->GetKey(m_nNowKey, m_nNowMotion, m_nIdx);
	}

	// �L�[�����ύX
	if (pKey->GetTrigger(DIK_I) == true)
	{// ���炷�ꍇ
		int nNumKey = m_pBody->GetMotion()->GetNumKey();
		nNumKey--;

		if (nNumKey < 1)
		{
			nNumKey = 1;
		}

		m_pBody->GetMotion()->SetNumKey(nNumKey);
	}
	else if (pKey->GetTrigger(DIK_K) == true)
	{// ���₷�ꍇ
		int nNumKey = m_pBody->GetMotion()->GetNumKey();
		nNumKey++;

		if (nNumKey >= MAX_KEY)
		{
			nNumKey = MAX_KEY - 1;
		}

		m_pBody->GetMotion()->SetNumKey(nNumKey);
	}

	// ��Ԃ��Ƃ̑���
	switch (m_State)
	{
	case STATE_EDIT:
		EditController();
		break;
		
	case STATE_PLAY:
		PlayController();
		break;
	}
}

//===================================================
// �G�f�B�b�g��ԑ���
//===================================================
void CEdit::EditController(void)
{
	CInputKeyboard *pKey = CManager::GetInputKeyboard();	// �L�[�{�[�h�̃|�C���^

	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;

	// �p�[�c���ύX
	if (pKey->GetRepeat(DIK_T) == true || pKey->GetTrigger(DIK_T) == true)
	{// ���炷�ꍇ
		m_Key.fRotX -= D3DX_PI * 0.01f;

		if (m_Key.fRotX < -D3DX_PI)
		{
			m_Key.fRotX += D3DX_PI * 2;
		}

		m_pBody->GetParts(m_nIdx)->SetCurrentRotation(D3DXVECTOR3(m_Key.fRotX, m_Key.fRotY, m_Key.fRotZ));

		pos = m_pBody->GetParts(m_nIdx)->GetCurrentPosition();
		rot = m_pBody->GetParts(m_nIdx)->GetCurrentRotation();
		m_Key = { pos.x, pos.y, pos.z, rot.x, rot.y, rot.z };
	}
	else if (pKey->GetRepeat(DIK_G) == true || pKey->GetTrigger(DIK_G) == true)
	{// ���₷�ꍇ
		m_Key.fRotX += D3DX_PI * 0.01f;

		if (m_Key.fRotX > D3DX_PI)
		{
			m_Key.fRotX += -D3DX_PI * 2;
		}

		m_pBody->GetParts(m_nIdx)->SetCurrentRotation(D3DXVECTOR3(m_Key.fRotX, m_Key.fRotY, m_Key.fRotZ));

		pos = m_pBody->GetParts(m_nIdx)->GetCurrentPosition();
		rot = m_pBody->GetParts(m_nIdx)->GetCurrentRotation();
		m_Key = { pos.x, pos.y, pos.z, rot.x, rot.y, rot.z };
	}
	else if (pKey->GetTrigger(DIK_B) == true)
	{// ���Z�b�g
		m_Key.fRotX = 0.0f;

		m_pBody->GetParts(m_nIdx)->SetCurrentRotation(D3DXVECTOR3(m_Key.fRotX, m_Key.fRotY, m_Key.fRotZ));

		pos = m_pBody->GetParts(m_nIdx)->GetCurrentPosition();
		rot = m_pBody->GetParts(m_nIdx)->GetCurrentRotation();
		m_Key = { pos.x, pos.y, pos.z, rot.x, rot.y, rot.z };
	}
	if (pKey->GetRepeat(DIK_Y) == true || pKey->GetTrigger(DIK_Y) == true)
	{// ���炷�ꍇ
		m_Key.fRotY -= D3DX_PI * 0.01f;

		if (m_Key.fRotY < -D3DX_PI)
		{
			m_Key.fRotY += D3DX_PI * 2;
		}

		m_pBody->GetParts(m_nIdx)->SetCurrentRotation(D3DXVECTOR3(m_Key.fRotX, m_Key.fRotY, m_Key.fRotZ));

		pos = m_pBody->GetParts(m_nIdx)->GetCurrentPosition();
		rot = m_pBody->GetParts(m_nIdx)->GetCurrentRotation();
		m_Key = { pos.x, pos.y, pos.z, rot.x, rot.y, rot.z };
	}
	else if (pKey->GetRepeat(DIK_H) == true || pKey->GetTrigger(DIK_H) == true)
	{// ���₷�ꍇ
		m_Key.fRotY += D3DX_PI * 0.01f;

		if (m_Key.fRotY > D3DX_PI)
		{
			m_Key.fRotY += -D3DX_PI * 2;
		}

		m_pBody->GetParts(m_nIdx)->SetCurrentRotation(D3DXVECTOR3(m_Key.fRotX, m_Key.fRotY, m_Key.fRotZ));

		pos = m_pBody->GetParts(m_nIdx)->GetCurrentPosition();
		rot = m_pBody->GetParts(m_nIdx)->GetCurrentRotation();
		m_Key = { pos.x, pos.y, pos.z, rot.x, rot.y, rot.z };
	}
	else if (pKey->GetTrigger(DIK_N) == true)
	{// ���Z�b�g
		m_Key.fRotY = 0.0f;

		m_pBody->GetParts(m_nIdx)->SetCurrentRotation(D3DXVECTOR3(m_Key.fRotX, m_Key.fRotY, m_Key.fRotZ));

		pos = m_pBody->GetParts(m_nIdx)->GetCurrentPosition();
		rot = m_pBody->GetParts(m_nIdx)->GetCurrentRotation();
		m_Key = { pos.x, pos.y, pos.z, rot.x, rot.y, rot.z };
	}
	if (pKey->GetRepeat(DIK_U) == true || pKey->GetTrigger(DIK_U) == true)
	{// ���炷�ꍇ
		m_Key.fRotZ -= D3DX_PI * 0.01f;

		if (m_Key.fRotZ < -D3DX_PI)
		{
			m_Key.fRotZ += D3DX_PI * 2;
		}

		m_pBody->GetParts(m_nIdx)->SetCurrentRotation(D3DXVECTOR3(m_Key.fRotX, m_Key.fRotY, m_Key.fRotZ));
	}
	else if (pKey->GetRepeat(DIK_J) == true || pKey->GetTrigger(DIK_J) == true)
	{// ���₷�ꍇ
		m_Key.fRotZ += D3DX_PI * 0.01f;

		if (m_Key.fRotZ > D3DX_PI)
		{
			m_Key.fRotZ += -D3DX_PI * 2;
		}

		m_pBody->GetParts(m_nIdx)->SetCurrentRotation(D3DXVECTOR3(m_Key.fRotX, m_Key.fRotY, m_Key.fRotZ));
	}
	else if (pKey->GetTrigger(DIK_M) == true)
	{// ���Z�b�g
		m_Key.fRotZ = 0.0f;

		m_pBody->GetParts(m_nIdx)->SetCurrentRotation(D3DXVECTOR3(m_Key.fRotX, m_Key.fRotY, m_Key.fRotZ));

		pos = m_pBody->GetParts(m_nIdx)->GetCurrentPosition();
		rot = m_pBody->GetParts(m_nIdx)->GetCurrentRotation();
		m_Key = { pos.x, pos.y, pos.z, rot.x, rot.y, rot.z };
	}

	// �ʒu�ύX
	if (pKey->GetRepeat(DIK_Q) == true || pKey->GetTrigger(DIK_Q) == true)
	{// ���炷�ꍇ
		
		pos = m_pBody->GetParts(0)->GetCurrentPosition();
		pos.x += 0.1f;
		m_pBody->GetParts(0)->SetCurrentPosition(pos);
	}
	else if (pKey->GetRepeat(DIK_A) == true || pKey->GetTrigger(DIK_A) == true)
	{// ���₷�ꍇ
		pos = m_pBody->GetParts(0)->GetCurrentPosition();
		pos.x -= 0.1f;
		m_pBody->GetParts(0)->SetCurrentPosition(pos);
	}
	if (pKey->GetRepeat(DIK_W) == true || pKey->GetTrigger(DIK_W) == true)
	{// ���炷�ꍇ
		pos = m_pBody->GetParts(0)->GetCurrentPosition();
		pos.y += 0.1f;
		m_pBody->GetParts(0)->SetCurrentPosition(pos);
	}
	else if (pKey->GetRepeat(DIK_S) == true || pKey->GetTrigger(DIK_S) == true)
	{// ���₷�ꍇ
		pos = m_pBody->GetParts(0)->GetCurrentPosition();
		pos.y -= 0.1f;
		m_pBody->GetParts(0)->SetCurrentPosition(pos);
	}
	if (pKey->GetRepeat(DIK_E) == true || pKey->GetTrigger(DIK_E) == true)
	{// ���炷�ꍇ
		pos = m_pBody->GetParts(0)->GetCurrentPosition();
		pos.z += 0.1f;
		m_pBody->GetParts(0)->SetCurrentPosition(pos);
	}
	else if (pKey->GetRepeat(DIK_D) == true || pKey->GetTrigger(DIK_D) == true)
	{// ���₷�ꍇ
		pos = m_pBody->GetParts(0)->GetCurrentPosition();
		pos.z -= 0.1f;
		m_pBody->GetParts(0)->SetCurrentPosition(pos);
	}

	// �p�[�c�ԍ��ύX
	if (pKey->GetTrigger(DIK_UP) == true)
	{
		m_nIdx = (m_nIdx + m_pBody->GetNumParts() - 1) % m_pBody->GetNumParts();
		pos = m_pBody->GetParts(m_nIdx)->GetCurrentPosition();
		rot = m_pBody->GetParts(m_nIdx)->GetCurrentRotation();
		m_Key = {pos.x, pos.y, pos.z, rot.x, rot.y, rot.z};
	}
	else if (pKey->GetTrigger(DIK_DOWN) == true)
	{
		m_nIdx = (m_nIdx + 1) % m_pBody->GetNumParts();
		pos = m_pBody->GetParts(m_nIdx)->GetCurrentPosition();
		rot = m_pBody->GetParts(m_nIdx)->GetCurrentRotation();
		m_Key = { pos.x, pos.y, pos.z, rot.x, rot.y, rot.z };
	}

	// �쐬�L�[���o�^
	if (pKey->GetTrigger(DIK_F3) == true)
	{
		for (int nCnt = 0; nCnt < m_pBody->GetNumParts(); nCnt++)
		{
			m_pBody->GetMotion()->SetKey(m_nNowKey, m_nNowMotion, nCnt);
		}
	}

	// �R�s�[
	if (pKey->GetTrigger(DIK_F6) == true)
	{
		m_pInfo = m_pBody->GetMotion()->GetKeyInfo(m_nNowKey, m_nNowMotion);
	}

	// �y�[�X�g
	if (pKey->GetTrigger(DIK_F7) == true)
	{
		if (m_pInfo != NULL)
		{
			for (int nCnt = 0; nCnt < m_pBody->GetNumParts(); nCnt++)
			{
				m_pBody->GetParts(nCnt)->SetCurrentRotation(D3DXVECTOR3(m_pInfo->aKey[nCnt].fRotX,
					m_pInfo->aKey[nCnt].fRotY, m_pInfo->aKey[nCnt].fRotZ));
				m_pBody->GetParts(nCnt)->SetCurrentPosition(D3DXVECTOR3(m_pInfo->aKey[nCnt].fPosX + m_pBody->GetParts(nCnt)->GetPosition().x,
					m_pInfo[nCnt].aKey[nCnt].fPosY + m_pBody->GetParts(nCnt)->GetPosition().y, m_pInfo->aKey[nCnt].fPosZ + m_pBody->GetParts(nCnt)->GetPosition().z));
			}
		}
	}

	// �����o��
	if (pKey->GetTrigger(DIK_F9) == true)
	{
		m_pBody->GetMotion()->Save();
	}

	// �L�[��񃊃Z�b�g
	if (pKey->GetTrigger(DIK_RETURN) == true)
	{
		m_pBody->GetMotion()->Reset();
		pos = m_pBody->GetParts(m_nIdx)->GetCurrentPosition();
		rot = m_pBody->GetParts(m_nIdx)->GetCurrentRotation();
		m_Key = { pos.x, pos.y, pos.z, rot.x, rot.y, rot.z };
	}
}

//===================================================
// �v���C��ԑ���
//===================================================
void CEdit::PlayController(void)
{
	CInputKeyboard *pKey = CManager::GetInputKeyboard();	// �L�[�{�[�h�̃|�C���^
	int nFrame = m_pBody->GetMotion()->GetFrame(m_nNowKey, m_nNowMotion);

	// �t���[������ύX
	if (pKey->GetTrigger(DIK_UP) == true || pKey->GetRepeat(DIK_UP) == true)
	{
		nFrame--;

		if (nFrame < 1)
		{
			nFrame = 1;
		}
	}
	else if (pKey->GetTrigger(DIK_DOWN) == true || pKey->GetRepeat(DIK_DOWN) == true)
	{
		nFrame++;
	}

	// �Đ���蒼��
	if (pKey->GetTrigger(DIK_F4) == true)
	{
		CManager::GetPlayer()->GetBody()->GetMotion()->Set(m_nNowMotion, false);
		CManager::GetPlayer()->GetLeg()->GetMotion()->Set(m_nNowMotion, false);
	}

	// �t���[�����ݒ�
	m_pBody->GetMotion()->SetFrame(m_nNowKey, m_nNowMotion, nFrame);
}