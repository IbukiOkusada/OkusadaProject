//===================================================
//
// �K�w�\���ɂ�郂�[�V�������� [motion.h]
// Author Ibuki Okusada
//
//===================================================
#ifndef _MOITON_H_
#define _MOITON_H_

#include "main.h"		//main.h�Œ�`���Ă�����̂��K�v�Ȃ���include

#define MAX_MOTION		(64)	// ���[�V�����ő吔
#define MAX_KEY		(64)		// �L�[�̍ő吔

// �O���錾
class CModel;

//**********************************************************
// ���[�V�����N���X�̒�`
//**********************************************************
class CMotion
{
public: // �N�ł��A�N�Z�X�\�Ȓ�`

	// �L�[
	typedef struct
	{
		float fPosX;
		float fPosY;
		float fPosZ;
		float fRotX;
		float fRotY;
		float fRotZ;
	}KEY;

	// �L�[���
	typedef struct
	{
		int nFrame;			// �Đ��t���[��
		KEY *aKey;			// �p�[�c�̑���
	}KEY_INFO;

private:	// �����������A�N�Z�X�\�Ȓ�`

	// ���[�V�������
	typedef struct
	{
		bool bLoop;			// ���[�v���邩�ǂ���
		int nNumKey;		// �L�[��
		KEY_INFO aKeyInfo[MAX_KEY];	// �L�[�̑���
	}INFO;

	//���̃t�@�C�����
	typedef struct
	{
		CModel **ppParts;		// �p�[�c�̏��
		int nNumParts;			// �p�[�c��
	}BodyFileData;

public:		// �N�ł��A�N�Z�X�\
	CMotion();	// �R���X�g���N�^
	~CMotion();	// �f�X�g���N�^

	// �����o�֐�
	void Uninit(void);
	void Update(void);
	void Set(int nType);
	void Set(int nType, bool b);
	void SetModel(CModel **pModel, int nNumParts);
	void SetNumKey(int nNumKey) { aInfo[m_nNowMotion].nNumKey = nNumKey; }
	void SetFrame(int nKey, int nMotion, int nFrame) { aInfo[nMotion].aKeyInfo[nKey].nFrame = nFrame; }
	void LoadMotionData(FILE *pFile);
	int GetNumKey(void) { return aInfo[m_nNowMotion].nNumKey; }
	int GetNum(void) { return m_nNumMotion; }
	int GetNow(void) { return m_nNowMotion; }
	KEY GetKey(int nKey, int nMotion, int nParts);
	KEY_INFO *GetKeyInfo(int nKey, int nMotion) { return &aInfo[nMotion].aKeyInfo[nKey]; }
	void SetKey(int nKey, int nMotion, int nParts);
	void SetKey(int nKey);
	void Reset(void);
	void Save(void);
	int GetFrame(int nKey, int nMotion) { return aInfo[nMotion].aKeyInfo[nKey].nFrame; }
	int GetFrame(void);
	int GetNumFrame(void);
	int GetNowKey(void) { return m_nNowKey;}
	int GetNowFrame(void) { return m_nNowFrame; }

private:	// �����������A�N�Z�X�\

	// �����o�ϐ�
	KEY OldKey;				// �O��̃L�[���
	INFO aInfo[MAX_MOTION];	// ���[�V�������
	int m_nNumMotion;		// ���[�V������
	int m_nNowFrame;		// ���݂̃t���[����
	int m_nNowMotion;		// ���݂̃��[�V�����ԍ�
	int m_nNowKey;			// ���݂̃L�[��
	bool m_bFinish;			// �I���������ǂ���
	BodyFileData m_FileData;// �t�@�C�����
};

#endif
