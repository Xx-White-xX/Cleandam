//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.h
//!
//! @brief  ゲーム関連のヘッダファイル
//!
//! @date   2016/12/12
//!
//! @author T.ichioka
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once

#include "GameBase.h"
#include "Enemy.h"
#include "Stage.h"
#include "Boss.h"
#include "Bullet.h"
#include "Player.h"

#include "Player.h"
#include "Funnel.h"

class GamePlay :public GameBase
{
private:

	Enemy** enemy;
	Stage* stage;
	Boss* boss;

	Player* player;
	
	Funnel** funnel;

	int a;

	int funnel_cnt;

	//敵の数
	int enemy_count;

	//自機の数
	int m_Life;

	int m_BossLife;

public:
	GamePlay();
	~GamePlay();
	int Update();
	void Render();

	void EnemyLost(int number);

	void EnemyCreate(int number);
};
