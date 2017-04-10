//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.h
//!
//! @brief  ゲームプレイのヘッダファイル
//!
//! @date   日付
//!
//! @author 制作者名	後藤将斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once


#include "GameBase.h"

#include "../Enemy.h"
#include "../Stage.h"
#include "../Boss.h"
#include "../Bullet.h"
#include "Player.h"
#include "Bullet.h"
#include "Item.h"
#include "Funnel.h"
#include "Enemy.h"

#define MAX_BULLET 30

class GamePlay :public GameBase
{
private:
	int cnt;				// カウンタ
	int bullet_shot_cnt;	// 弾を放つタイミングの変数を増加カウンタ
	int bullet_cllas_cnt;	// 弾の種類のカウンタ

	int a;

	int funnel_cnt;

	Player* player;
	Item* item;
	Bullet** bullet;
	Bullet** bullet_up;
	Bullet** bullet_down;

	Funnel** funnel;

	Enemy* enemy;


	int enemy_count;

public:
	GamePlay();		// コンストラクタ
	~GamePlay();	// デストラクタ

	void Update();
	void Render();

};
