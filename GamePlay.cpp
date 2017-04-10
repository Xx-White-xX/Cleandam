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
GamePlay::GamePlay():
	enemy_count(0)
{
	Vector2 pos;
	Vector2 pos2;
	Vector2 pos3;

	pos.x = 0;
	pos.y = 0;
	pos2.x = 400;
	pos2.y = 150;
	pos3.x = 360;
	pos3.y = 240;

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
	enemy->Move();

	if (enemy->GetPosX() == 120)
	{
		if (enemy->GetPosX() == 120)
		{
			int randm = 0;
		{
			if (randm == 0)
			{
				enemy->ChangeMobe();
			}
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
	//if (g_keyTracker->released.Space)
	//{
	//	enemy->Shot();
	//}

	//if (enemy->GoShot() == true)
	//{
	//	enemy->on();
	//	enemy->BulletMove();
	//}

	////消える
	//if (enemy->GoShot() == true)
	//{
	//	enemy->Lost();
	//}
	stage->Render();

	if (g_keyTracker->released.Space)
	{
		boss->Shot();
	}

	if (boss->GoShot() == true)
	{
		boss->on();
		boss->BulletMove();
	}

	//消える
	if (boss->GoShot() == true)
	{
		boss->Lost();
	}



	boss->Render();
}

	//ここで描画
	enemy->Render();

	if (g_keyTracker->released.Space)
	{
		enemy->Shot();
	}

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



int collston(Enemy* enemy , OBJECT B)
{
	float x1 = enemy->GetPosX() + (enemy->GetGrpW() / 2);		//中心座標x
	float y1 = enemy->GetPosY() + (enemy->GetGrpH() / 2);		//中心座標y
	float x2 = B.pos_x + (B.grp_w / 2);
	float y2 = B.pos_y + (B.grp_h / 2);

	float r1 = A.grp_w / 2;
	float r2 = B.grp_w / 2;

	if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) <= (r1 + r2)*(r1 + r2))
	{
		return 1;
	}
	return 0;
}