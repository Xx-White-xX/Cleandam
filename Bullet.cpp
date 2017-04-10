#include "Bullet.h"

#include <d3d11.h>
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

Bullet::Bullet(Vector2 pos)
{
	grp_h = 16*2;
	grp_w = 16*2;
	grp_x = 0;
	grp_y = 0;

	pos_x = pos.x - GetGrpW();
	pos_y = pos.y;// -(GetGrpH() / 2);

	spd_x = 2;
	spd_y = 2;

	handle = new Texture(L"enemy.png");

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
	if (Player_pos_y + (GetGrpH() / 2) <= GetPosY())
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