//===================================================
//
// �K�w�\���ɂ�郂�[�V�������� [motion.cpp]
// Author Ibuki Okusada
//
//===================================================
#include "motion.h"
#include "manager.h"
#include "renderer.h"
#include "debugproc.h"
#include "texture.h"
#include "Xfile.h"
#include "model.h"
#include <string.h>

// �}�N����`
#define DEST_MAG	(0.1f)	// �����␳�{��

//===================================================
// �R���X�g���N�^
//===================================================
CMotion::CMotion()
{
	m_nNowFrame = 0;
	m_nNowKey = 0;
	m_nNowMotion = 1;
	m_nNumMotion = 0;
	m_FileData.nNumParts = 0;
	m_FileData.ppParts = NULL;
	m_bFinish = false;

	for (int nCnt = 0; nCnt < MAX_MOTION; nCnt++)
	{
		aInfo[nCnt].nNumKey = 0;
		memset(&aInfo[nCnt].aKeyInfo, NULL, sizeof(CMotion::KEY_INFO));
		aInfo[m_nNumMotion].aKeyInfo[nCnt].nFrame = 1;
		aInfo[nCnt].bLoop = false;
	}

	OldKey = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
}

//===================================================
// �f�X�g���N�^
//===================================================
CMotion::~CMotion()
{

}

//===================================================
// �I������
//===================================================
void CMotion::Uninit(void)
{
	// ���[�V�������̔p��
	for (int nCntMotion = 0; nCntMotion < MAX_MOTION; nCntMotion++)
	{
		if (aInfo[nCntMotion].aKeyInfo != NULL)
		{
			for (int nCntKey = 0; nCntKey < aInfo[nCntMotion].nNumKey; nCntKey++)
			{

				delete[] aInfo[nCntMotion].aKeyInfo[nCntKey].aKey;
				aInfo[nCntMotion].aKeyInfo[nCntKey].aKey = NULL;
			}
		}
	}
}

