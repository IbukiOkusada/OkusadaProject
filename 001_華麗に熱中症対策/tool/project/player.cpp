//===============================================
//
// �v���C���[�̏��� [player.cpp]
// Author : Ibuki Okusada
//
//===============================================
#include "player.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "debugproc.h"
#include "camera.h"
#include "Xfile.h"
#include "shadow.h"
#include "waist.h"
#include "character.h"
#include "motion.h"
#include "model.h"
#include "texture.h"
#include "meshfield.h"
#include "edit.h"

//===============================================
// �}�N����`
//===============================================
#define PLAYER_GRAVITY	(-0.7f)	//�v���C���[�d��
#define PLAYER_JUMP		(15.0f)	//�v���C���[�W�����v��
#define MOVE	(2.0f)

//===============================================
// �R���X�g���N�^
//===============================================
//CPlayer::CPlayer()
//{
//	// �l���N���A����
//	m_nCounterAnim = 0;
//	m_nPatternAnim = 0;
//}

//===============================================
// �R���X�g���N�^(�I�[�o�[���[�h)
//===============================================
CPlayer::CPlayer(const D3DXVECTOR3 pos)
{
	// �l���N���A����
	m_bJump = false;
	m_Info.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Info.posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Info.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Info.move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fRotMove = 0.0f;
	m_fRotDiff = 0.0f;
	m_fRotDest = 0.0f;
	pShadow = NULL;
	m_pBody = NULL;
	m_pLeg = NULL;
	m_pWaist = NULL;
}

//===============================================
// �R���X�g���N�^(�I�[�o�[���[�h)
//===============================================
CPlayer::CPlayer(int nPriOrity)
{
	// �l���N���A����
	m_bJump = false;
	m_Info.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Info.posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Info.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Info.move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fRotMove = 0.0f;
	m_fRotDiff = 0.0f;
	m_fRotDest = 0.0f;
	pShadow = NULL;
	m_pBody = NULL;
	m_pLeg = NULL;
	m_pWaist = NULL;
}

//===============================================
// �f�X�g���N�^
//===============================================
CPlayer::~CPlayer()
{

}

//===============================================
// ����������
//===============================================
HRESULT CPlayer::Init(void)
{
	// ���̐���
	if (m_pWaist == NULL)
	{
		m_pWaist = new CWaist;
		m_pWaist->SetParent(&m_Info.mtxWorld);
	}

	return S_OK;
}

//===============================================
// ����������(�I�[�o�[���[�h)
//===============================================
HRESULT CPlayer::Init(const char *pBodyName, const char *pLegName)
{
	CTexture *pTexture = CManager::GetTexture();

	// ���̐���
	if (m_pWaist == NULL)
	{
		m_pWaist = new CWaist;
		m_pWaist->SetParent(&m_Info.mtxWorld);
	}

	// ���̂̐ݒ�
	if (pBodyName != NULL)
	{// �t�@�C���������݂��Ă���
		m_pBody = CCharacter::Create(pBodyName);
		m_pBody->SetParent(m_pWaist->GetMtxWorld());

		if (m_pBody->GetMotion() != NULL)
		{
			// �������[�V�����̐ݒ�
			m_pBody->GetMotion()->Set(0);
		}
	}

	// �����g�̐ݒ�
	if (pLegName != NULL)
	{// �t�@�C���������݂��Ă���
		m_pLeg = CCharacter::Create(pLegName);
		m_pLeg->SetParent(m_pWaist->GetMtxWorld());

		if (m_pLeg->GetMotion() != NULL)
		{
			// �������[�V�����̐ݒ�
			m_pLeg->GetMotion()->Set(0);
		}
	}

	// ���̍��������킹��
	if (m_pLeg != NULL)
	{// �r���g�p����Ă���ꍇ
		CModel *pModel = m_pLeg->GetParts(0);	// ���p�[�c���擾

		if (pModel != NULL)
		{// �p�[�c�����݂���ꍇ
			D3DXVECTOR3 pos = pModel->GetPosition();	// ���f���̑��Έʒu���擾

			// ������ݒ�
			m_pWaist->SetHeight(pos);

			// ���̃��f���̈ʒu��ύX
			pModel->SetPosition(pos);

			CMotion::KEY key = m_pLeg->GetMotion()->GetKey(CManager::GetEdit()->GetKey(), CManager::GetEdit()->GetMotion(), 0);
			pos = { key.fPosX, key.fPosY, key.fPosZ };
			m_pWaist->SetPosition(m_pWaist->GetSetPosition() + pos);
		}
	}

	return S_OK;
}

