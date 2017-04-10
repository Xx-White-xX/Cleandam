//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitle.cpp
//!
//! @brief  タイトル処理のソースファイル
//!
//! @date   日付		
//!
//! @author 制作者名	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "PBullet.h"

#include <d3d11.h>
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
PBullet::PBullet()
{
	Texture* PBimage = new Texture(L"Resources\\Images\\tate.png");

	handle = PBimage;

	pos_x = 160;
	pos_y = 240;
	spd_x = 0.0f;
	spd_y = 0.0f;

	grp_w = 48;
	grp_h = 16;
	grp_x = 16;
	grp_y = 16;

	state = 0;

	m_col = false;
}

//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
//= @brief ステータスを決める
//=
//= @param[in] 各能力
//=
//= @return ステータス値
//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
PBullet::~PBullet()
{

}

//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
//= @brief ステータスを決める
//=
//= @param[in] 各能力
//=
//= @return ステータス値
//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
bool PBullet::distinction()
{
	//if ((enemy.pos_x <= player.pos_x + player.grp_w) && (enemy.pos_x + enemy.grp_w >= player.pos_x) &&
	//	(enemy.pos_y <= player.pos_y + player.grp_h) && (enemy.pos_y + enemy.grp_h >= player.pos_y))
	//{
	//	m_col = true;
	//}

	return m_col;
}