//===================================================
// �X�V����
//===================================================
void CMotion::Update(void)
{
	if (m_FileData.ppParts != NULL)
	{// �g�p����Ă��Ȃ��ꍇ
		if (aInfo[m_nNowMotion].nNumKey > 0)
		{//�L�[�������݂��Ă���ꍇ
			int nNowMotion = m_nNowMotion;	// ���݂̃��[�V�����ԍ�
			int nNowKey = m_nNowKey;		// ���݂̃L�[
			int nNextkey = (nNowKey + 1) % aInfo[nNowMotion].nNumKey;	//���̃L�[
			int nFrame = aInfo[nNowMotion].aKeyInfo[nNowKey].nFrame;

			float fFrame = ((float)m_nNowFrame / (float)nFrame);	// �t���[���Ԃ̍���

			for (int nCntParts = 0; nCntParts < m_FileData.nNumParts; nCntParts++)
			{
				// �O��̒l���擾
				OldKey.fPosX = m_FileData.ppParts[nCntParts]->GetPosition().x;
				OldKey.fPosY = m_FileData.ppParts[nCntParts]->GetPosition().y;
				OldKey.fPosZ = m_FileData.ppParts[nCntParts]->GetPosition().z;
				OldKey.fRotX = m_FileData.ppParts[nCntParts]->GetPosition().x;
				OldKey.fRotY = m_FileData.ppParts[nCntParts]->GetRotation().y;
				OldKey.fRotZ = m_FileData.ppParts[nCntParts]->GetRotation().z;

				D3DXVECTOR3 setPos = m_FileData.ppParts[nCntParts]->GetPosition();	// �����ʒu
				D3DXVECTOR3 setRot = m_FileData.ppParts[nCntParts]->GetRotation();	// ��������

				//�������Z�o
				float fPosDiffX = aInfo[nNowMotion].aKeyInfo[nNextkey].aKey[nCntParts].fPosX	// X���W
					- aInfo[nNowMotion].aKeyInfo[nNowKey].aKey[nCntParts].fPosX;
				float fPosDiffY = aInfo[nNowMotion].aKeyInfo[nNextkey].aKey[nCntParts].fPosY	// Y���W
					- aInfo[nNowMotion].aKeyInfo[nNowKey].aKey[nCntParts].fPosY;
				float fPosDiffZ = aInfo[nNowMotion].aKeyInfo[nNextkey].aKey[nCntParts].fPosZ	// Z���W
					- aInfo[nNowMotion].aKeyInfo[nNowKey].aKey[nCntParts].fPosZ;
				float fRotDiffX = aInfo[nNowMotion].aKeyInfo[nNextkey].aKey[nCntParts].fRotX	// X����
					- aInfo[nNowMotion].aKeyInfo[nNowKey].aKey[nCntParts].fRotX;
				float fRotDiffY = aInfo[nNowMotion].aKeyInfo[nNextkey].aKey[nCntParts].fRotY	// Y����
					- aInfo[nNowMotion].aKeyInfo[nNowKey].aKey[nCntParts].fRotY;
				float fRotDiffZ = aInfo[nNowMotion].aKeyInfo[nNextkey].aKey[nCntParts].fRotZ	// Z����
					- aInfo[nNowMotion].aKeyInfo[nNowKey].aKey[nCntParts].fRotZ;

				if (fRotDiffZ < -D3DX_PI)
				{// z���W�p�x���E
					fRotDiffZ += D3DX_PI * 2;
				}
				else if (fRotDiffZ > D3DX_PI)
				{// z���W�p�x���E
					fRotDiffZ += -D3DX_PI * 2;
				}

				if (fRotDiffX < -D3DX_PI)
				{// x���W�p�x���E
					fRotDiffX += D3DX_PI * 2;
				}
				else if (fRotDiffX > D3DX_PI)
				{// x���W�p�x���E
					fRotDiffX += -D3DX_PI * 2;
				}

				if (fRotDiffY < -D3DX_PI)
				{// x���W�p�x���E
					fRotDiffY += D3DX_PI * 2;
				}
				else if (fRotDiffY > D3DX_PI)
				{// x���W�p�x���E
					fRotDiffY += -D3DX_PI * 2;
				}

				//���݂̃t���[���̍��W�����߂�
				float fPosDestX = setPos.x	// X���W
					+ aInfo[nNowMotion].aKeyInfo[nNowKey].aKey[nCntParts].fPosX
					+ fPosDiffX * fFrame;
				float fPosDestY = setPos.y	// Y���W
					+ aInfo[nNowMotion].aKeyInfo[nNowKey].aKey[nCntParts].fPosY
					+ fPosDiffY * fFrame;
				float fPosDestZ = setPos.z	// Z���W
					+ aInfo[nNowMotion].aKeyInfo[nNowKey].aKey[nCntParts].fPosZ
					+ fPosDiffZ * fFrame;

				//���݂̃t���[���̌��������߂�
				float fRotDestX = setRot.x	// X����
					+ aInfo[nNowMotion].aKeyInfo[nNowKey].aKey[nCntParts].fRotX
					+ fRotDiffX * fFrame;
				float fRotDestY = setRot.y	// Y����
					+ aInfo[nNowMotion].aKeyInfo[nNowKey].aKey[nCntParts].fRotY
					+ fRotDiffY * fFrame;
				float fRotDestZ = setRot.z	// Z����
					+ aInfo[nNowMotion].aKeyInfo[nNowKey].aKey[nCntParts].fRotZ
					+ fRotDiffZ * fFrame;

				// �ݒ�
				m_FileData.ppParts[nCntParts]->SetCurrentPosition(D3DXVECTOR3(fPosDestX, fPosDestY, fPosDestZ));
				m_FileData.ppParts[nCntParts]->SetCurrentRotation(D3DXVECTOR3(fRotDestX, fRotDestY, fRotDestZ));
			}

			m_nNowFrame++;

			if (aInfo[nNowMotion].aKeyInfo[nNowKey].nFrame != 0)
			{//�t���[����0�ł͂Ȃ��ꍇ
				if (m_nNowFrame >= nFrame)
				{//���݂̃t���[���������B�����ꍇ
					m_nNowKey = nNextkey;	//���̃L�[�Ɉړ�
					m_nNowFrame = 0;
				}
			}
			else
			{//0�̏ꍇ
				m_nNowKey = 0;
				m_nNowFrame = 0;
			}
		}
	}
}

