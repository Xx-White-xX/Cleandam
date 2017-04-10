//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitel.h
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
#include "../image.h"

class GameTitle :public GameBase
{
private:

	image* title;

public:
	GameTitle();
	~GameTitle();
	int Update();
	void Render();


};