//===============================================
// �I������
//===============================================
void CPlayer::Uninit(void)
{

	// ���̂̏I������
	if (m_pBody != NULL)
	{
		m_pBody->Uninit();
		delete m_pBody;
		m_pBody = NULL;
	}

	// �����g�̏I������
	if (m_pLeg != NULL)
	{
		m_pLeg->Uninit();
		delete m_pLeg;
		m_pLeg = NULL;
	}

	// ���̏I������
	if (m_pWaist != NULL)
	{
		delete m_pWaist;
		m_pWaist = NULL;
	}

	// �p��
	Release();
}

//===============================================
// �X�V����
//===============================================
void CPlayer::Update(void)
{
	// �O��̍��W���擾
	m_Info.posOld = GetPosition();

	CInputKeyboard *pInputKey = CManager::GetInputKeyboard();	// �L�[�{�[�h�̃|�C���^

	// ���̍X�V
	if (m_pBody != NULL)
	{// �g�p����Ă���ꍇ
		m_pBody->Update();
	}
	
	// �����g�X�V
	if (m_pLeg != NULL)
	{// �g�p����Ă���ꍇ
		m_pLeg->Update();

		CModel *pModel = m_pLeg->GetParts(0);

		// ���̍������U
		if (pModel != NULL)
		{
			m_pWaist->SetPosition(m_pWaist->GetSetPosition() + pModel->GetCurrentPosition());
		}
	}

	if (CManager::GetEdit()->GetState() == CEdit::STATE_PLAY)
	{
		// �v���C���[����
		Controller();
	}

	// �����ݒ�
	//SetBodyRot();

	// �J�����Ǐ]
	CCamera *pCamera = CManager::GetCamera();
	//pCamera->Pursue(GetPosition(), GetRotation());
	
	// �e�̍��W�X�V
	if (pShadow != NULL)
	{
		if (m_pBody != NULL)
		{
			pShadow->SetPosition(D3DXVECTOR3(m_pBody->GetParts(0)->GetMtxWorld()->_41, 0.0f, m_pBody->GetParts(0)->GetMtxWorld()->_43));
		}
	}
}


//===============================================
// �`�揈��
//===============================================
void CPlayer::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();	//�f�o�C�X�ւ̃|�C���^���擾
	CTexture *pTexture = CManager::GetTexture();	// �e�N�X�`���ւ̃|�C���^
	D3DXMATRIX mtxRot, mtxTrans;	//�v�Z�p�}�g���b�N�X

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_Info.mtxWorld);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_Info.rot.y, m_Info.rot.x, m_Info.rot.z);
	D3DXMatrixMultiply(&m_Info.mtxWorld, &m_Info.mtxWorld, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_Info.pos.x, m_Info.pos.y, m_Info.pos.z);
	D3DXMatrixMultiply(&m_Info.mtxWorld, &m_Info.mtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_Info.mtxWorld);

	// ���̐ݒ�
	if (m_pWaist != NULL)
	{
		m_pWaist->SetMatrix();
	}

	// �����g�̕`��
	if (m_pLeg != NULL)
	{
		CModel *pModel = m_pLeg->GetParts(0);

		D3DXVECTOR3 pos = pModel->GetCurrentPosition();

		pModel->SetCurrentPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

		if (CManager::GetEdit()->GetType() == CEdit::TYPE_LEG && CManager::GetEdit()->GetState() == CEdit::STATE_EDIT)
		{
			m_pLeg->DrawCheck();
		}
		else
		{
			m_pLeg->Draw();
		}

		pModel->SetCurrentPosition(pos);
	}

	// ���̂̕`��
	if (m_pBody != NULL)
	{
		if (CManager::GetEdit()->GetType() == CEdit::TYPE_BODY && CManager::GetEdit()->GetState() == CEdit::STATE_EDIT)
		{
			m_pBody->DrawCheck();
		}
		else
		{
			m_pBody->Draw();
		}
	}
}