//==========================================================
// ���[�V�������ǂݍ���
//==========================================================
void CMotion::LoadMotionData(FILE *pFile)
{
	char aStr[128] = {};	//�z�u�������i�[�p
	int nCntParts = 0;
	int nCntKey = 0;
	bool bKey = false;

	while (1)
	{
		//�e�L�X�g�ǂݍ���
		int nResult = fscanf(pFile, "%s", &aStr[0]);

		if (nCntKey >= aInfo[m_nNumMotion].nNumKey && bKey == true)
		{//�L�[���ɗ����ꍇ
			m_nNumMotion++;	// ���[�V�������J�E���g�A�b�v
			break;
		}
		if (strcmp(&aStr[0], "LOOP") == 0)
		{//���[�v�m�F
			int nLoop = 0;
			fscanf(pFile, "%s", &aStr[0]);	//(=)�ǂݍ���
			fscanf(pFile, "%d", &nLoop);	//(=)�ǂݍ���

			if (nLoop == 0)
			{//���[�v���Ȃ��ꍇ
				aInfo[m_nNumMotion].bLoop = false;	//���[�v���Ȃ��悤�ɂ���
			}
			else
			{
				aInfo[m_nNumMotion].bLoop = true;	//���[�v����悤�ɂ���
			}
		}
		else if (strcmp(&aStr[0], "NUM_KEY") == 0)
		{//�L�[��
			fscanf(pFile, "%s", &aStr[0]);	//(=)�ǂݍ���
			fscanf(pFile, "%d", &aInfo[m_nNumMotion].nNumKey);	//�L�[���ǂݍ���

			// �p�[�c�����L�[���m��
			for (int nCnt = 0; nCnt < MAX_KEY; nCnt++)
			{
				aInfo[m_nNumMotion].aKeyInfo[nCnt].aKey = new KEY[m_FileData.nNumParts];

				for (int i = 0; i < m_FileData.nNumParts; i++)
				{
					aInfo[m_nNumMotion].aKeyInfo[nCnt].aKey[i].fPosX = 0.0f;
					aInfo[m_nNumMotion].aKeyInfo[nCnt].aKey[i].fPosY = 0.0f;
					aInfo[m_nNumMotion].aKeyInfo[nCnt].aKey[i].fPosZ = 0.0f;
					aInfo[m_nNumMotion].aKeyInfo[nCnt].aKey[i].fRotX = 0.0f;
					aInfo[m_nNumMotion].aKeyInfo[nCnt].aKey[i].fRotY = 0.0f;
					aInfo[m_nNumMotion].aKeyInfo[nCnt].aKey[i].fRotZ = 0.0f;
				}
			}

			bKey = true;	//�L�[�����擾������Ԃɂ���
		}
		else if (strcmp(&aStr[0], "KEYSET") == 0)
		{//�p�[�c���m�F�����������ꍇ
			bool bFrame = false;
			nCntParts = 0;
			while (1)
			{
				//�ǂݍ���
				fscanf(pFile, "%s", &aStr[0]);

				if (nCntParts >= m_FileData.nNumParts)
				{//�p�[�c�����ɓ��B�����ꍇ
					break;
				}
				else if (strcmp(&aStr[0], "FRAME") == 0)
				{//�t���[����
					fscanf(pFile, "%s", &aStr[0]);	//(=)�ǂݍ���
					fscanf(pFile, "%d", &aInfo[m_nNumMotion].aKeyInfo[nCntKey].nFrame);	//�ǂݍ���
					bFrame = true;
				}
				else if (strcmp(&aStr[0], "KEY") == 0 && bFrame == true)
				{//�e�ԍ�
					while (1)
					{
						//�ǂݍ���
						fscanf(pFile, "%s", &aStr[0]);

						if (strcmp(&aStr[0], "END_KEY") == 0)
						{//�t���[����
							break;
						}
						else if (strcmp(&aStr[0], "POS") == 0)
						{//�t���[����
							fscanf(pFile, "%s", &aStr[0]);	//(=)�ǂݍ���
							fscanf(pFile, "%f", &aInfo[m_nNumMotion].aKeyInfo[nCntKey].aKey[nCntParts].fPosX);	//x���W�ǂݍ���
							fscanf(pFile, "%f", &aInfo[m_nNumMotion].aKeyInfo[nCntKey].aKey[nCntParts].fPosY);	//y���W�ǂݍ���
							fscanf(pFile, "%f", &aInfo[m_nNumMotion].aKeyInfo[nCntKey].aKey[nCntParts].fPosZ);	//z���W�ǂݍ���
						}
						else if (strcmp(&aStr[0], "ROT") == 0)
						{//�t���[����																   
							fscanf(pFile, "%s", &aStr[0]);	//(=)�ǂݍ���								
							fscanf(pFile, "%f", &aInfo[m_nNumMotion].aKeyInfo[nCntKey].aKey[nCntParts].fRotX);	//x���W�ǂݍ���
							fscanf(pFile, "%f", &aInfo[m_nNumMotion].aKeyInfo[nCntKey].aKey[nCntParts].fRotY);	//y���W�ǂݍ���
							fscanf(pFile, "%f", &aInfo[m_nNumMotion].aKeyInfo[nCntKey].aKey[nCntParts].fRotZ);	//z���W�ǂݍ���
						}
					}
					nCntParts++;
				}
				else if (strcmp(&aStr[0], "END_KEYSET") == 0)
				{//�p�[�c���I�������m�F�ł����ꍇ
					break;
				}
			}
			nCntKey++;	//�L�[���ړ�
		}
		if (strcmp(&aStr[0], "END_MOTIONSET") == 0)
		{//�L�����N�^�[���I�������m�F�ł����ꍇ
			m_nNumMotion++;	// ���[�V�������J�E���g�A�b�v
			break;
		}
	}
}

