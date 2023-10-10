/*******************************************************************************
* タイトル:		バトル1プログラム
* プログラム名:	battle1.cpp
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
* マクロ定義
*******************************************************************************/


/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言(こんな関数を用意してありますよ宣言/関数の説明書)
*******************************************************************************/
void kougeki(void);
void tousou(void);
void steal(void);
void kaihuku(void);
void dexupm(void);


/*******************************************************************************
* グローバル変数
*******************************************************************************/
	int data=0;
	int dexup = 5;
	int curp = 50;
	int dex = 30;
	int ehp = 170;
	int ehp_max = 170;

	int eatk = 30;			// 攻撃力
	int edmg = 0;
	int edef = 10;
	int k = 0;//逃走時,勝利時に1 全滅時に2をとる

void InitBattle1(void)
{
}

void UninitBattle1(void)
{
}

void UpdateBattle1(void)
{


	PLAYER* player = GetPlayer();


	int hensuu = 0;
	int damage = 0;			// ダメージ値
	int firetaisei = 0;
	int eatkp = 0;
	int hensuu2 = 0;
	int mpm = 5;
	int i = 0;
	int j = 0;


	i = 0;
	j = 0;
	k = 0;

	system("cls");



	printf("人工鉱物生命体");
	printf("が現れた！\n");

		Sleep(1000);


		while (k == 0)
		{



			// キー入力待ち
			rewind(stdin);
			_getch();


			// 画面クリア
			system("cls");


			do {


				printf("コマンド？\n");
				printf("ＨＰ %d\n\n", player->hp);
				printf("ＭＰ %d\n\n", player->mp);
				printf("1 たたかう　2 にげる　3 盗む　4 魔導\n");


				scanf("%d", &hensuu);

				// 画面クリア
				system("cls");


				switch (hensuu)
				{
					hensuu = 0;
				case 1:

					kougeki();
					i = 0;
					break;

				case 2:
					tousou();
					i = 0;
					break;

				case 3:

					steal();
					i = 0;
					break;



				case 4:

					do {

						printf("コマンド？\n");
						printf("ＨＰ %d\n\n", player->hp);
						printf("ＭＰ %d\n\n", player->mp);
						printf("1 戻る　2 初級回復魔導 3 初級器用さ上昇魔導\n");

						scanf("%d", &hensuu2);

						// 画面クリア
						system("cls");

						switch (hensuu2) //魔導のコマンド選択
						{
							hensuu2 = 0;
						case 1:

							i = 1;
							j = 0;
							break;


						case 2: //回復魔導を使った場合

							kaihuku();

							i = 0;
							j = 0;

							break;
						case 3:
							dexupm();
							i = 0;
							j = 0;



							break;


						default:
							i = 0;
							j = 1;



							break;

						}

					} while (j > 0);//魔導コマンドのループ　普段は偽　defaultの時のみ真をとる
					j = 0;
					break;	//case4終了



				default:
					i = 1;

					break;
				}	//switch終了
			} while (i > 0);//戦闘コマンドのループ　普段は偽　default,戻るコマンドを選択した時のみ真をとる

			i = 0;


			if (k == 0)
			{

				srand((unsigned)time(NULL));

				printf("人工鉱物生命体の攻撃！\n\n");

				//人工鉱物生命体の攻撃処理


				// キー入力待ち
				rewind(stdin);

				_getch();


				//人工鉱物生命体の攻撃パターン
				eatkp = rand() % 5;

				if (eatkp > 1)
				{
					// ダメージ計算
					damage = (rand() % (eatk / 2)) + (eatk / 2) / (player->def / 2);	// eatkを元にランダムでダメージを決定

				}
				else
				{

					printf("巨刃による斬りつけ！！\n");

					// キー入力待ち
					rewind(stdin);
					_getch();


					// 画面クリア
					system("cls");

					printf("[シーフ]\n");
					printf("「ぐはぁっ！！」\n");

					damage = 30;
				}



				printf("シーフは%dのダメージを受けた！\n", damage);

				//残りHP表示処理
				player->hp = player->hp - damage;		// HPの計算処理



			// キー入力待ち
				rewind(stdin);
				_getch();

				if (player->hp <= 0)
				{
					k = 2;

					printf("シーフは力尽きてしまった！\n");
					// キー入力待ち
					rewind(stdin);
					_getch();




					//printf("キー入力で強制終了します。お疲れさまでした。\n");
					//// キー入力待ち
					//rewind(stdin);
					//_getch();
					//exit(-1);		//プログラム強制終了
				}


				else
				{

					printf("ＨＰ残り%d\n\n", player->hp);

					if (player->hp < 30)

					{
						printf("[シーフ]\n");
						printf("「もう僕だめそう...」");
					}

					else if (player->hp < 60)
					{
						printf("[シーフ]\n");
						printf("「僕ってば、ちょっぴり辛いかも...」");

					}


					else if (player->hp < 200)
					{
						printf("[シーフ]\n");
						printf("「僕ってば、まだまだ元気だもんね！」");
					}


					// キー入力待ち
					rewind(stdin);
					_getch();


				}
			}
		}

		if(k==1)//逃走,勝利時
		{
			ehp = ehp_max;
			

			k = 0;
			SetMode(GAME_MODE);

		}

		else if (k == 2)//gameover時
		{
			k = 0;
			printf("[シーフ]\n");
			printf("\n「.....」\n");

			// キー入力待ち
			rewind(stdin);
			_getch();
			// 画面クリア
			system("cls");

			printf("GAME OVER\n");

			// キー入力待ち
			rewind(stdin);
			_getch();
			// 画面クリア
			system("cls");

			player->hp = player->hp_max = 100;
			player->mp = player->mp_max = 100;


			SetMode(GAME_RESULT);
		}
}

	/*******************************************************************************/




