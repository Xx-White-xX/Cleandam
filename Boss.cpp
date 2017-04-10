#include "Boss.h"
#include <time.h>



Boss::Boss(Vector2 pos)
	:m_HP(100)
	,m_bullet_cnt(0)
	,m_Move(false)
	,m_Shot_on(false)
	
{
	srand((unsigned int)time(NULL));

	grp_h = 256;
	grp_w = 256;
	grp_x = 0;
	grp_y = 0;

	spd_y = 1.0f;

	for (int i = 0; i < 29; i++)
	{
		m_Bullet[i] = nullptr;
	}
	

	pos_x = pos.x;
	pos_y = pos.y;


	handle = new Texture(L"Resources\\images\\pikky.png");
}


Boss::~Boss()
{

}

void Boss::move()
{
	
}

void Boss::Shot()
{
	StatPos.x = GetPosX() + rand() % 100;
	StatPos.y = GetPosY() + rand() % 200;

	for (int i = 0; i < 29; i++)
	{
		if (m_Bullet[i] == nullptr)
		{
			m_Bullet[i] = new Bullet(StatPos);
			break;
		}

	}


	m_Shot_on = true;
}

void Boss::Lost()
{
	for (int i = 0; i < 29; i++)
	{
		if (m_Bullet[i] != nullptr)
		{ 
			if (m_Bullet[i]->GetPosX() <= 0)
			{
				delete m_Bullet[i];
				m_Bullet[i] = nullptr;
			}
		}
	}
}

bool Boss::GoShot()
{
	return m_Shot_on;
}

void Boss::on()
{
	for (int i = 0; i < 29; i++)
	{
		if (m_Bullet[i] != nullptr)
		{
			m_Bullet[i]->Render();
		}

	}
}

void Boss::BulletMove()
{
	for (int i = 0; i < 29; i++)
	{
	switch (m_BulletType)
	{
	case 0:
		if (m_Bullet[i] != nullptr)
		{
		m_Bullet[i]->ShotMove();
		}
		break;

	case 1:
		//引数、プレイヤーのy座標
		//m_Bullet->CurveShot();
		break;
	}

	}
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