//==========================================================
// ���[�V�����ԍ��ݒ�
//==========================================================
void CMotion::Set(int nType)
{
	if (nType >= 0 && nType < m_nNumMotion)
	{// ���[�V�����͈͓�
		if (m_nNowMotion != nType)
		{// ���݂̃��[�V�����ƈႤ�ꍇ

			m_nNowMotion = nType;	// ��ނ�ݒ�
			m_nNowKey = 0;
			m_nNowFrame = 0;

			for (int nCntParts = 0; nCntParts < m_FileData.nNumParts; nCntParts++)
			{
				D3DXVECTOR3 setPos = m_FileData.ppParts[nCntParts]->GetPosition();	// �����ʒu
				D3DXVECTOR3 setRot = m_FileData.ppParts[nCntParts]->GetRotation();	// ��������

				//���݂̃t���[���̍��W�����߂�
				float fPosDestX = setPos.x	// X���W
					+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fPosX;
				float fPosDestY = setPos.y	// Y���W
					+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fPosY;
				float fPosDestZ = setPos.z	// Z���W
					+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fPosZ;

				//���݂̃t���[���̌��������߂�
				float fRotDestX = setRot.x	// X����
					+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fRotX;
				float fRotDestY = setRot.y	// Y����
					+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fRotY;
				float fRotDestZ = setRot.z	// Z����
					+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fRotZ;

				// �ݒ�
				m_FileData.ppParts[nCntParts]->SetCurrentPosition(D3DXVECTOR3(fPosDestX, fPosDestY, fPosDestZ));
				m_FileData.ppParts[nCntParts]->SetCurrentRotation(D3DXVECTOR3(fRotDestX, fRotDestY, fRotDestZ));
			}
		}
	}
}

