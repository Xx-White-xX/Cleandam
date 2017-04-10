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
#include "../Enemy.h"
#include "Stage.h"
#include "Boss.h"

class GamePlay :public GameBase
{
private:

	Enemy* enemy;
	Stage* stage;
	Boss* boss;
	

public:
	GamePlay();
	~GamePlay();
	int Update();
	void Render();
};
