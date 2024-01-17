//===============================================
//
// �I�u�W�F�N�g�̏��� [object.cpp]
// Author : Ibuki Okusada
//
//===============================================
#include "object.h"
#include "manager.h"
#include "renderer.h"
#include "camera.h"

// �}�N����`
#define DEFAULT_PRIORITY	(3)	// ��{�̗D�揇��

//===============================================
// �ÓI�����o�ϐ��錾
//===============================================
CObject *CObject::m_apObject[NUM_PRIORITY][MAX_OBJECT] = {};	// �I�u�W�F�N�g�̃|�C���^
int CObject::m_nNumAll = 0;
int CObject::m_nItemNumAll = 0;
int CObject::m_aPriNumAll[NUM_PRIORITY] = {};

//===============================================
// �R���X�g���N�^
//===============================================
//CObject::CObject()
//{
//	for (int nCntObject = 0; nCntObject < MAX_OBJECT; nCntObject++)
//	{
//		if (m_apObject[DEFAULT_PRIORITY][nCntObject] == NULL)
//		{// �g�p����Ă��Ȃ��ꍇ
//			m_apObject[DEFAULT_PRIORITY][nCntObject] = this;	// �������g����
//			m_nID = nCntObject;	// �������g��ID���
//			m_nNumAll++;			// �������J�E���g�A�b�v
//			m_nPriority = DEFAULT_PRIORITY;
//			m_type = TYPE_NONE;	// ��ނ����Z�b�g
//			break;
//		}
//	}
//}

//===============================================
// �R���X�g���N�^(�I�[�o�[���[�h)
//===============================================
CObject::CObject(int nPriority)
{
	if (nPriority < 0)
	{
		nPriority = 0;
	}
	else if (nPriority >= NUM_PRIORITY)
	{
		nPriority = NUM_PRIORITY - 1;
	}

	m_nID = -1;

	for (int nCntObject = 0; nCntObject < MAX_OBJECT; nCntObject++)
	{
		if (m_apObject[nPriority][nCntObject] == NULL)
		{// �g�p����Ă��Ȃ��ꍇ
			m_apObject[nPriority][nCntObject] = this;	// �������g����
			m_nID = nCntObject;	// �������g��ID��ۑ�
			m_nNumAll++;			// �������J�E���g�A�b�v
			m_aPriNumAll[nPriority]++;	// �D�揇�ʂ̑����J�E���g�A�b�v
			m_nPriority = nPriority;
			m_type = TYPE_NONE;	// ��ނ����Z�b�g
			break;
		}
	}
}

//===============================================
// �f�X�g���N�^
//===============================================
CObject::~CObject()
{
	
}

#if 0	// �������z�֐��Ȃ̂Œʂ�Ȃ�
//===============================================
// ����������
//===============================================
HRESULT CObject::Init(void)
{

}
#endif

#if 0	// �������z�֐��Ȃ̂Œʂ�Ȃ�
//===============================================
// �I������
//===============================================
void CObject::Uninit(void)
{
	
}
#endif

#if 0	// �������z�֐��Ȃ̂Œʂ�Ȃ�
//===============================================
// �X�V����
//===============================================
void CObject::Update(void)
{

}
#endif

#if 0	// �������z�֐��Ȃ̂Œʂ�Ȃ�
//===============================================
// �`�揈��
//===============================================
void CObject::Draw(void)
{

}
#endif

//===============================================
// �S�ẴI�u�W�F�N�g�̔p��
//===============================================
void CObject::ReleaseAll(void)
{
	for (int nCntPri = 0; nCntPri < NUM_PRIORITY; nCntPri++)
	{
		for (int nCntObj = 0; nCntObj < MAX_OBJECT; nCntObj++)
		{
			if (m_apObject[nCntPri][nCntObj] != NULL)
			{// �g�p���Ă���ꍇ
				// �I������
				m_apObject[nCntPri][nCntObj]->Uninit();
			}
		}
	}
}

//===============================================
// �S�ẴI�u�W�F�N�g�̍X�V
//===============================================
void CObject::UpdateAll(void)
{
	for (int nCntPri = 0; nCntPri < NUM_PRIORITY; nCntPri++)
	{
		for (int nCntObject = 0; nCntObject < MAX_OBJECT; nCntObject++)
		{
			if (m_apObject[nCntPri][nCntObject] != NULL)
			{// �g�p���Ă���ꍇ
				// �X�V����
				m_apObject[nCntPri][nCntObject]->Update();
			}
		}
	}
}

//===============================================
// �S�ẴI�u�W�F�N�g�̕`��
//===============================================
void CObject::DrawAll(void)
{
	CCamera *pCamera = CManager::GetCamera();

	if (pCamera != NULL)
	{// �g�p����Ă���ꍇ
		pCamera->SetCamera();
	}

	for (int nCntPri = 0; nCntPri < NUM_PRIORITY; nCntPri++)
	{
		for (int nCntObject = 0; nCntObject < MAX_OBJECT; nCntObject++)
		{
			if (m_apObject[nCntPri][nCntObject] != NULL)
			{// �g�p���Ă���ꍇ
				// �`�揈��
				m_apObject[nCntPri][nCntObject]->Draw();
			}
		}
	}
}

//===============================================
// �I�u�W�F�N�g�̔p��
//===============================================
void CObject::Release(void)
{
	int nID = m_nID;	// �ԍ��ێ�
	int nPri = m_nPriority;	// �D�揇�ʔԍ��ێ�
	TYPE type = m_type;

	if (m_apObject[nPri][nID] != NULL)
	{// �g�p���Ă���ꍇ
		delete m_apObject[nPri][nID];	// �������̊J��
		m_apObject[nPri][nID] = NULL;	// �g�p���Ă��Ȃ���Ԃɂ���
		m_nNumAll--;			//�������J�E���g�_�E��
		m_aPriNumAll[nPri]--;	// �D�揇�ʂ��Ƃ̑����J�E���g�_�E��

		if (type == TYPE_MODEL)
		{
			m_nItemNumAll--;
		}
	}

}

//===============================================
// �^�C�v�̐ݒ�
//===============================================
void CObject::SetType(const TYPE type)
{
	if (m_type != type)
	{
		if (type == TYPE_MODEL)
		{
			m_nItemNumAll++;
		}
	}

	m_type = type;	// ��ނ�ݒ�
}
