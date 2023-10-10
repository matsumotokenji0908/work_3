/*******************************************************************************
* �^�C�g��:		���U���g�v���O����
* �v���O������:	result.cpp
* �쐬��:		GP11A132 25 ���{�@����
* �쐬��:		2022/07/07
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "result.h"
#include "battle1.h"
#include "battle2.h"
#include "player.h"
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









int g_ResultLoopCount;			// �^�C�g���̕`����J��Ԃ��ׂ̃J�E���^�[

// �c24�s���A��80��������4��ʕ�
char result[DISP_H * ANIM_CNT][DISP_W] = {
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",



	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                            ���   ���{ ����                                  \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                          �v���O����   ���{ ����                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",


	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                            THANKYOU FOR PLAYING!!                            \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",




};



// �^�C�g���̏���������
void InitResult(void)
{
	g_ResultLoopCount = 0;

}


// �^�C�g���̏I������
void UninitResult(void)
{
	//SetMode(GAME_RESULT);
}


// �^�C�g���̍X�V����
void UpdateResult(void)
{
	//// �e�X�g�Ń��p���R�����Q��J��Ԃ��Ă݂�
	//g_ResultLoopCount++;
	//if (g_ResultLoopCount > 1)
	//{
	//	// �L�[���͑҂�
	//	rewind(stdin);
	//	_getch();

	////	SetMode(GAME_TITLE);		// �Q��������I��������B�{���͂����Ŏ��̃Q�[�����[�h�ֈڍs����
	//}

}


// �^�C�g����ʏ���
void DrawResult(void)
{


	PLAYER* player = GetPlayer();

	printf("RESULT %dg\n", player->gold);


	// �L�[���͑҂�
	rewind(stdin);
	_getch();


	// ��ʃN���A
	system("cls");




	/* ��ʕ`�揈�� */
	for (int y = 0; y < DISP_H * ANIM_CNT; y++)
	{
		/* 1��ʕ��\�������班���E�F�C�g������ */
		if (y % DISP_H == 0)
		{
			/* �E�F�C�g */
			Sleep(500);

			/* ��ʃN���A */
			//system("cls");
		}

		///* 1�������`�悷�� */
		//for (int x = 0; x < DISP_W; x++)
		//{
		//	// ������1�������\������v���O����������
		//	printf("%c", result[y][x]);
		//}

		// �P���������ƒx������P�s���\��������
		printf("%s", &result[y][0]);

		Sleep(100);

	}


	Sleep(500);

	SetMode(GAME_TITLE);

	player->hp= player->hp_max;
	player->mp = player->mp_max;
	player->gold=0;
	player->stps = 0;

	player->atk =50;
	player->atk_max =50;
	player->def =5;
	player->def_max =5;
	player->hae = 0;
	player->boe = 0;





	// �L�[���͑҂�
	rewind(stdin);
	_getch();
	// ��ʃN���A
	system("cls");

}


