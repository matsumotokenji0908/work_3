/*******************************************************************************
* �^�C�g��:		���C���v���O����
* �v���O������:	main.cpp
* �쐬��:		GP11A132 25 ���{�@����
* �쐬��:		2022/07/07
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "title.h"
#include "field.h"
#include"player.h"
#include"enemy.h"
#include"battle1.h"
#include"battle2.h"
#include"result.h"
#include"tutorial.h"
#include"file.h"
#include"shop.h"


/*******************************************************************************
* �}�N����`
*******************************************************************************/


/*******************************************************************************
* �\���̒�`
*******************************************************************************/


/*******************************************************************************
* �v���g�^�C�v�錾(�֐��̐�����)
*******************************************************************************/


/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/

int g_Mode = GAME_TITLE;		// ���ݓ��삵�Ă����ԁi�Q�[�����[�h�j
BOOL g_LoadGame =0;					// NewGame


/*******************************************************************************
 �֐���:	int main( void )
 ����:		void
 �߂�l:	����I��: int�^�� 0
 ����:		���C���֐�
*******************************************************************************/
int main(void)
{

	Init();			// �Q�[���S�̂̏���������

	// �Q�[�����[�h���I������Ȃ��ԁA�i�v�ɌJ��Ԃ�
	while (GetMode() < GAME_END)
	{
		Update();	// �Q�[���S�̂̍X�V����

		Draw();		// �Q�[���S�̂̕`�揈��
	}

	Uninit();		// �Q�[���S�̂̏I������

	return 0;
}



// �Q�[���S�̂̏���������
void Init(void)
{
	// �����_���̏���������
	srand((unsigned)time(NULL));

	// �^�C�g���̏���������
	InitTitle();

	InitTutorial();

	InitField();
	InitPlayer();
	InitEnemy();
	InitShop();
	InitBattle1();
	InitBattle2();

	InitResult();

	printf("\n�Z�[�u�f�[�^�����[�h���܂����H");
	printf("\nYES��x�L�[");


	// �L�[���͏���
	int key = _getch();
	if ((key == 0) || (key == 224))	// ����Key�Ȃ�����P�x�擾����
	{
		key = _getch();
	}

	// �L�[���͑҂�
	rewind(stdin);
	_getch();

	switch (key)
	{
	case 'x':
		g_LoadGame = TRUE;
	}
		// ���[�h�Q�[���������炷�ׂĂ̏��������I�������ɃZ�[�u�f�[�^��ǂݍ���
		if (g_LoadGame == TRUE)
		{
			LoadData();
			g_LoadGame = FALSE;		// ���[�h��������t���O��Clear����

		}
	
}


// �Q�[���S�̂̏I������
void Uninit(void)
{
	// �L�[���͑҂�
	rewind(stdin);
	_getch();

	UninitTitle();

	UninitTutorial();


	UninitField();
	UninitPlayer();
	UninitEnemy();
	UninitShop();
	UninitBattle1();
	UninitBattle2();
	UninitResult();
}


// �Q�[���S�̂̍X�V����
void Update(void)
{
	// ���݂̃��[�h�ɂ���ď�������������
	switch ( GetMode() )
	{
	case GAME_TITLE:
		UpdateTitle();
		break;

	// �{���͂����֑��̃Q�[�����[�h��ǉ�����
	// �Ⴆ�΁A�t�B�[���h�Ƃ��o�g���Ƃ��A�G���f�B���O�Ƃ��A�A�A

	case GAME_TUTORIAL:
		UpdateTutorial();
		break;



	case GAME_MODE:
		UpdatePlayer();
		UpdateEnemy();
		UpdateField();
		break;

	case GAME_SHOP:
		UpdateShop();
		break;

	case GAME_BATTLE1:
			UpdateBattle1();
			break;


	case GAME_BATTLE2:
		UpdateBattle2();
		break;

	case GAME_RESULT:
		UpdateResult();
		break;
	}

}


// �Q�[���S�̂̕`�揈��
void Draw(void)
{
	// ���݂̃��[�h�ɂ���ď�������������
	switch (GetMode())
	{
	case GAME_TITLE:
		DrawTitle();
		break;

	// �{���͂����֑��̃Q�[�����[�h��ǉ�����
	// �Ⴆ�΁A�t�B�[���h�Ƃ��o�g���Ƃ��A�G���f�B���O�Ƃ��A�A�A

	case GAME_TUTORIAL:
		DrawTutorial();
		break;




	case GAME_MODE:
		DrawPlayer();
		DrawEnemy();
		DrawField();
		break;

	case GAME_SHOP:
		DrawShop();
		break;

	case GAME_BATTLE1:
		DrawBattle1();
		break;

	case GAME_BATTLE2:
		DrawBattle2();
		break;


	case GAME_RESULT:
		DrawResult();
		break;

	}

}


// ���݂̃Q�[�����[�h���擾����
int GetMode(void)
{
	return g_Mode;
}


// �Q�[�����[�h��ύX����
void SetMode(int mode)
{
	g_Mode = mode;
}

