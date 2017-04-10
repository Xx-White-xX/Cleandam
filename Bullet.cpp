//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file  
//!
//! @brief 
//!
//! @date   “ú•t
//!
//! @author §ìÒ–¼	Œã“¡«“l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#include "GameMain.h"
#include "Bullet.h"

Bullet::Bullet(float x, float y)
{
	handle = g_BulletImage;
	grp_x = 0;
	grp_y = 0;
	grp_w = 16;
	grp_h = 16;
	pos_x = x + 20.0f;
	pos_y = y;
	spd_x = 0.0f;
	spd_y = 0.0f;
	state = 0;

}

Bullet::~Bullet()
{
}

void Bullet::BulletPos(float x, float y)
{
	pos_x = x + 20.0f;
	pos_y = y;

}

void Bullet::LostBullet()
{
	if (pos_x >= 656.0f)
	{
		state = 0;
	}

}
