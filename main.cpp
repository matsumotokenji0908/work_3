/*******************************************************************************
* タイトル:		メインプログラム
* プログラム名:	main.cpp
* 作成者:		GP11A132 25 松本　賢治
* 作成日:		2022/07/07
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
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

int g_Mode = GAME_TITLE;		// 現在動作している状態（ゲームモード）
BOOL g_LoadGame =0;					// NewGame


/*******************************************************************************
 関数名:	int main( void )
 引数:		void
 戻り値:	正常終了: int型の 0
 説明:		メイン関数
*******************************************************************************/
int main(void)
{

	Init();			// ゲーム全体の初期化処理

	// ゲームモードが終了じゃない間、永久に繰り返す
	while (GetMode() < GAME_END)
	{
		Update();	// ゲーム全体の更新処理

		Draw();		// ゲーム全体の描画処理
	}

	Uninit();		// ゲーム全体の終了処理

	return 0;
}



// ゲーム全体の初期化処理
void Init(void)
{
	// ランダムの初期化処理
	srand((unsigned)time(NULL));

	// タイトルの初期化処理
	InitTitle();

	InitTutorial();

	InitField();
	InitPlayer();
	InitEnemy();
	InitShop();
	InitBattle1();
	InitBattle2();

	InitResult();

	printf("\nセーブデータをロードしますか？");
	printf("\nYES→xキー");


	// キー入力処理
	int key = _getch();
	if ((key == 0) || (key == 224))	// 特殊Keyならもう１度取得する
	{
		key = _getch();
	}

	// キー入力待ち
	rewind(stdin);
	_getch();

	switch (key)
	{
	case 'x':
		g_LoadGame = TRUE;
	}
		// ロードゲームだったらすべての初期化が終わった後にセーブデータを読み込む
		if (g_LoadGame == TRUE)
		{
			LoadData();
			g_LoadGame = FALSE;		// ロードしたからフラグをClearする

		}
	
}


// ゲーム全体の終了処理
void Uninit(void)
{
	// キー入力待ち
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


// ゲーム全体の更新処理
void Update(void)
{
	// 現在のモードによって処理分けをする
	switch ( GetMode() )
	{
	case GAME_TITLE:
		UpdateTitle();
		break;

	// 本来はここへ他のゲームモードを追加する
	// 例えば、フィールドとかバトルとか、エンディングとか、、、

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


// ゲーム全体の描画処理
void Draw(void)
{
	// 現在のモードによって処理分けをする
	switch (GetMode())
	{
	case GAME_TITLE:
		DrawTitle();
		break;

	// 本来はここへ他のゲームモードを追加する
	// 例えば、フィールドとかバトルとか、エンディングとか、、、

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


// 現在のゲームモードを取得する
int GetMode(void)
{
	return g_Mode;
}


// ゲームモードを変更する
void SetMode(int mode)
{
	g_Mode = mode;
}

