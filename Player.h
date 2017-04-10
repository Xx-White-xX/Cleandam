//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Player.h
//!
//! @brief  プレイイヤー処理のヘッダファイル
//!
//! @date   2017/04/07
//!
//! @author Shuta Furukawa	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//多重インクルードの防止
#pragma once

//ヘッダファイルのインクルード
#include "GameBase.h"
#include "ObjectBase.h"
#include "PBullet.h"

class Player: public ObjectBase
{
private:
	//プレイヤーの移動速度
	static float m_speed;
	//プレイヤーの残機
	int m_lives;

	//弾の数
	int m_bullet;

public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	//プレイヤーの移動処理
	void PlayerMove(Player* player, float dir);
	//プレイヤーの死亡処理
	void PlayerDeath(PBullet* collender);

};
