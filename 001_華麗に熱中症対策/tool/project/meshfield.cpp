//==========================================================
//
// ���b�V���t�B�[���h�̏��� [meshfield.cpp]
// Author : Ibuki Okusada
//
//==========================================================
#include "meshfield.h"
#include "texture.h"
#include "manager.h"

//==========================================================
// �R���X�g���N�^
//==========================================================
CMeshField::CMeshField()
{

}

//==========================================================
// �f�X�g���N�^
//==========================================================
CMeshField::~CMeshField()
{

}

//==========================================================
// ����������
//==========================================================
HRESULT CMeshField::Init(void)
{
	return S_OK;
}

//==========================================================
// �I������
//==========================================================
void CMeshField::Uninit(void)
{
	//���_�o�b�t�@�̔p��
	CObjectMesh::Uninit();
}

//==========================================================
// �X�V����
//==========================================================
void CMeshField::Update(void)
{
	
}

//==========================================================
// �`�揈��
//==========================================================
void CMeshField::Draw(void)
{
	// �`��
	CObjectMesh::Draw();
}

//==========================================================
// ���_���ݒ�
//==========================================================
void CMeshField::SetVtxInfo(void)
{
	int nVertex = GetVertex();			// ���_�����擾
	int nNumWidth = GetNumWidth();		// ���������擾
	int nNumHeight = GetNumHeight();	// �����������擾

	//���_���W�̐ݒ�(��������E��O�Ɍ������Ē��_����ݒ肷��
	for (int nCntpVtx = 0; nCntpVtx < nVertex; nCntpVtx++)
	{
		//���_���W
		m_pVtx[nCntpVtx].pos.x = -(m_fWidth * nNumWidth) + (nCntpVtx % (nNumWidth + 1) * (m_fWidth * 2));
		m_pVtx[nCntpVtx].pos.y = 0.0f;
		m_pVtx[nCntpVtx].pos.z = (m_fHeight * nNumHeight) + ((nCntpVtx / (nNumWidth + 1) * (-m_fHeight * 2)));

		//
		m_pVtx[nCntpVtx].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		//�F
		m_pVtx[nCntpVtx].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		m_pVtx[nCntpVtx].tex = D3DXVECTOR2(1.0f * (nCntpVtx % (nNumWidth + 1)), 1.0f * (nCntpVtx / (nNumWidth + 1)));
	}

	// ���_�ݒ�
	SetVtx();
}

//==========================================================
// ����
//==========================================================
CMeshField *CMeshField::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, 
	float fWidth, float fHeight, const char *pFileName, const int nWidth, const int nHeight, const int nPriority)
{
	CMeshField *pMeshField = NULL;	// ���b�V���t�B�[���h�̃|�C���^
	CTexture *pTexture = CManager::GetTexture();	// �e�N�X�`���ւ̃|�C���^

	// �������̊m��
	pMeshField = new CMeshField;

	if (pMeshField != NULL)
	{// �m�ۂł����ꍇ
		if (pMeshField->GetId() < 0)
		{// �I�u�W�F�N�g���ŊǗ��ł��Ă��Ȃ��ꍇ
			delete pMeshField;
			pMeshField = NULL;

			return NULL;
		}

		// ������
		pMeshField->Init();

		// ���W�ݒ�
		pMeshField->SetPosition(pos);

		// �����ݒ�
		pMeshField->SetRotation(rot);

		// ���_����
		pMeshField->CObjectMesh::Create(nWidth, nHeight);

		// �T�C�Y�ݒ�
		pMeshField->SetSize(fWidth, fHeight);

		// �e�N�X�`���ݒ�
		pMeshField->BindTexture(pTexture->Regist(pFileName));
	}

	return pMeshField;
}


//==========================================================
// ���ݒ�
//==========================================================
void CMeshField::SetSize(float fWidth, float fHeight)
{
	// �T�C�Y�ݒ�
	m_fWidth = fWidth;
	m_fHeight = fHeight;

	// ���_���ݒ�
	SetVtxInfo();
}
