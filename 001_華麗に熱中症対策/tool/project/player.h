//==========================================================
//
// �v���C���[�̏��� [player.h]
// Author : Ibuki Okusada
//
//==========================================================
#ifndef _PLAYER_H_		// ���̃}�N������`����Ă��Ȃ��ꍇ
#define _PLAYER_H_		// ��d�C���N���[�h�h�~�p�}�N�����`

#include "main.h"
#include "object.h"

// �O���錾
class CShadow;
class CCharacter;
class CWaist;
class CObjectBillboard;

//==========================================================
// �A�j���[�V�����I�u�W�F�N�g(2D)�̃N���X��`(�h���N���X)
//==========================================================
class CPlayer : public CObject
{
private:	// �����������A�N�Z�X�\�Ȓ�`

	// ���\����
	typedef struct
	{
		D3DXVECTOR3 pos;		// �ʒu
		D3DXVECTOR3 rot;		// ����
		D3DXVECTOR3 move;		// �ړ���
		D3DXVECTOR3 posOld;		// �ݒ�ʒu
		D3DXMATRIX mtxWorld;	// ���[���h�}�g���b�N�X
	}INFO;

public:	// �N�ł��A�N�Z�X�\

	//CPlayer();	// �R���X�g���N�^
	CPlayer(const D3DXVECTOR3 pos);	// �R���X�g���N�^(�I�[�o�[���[�h)
	CPlayer(int nPriOrity = 1);
	~CPlayer();	// �f�X�g���N�^

	// �����o�֐�
	HRESULT Init(void);
	HRESULT Init(const char *pBodyName, const char *pLegName);	// �I�[�o�[���[�h
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CPlayer *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const D3DXVECTOR3 move, 
	const char *pBodyName, const char *pLegName, const int nPriority = 4);

	// �����o�֐�(�ݒ�)
	void SetMove(const D3DXVECTOR3 move) { m_Info.move = move; }
	void SetPosition(const D3DXVECTOR3 pos) { m_Info.pos = pos; }
	void SetRotation(const D3DXVECTOR3 rot) { m_Info.rot = rot; }

	// �����o�֐�(�擾)
	D3DXVECTOR3 GetMove(void) { return m_Info.move; }
	D3DXVECTOR3 GetPosition(void) { return m_Info.pos; }
	D3DXVECTOR3 GetRotation(void) { return m_Info.rot; }
	CCharacter *GetBody(void) { return m_pBody; }
	CCharacter *GetLeg(void) { return m_pLeg; }

private:	// �����������A�N�Z�X�\

	// �����o�֐�
	void Controller(void);
	void SetBodyRot(void);

	// �����o�ϐ�
	CWaist *m_pWaist;		// ��
	CCharacter *m_pBody;	// �㔼�g
	CCharacter *m_pLeg;		// �����g
	D3DXVECTOR3 m_PartsPos;	// ��0�p�[���W
	INFO m_Info;			// �������g�̏��
	bool m_bJump;			// �W�����v�������ǂ���
	bool m_bMove;			// �ړ��������ǂ���
	float m_fRotMove;		// ���݂̊p�x
	float m_fRotDiff;		// �ړI�̊p�x
	float m_fRotDest;		// �p�x�v�Z
	CShadow *pShadow;		// �e
};

#endif
