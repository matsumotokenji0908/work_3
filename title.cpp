/*******************************************************************************
* �^�C�g��:		�^�C�g���v���O����
* �v���O������:	title.cpp
* �쐬��:		GP11A132 25 ���{�@����
* �쐬��:		2022/07/07
*******************************************************************************/

/*******************************************************************************
* scanf ��warning�h�~
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "title.h"
#include "battle1.h"
#include "battle2.h"

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

int g_TitleLoopCount;			// �^�C�g���̕`����J��Ԃ��ׂ̃J�E���^�[

// �c24�s���A��80��������4��ʕ�
char title[DISP_H * ANIM_CNT][DISP_W] = {
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                   ooooo                                                      \n",
	"                                                                              \n",
	"                   ooooo                     o                                \n",
	"                                           oo                                 \n",
	"                                       oooo                                   \n",
	"                                   oooooo                                     \n",
	"                                 ooooo                                        \n",
	"                              oooooo                                          \n",
	"                           oooooo                                             \n",
	"                      ooooooooo                                               \n",
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
	"                           oooooooooooooooooo                                 \n",
	"                           oooooooooooooooooo                                 \n",
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
	"                        oooooooooooooooooooo                                  \n",
	"                        oooooooooooooooooooo                                  \n",
	"                                       ooooo                                  \n",
	"                                      oooo                                    \n",
	"                                    ooooo                                     \n",
	"                                  ooooo                                       \n",
	"                                oooooo                                        \n",
	"                               oooo                                           \n",
	"                             oooo                                             \n",
	"                            ooo                                               \n",
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
	"              oooo                       ooooooooooooo                        \n",
	"                                                     o                        \n",
	"              oooo       o                          o                         \n",
	"                        oo     ooooooo             o                          \n",
	"                     ooo       ooooooo            o                           \n",
	"                   ooo                           o                            \n",
	"               oooo                           oo                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                                                                              \n",
	"                     presented by Kenji Matsumoto                             \n",
	"                                                                              \n",
	"                                                                              \n",
	"     1 �`���[�g���A��                                                         \n",
	"                                                                              \n",
	"     2 �Q�[��                                                                 \n",
	"                                                                              \n",
};



// �^�C�g���̏���������
void InitTitle(void)
{



	//int game_select = 0;
	//int sel = 0;
	//

	//g_TitleLoopCount = 0;




	///* ��ʕ`�揈�� */
	//for (int y = 0; y < DISP_H * ANIM_CNT; y++)
	//{
	//	/* 1��ʕ��\�������班���E�F�C�g������ */
	//	if (y % DISP_H == 0)
	//	{
	//		/* �E�F�C�g */
	//		Sleep(500);

	//		/* ��ʃN���A */
	//		system("cls");
	//	}

	//	///* 1�������`�悷�� */
	//	//for (int x = 0; x < DISP_W; x++)
	//	//{
	//	//	// ������1�������\������v���O����������
	//	//	printf("%c", title[y][x]);
	//	//}

	//	// �P���������ƒx������P�s���\��������
	//	printf("%s", &title[y][0]);



	//}










	//	printf("1 �`���[�g���A��\n");
	//	printf("2 �Q�[��\n");


	//	//// �L�[���͑҂�
	//	//rewind(stdin);
	//	//_getch();


	//	scanf("%d", &game_select);

	//	



	//	switch (game_select)
	//	{

	//		do {


	//			sel = 0;


	//	case 1:



	//		SetMode(GAME_TUTORIAL);		// �Q��������I��������B�{���͂����Ŏ��̃Q�[�����[�h�ֈڍs����

	//		break;

	//	case 2:



	//		SetMode(GAME_MODE);		// �Q��������I��������B�{���͂����Ŏ��̃Q�[�����[�h�ֈڍs����

	//		break;


	//	default:


	//		sel = 1;



	//		break;


	//		} while (sel > 0);//�Q�[���I���R�}���h�̃��[�v�@���i�͋U�@default�̎��̂ݐ^���Ƃ�







	//	}






}


// �^�C�g���̏I������
void UninitTitle(void)
{

}


// �^�C�g���̍X�V����
void UpdateTitle(void)
{




	//int game_select = 0;
	//int sel = 0;


	////// �e�X�g�Ń��p���R�����Q��J��Ԃ��Ă݂�
	//g_TitleLoopCount++;
	//if (g_TitleLoopCount > 1)
	//{




	//	printf("1 �`���[�g���A��\n");
	//	printf("2 �Q�[��\n");


	//	//// �L�[���͑҂�
	//	//rewind(stdin);
	//	//_getch();


	//	scanf("%d", &game_select);




	//	switch (game_select)
	//	{

	//		do {


	//			sel = 0;


	//	case 1:



	//		SetMode(GAME_TUTORIAL);		// �Q��������I��������B�{���͂����Ŏ��̃Q�[�����[�h�ֈڍs����

	//		break;

	//	case 2:



	//		SetMode(GAME_MODE);		// �Q��������I��������B�{���͂����Ŏ��̃Q�[�����[�h�ֈڍs����

	//		break;


	//	default:


	//		sel = 1;



	//		break;


	//		} while (sel > 0);//�Q�[���I���R�}���h�̃��[�v�@���i�͋U�@default�̎��̂ݐ^���Ƃ�



	//	}

	//}

	//

}


// �^�C�g����ʏ���
void DrawTitle(void)
{
	/* ��ʕ`�揈�� */
	for (int y = 0; y < DISP_H * ANIM_CNT; y++)
	{
		/* 1��ʕ��\�������班���E�F�C�g������ */
		if (y % DISP_H == 0)
		{
			/* �E�F�C�g */
			Sleep(500);

			/* ��ʃN���A */
			system("cls");
		}

		///* 1�������`�悷�� */
		//for (int x = 0; x < DISP_W; x++)
		//{
		//	// ������1�������\������v���O����������
		//	printf("%c", title[y][x]);
		//}

		// �P���������ƒx������P�s���\��������
		printf("%s", &title[y][0]);



	}







	int game_select = 0;
	int sel = 0;


	//// �e�X�g�Ń��p���R�����Q��J��Ԃ��Ă݂�
	g_TitleLoopCount++;
	if (g_TitleLoopCount > 0)
	{


		game_select = 0;
		sel = 0;

		//printf("1 �`���[�g���A��\n");
		//printf("2 �Q�[��\n");



		scanf("%d", &game_select);






		switch (game_select)
		{

			do {


				sel = 0;


		case 1:



			SetMode(GAME_TUTORIAL);		// �Q��������I��������B�{���͂����Ŏ��̃Q�[�����[�h�ֈڍs����

			break;

		case 2:



			SetMode(GAME_MODE);		// �Q��������I��������B�{���͂����Ŏ��̃Q�[�����[�h�ֈڍs����

			break;


		default:


			sel = 1;



			break;


			} while (sel > 0);//�Q�[���I���R�}���h�̃��[�v�@���i�͋U�@default�̎��̂ݐ^���Ƃ�



		}

	}



}



