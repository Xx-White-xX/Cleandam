#pragma once

#include "Game\ObjectBase.h"
#include <d3d11.h>
#include <SimpleMath.h>

class Bullet:public ObjectBase
{
private:
	using Vector2 = DirectX::SimpleMath::Vector2;

public:
	Bullet(Vector2 pos);

	~Bullet();

	void ShotMove();	//í èÌíe

	void CurveShot(int pos_y);
};