void CMotion::Set(int nType, bool b)
{
	if (nType >= 0 && nType < m_nNumMotion)
	{// ���[�V�����͈͓�

		m_nNowMotion = nType;	// ��ނ�ݒ�
		m_nNowKey = 0;
		m_nNowFrame = 0;

		for (int nCntParts = 0; nCntParts < m_FileData.nNumParts; nCntParts++)
		{
			D3DXVECTOR3 setPos = m_FileData.ppParts[nCntParts]->GetPosition();	// �����ʒu
			D3DXVECTOR3 setRot = m_FileData.ppParts[nCntParts]->GetRotation();	// ��������

			//���݂̃t���[���̍��W�����߂�
			float fPosDestX = setPos.x	// X���W
				+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fPosX;
			float fPosDestY = setPos.y	// Y���W
				+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fPosY;
			float fPosDestZ = setPos.z	// Z���W
				+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fPosZ;

			//���݂̃t���[���̌��������߂�
			float fRotDestX = setRot.x	// X����
				+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fRotX;
			float fRotDestY = setRot.y	// Y����
				+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fRotY;
			float fRotDestZ = setRot.z	// Z����
				+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fRotZ;

			// �ݒ�
			m_FileData.ppParts[nCntParts]->SetCurrentPosition(D3DXVECTOR3(fPosDestX, fPosDestY, fPosDestZ));
			m_FileData.ppParts[nCntParts]->SetCurrentRotation(D3DXVECTOR3(fRotDestX, fRotDestY, fRotDestZ));
		}
	}
}

//==========================================================
// ���[�V�����L�[�ݒ�
//==========================================================
void CMotion::SetKey(int nKey)
{
	m_nNowKey = nKey;

	for (int nCntParts = 0; nCntParts < m_FileData.nNumParts; nCntParts++)
	{
		D3DXVECTOR3 setPos = m_FileData.ppParts[nCntParts]->GetPosition();	// �����ʒu
		D3DXVECTOR3 setRot = m_FileData.ppParts[nCntParts]->GetRotation();	// ��������

		//���݂̃t���[���̍��W�����߂�
		float fPosDestX = setPos.x	// X���W
			+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fPosX;
		float fPosDestY = setPos.y	// Y���W
			+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fPosY;
		float fPosDestZ = setPos.z	// Z���W
			+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fPosZ;

		//���݂̃t���[���̌��������߂�
		float fRotDestX = setRot.x	// X����
			+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fRotX;
		float fRotDestY = setRot.y	// Y����
			+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fRotY;
		float fRotDestZ = setRot.z	// Z����
			+ aInfo[m_nNowMotion].aKeyInfo[m_nNowKey].aKey[nCntParts].fRotZ;

		// �ݒ�
		m_FileData.ppParts[nCntParts]->SetCurrentPosition(D3DXVECTOR3(fPosDestX, fPosDestY, fPosDestZ));
		m_FileData.ppParts[nCntParts]->SetCurrentRotation(D3DXVECTOR3(fRotDestX, fRotDestY, fRotDestZ));
	}
}

//==========================================================
// �p�[�c���擾
//==========================================================
void CMotion::SetModel(CModel **pModel, int nNumParts)
{
	m_FileData.ppParts = pModel;
	m_FileData.nNumParts = nNumParts;
}

//==========================================================
// �p�[�c���擾
//==========================================================
CMotion::KEY CMotion::GetKey(int nKey, int nMotion, int nParts)
{
	KEY key = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};

	if (nParts >= 0 && nParts < m_FileData.nNumParts)
	{
		key = aInfo[nMotion].aKeyInfo[nKey].aKey[nParts];
	}

	return key;
}

//==========================================================
// �L�[����ݒ�
//==========================================================
void CMotion::SetKey(int nKey, int nMotion, int nParts)
{
	if (nParts >= 0 && nParts < m_FileData.nNumParts)
	{
		D3DXVECTOR3 pos = m_FileData.ppParts[nParts]->GetCurrentPosition() - m_FileData.ppParts[nParts]->GetPosition();
		D3DXVECTOR3 rot = m_FileData.ppParts[nParts]->GetCurrentRotation() - m_FileData.ppParts[nParts]->GetRotation();
		aInfo[nMotion].aKeyInfo[nKey].aKey[nParts] = {pos.x, pos.y, pos.z, rot.x, rot.y, rot.z};
	}
}

//==========================================================
// ������
//==========================================================
void CMotion::Reset(void)
{
	for (int nCntParts = 0; nCntParts < m_FileData.nNumParts; nCntParts++)
	{
		D3DXVECTOR3 setPos = m_FileData.ppParts[nCntParts]->GetPosition();	// �����ʒu
		D3DXVECTOR3 setRot = m_FileData.ppParts[nCntParts]->GetRotation();	// ��������

		// �ݒ�
		m_FileData.ppParts[nCntParts]->SetCurrentPosition(setPos);
		m_FileData.ppParts[nCntParts]->SetCurrentRotation(setRot);
	}
}

