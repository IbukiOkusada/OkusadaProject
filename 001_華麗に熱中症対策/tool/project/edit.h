//==========================================================
//
// ���[�V�����G�f�B�^�[�����S�� [edit.h]
// Author : Ibuki Okusada
//
//==========================================================
#ifndef _EDIT_H_		// ���̃}�N������`����Ă��Ȃ��ꍇ
#define _EDIT_H_		// ��d�C���N���[�h�h�~�p�}�N�����`

#include "motion.h"

// �O���錾
class CCharacter;

// �N���X��`
class CEdit
{
public:		// �N�ł��A�N�Z�X�\�Ȓ�`

	// ���
	enum STATE
	{
		STATE_EDIT = 0,	// �G�f�B�b�g���
		STATE_PLAY,		// �v���C���
		STATE_MAX
	};

	// ���ʎ��
	typedef enum
	{
		TYPE_BODY = 0,	// �㔼�g
		TYPE_LEG,		// �����g
		TYPE_MAX
	}TYPE;

public:		// �N�ł��A�N�Z�X�\

	CEdit();	// �R���X�g���N�^
	~CEdit();	// �f�X�g���N�^

	// �����o�֐�
	void Init(void);
	void Uninit(void);
	void Update(void);
	STATE GetState(void) { return m_State; }
	TYPE GetType(void) { return m_Type; }
	void SetBody(CCharacter *pBody) { m_pBody = pBody; }
	void SetInfo(CMotion::KEY_INFO *pInfo) { m_pInfo = pInfo; }
	int GetIdx(void) { return m_nIdx; }
	int GetKey(void) { return m_nNowKey; }
	int GetMotion(void) { return m_nNowMotion; }
	bool GetMotionNow(void) { return m_bMotion; }
	void SetMotionNow(bool bNow) { m_bMotion = bNow; }

private:	// �����������A�N�Z�X�\

	// �����o�֐�
	void Controller(void);
	void EditController(void);
	void PlayController(void);

	// �����o����
	const static char *m_apState[];			// �G�f�B�b�g���
	const static char *m_apType[TYPE_MAX];	// �I�𕔈�
	CMotion::KEY m_Key;	// �ݒ�L�[���
	bool m_bMotion;		// �ݒ肵�����[�V���������邩�ۂ�
	CMotion::KEY_INFO *m_pInfo;	// �R�s�[�p�L�[���
	STATE m_State;		// �G�f�B�b�g��Ԃ��ǂ���
	TYPE m_Type;		// �I�𕔈�
	int m_nIdx;			// �I�����Ă���p�[�c�ԍ�
	int m_nNowMotion;	// ���[�V�����ԍ�
	int m_nNowKey;		// �L�[�ԍ�
	CCharacter *m_pBody;	// �ҏW���ʏ��
};

#endif
