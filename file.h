//=============================================================================
//
// �t�@�C������ [file.h]
// Author : GP11A132 25 ���{�@����
//
//=============================================================================
#pragma once

#include "main.h"
#include "player.h"
#include "enemy.h"

/*******************************************************************************
* �}�N����`
*******************************************************************************/



/*******************************************************************************
* �\���̒�`
*******************************************************************************/
struct	SAVEDATA				// �Z�[�u�f�[�^�̍\����
{
	// �v���C���[�f�[�^��ۑ�
	PLAYER	player[1];	// �v���C���[��MAX�l�����Z�[�u����

	// �G�l�~�[�f�[�^��ۑ�
	//ENEMY	enemy[MAX_ENEMY];	// �G�l�~�[��MAX�l�����Z�[�u����

	// �X�R�A�f�[�^��ۑ�
	int		score;				// �X�R�A��ۑ�����

	// ���ɂ������Z�[�u��������������΂����ɒǉ�

	int		sum;				// �`�F�b�N�T��������
};



/*******************************************************************************
* �v���g�^�C�v�錾
*******************************************************************************/
void SaveData(void);
void LoadData(void);

