/*******************************************************************************
* �^�C�g��:		�o�g��2�v���O����
* �v���O������:	battle2.cpp
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
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>



#include "main.h"
#include "battle1.h"
#include "battle2.h"
#include "player.h"
#include "enemy.h"
#include "field.h"
/*******************************************************************************
* �}�N����`
*******************************************************************************/


/*******************************************************************************
* �\���̒�`
*******************************************************************************/


/*******************************************************************************
* �v���g�^�C�v�錾(����Ȋ֐���p�ӂ��Ă���܂���錾/�֐��̐�����)
*******************************************************************************/
void kougeki2(void);
void tousou2(void);
void steal2(void);
void kaihuku2(void);
void dexupm2(void);


/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/

	int data2 = 0;
	int dexup2 = 5;
	int curp2 = 50;
	int dex2 = 30;
	int ehp2 = 110;
	int ehp2_max = 110;

	int eatk2 = 35;			// �U����
	int edmg2 = 0;
	int edef2 = 10;
	int k2 = 0;//������,��������1 �S�Ŏ���2���Ƃ�


void InitBattle2(void)
{
}

void UninitBattle2(void)
{
}

void UpdateBattle2(void)
{


	PLAYER* player = GetPlayer();


	int hensuu = 0;
	int damage = 0;			// �_���[�W�l
	int firetaisei = 0;
	int eatkp = 0;
	int hensuu2 = 0;
	int mpm = 5;
	int i = 0;
	int j = 0;


	i = 0;
	j = 0;
	k2 = 0;



	system("cls");



	printf("���R�m");
	printf("�����ꂽ�I\n");

		Sleep(1000);


		while (k2 == 0)
		{



			// �L�[���͑҂�
			rewind(stdin);
			_getch();


			// ��ʃN���A
			system("cls");


			do {


				printf("�R�}���h�H\n");
				printf("�g�o %d\n\n", player->hp);
				printf("�l�o %d\n\n", player->mp);
				printf("1 ���������@2 �ɂ���@3 ���ށ@4 ����\n");


				scanf("%d", &hensuu);

				// ��ʃN���A
				system("cls");


				switch (hensuu)
				{
					hensuu = 0;

				case 1:

					kougeki2();
					i = 0;
					break;

				case 2:
					tousou2();
					i = 0;
					break;

				case 3:

					steal2();
					i = 0;
					break;



				case 4:

					do {

						printf("�R�}���h�H\n");
						printf("�g�o %d\n\n", player->hp);
						printf("�l�o %d\n\n", player->mp);
						printf("1 �߂�@2 �����񕜖��� 3 ������p���㏸����\n");

						scanf("%d", &hensuu2);

						// ��ʃN���A
						system("cls");

						switch (hensuu2) //�����̃R�}���h�I��
						{
							hensuu2 = 0;
						case 1:

							i = 1;
							j = 0;
							break;


						case 2: //�񕜖������g�����ꍇ

							kaihuku2();

							i = 0;
							j = 0;

							break;
						case 3:
							dexupm2();
							i = 0;
							j = 0;



							break;


						default:
							i = 0;
							j = 1;



							break;

						}

					} while (j > 0);//�����R�}���h�̃��[�v�@���i�͋U�@default�̎��̂ݐ^���Ƃ�
					j = 0;
					break;	//case4�I��



				default:
					i = 1;

					break;
				}	//switch�I��
			} while (i > 0);//�����R�}���h�̃��[�v�@���i�͋U�@default,�߂�R�}���h��I���������̂ݐ^���Ƃ�

			i = 0;


			if (k2 == 0)
			{

				srand((unsigned)time(NULL));

				printf("���R�m�̍U���I\n\n");

				//���R�m�̍U������


				// �L�[���͑҂�
				rewind(stdin);

				_getch();


				//���R�m�̍U���p�^�[��
				eatkp = rand() % 5;

				if (eatkp > 1)
				{
					// �_���[�W�v�Z
					damage = (rand() % (eatk2 / 2)) + (eatk2 / 2) / (player->def / 2);	// eatk�����Ƀ����_���Ń_���[�W������

				}
				else
				{

					printf("���̑��U���I�I\n");

					// �L�[���͑҂�
					rewind(stdin);
					_getch();


					// ��ʃN���A
					system("cls");

					printf("[�V�[�t]\n");
					printf("�u�������������I�I�v\n");

					damage = 25 - firetaisei;
				}



				printf("�V�[�t��%d�̃_���[�W���󂯂��I\n", damage);

				//�c��HP�\������
				player->hp = player->hp - damage;		// HP�̌v�Z����



			// �L�[���͑҂�
				rewind(stdin);
				_getch();

				if (player->hp <= 0)
				{
					k2 = 2;

					printf("�V�[�t�͗͐s���Ă��܂����I\n");
					// �L�[���͑҂�
					rewind(stdin);
					_getch();

					//printf("�L�[���͂ŋ����I�����܂��B����ꂳ�܂ł����B\n");
					//// �L�[���͑҂�
					//rewind(stdin);
					//_getch();
					//exit(-1);		//�v���O���������I��
				}


				else
				{

					printf("�g�o�c��%d\n\n", player->hp);

					if (player->hp < 30)

					{
						printf("[�V�[�t]\n");
						printf("�u�����l���߂���...�v");
					}

					else if (player->hp < 60)
					{
						printf("[�V�[�t]\n");
						printf("�u�l���Ă΁A������҂�h������...�v");

					}


					else if (player->hp < 200)
					{
						printf("[�V�[�t]\n");
						printf("�u�l���Ă΁A�܂��܂����C������ˁI�v");
					}


					// �L�[���͑҂�
					rewind(stdin);
					_getch();


				}
			}
		}

		if (k2 == 1)
		{

			ehp2 = ehp2_max;



			k2 = 0;
			SetMode(GAME_MODE);

		}

		else if (k2 == 2)//gameover��
		{
			k2 = 0;
			printf("[�V�[�t]\n");
			printf("\n�u.....�v\n");

			// �L�[���͑҂�
			rewind(stdin);
			_getch();
			// ��ʃN���A
			system("cls");

			printf("GAME OVER\n");

			// �L�[���͑҂�
			rewind(stdin);
			_getch();
			// ��ʃN���A
			system("cls");

			player->hp = player->hp_max = 100;
			player->mp = player->mp_max = 100;


			SetMode(GAME_RESULT);
		}
}

	/*******************************************************************************/




