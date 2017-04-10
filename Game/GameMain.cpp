//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  ゲーム関連のソースファイル
//!
//! @date   日付		
//!
//! @author 制作者名	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#define _GAMEMAIN_
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "GameMain.h"

#include "GameClear.h"
#include "GameLogo.h"
#include "GameOver.h"
#include "GamePlay.h"
#include "GameTitle.h"
#include "GameBase.h"
using namespace std;


#pragma comment(lib, "cri_ware_pcx86_LE_import.lib")

using namespace DirectX::SimpleMath;
using namespace DirectX;

// 関数の定義 ==============================================================

GameMain::GameMain()
	:m_scene(0)
	, m_nextScene(0)
{

}

GameMain::~GameMain()
{
	delete m_base;
}

//----------------------------------------------------------------------
//! @brief ゲームの初期化処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GameMain::InitializeGame(void)
{
	srand(static_cast<unsigned int>(time(nullptr)));

	m_base = new GamePlay();

	//m_scene = LOGO;
}



//----------------------------------------------------------------------
//! @brief ゲームの更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
bool GameMain::UpdateGame(void)
{
	//ADX2Le::Update();

	//シーン管理
	if (m_nextScene != m_scene)
	{
		m_scene = m_nextScene;

		delete m_base;

		//シーンごとの呼び出し
		switch (m_scene)
		{
		case LOGO:
			m_base = new GameLogo();
			break;

		case TITLE:
			m_base = new GameTitle();
			break;

		case PLAY:
			m_base = new GamePlay();
			break;

		case CLEAR:
			m_base = new GameClear();
			break;

		case OVER:
			m_base = new GameOver();
			break;
		}
	}

	m_nextScene = m_base->Update();

	m_key_old = m_key_code;

	return true;
}



//----------------------------------------------------------------------
//! @brief ゲームの描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GameMain::RenderGame(void)
{
	m_base->Render();
}



//----------------------------------------------------------------------
//! @brief ゲームの終了処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GameMain::FinalizeGame(void)
{

}