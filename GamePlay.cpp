//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.cpp
//!
//! @brief  ゲームプレイ処理のソースファイル
//!
//! @date   日付		
//!
//! @author 制作者名	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "GamePlay.h"
using namespace DirectX::SimpleMath;
using namespace DirectX;
//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GamePlay::GamePlay()
{
	Vector2 pos;
	Vector2 pos2;

	pos.x = 0;
	pos.y = 0;
	pos2.x = 400;
	pos2.y = 150;

	enemy = new Enemy(pos);

	stage = new Stage(pos);

	boss = new Boss(pos2);

	


}

//----------------------------------------------------------------------
//! @brief デストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GamePlay::~GamePlay()
{
	delete enemy;
}

//----------------------------------------------------------------------
//! @brief ゲームプレイ処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
int GamePlay::Update(void)
{
	enemy->Move();

	stage->Move();

	//boss->move();

	if (g_keyTracker->pressed.Space)
	{
		return  CLEAR;
	}
	
	if (g_keyTracker->pressed.A)
	{
		return OVER;
	}

	return PLAY;
}



//----------------------------------------------------------------------
//! @brief ゲームプレイ描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GamePlay::Render(void)
{
	enemy->Render();

	stage->Render();

	boss->Render();
}