void DrawBattle2(void)
{

}



	void kougeki2(void)
	{
		PLAYER* player = GetPlayer();


		printf("[�V�[�t]\n");
		printf("\n�u�����΂�I�v\n");


		edmg2 = (rand() % (player->atk / 2)) + (player->atk / 2) / (edef2 / 2);	// eatk�����Ƀ����_���Ń_���[�W������




		ehp2 = ehp2 - edmg2;





		printf("���R�m�� %d �_���[�W�I\n\n",edmg2);

		if (ehp2 <= 0)
		{
			k2 = 1;

			printf("���R�m�͗͐s�����I\n");

			

			// �L�[���͑҂�
			rewind(stdin);
			_getch();
			// ��ʃN���A
			system("cls");

			printf("200g��ɓ��ꂽ�I\n");

			player->gold = player->gold + 200;

			// �L�[���͑҂�
			rewind(stdin);
			_getch();
			// ��ʃN���A
			system("cls");

		}




		// �L�[���͑҂�
		rewind(stdin);
		_getch();


		// ��ʃN���A
		system("cls");

	}


	void tousou2(void)
	{

		printf("[�V�[�t]\n");




		printf("�u�����͓����Ȃ��ẮI�v\n");


		// �L�[���͑҂�
		rewind(stdin);
		_getch();


		// ��ʃN���A
		system("cls");

		data2 = rand() % 100;


		if (data2 < 85)
		{
			k2 = 1;
	
			printf("[�V�[�t]\n");
			printf("�u�����I�I�v\n");



			// �L�[���͑҂�
			rewind(stdin);
			_getch();


		}


		else {

			printf("[�V�[�t]\n");
			printf("�u�����I�����錄���Ȃ��I�v\n");
		}





		// �L�[���͑҂�
		rewind(stdin);
		_getch();


		// ��ʃN���A
		system("cls");

	}







