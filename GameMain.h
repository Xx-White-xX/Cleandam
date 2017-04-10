//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.h
//!
//! @brief  ゲーム関連のヘッダファイル
//!
//! @date   日付
//!
//! @author 制作者名
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once

#include <Windows.h>
#include <d3d11.h>
#include <SimpleMath.h>
#include <iostream>
#include <string>
#include "../DirectXTK.h"
#include "Texture.h"
#include "GameBase.h"

#ifndef _GAMEMAIN_
#define EXTERN extern
#else
#define EXTERN
#endif



// 定数の定義 ==============================================================

// ゲームタイトル
#define GAME_TITLE "thousand"

// ゲーム画面
#define SCREEN_WIDTH  640    // 幅[pixel]
#define SCREEN_HEIGHT 480    // 高さ[pixel]

					//　列挙型宣言
enum SCENE
{
	LOGO,
	TITLE,
	PLAY,
	CLEAR,
	OVER
};

// グローバル変数の宣言 ====================================================
EXTERN Texture* g_enemy;

EXTERN int g_init;				//初期化管理


class GameMain
{
protected:

	GameBase* m_base;	//ゲームベース

	int m_nextScene;	//次のシーン
	int m_scene;		//今のシーン

	int m_key_code;			//キー情報
	int m_key_old;			//前フレームのキー情報

public:
	GameMain();
	~GameMain();
	// 関数の宣言 ==============================================================
	// ゲームの初期化
	void InitializeGame(void);

	// ゲームの更新
	bool UpdateGame(void);

	// ゲームの描画
	void RenderGame(void);

	// ゲームの終了
	void FinalizeGame(void);
};