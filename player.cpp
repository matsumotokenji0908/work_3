/*******************************************************************************
* タイトル:		プレイヤープログラム
* プログラム名:	player.cpp
* 作成者:		GP11A132 25 松本　賢治
* 作成日:		2022/07/07
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
#include "player.h"
#include "field.h"
#include "battle1.h"
#include "battle2.h"
#include "file.h"

/*******************************************************************************
* マクロ定義
*******************************************************************************/


/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言(こんな関数を用意してありますよ宣言/関数の説明書)
*******************************************************************************/



/*******************************************************************************
* グローバル変数
*******************************************************************************/
PLAYER g_Player;	// PLAYER型でプレイヤー１体分

// プレイヤーの初期化処理
void InitPlayer(void)
{


	// 構造体の初期化
	g_Player.y = 2;		//Player構造体の中のyに2を入れている
	g_Player.x = 2;		//この.（ドット）のことをドット演算子という 意　～の中の
						//構造体の中の変数（xやy等）のことをメンバー変数という

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


// プレイヤーの終了処理
void UninitPlayer(void)
{

}


// プレイヤーの更新処理
void UpdatePlayer(void)
{

	PLAYER* player = GetPlayer();


	// 動く前の座標を保存しておく（移動してぶつかった時はこの座標へ戻す為）
	g_Player.old_x = g_Player.x;
	g_Player.old_y = g_Player.y;

	// キー入力処理
	int key = _getch();
	if ((key == 0) || (key == 224))	// 特殊Keyならもう１度取得する
	{
		key = _getch();
	}

		// 現状をセーブする
	switch (key)
	{
	case 'x':
		SaveData();
		break;
	}


	// 押されたkeyの方向へ移動させる
	switch (key)
	{

	case 'a':
	case 0x4b:	// ←
		g_Player.x--;

		break;

	case 'd':
	case 0x4d:	// →
		g_Player.x++;
		break;

	case 'w':
	case 0x48:	// ↑
		g_Player.y--;
		break;

	case 's':
	case 0x50:	// ↓
		g_Player.y++;
		break;

	default:
		break;
	}




	// MAPとの当たり判定処理
	// 移動した先はNGな場所？
	int answer = CheckField(g_Player.y, g_Player.x);
	switch(answer)
	{
	case 1:	// 移動してはNGな場所だったので前の場所へ戻す
		g_Player.y = g_Player.old_y;
		g_Player.x = g_Player.old_x;
		break;

	case 2:
		if (g_Player.trb == true && g_Player.flg1 == true)
		{

			printf("しかし宝箱は空だった\n");

			/* 処理速度調整 */
			Sleep(1000);
		}

		if (g_Player.trb == false && g_Player.flg1 == true)
		{
			player->gold = player->gold + 250;

			printf("250g手に入れた！\n");

			g_Player.trb = true;

			/* 処理速度調整 */
			Sleep(30);
		}
		break;

	case 3:
		if (g_Player.flg2 == false)
		{

		g_Player.stps = 0;
		SetMode(GAME_SHOP);
		/* 処理速度調整 */
		Sleep(30);
		}

		break;
	default:

		break;
	}

	g_Player.flg1 = true;
}


// プレイヤーの描画処理
void DrawPlayer(void)
{
	PLAYER* player = GetPlayer();



	// プレイヤーをMAPの指定座標へ書き込む
	SetField(g_Player.y, g_Player.x, 'P');







	int answer = CheckField(g_Player.y, g_Player.x);

	if (answer==3)
	{


		player->gold = player->gold + 250;

		printf("250g手に入れた！\n");



	}







	Sleep(30);//

	g_Player.stps++;

	if (g_Player.stps>5)
	{



		// ランダムの初期化処理
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


// プレイヤーのアドレスを返す
PLAYER *GetPlayer(void)
{
	return &g_Player;
}


