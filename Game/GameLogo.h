//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLogo.h
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

class GameLogo :public GameBase
{
private:
	int *p;
	int cnt;		//カウンタ

public:
	GameLogo();
	~GameLogo();
	int Update();
	void Render();

};