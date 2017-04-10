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
#include "GameTitle.h"
//#include "..\ADX2Le.h"
//#include "CueSheet_0.h"

#pragma comment(lib, "cri_ware_pcx86_LE_import.lib")
using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GameTitle::GameTitle()
{
	Vector2 pos;

	pos.x = 0;
	pos.y = 0;

	title = new image(pos);
}

//----------------------------------------------------------------------
//! @brief デストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GameTitle::~GameTitle()
{
	delete title;
}

//----------------------------------------------------------------------
//! @brief タイトル処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
int GameTitle::Update(void)
{
	if (g_keyTracker->pressed.Space)
	{
		return PLAY;
	}

	return TITLE;
}

//----------------------------------------------------------------------
//! @brief タイトル描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GameTitle::Render(void)
{
	swprintf_s(buf, L"Title");
	g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(0, 20));

	title->Render();
}