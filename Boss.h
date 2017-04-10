#pragma once

//インクルード
#include <d3d11.h>
#include <SimpleMath.h>

#include "ObjectBase.h"

class Boss:public ObjectBase
{
private:

	using Vector2 = DirectX::SimpleMath::Vector2;

	//弾
	int m_Bullet[10];

	int m_HP;

	int m_bullet_cnt;



public:
	Boss(Vector2 pos);
	~Boss();
	void move();
	void attck();
};