//===============================================
// ����
//===============================================
CPlayer *CPlayer::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 move, const char *pBodyName, const char *pLegName, const int nPriority)
{
	CPlayer *pPlayer = NULL;
	CXFile *pModelFile = CManager::GetModelFile();

	// �I�u�W�F�N�g2D�̐���
	pPlayer = new CPlayer(nPriority);

	if (pPlayer != NULL)
	{// �����ł����ꍇ

		if (pPlayer->GetId() < 0)
		{// �I�u�W�F�N�g���ŊǗ�����Ă��Ȃ��ꍇ
			delete pPlayer;

			return NULL;
		}

		// ����������
		pPlayer->Init(pBodyName, pLegName);

		// ���W�ݒ�
		pPlayer->SetPosition(pos);

		// �����ݒ�
		pPlayer->SetRotation(rot);

		pPlayer->m_fRotDest = rot.y;

		// �ړ��ʐݒ�
		pPlayer->SetMove(move);

		// ��ނ̐ݒ�
		pPlayer->SetType(TYPE_PLAYER);

		// �e�̐ݒ�
		pPlayer->pShadow = CShadow::Create(pos, 30.0f, 30.0f);
	}
	else
	{// �����Ɏ��s�����ꍇ
		return NULL;
	}

	return pPlayer;
}