void steal2(void)
{

	printf("[�V�[�t]\n");
	printf("\n�u��������I�H�v\n");


	// �L�[���͑҂�
	rewind(stdin);
	_getch();


	// ��ʃN���A
	system("cls");

	data2 = rand() % 100;




	if (data2 < dex2)
	{
		PLAYER* player = GetPlayer();

		printf("[�V�[�t]\n");
		printf("�u��股�I�����I�I�v\n");

		// �L�[���͑҂�
		rewind(stdin);
		_getch();


		// ��ʃN���A
		system("cls");
		printf("���؊Z�𓐂񂾁I\n");

		// �L�[���͑҂�
		rewind(stdin);
		_getch();


		// ��ʃN���A
		system("cls");

		printf("[�V�[�t]\n");
		printf("�u�����350g���ĂƂ����ȁH�v\n");

		player->gold = player->gold + 350;

		// �L�[���͑҂�
		rewind(stdin);
		_getch();



		if (player->boe == 0)//�������Ȃ��Ƃ��A��������
		{
			player->boe = 1;//1�̎��A�������

			player->def_max = player->def_max + 3;
			player->def = player->def_max;


			printf("[�V�[�t]\n");
			printf("�u���傤�ǊZ�̗ނ��~�����Ǝv���Ă��񂾁v\n");
			// �L�[���͑҂�
			rewind(stdin);
			_getch();
			printf("�u��������܂ł̊Ԃ͂����𒅂邩�I�v\n");

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			printf("���؊Z�������т����I\n");


		}


	}

	else
	{
		printf("�~�X�I�I\n");

		printf("[�V�[�t]\n");
		printf("�u�������́I�I�v\n");
	}



	// �L�[���͑҂�
	rewind(stdin);
	_getch();


	// ��ʃN���A
	system("cls");


}



void kaihuku2(void)
{

	PLAYER* player = GetPlayer();

	if (player->mp >= 4)
	{
		if (player->hp_max == player->hp)
		{
			player->mp = player->mp - 4;
			printf("�����������N����Ȃ�����\n\n");
			printf("[�V�[�t]\n");
			printf("�u���܂����I���C�����ς��Ȃ̂ɉ񕜂��Ă��܂����I�v\n");

		

		}

		else if (player->hp_max < curp2 + player->hp)
		{
			player->mp = player->mp - 4;

			player->hp = player->hp_max;


			printf("�g�o���S���ɂȂ����I\n");
			printf("�g�o�c��%d\n\n", player->hp);
			printf("[�V�[�t]\n");
			printf("�u���C�����ς����I�v\n");


			// �L�[���͑҂�
			rewind(stdin);
			_getch();


			// ��ʃN���A
			system("cls");

		

		}
		else
		{
			player->mp = player->mp - 4;

			player->hp = curp2 + player->hp;


		}


		printf("�g�o�c��%d\n\n", player->hp);

		if (player->hp < 30)

		{
			printf("[�V�[�t]\n");
			printf("�u�����l���߂���...�v");

			
		}

		else if (player->hp < 60)
		{
			printf("[�V�[�t]\n");
			printf("�u�l���Ă΁A������҂�h������...�v");

			
		}


		else if (player->hp < 200)
		{
			printf("[�V�[�t]\n");
			printf("�u�l���Ă΁A�܂��܂����C������ˁI�v");

		
		}









		else //player->mp�����Ȃ�
		{
			printf("�������l�o������Ȃ������I\n\n");
			printf("[�V�[�t]\n");
			printf("�u�����I...�����������g�������̗͂�...�v\n");

			
		}

	}

	// �L�[���͑҂�
	rewind(stdin);
	_getch();


	// ��ʃN���A
	system("cls");



}



void dexupm2(void)
{
	PLAYER* player = GetPlayer();

	if (player->mp >= 4)
	{
		player->mp = player->mp - 4;

		dex2 = dexup2 + 5;

		printf("��p����5�㏸�I\n");

		printf("��p����%d�ɂȂ����I\n\n", dex2);
		printf("[�V�[�t]\n");
		printf("�u���낻�듐�߂邩...�H�v\n");


	}


	else

	{
		printf("�������l�o������Ȃ������I\n\n");
		printf("[�V�[�t]\n");
		printf("�u�����I...�����������g�������̗͂�...�v\n");

		// �L�[���͑҂�
		rewind(stdin);
		_getch();


		// ��ʃN���A


		system("cls");



	}

}



