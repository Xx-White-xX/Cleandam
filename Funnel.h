//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   
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

class Funnel :public ObjectBase
{

public:

	Funnel(float x,float y);

	~Funnel();

	void FunnelPos(float x, float y);

};