void DrawBattle1(void)
{

}



	void kougeki(void)
	{
		PLAYER* player = GetPlayer();

		printf("[シーフ]\n");
		printf("\n「くたばれ！」\n");

		edmg = (rand() % (player->atk / 2)) + (player->atk / 2) / (edef / 2);	// eatkを元にランダムでダメージを決定




		ehp = ehp - edmg;


		printf("人工鉱物生命体に %d ダメージ！\n\n",edmg);

		if (ehp <= 0)
		{
			k = 1;

			printf("人工鉱物生命体は力尽きた！\n");

			// キー入力待ち
			rewind(stdin);
			_getch();
			// 画面クリア
			system("cls");

			printf("250g手に入れた！\n");

			player->gold = player->gold + 250;

			// キー入力待ち
			rewind(stdin);
			_getch();
			// 画面クリア
			system("cls");


		}




		// キー入力待ち
		rewind(stdin);
		_getch();


		// 画面クリア
		system("cls");

	}


	void tousou(void)
	{

		printf("[シーフ]\n");


		printf("「ここは逃げなくては！」\n");


		// キー入力待ち
		rewind(stdin);
		_getch();


		// 画面クリア
		system("cls");

		data = rand() % 100;


		if (data < 85)
		{
			k = 1;
			printf("[シーフ]\n");
			printf("「成功！！」\n");



			// キー入力待ち
			rewind(stdin);
			_getch();


		}


		else {

			printf("[シーフ]\n");
			printf("「くっ！逃げる隙がない！」\n");
		}





		// キー入力待ち
		rewind(stdin);
		_getch();


		// 画面クリア
		system("cls");

	}







void steal(void)
{

	printf("[シーフ]\n");
	printf("\n「やったか！？」\n");


	// キー入力待ち
	rewind(stdin);
	_getch();


	// 画面クリア
	system("cls");

	data = rand() % 100;




	if (data < dex)
	{
		PLAYER* player = GetPlayer();

		printf("[シーフ]\n");
		printf("「やりぃ！成功！！」\n");

		// キー入力待ち
		rewind(stdin);
		_getch();


		// 画面クリア
		system("cls");
		printf("古代魔学の大剣を盗んだ！\n");

		// キー入力待ち
		rewind(stdin);
		_getch();


		// 画面クリア
		system("cls");

		printf("[シーフ]\n");
		printf("「相場は300gってとこかな？」\n");

		player->gold = player->gold + 300;

		// キー入力待ち
		rewind(stdin);
		_getch();



		if (player->hae==0)//装備がないとき、装備する
		{
			player->hae = 1;//1の時、装備状態

			player->atk_max = player->atk_max + 20;
			player->atk = player->atk_max;

			printf("[シーフ]\n");
			printf("「ちょうど武器が欲しいと思ってたんだ」\n");
			// キー入力待ち
			rewind(stdin);
			_getch();
			printf("「換金するまでの間はこいつを使うか！」\n");

			// キー入力待ち
			rewind(stdin);
			_getch();

			printf("古代魔学の大剣をそうびした！\n");


		}





	}

	else
	{
		printf("ミス！！\n");

		printf("[シーフ]\n");
		printf("「次こそは！！」\n");
	}



	// キー入力待ち
	rewind(stdin);
	_getch();


	// 画面クリア
	system("cls");


}



void kaihuku(void)
{

	PLAYER* player = GetPlayer();

	if (player->mp >= 4)
	{
		if (player->hp_max == player->hp)
		{
			player->mp = player->mp - 4;
			printf("しかし何も起こらなかった\n\n");
			printf("[シーフ]\n");
			printf("「しまった！元気いっぱいなのに回復してしまった！」\n");

		

		}

		else if (player->hp_max < curp + player->hp)
		{
			player->mp = player->mp - 4;

			player->hp = player->hp_max;


			printf("ＨＰが全快になった！\n");
			printf("ＨＰ残り%d\n\n", player->hp);
			printf("[シーフ]\n");
			printf("「元気いっぱいだ！」\n");


			// キー入力待ち
			rewind(stdin);
			_getch();


			// 画面クリア
			system("cls");

		

		}
		else
		{
			player->mp = player->mp - 4;

			player->hp = curp + player->hp;


		}


		printf("ＨＰ残り%d\n\n", player->hp);

		if (player->hp < 30)

		{
			printf("[シーフ]\n");
			printf("「もう僕だめそう...」");

			
		}

		else if (player->hp < 60)
		{
			printf("[シーフ]\n");
			printf("「僕ってば、ちょっぴり辛いかも...」");

			
		}


		else if (player->hp < 200)
		{
			printf("[シーフ]\n");
			printf("「僕ってば、まだまだ元気だもんね！」");

		
		}









		else //player->mpが少ない
		{
			printf("しかしＭＰが足りなかった！\n\n");
			printf("[シーフ]\n");
			printf("「くっ！...もう魔導を使うだけの力が...」\n");

			
		}

	}

	// キー入力待ち
	rewind(stdin);
	_getch();


	// 画面クリア
	system("cls");



}



void dexupm(void)
{
	PLAYER* player = GetPlayer();

	if (player->mp >= 4)
	{
		player->mp = player->mp - 4;

		dex = dexup + 5;

		printf("器用さが5上昇！\n");

		printf("器用さが%dになった！\n\n", dex);
		printf("[シーフ]\n");
		printf("「そろそろ盗めるか...？」\n");


	}


	else

	{
		printf("しかしＭＰが足りなかった！\n\n");
		printf("[シーフ]\n");
		printf("「くっ！...もう魔導を使うだけの力が...」\n");

		// キー入力待ち
		rewind(stdin);
		_getch();


		// 画面クリア


		system("cls");



	}

}



