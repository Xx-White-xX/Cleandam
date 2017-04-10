#include "Enemy.h"
#include "Direct3D.h"
#include "DirectXTK.h"
#include <ctime>

using namespace DirectX::SimpleMath;
using namespace DirectX;

//�R���X�g���N�^
Enemy::Enemy(Vector2 pos)
	: m_Bullet(nullptr)
	, m_Move(false)
	, m_Shot_on(false)
{
	grp_h = 32;
	grp_w = 32;
	grp_x = 0;
	grp_y = 0;

	spd_x = 2.0f;
	spd_y = 2.0f;

	pos_x = pos.x;
	pos_y = pos.y;

	//�����Œ�`
	handle = new Texture(L"enemy.png");
}

//�f�X�g���N�^
Enemy::~Enemy()
{
	delete handle;
}

void Enemy::Move()
{
	/////////�f�o�b�N////////////
	if (g_key.Up)
	{
		pos_y -= spd_y;
	}
	else if (g_key.Down)
	{
		pos_y += spd_y;
	}
	if (g_key.Right)
	{
		pos_x += spd_x;
	}
	else if (g_key.Left)
	{
		pos_x -= spd_x;
	}
	////////////////////////////

	/////////////////////
	//if (m_Move == false)
	//{
	//	//���Ɉړ�
	//	pos_x -= spd_x;
	//}

	//if (m_Move == true)
	//{
	//	//�E�Ɉړ�
	//	pos_x += spd_x;
	//}
	//////////////////////
}

void Enemy::ChangeMobe()
{
	m_Move = true;
}

void Enemy::Shot()
{
	StatPos.x = GetPosX();
	StatPos.y = GetPosY();

	m_Bullet = new Bullet(StatPos);

	m_Shot_on = true;
}

void Enemy::Lost()
{
	if (m_Bullet->GetPosX()<= 0)
	{
		delete m_Bullet;
		m_Bullet = nullptr;
		m_Shot_on = false;
	}
}

bool Enemy::GoShot()
{
	return m_Shot_on;
}

void Enemy::on()
{
	if (m_Bullet != nullptr)
	{
		m_Bullet->Render();
	}
}

void Enemy::BulletMove()
{
	m_Bullet->ShotMove();
}