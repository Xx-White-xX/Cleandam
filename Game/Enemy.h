#pragma once

//インクルード
#include <d3d11.h>
#include <SimpleMath.h>

#include "ObjectBase.h"
#include "Bullet.h"

const float MOVESPD = 2.0f;

class Enemy:public ObjectBase
{
private:

	using Vector2 = DirectX::SimpleMath::Vector2;

	//弾数
	Bullet* m_Bullet;

	bool m_Move;

	bool m_Shot_on;

	Vector2 StatPos;

	int m_BulletType;

	int m_Bullet_count;

public:

	Enemy(Vector2 pos);

	~Enemy();

	void Move();

	void ChangeMobe();

	void Shot();

	void Lost();

	bool GoShot();

	//仮
	void on();

	void BulletMove();

	bool BulletTime();
	
	int PossGrpW();
	int PossGrpH();
	int PossGrpX();
	int PossGrpY();

	float PossPosX();
	float PossPosY();
};