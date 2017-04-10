#pragma once

//�C���N���[�h
#include <d3d11.h>
#include <SimpleMath.h>

#include "Game\ObjectBase.h"
#include "Bullet.h"

const float MOVESPD = 2.0f;

class Texture;

class Enemy:public ObjectBase
{
private:

	using Vector2 = DirectX::SimpleMath::Vector2;

	//�e��
	Bullet* m_Bullet;

	bool m_Move;

	bool m_Shot_on;

	Vector2 StatPos;

public:

	Enemy(Vector2 pos);

	~Enemy();

	void Move();

	void ChangeMobe();

	void Shot();

	void Lost();

	bool GoShot();

	//��
	void on();

	void BulletMove();
};