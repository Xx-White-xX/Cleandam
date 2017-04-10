#pragma once

//インクルード
#include <d3d11.h>
#include <SimpleMath.h>
#include "Bullet.h"
#include "ObjectBase.h"

class Boss:public ObjectBase
{
private:

	using Vector2 = DirectX::SimpleMath::Vector2;

	//弾数
	Bullet* m_Bullet[30];

	int m_HP;

	int m_bullet_cnt;

	bool m_Move;

	bool m_Shot_on;

	Vector2 StatPos;

	int m_BulletType;

	bool direction;

	int m_Bullet_count;

public:
	Boss(Vector2 pos);
	~Boss();
	void move();

	void attck();

	void Shot();

	void Lost();

	bool GoShot();

	void on();

	void BulletMove();

	bool BulletTime();

	int PossGrpW();
	int PossGrpH();
	int PossGrpX();
	int PossGrpY();

	float PossPosX(int i);
	float PossPosY(int i);
};

