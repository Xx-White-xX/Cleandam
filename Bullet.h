//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   弾丸の処理
//!
//! @brief 
//!
//! @date   日付
//!
//! @author 制作者名	後藤将斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once

#include "ObjectBase.h"

class Bullet :public ObjectBase
{

public:

	Bullet(float x, float y);

	~Bullet();

	void BulletPos(float x, float y);

	void LostBullet();

};