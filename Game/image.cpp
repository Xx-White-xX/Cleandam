#include "image.h"

image::image(Vector2 pos)
{
	grp_h = 480;
	grp_w = 640;
	grp_x = 0;
	grp_y = 0;

	pos_x = pos.x;
	pos_y = pos.y;

	handle = new Texture(L"Resources\\images\\title.png");
}


image::~image()
{

}
