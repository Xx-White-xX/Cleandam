//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file  
//!
//! @brief 
//!
//! @date   ì˙ït
//!
//! @author êßçÏé“ñº	å„ì°è´ìl
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#include "GameMain.h"
#include "Item.h"

Item::Item()
{
	handle = g_PongImage;
	grp_x = 160;
	grp_y = 0;
	grp_w = 32;
	grp_h = 32;
	pos_x = 640.0f / 2.0f;
	pos_y = 480.0f / 4.0f;
	spd_x = 0.0f;
	spd_y = 0.0f;
	state = 1;
}

Item::~Item()
{
}
