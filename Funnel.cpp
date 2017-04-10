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
#include "Funnel.h"

Funnel::Funnel(float x,float y)
{
	handle = g_PongImage;
	grp_x = 0;
	grp_y = 0;
	grp_w = 32;
	grp_h = 32;
	pos_x = x;
	pos_y = y;
	spd_x = 0.0f;
	spd_y = 0.0f;
	state = 1;

}

Funnel::~Funnel()
{
}

void Funnel::FunnelPos(float x, float y)
{
	pos_x = x;
	pos_y = y;
}
