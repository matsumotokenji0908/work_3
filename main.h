/*******************************************************************************
* タイトル:		メインヘッダー
* プログラム名:	main.h
* 作成者:		GP11A132 25 松本　賢治
* 作成日:		2022/07/07
*******************************************************************************/

#pragma once	// インクルードガード（多重インクルード防止）

/*******************************************************************************
* scanf のwarning防止
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <math.h>

/*******************************************************************************
* マクロ定義
*******************************************************************************/

enum {
	GAME_TITLE,

	GAME_TUTORIAL,

	GAME_MODE,
	GAME_SHOP,
	GAME_BATTLE1,
	GAME_BATTLE2,
	GAME_PLAYER,
	GAME_RESULT,
	GAME_END,
};


#define		DISP_H		(24)	// 表示画面の縦サイズ
#define		DISP_W		(80)	// 表示画面の横サイズ

/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void Init(void);
void Uninit(void);
void Update(void);
void Draw(void);

int  GetMode(void);
void SetMode(int mode);




