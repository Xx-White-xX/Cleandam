//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   PBullet.h
//!
//! @brief  プレイヤーの弾関連のヘッダファイル
//!
//! @date   2016/12/12
//!
//! @author T.ichioka
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once

#include "GameBase.h"
#include "ObjectBase.h"

#define BULLET_MAX 50

class PBullet :public ObjectBase
{
private:
	//弾の数
	int bullet[BULLET_MAX];

public:
	PBullet();
	~PBullet();

	//弾の発射
	void Create();
	//弾の消去
	void Delete();


};
