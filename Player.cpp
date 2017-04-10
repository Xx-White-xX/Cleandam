//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Player.cpp
//!
//! @brief  プレイイヤー処理のソースファイル
//!
//! @date   2017/04/07
//!
//! @author Shuta Furukawa	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//ヘッダファイルのインクルード
#include "GameMain.h"
#include "Player.h"
#include <d3d11.h>
#include <SimpleMath.h>

//名前空間
using namespace DirectX::SimpleMath;
using namespace DirectX;

//メンバ関数の定義
//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] プレイヤーネーム
//----------------------------------------------------------------------
Player::Player()
{
	Texture* PImage = new Texture(L"Resources\\Images\\gundam.jpg");

	handle = PImage;

	pos_x = 160;
	pos_y = 240;
	spd_x = 0.0f;
	spd_y = 0.0f;

	grp_w = 48;
	grp_h = 48;
	grp_x = 98;
	grp_y = 98;

	state = 1;

	m_lives = 3;
}

//----------------------------------------------------------------------
//! @brief デストラクタ
//----------------------------------------------------------------------
Player::~Player()
{

}

//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
//= @brief ステータスを決める
//=
//= @param[in] 各能力
//=
//= @return ステータス値
//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
void Player::PlayerMove(Player* player, float dir)
{
	//キー入力処理
	if (g_keyTracker->lastState.Right)
	{
		if (player->GetPosX() <= SCREEN_WIDTH)
		{
			player->SetSpdX(dir);
			player->SetSpdY(0);
		}
		else
		{
			player->SetSpdX(0);
			player->SetSpdY(0);

		}
	}
	else if (g_keyTracker->lastState.Left)
	{
		if (player->GetPosX() >= 0)
		{
			player->SetSpdX(-dir);
			player->SetSpdY(0);
		}
		else
		{
			player->SetSpdX(0);
			player->SetSpdY(0);

		}

	}
	else if (g_keyTracker->lastState.Up)
	{
		if (player->GetPosY() >= 0)
		{
			player->SetSpdY(-dir);
			player->SetSpdX(0);
		}
		else
		{
			player->SetSpdX(0);
			player->SetSpdY(0);

		}

	}
	else if (g_keyTracker->lastState.Down)
	{
		if (player->GetPosY() <= SCREEN_HEIGHT)
		{
			player->SetSpdY(dir);
			player->SetSpdX(0);
		}
		else
		{
			player->SetSpdX(0);
			player->SetSpdY(0);

		}
	}
	else
	{
		//速度０
		player->SetSpdX(0);
		player->SetSpdY(0);
	}
}

//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
//= @brief ステータスを決める
//=
//= @param[in] 各能力
//=
//= @return ステータス値
//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
void Player::PlayerDeath(PBullet* collender)
{
	if (collender->distinction() == true)
	{
		m_lives--;

		if (m_lives == 0)
		{
			g_NextScene = OVER;
		}
	}
}
