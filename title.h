/*******************************************************************************
* タイトル:		タイトルヘッダー
* プログラム名:	title.h
* 作成者:		GP11A132 25 松本　賢治
* 作成日:		2022/07/07
*******************************************************************************/

#pragma once	// インクルードガード（多重インクルード防止）

/*******************************************************************************
* インクルードファイル
*******************************************************************************/


/*******************************************************************************
* マクロ定義
*******************************************************************************/
#define		ANIM_CNT	(4)		// タイトルアニメーションの数


/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void InitTitle(void);
void UninitTitle(void);
void UpdateTitle(void);
void DrawTitle(void);