//==========================================================
// ������
//==========================================================
int CMotion::GetFrame(void)
{
	int nFrame = 0;

	for (int nCntKey = 0; nCntKey < m_nNowKey; nCntKey++)
	{
		nFrame += aInfo[m_nNowMotion].aKeyInfo[nCntKey].nFrame;
	}

	return nFrame + m_nNowFrame;
}

//==========================================================
// ������
//==========================================================
int CMotion::GetNumFrame(void)
{
	int nFrame = 0;

	for (int nCntKey = 0; nCntKey < aInfo[m_nNowMotion].nNumKey; nCntKey++)
	{
		nFrame += aInfo[m_nNowMotion].aKeyInfo[nCntKey].nFrame;
	}

	return nFrame;
}

//==========================================================
// ���[�V������񏑂��o��
//==========================================================
void CMotion::Save(void)
{
	FILE *pFile;

	// �t�@�C�����J��
	pFile = fopen("data\\motion_info.txt", "w");

	if (pFile == NULL)
	{// �J���Ȃ������ꍇ
		return;
	}

	// �����o���J�n(���o��)
	fprintf(pFile, "+=========================================+\n");
	fprintf(pFile, "|                                         |\n");
	fprintf(pFile, "|              ���[�V�������             |\n");
	fprintf(pFile, "|           [ ���[�V�����ԍ� : %d]         |\n", m_nNowMotion);
	fprintf(pFile, "|                                         |\n");
	fprintf(pFile, "+=========================================+\n\n");

	// �m�F����
	fprintf(pFile, "MOTIONSET\n");

	// ���[�v�m�F
	fprintf(pFile, "	LOOP = ");
	if (aInfo[m_nNowMotion].bLoop == false)
	{// ���Ȃ�
		fprintf(pFile, "0");
	}
	else
	{// ����
		fprintf(pFile, "1");
	}
	fprintf(pFile, "		# ���[�v���邩�ǂ���[0:���[�v���Ȃ� / 1:���[�v����]\n");

	// �L�[��
	fprintf(pFile, "	NUM_KEY = %d		# �L�[��\n\n", aInfo[m_nNowMotion].nNumKey);

	// �L�[��񏑂��o��
	for (int nCntKey = 0; nCntKey < aInfo[m_nNowMotion].nNumKey; nCntKey++)
	{
		// �L�[���J�n����
		fprintf(pFile, "	KEYSET			# --- << KEY : %d / %d >> ---\n", nCntKey, aInfo[m_nNowMotion].nNumKey);

		// �t���[����
		fprintf(pFile, "		FRAME = %d\n", aInfo[m_nNowMotion].aKeyInfo[nCntKey].nFrame);

		for (int nCntParts = 0; nCntParts < m_FileData.nNumParts; nCntParts++)
		{// �p�[�c���J��Ԃ�
			KEY key = aInfo[m_nNowMotion].aKeyInfo[nCntKey].aKey[nCntParts];	// �L�[�����擾

			// ��񏑂��o��
			fprintf(pFile, "		KEY	# ----- [ %d ] -----\n", nCntParts);
			fprintf(pFile, "			POS = %.2f %.2f %.2f\n", key.fPosX, key.fPosY, key.fPosZ);
			fprintf(pFile, "			ROT = %.2f %.2f %.2f\n", key.fRotX, key.fRotY, key.fRotZ);
			fprintf(pFile, "		END_KEY\n");

			if (nCntParts + 1 < m_FileData.nNumParts)
			{// �Ō�̎�O�܂�
				fprintf(pFile, "\n");
			}
		}

		fprintf(pFile, "	END_KEYSET\n");	// �I������

		if (nCntKey + 1 < aInfo[m_nNowMotion].nNumKey)
		{// �Ō�̎�O�܂�
			fprintf(pFile, "\n");
		}
	}

	fprintf(pFile, "END_MOTIONSET\n");	// �I������

	// �t�@�C�������
	fclose(pFile);
}