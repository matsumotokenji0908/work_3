/*******************************************************************************
* �^�C�g��:		�v���C���[�v���O����
* �v���O������:	player.cpp
* �쐬��:		GP11A132 25 ���{�@����
* �쐬��:		2022/07/07
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "player.h"
#include "field.h"
#include "battle1.h"
#include "battle2.h"
#include "file.h"

/*******************************************************************************
* �}�N����`
*******************************************************************************/


/*******************************************************************************
* �\���̒�`
*******************************************************************************/


/*******************************************************************************
* �v���g�^�C�v�錾(����Ȋ֐���p�ӂ��Ă���܂���錾/�֐��̐�����)
*******************************************************************************/



/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/
PLAYER g_Player;	// PLAYER�^�Ńv���C���[�P�̕�

// �v���C���[�̏���������
void InitPlayer(void)
{


	// �\���̂̏�����
	g_Player.y = 2;		//Player�\���̂̒���y��2�����Ă���
	g_Player.x = 2;		//����.�i�h�b�g�j�̂��Ƃ��h�b�g���Z�q�Ƃ��� �Ӂ@�`�̒���
						//�\���̂̒��̕ϐ��ix��y���j�̂��Ƃ������o�[�ϐ��Ƃ���

	g_Player.hp  = g_Player.hp_max  = 100;
	g_Player.mp = g_Player.mp_max = 100;
	g_Player.atk = g_Player.atk_max =  80;
	g_Player.def = g_Player.def_max = 5;



	g_Player.gold = 0;
	g_Player.stps = 0;

	g_Player.hae = 0;
	g_Player.boe = 0;

	g_Player.trb = false;
	g_Player.flg1 = false;
	g_Player.flg2 = false;
}


// �v���C���[�̏I������
void UninitPlayer(void)
{

}


// �v���C���[�̍X�V����
void UpdatePlayer(void)
{

	PLAYER* player = GetPlayer();


	// �����O�̍��W��ۑ����Ă����i�ړ����ĂԂ��������͂��̍��W�֖߂��ׁj
	g_Player.old_x = g_Player.x;
	g_Player.old_y = g_Player.y;

	// �L�[���͏���
	int key = _getch();
	if ((key == 0) || (key == 224))	// ����Key�Ȃ�����P�x�擾����
	{
		key = _getch();
	}

		// ������Z�[�u����
	switch (key)
	{
	case 'x':
		SaveData();
		break;
	}


	// �����ꂽkey�̕����ֈړ�������
	switch (key)
	{

	case 'a':
	case 0x4b:	// ��
		g_Player.x--;

		break;

	case 'd':
	case 0x4d:	// ��
		g_Player.x++;
		break;

	case 'w':
	case 0x48:	// ��
		g_Player.y--;
		break;

	case 's':
	case 0x50:	// ��
		g_Player.y++;
		break;

	default:
		break;
	}




	// MAP�Ƃ̓����蔻�菈��
	// �ړ��������NG�ȏꏊ�H
	int answer = CheckField(g_Player.y, g_Player.x);
	switch(answer)
	{
	case 1:	// �ړ����Ă�NG�ȏꏊ�������̂őO�̏ꏊ�֖߂�
		g_Player.y = g_Player.old_y;
		g_Player.x = g_Player.old_x;
		break;

	case 2:
		if (g_Player.trb == true && g_Player.flg1 == true)
		{

			printf("�������󔠂͋󂾂���\n");

			/* �������x���� */
			Sleep(1000);
		}

		if (g_Player.trb == false && g_Player.flg1 == true)
		{
			player->gold = player->gold + 250;

			printf("250g��ɓ��ꂽ�I\n");

			g_Player.trb = true;

			/* �������x���� */
			Sleep(30);
		}
		break;

	case 3:
		if (g_Player.flg2 == false)
		{

		g_Player.stps = 0;
		SetMode(GAME_SHOP);
		/* �������x���� */
		Sleep(30);
		}

		break;
	default:

		break;
	}

	g_Player.flg1 = true;
}


// �v���C���[�̕`�揈��
void DrawPlayer(void)
{
	PLAYER* player = GetPlayer();



	// �v���C���[��MAP�̎w����W�֏�������
	SetField(g_Player.y, g_Player.x, 'P');







	int answer = CheckField(g_Player.y, g_Player.x);

	if (answer==3)
	{


		player->gold = player->gold + 250;

		printf("250g��ɓ��ꂽ�I\n");



	}







	Sleep(30);//

	g_Player.stps++;

	if (g_Player.stps>5)
	{



		// �����_���̏���������
		srand((unsigned)time(NULL));

		g_Player.enc = 0;

		g_Player.enc = rand() % 100;

		if (g_Player.enc < 30)
		{

			g_Player.stps = 0;

			SetMode(GAME_BATTLE1);



		}

		else if (g_Player.enc < 60)
		{
			g_Player.stps = 0;
			SetMode(GAME_BATTLE2);

		}


	}
	player->flg2 = false;




}


// �v���C���[�̃A�h���X��Ԃ�
PLAYER *GetPlayer(void)
{
	return &g_Player;
}


