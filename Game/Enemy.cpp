#include "Enemy.h"
#include "../Direct3D.h"
#include "../DirectXTK.h"
#include <ctime>

using namespace DirectX::SimpleMath;
using namespace DirectX;

//コンストラクタ
Enemy::Enemy(Vector2 pos)
	: m_Bullet(nullptr)
	, m_Move(false)
	, m_Shot_on(false)
{
	//画像の大きさ
	grp_h = 32;
	grp_w = 32;
	grp_x = 0;
	grp_y = 0;

	//移動速度
	spd_x = 2.0f;
	spd_y = 2.0f;

	//位置
	pos_x = pos.x;
	pos_y = pos.y;

	//どんな弾を撃ってくるか
	m_BulletType = rand() % 2;

	//弾の発射感覚
	m_Bullet_count = rand() % 30 + 20;

	//ここで定義
	handle = new Texture(L"Resources\\images\\enemy.png");
}

//デストラクタ
Enemy::~Enemy()
{
	delete handle;
}

void Enemy::Move()
{
	if (m_Move == false)
	{
		//左に移動
		pos_x -= spd_x;
	}

	if (m_Move == true)
	{
		//右に移動
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
		//引数、プレイヤーのy座標
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