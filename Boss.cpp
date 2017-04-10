#include "Boss.h"
#include <time.h>



Boss::Boss(Vector2 pos)
	:m_HP(10)
	,m_bullet_cnt(0)
	
{
	srand((unsigned int)time(NULL));

	grp_h = 256;
	grp_w = 256;
	grp_x = 0;
	grp_y = 0;

	spd_y = 1.0f;

	pos_x = pos.x;
	pos_y = pos.y;

	for (int i = 0; i < 9; i++)
	{

	}

	handle = new Texture(L"Resources\\images\\pikky.png");
}


Boss::~Boss()
{

}

void Boss::move()
{
	
}

void Boss::attck()
{
	if (m_HP > 5)
	{
		switch (m_bullet_cnt)
		{
		case 0:
			m_bullet_cnt++;
			break;
		case 1:
			m_bullet_cnt++;
			break;
		case 2:
			m_bullet_cnt = 0;
			break;
		}
	}
	else if(m_HP <= 5)
	{
			switch (m_bullet_cnt)
		{
			case 0:
				m_bullet_cnt = rand() % 3;
				break;
			case 1:
				m_bullet_cnt = rand() % 3;
				break;
			case 2:
				m_bullet_cnt = rand() % 3;
				break;
		}

	}
}
