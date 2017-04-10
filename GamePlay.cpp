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
#include "../Player.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

bool collston(Enemy* enemy, Funnel* funnel1, Funnel* funnel2);
//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GamePlay::GamePlay():
	enemy_count(0)
{
	Vector2 pos;

	pos.x = 360;
	pos.y = 240;

	enemy = new Enemy(pos);
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
	if (enemy != nullptr)
	{
		enemy->Move();

		if (enemy->GetPosX() == 120)
		{
			int randm = 0;

			randm = rand() % 2;

			{
				if (randm == 0)
				{
					enemy->ChangeMobe();
				}
			}
		}

		//if (g_keyTracker->pressed.Space)
		//{
		//	return  CLEAR;
		//}
		//
		//if (g_keyTracker->pressed.A)
		//{
		//	return OVER;
		//}

		enemy->BulletDown();

		//ファンネルを連結した後
		if (/*(collston(enemy, funnnel[0], funnnel[1]) == true) ||*/
			(enemy->GetPosX() <= 0) ||
			(enemy->GetPosX() >= 640))
		{
			EnemyLost();
		}
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
	if (enemy != nullptr)
	{
		//ここで描画
		enemy->Render();

		enemy->Shot();

		if (enemy->GoShot() == true)
		{
			enemy->on();
			enemy->BulletMove();
		}

		//消える
		if (enemy->GoShot() == true)
		{
			enemy->Lost();
		}
	}
}

void GamePlay::EnemyCreate()
{
	Vector2 enemypos;

	enemypos.x = 0;
	enemypos.y = 0;

	enemy = new Enemy(enemypos);
}

void GamePlay::EnemyLost()
{
	enemy = nullptr;
	delete enemy;
}



bool collston(Enemy* enemy , Funnel* funnel0, Funnel* funnel1)
{
	if ((funnel0->GetPosY() + funnel0->GetGrpW() == enemy->GetSpdY() && funnel0->GetPosX() <= enemy->GetPosX() && funnel0->GetPosX() + funnel0->GetGrpW() >= enemy->GetPosX()) &&
		(funnel1->GetPosY() == enemy->GetPosY() + enemy->GetGrpH() && funnel1->GetPosX() <= enemy->GetPosX() && funnel1->GetPosX() + funnel1->GetGrpW() >= enemy->GetPosX()))
	{
		return true;
	}

	return false;
}