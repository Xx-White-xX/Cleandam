#include "Enemy.h"
#include "../Direct3D.h"
#include "../DirectXTK.h"
#include <ctime>

using namespace DirectX::SimpleMath;
using namespace DirectX;

//�R���X�g���N�^
Enemy::Enemy(Vector2 pos)
	: m_Bullet(nullptr)
	, m_Move(false)
	, m_Shot_on(false)
{
	//�摜�̑傫��
	grp_h = 32;
	grp_w = 32;
	grp_x = 0;
	grp_y = 0;

	//�ړ����x
	spd_x = 2.0f;
	spd_y = 2.0f;

	//�ʒu
	pos_x = pos.x;
	pos_y = pos.y;

	//�ǂ�Ȓe�������Ă��邩
	m_BulletType = rand() % 2;

	//�e�̔��ˊ��o
	m_Bullet_count = rand() % 30 + 20;

	//�����Œ�`
	handle = new Texture(L"Resources\\images\\enemy.png");
}

//�f�X�g���N�^
Enemy::~Enemy()
{
	delete handle;
}

void Enemy::Move()
{
	if (m_Move == false)
	{
		//���Ɉړ�
		pos_x -= spd_x;
	}

	if (m_Move == true)
	{
		//�E�Ɉړ�
		pos_x += spd_x;
	}
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
	switch (m_BulletType)
	{
	case 0:
		m_Bullet->ShotMove();
		break;

	case 1:
		//�����A�v���C���[��y���W
		//m_Bullet->CurveShot();
		break;
	}
}

bool Enemy::BulletTime()
{
	if (m_Bullet_count == 0)
	{
		return true;
	}
	else
	{
		m_Bullet_count--;
		return false;
	}
}

int Enemy::PossGrpW()
{
	return m_Bullet->GetGrpW();
}
int Enemy::PossGrpH()
{
	return m_Bullet->GetGrpH();
}
int Enemy::PossGrpX()
{
	return m_Bullet->GetGrpX();
}
int Enemy::PossGrpY()
{
	return m_Bullet->GetGrpY();
}

float Enemy::PossPosX()
{
	return m_Bullet->GetPosX();
}
float Enemy::PossPosY()
{
	return m_Bullet->GetPosY();
}