//===============================================
// ���쏈��
//===============================================
void CPlayer::Controller(void)
{
	D3DXVECTOR3 pos = GetPosition();	// ���W���擾
	D3DXVECTOR3 rot = GetRotation();	// �������擾
	CInputKeyboard *pInputKey = CManager::GetInputKeyboard();	// �L�[�{�[�h�̃|�C���^
	CCamera *pCamera = CManager::GetCamera();		// �J�����̃|�C���^
	D3DXVECTOR3 CamRot = pCamera->GetRotation();	// �J�����̊p�x
	bool bMove = false;	// �ړ����Ă��邩�ۂ�
	float fSpeed = MOVE;

	m_fRotMove = rot.y;	//���݂̌������擾

	//�v���C���[�̍X�V
	if (pInputKey->GetPress(DIK_A) == true)
	{
		if (pInputKey->GetPress(DIK_W) == true)
		{
			m_Info.move.x += cosf(CamRot.y + (-D3DX_PI * 0.75f)) * fSpeed;
			m_Info.move.z += sinf(CamRot.y + (-D3DX_PI * 0.75f)) * fSpeed;
			m_fRotDest = (-CamRot.y + D3DX_PI * 0.25f);
		}
		else if (pInputKey->GetPress(DIK_S) == true)
		{
			m_Info.move.x += cosf(CamRot.y + (-D3DX_PI * 0.25f)) * fSpeed;
			m_Info.move.z += sinf(CamRot.y + (-D3DX_PI * 0.25f)) * fSpeed;
			m_fRotDest = (-CamRot.y + -D3DX_PI * 0.25f);
		}
		else
		{
			m_Info.move.x += cosf(CamRot.y + (-D3DX_PI * 0.5f)) * fSpeed;
			m_Info.move.z += sinf(CamRot.y + (-D3DX_PI * 0.5f)) * fSpeed;
			m_fRotDest = -CamRot.y;
		}

		// �ړ�������Ԃɂ���
		bMove = true;
	}
	else if (pInputKey->GetPress(DIK_D) == true)
	{
		if (pInputKey->GetPress(DIK_W) == true)
		{
			m_Info.move.x += cosf(CamRot.y + (D3DX_PI * 0.75f)) * fSpeed;
			m_Info.move.z += sinf(CamRot.y + (D3DX_PI * 0.75f)) * fSpeed;

			m_fRotDest = (-CamRot.y + D3DX_PI * 0.75f);
		}
		else if (pInputKey->GetPress(DIK_S) == true)
		{
			m_Info.move.x += cosf(CamRot.y + (D3DX_PI * 0.25f)) * fSpeed;
			m_Info.move.z += sinf(CamRot.y + (D3DX_PI * 0.25f)) * fSpeed;

			m_fRotDest = (-CamRot.y + -D3DX_PI * 0.75f);
		}
		else
		{
			m_Info.move.x += cosf(CamRot.y + (D3DX_PI * 0.5f)) * fSpeed;
			m_Info.move.z += sinf(CamRot.y + (D3DX_PI * 0.5f)) * fSpeed;
			m_fRotDest = (-CamRot.y + D3DX_PI * 1.0f);
		}

		// �ړ�������Ԃɂ���
		bMove = true;
	}
	else if (pInputKey->GetPress(DIK_W) == true)
	{
		m_Info.move.x += -cosf(CamRot.y) * fSpeed;
		m_Info.move.z += -sinf(CamRot.y) * fSpeed;
		m_fRotDest = (-CamRot.y + D3DX_PI * 0.5f);

		// �ړ�������Ԃɂ���
		bMove = true;

	}
	else if (pInputKey->GetPress(DIK_S) == true)
	{
		m_Info.move.x += cosf(CamRot.y) * fSpeed;
		m_Info.move.z += sinf(CamRot.y) * fSpeed;
		m_fRotDest = (-CamRot.y + -D3DX_PI * 0.5f);

		// �ړ�������Ԃɂ���
		bMove = true;
	}

	if (m_bJump == false && bMove == true)
	{// �W�����v���Ă��Ȃ���Ԃňړ�
		m_pBody->GetMotion()->Set(1);
		m_pLeg->GetMotion()->Set(1);
		CManager::GetEdit()->SetMotionNow(false);
	}
	else if (m_bJump == false && bMove == false)
	{
		if (CManager::GetEdit()->GetMotionNow() == false)
		{
			m_pBody->GetMotion()->Set(0);
			m_pLeg->GetMotion()->Set(0);
		}
	}

	// �W�����v
	if (pInputKey->GetPress(DIK_SPACE) == true)
	{// SPACE�L�[
		if (m_bJump == false)
		{// �W�����v���Ă��Ȃ��ꍇ
			m_bJump = true;
			m_Info.move.y = PLAYER_JUMP;
			m_pBody->GetMotion()->Set(3);
			m_pLeg->GetMotion()->Set(3);
		}
	}

	float fGravity = PLAYER_GRAVITY;
	m_Info.move.y += fGravity;
	m_Info.move.x += (0.0f - m_Info.move.x) * 0.25f;	//x���W
	m_Info.move.z += (0.0f - m_Info.move.z) * 0.25f;	//x���W

	pos.x += m_Info.move.x;
	pos.y += m_Info.move.y;
	pos.z += m_Info.move.z;

	if (m_fRotDest > D3DX_PI || m_fRotDest < -D3DX_PI)
	{//-3.14�`3.14�͈̔͊O�̏ꍇ
		if (m_fRotDest > D3DX_PI)
		{
			m_fRotDest += (-D3DX_PI * 2);
		}
		else if (m_fRotDest < -D3DX_PI)
		{
			m_fRotDest += (D3DX_PI * 2);
		}
	}

	m_fRotDiff = m_fRotDest - m_fRotMove;	//�ڕW�܂ł̈ړ������̍���

	if (m_fRotDiff > D3DX_PI || m_fRotDiff < -D3DX_PI)
	{//-3.14�`3.14�͈̔͊O�̏ꍇ
		if (m_fRotDiff > D3DX_PI)
		{
			m_fRotDiff += (-D3DX_PI * 2);
		}
		else if (m_fRotDiff < -D3DX_PI)
		{
			m_fRotDiff += (D3DX_PI * 2);
		}
	}

	rot.y += m_fRotDiff * 0.08f;

	if (rot.y > D3DX_PI || rot.y < -D3DX_PI)
	{//-3.14�`3.14�͈̔͊O�̏ꍇ
		if (rot.y > D3DX_PI)
		{
			rot.y += (-D3DX_PI * 2);
		}
		else if (rot.y < -D3DX_PI)
		{
			rot.y += (D3DX_PI * 2);
		}
	}

	if (pos.y < 0.0f)
	{
		if (m_bJump == true)
		{

		}

		m_Info.move.y = 0.0f;
		pos.y = 0.0f;
		m_bJump = false;
	}
	
	// ���_���ݒ�
	SetRotation(rot);
	SetPosition(pos);

	pos = GetPosition();
}

//===============================================
// ���̂̌����ύX
//===============================================
void CPlayer::SetBodyRot(void)
{
	CCamera *pCamera = CManager::GetCamera();		// �J�����̃|�C���^
	D3DXVECTOR3 CamRot = pCamera->GetRotation();	// �J�����̊p�x

	if (m_pBody == NULL || m_pLeg == NULL)
	{// ��i�K�̊K�w�\���ł͂Ȃ��ꍇ
		return;
	}

	D3DXVECTOR3 rot = m_pBody->GetRotation();	// ���̂̌������擾

	rot.y = (-CamRot.y + D3DX_PI * 0.5f) - m_Info.rot.y;	// �J�����̌����Ă�������ɍ��킹��

	// ���̂̌�����ݒ�
	m_pBody->SetRotation(rot);
}
