/*******************************************************************************
* タイトル:		タイトルプログラム
* プログラム名:	title.cpp
* 作成者:		GP11A132 25 松本　賢治
* 作成日:		2022/07/07
*******************************************************************************/

/*******************************************************************************
* scanf のwarning防止
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
#include "title.h"
#include "battle1.h"
#include "battle2.h"

/*******************************************************************************
* マクロ定義
*******************************************************************************/


/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言(関数の説明書)
*******************************************************************************/



/*******************************************************************************
* グローバル変数
*******************************************************************************/

int g_TitleLoopCount;			// タイトルの描画を繰り返す為のカウンター

// 縦24行分、横80文字分を4画面分
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
	"     1 チュートリアル                                                         \n",
	"                                                                              \n",
	"     2 ゲーム                                                                 \n",
	"                                                                              \n",
};



// タイトルの初期化処理
void InitTitle(void)
{



	//int game_select = 0;
	//int sel = 0;
	//

	//g_TitleLoopCount = 0;




	///* 画面描画処理 */
	//for (int y = 0; y < DISP_H * ANIM_CNT; y++)
	//{
	//	/* 1画面分表示したら少しウェイトさせる */
	//	if (y % DISP_H == 0)
	//	{
	//		/* ウェイト */
	//		Sleep(500);

	//		/* 画面クリア */
	//		system("cls");
	//	}

	//	///* 1文字ずつ描画する */
	//	//for (int x = 0; x < DISP_W; x++)
	//	//{
	//	//	// ここに1文字ずつ表示するプログラムを書く
	//	//	printf("%c", title[y][x]);
	//	//}

	//	// １文字ずつだと遅いから１行ずつ表示させる
	//	printf("%s", &title[y][0]);



	//}










	//	printf("1 チュートリアル\n");
	//	printf("2 ゲーム\n");


	//	//// キー入力待ち
	//	//rewind(stdin);
	//	//_getch();


	//	scanf("%d", &game_select);

	//	



	//	switch (game_select)
	//	{

	//		do {


	//			sel = 0;


	//	case 1:



	//		SetMode(GAME_TUTORIAL);		// ２回やったら終了させる。本当はここで次のゲームモードへ移行する

	//		break;

	//	case 2:



	//		SetMode(GAME_MODE);		// ２回やったら終了させる。本当はここで次のゲームモードへ移行する

	//		break;


	//	default:


	//		sel = 1;



	//		break;


	//		} while (sel > 0);//ゲーム選択コマンドのループ　普段は偽　defaultの時のみ真をとる







	//	}






}


// タイトルの終了処理
void UninitTitle(void)
{

}


// タイトルの更新処理
void UpdateTitle(void)
{




	//int game_select = 0;
	//int sel = 0;


	////// テストでルパン３世を２回繰り返してみる
	//g_TitleLoopCount++;
	//if (g_TitleLoopCount > 1)
	//{




	//	printf("1 チュートリアル\n");
	//	printf("2 ゲーム\n");


	//	//// キー入力待ち
	//	//rewind(stdin);
	//	//_getch();


	//	scanf("%d", &game_select);




	//	switch (game_select)
	//	{

	//		do {


	//			sel = 0;


	//	case 1:



	//		SetMode(GAME_TUTORIAL);		// ２回やったら終了させる。本当はここで次のゲームモードへ移行する

	//		break;

	//	case 2:



	//		SetMode(GAME_MODE);		// ２回やったら終了させる。本当はここで次のゲームモードへ移行する

	//		break;


	//	default:


	//		sel = 1;



	//		break;


	//		} while (sel > 0);//ゲーム選択コマンドのループ　普段は偽　defaultの時のみ真をとる



	//	}

	//}

	//

}


// タイトル画面処理
void DrawTitle(void)
{
	/* 画面描画処理 */
	for (int y = 0; y < DISP_H * ANIM_CNT; y++)
	{
		/* 1画面分表示したら少しウェイトさせる */
		if (y % DISP_H == 0)
		{
			/* ウェイト */
			Sleep(500);

			/* 画面クリア */
			system("cls");
		}

		///* 1文字ずつ描画する */
		//for (int x = 0; x < DISP_W; x++)
		//{
		//	// ここに1文字ずつ表示するプログラムを書く
		//	printf("%c", title[y][x]);
		//}

		// １文字ずつだと遅いから１行ずつ表示させる
		printf("%s", &title[y][0]);



	}







	int game_select = 0;
	int sel = 0;


	//// テストでルパン３世を２回繰り返してみる
	g_TitleLoopCount++;
	if (g_TitleLoopCount > 0)
	{


		game_select = 0;
		sel = 0;

		//printf("1 チュートリアル\n");
		//printf("2 ゲーム\n");



		scanf("%d", &game_select);






		switch (game_select)
		{

			do {


				sel = 0;


		case 1:



			SetMode(GAME_TUTORIAL);		// ２回やったら終了させる。本当はここで次のゲームモードへ移行する

			break;

		case 2:



			SetMode(GAME_MODE);		// ２回やったら終了させる。本当はここで次のゲームモードへ移行する

			break;


		default:


			sel = 1;



			break;


			} while (sel > 0);//ゲーム選択コマンドのループ　普段は偽　defaultの時のみ真をとる



		}

	}



}



