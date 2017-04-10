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
#include "Bit.h"

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
Bit::Bit()
{
	Texture* BImage = new Texture(L"Resources\\Images\\longriful.jpg");

	handle = BImage;

	pos_x = 160;
	pos_y = 200;
	spd_x = 0.0f;
	spd_y = 0.0f;

	grp_w = 60;
	grp_h = 16;
	grp_x = 68;
	grp_y = 48;

	state = 1;

	m_modeFlag = false;
}

//----------------------------------------------------------------------
//! @brief デストラクタ
//----------------------------------------------------------------------
Bit::~Bit()
{

}

//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
//= @brief ステータスを決める
//=
//= @param[in] 各能力
//=
//= @return ステータス値
//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
void Bit::BitMove(Bit* bits, Player* player, float dir)
{
	//キー入力処理
	if (g_keyTracker->lastState.Right)
	{
		if (player->GetPosX() <= SCREEN_WIDTH / 2)
		{
			bits->SetSpdX(dir);
			bits->SetSpdY(0);
		}
		else
		{
			bits->SetSpdX(0);
			bits->SetSpdY(0);
		}
	}
	else if (g_keyTracker->lastState.Left)
	{
		if (player->GetPosX() >= 0)
		{
			bits->SetSpdX(-dir);
			bits->SetSpdY(0);
		}
		else
		{
			bits->SetSpdX(0);
			bits->SetSpdY(0);
		}

	}
	else if (g_keyTracker->lastState.Up)
	{
		if (player->GetPosY() >= 0)
		{
			bits->SetSpdY(-dir);
			bits->SetSpdX(0);
		}
		else
		{
			bits->SetSpdX(0);
			bits->SetSpdY(0);
		}

	}
	else if (g_keyTracker->lastState.Down)
	{
		if (player->GetPosY() <= SCREEN_HEIGHT)
		{
			bits->SetSpdY(dir);
			bits->SetSpdX(0);
		}
		else
		{
			bits->SetSpdX(0);
			bits->SetSpdY(0);
		}

	}
	else
	{
		//何も入力しないときは速度０
		bits->SetSpdX(0);
		bits->SetSpdY(0);
	}
}

//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
//= @brief ステータスを決める
//=
//= @param[in] 各能力
//=
//= @return ステータス値
//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
void Bit::ChengePos()
{
	if (g_keyTracker->pressed.Z)
	{
		if (m_modeFlag == true)
		{
			m_modeFlag = false;
			pos_x = GetPosX() - 70;
		}
		else if (m_modeFlag == false)
		{
			m_modeFlag = true;
			pos_x = GetPosX() + 70;
		}
	}
}

//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
//= @brief ステータスを決める
//=
//= @param[in] 各能力
//=
//= @return ステータス値
//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
void Bit::Sandwich()
{

}