//===============================================
//
// �I�u�W�F�N�g�̏��� [object.h]
// Author : Ibuki Okusada
//
//===============================================
#ifndef _OBJECT_H_		// ���̃}�N������`����Ă��Ȃ��ꍇ
#define _OBJECT_H_		// ��d�C���N���[�h�h�~�p�}�N�����`

#include "main.h"

// �}�N����`
#define MAX_OBJECT		(1024)	// �ő吔
#define NUM_PRIORITY	(8)		// �D�揇�ʊǗ���

// �O���錾
class CObject2D;
class CMultiBg;

//===============================================
// �I�u�W�F�N�g�N���X�̒�`(���ۃN���X)
//===============================================
class CObject
{
public:	// �N�ł��A�N�Z�X�\

		// ��ޗ񋓌^�̒�`
	typedef enum
	{
		TYPE_NONE = 0,	// �����Ȃ�
		TYPE_BG,		// �w�i
		TYPE_PLAYER,	// �v���C���[
		TYPE_ENEMY,		// �G
		TYPE_BULLET,	// �e
		TYPE_ITEM,		// �A�C�e��
		TYPE_EXPLOSION,	// ����
		TYPE_EFFECT,	// �G�t�F�N�g
		TYPE_BLOCK,		// �u���b�N
		TYPE_MODEL,		// ���f��
		TYPE_MAX
	}TYPE;

	//CObject();			// �R���X�g���N�^
	CObject(int nPriority = 3);	// �R���X�g���N�^(�I�[�o�[���[�h)�f�t�H���g����
	virtual ~CObject();	// �f�X�g���N�^

	// �������z�֐��֐�
	virtual HRESULT Init(void) = 0;
	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

	// �����o�֐�(�ݒ�)
	virtual void SetPosition(const D3DXVECTOR3 pos) = 0;
	virtual void SetRotation(const D3DXVECTOR3 rot) = 0;

	// �����o�֐�(�擾)
	virtual D3DXVECTOR3 GetPosition(void) = 0;
	virtual D3DXVECTOR3 GetRotation(void) = 0;
	virtual CObject2D *GetObject2D(void) { return NULL; }

	// �����o�֐�
	static void ReleaseAll(void);
	static void UpdateAll(void);
	static void DrawAll(void);
	static CObject *GetObject(const int nPriority,const int nIdx) { return m_apObject[nPriority][nIdx]; }
	static int GetNumAll(void) { return m_nNumAll; }
	static int GetItemNumAll(void) { return m_nItemNumAll; }
	static int GetPriNumAll(int nPriority) { return m_aPriNumAll[nPriority]; }

	// �����o�֐�(�擾
	TYPE GetType(void) { return m_type; }
	int GetId(void) { return m_nID; }

	// �����o�֐�(�ݒ�)
	void SetType(const TYPE type);

protected:	// �h���N���X������A�N�Z�X�\

	// �����o�֐�
	void Release(void);

private:	// �����������A�N�Z�X�\

	static CObject *m_apObject[NUM_PRIORITY][MAX_OBJECT];	// �I�u�W�F�N�g�N���X�̃|�C���^
	static int m_aPriNumAll[NUM_PRIORITY];	// �e�D�揇�ʂ��Ƃ̑���
	static int m_nNumAll;	// �I�u�W�F�N�g����
	static int m_nItemNumAll;	// �A�C�e���̑���
	int m_nID;			// �������g��ID
	int m_nPriority;	// �D�揇�ʂ̈ʒu
	TYPE m_type;		// ���
};

#endif
