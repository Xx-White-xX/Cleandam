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
#include "Bullet.h"

#include <d3d11.h>
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

Bullet::Bullet(float x, float y)
{
	handle = new Texture(L"Resources\\images\\puttyo2.png");

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
	delete handle;
}

void Bullet::ShotMove()
{
	pos_x -= spd_x;
}

void Bullet::CurveShot(int Player_pos_y)
{
	if (Player_pos_y <= GetPosY())
	{
		pos_y += 12;
		pos_x -= spd_x;
	}
	else
	{
		pos_y -= 12;
		pos_x -= spd_x;
	}
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
