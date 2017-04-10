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
	Texture* PImage = new Texture(L"Resources\\Images\\player.png");

	handle = PImage;

	pos_x = 160;
	pos_y = 240;
	spd_x = 0.0f;
	spd_y = 0.0f;

	grp_w = 32;
	grp_h = 32;
	grp_x = 0;
	grp_y = 0;

	state = 1;
}

//----------------------------------------------------------------------
//! @brief デストラクタ
//----------------------------------------------------------------------
Player::~Player()
{

}