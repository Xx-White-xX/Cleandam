#include "Stage.h"



Stage::Stage(Vector2 pos)
{
	grp_h = 480;
	grp_w = 1280;
	grp_x = 0;
	grp_y = 0;

	spd_x = 2.0f;

	pos_x = pos.x;
	
	

	handle = new Texture(L"Resources\\images\\internal2.png");

}


Stage::~Stage()
{

}

void Stage::Move()
{
	if (pos_x >= -550)
	{
		pos_x -= spd_x;
	}
	else
	{
		pos_x = 0;
	}
}
