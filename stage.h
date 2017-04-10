#pragma once

//インクルード
#include <d3d11.h>
#include <SimpleMath.h>

#include "Game\ObjectBase.h"

class Stage : public ObjectBase
{

private:

	using Vector2 = DirectX::SimpleMath::Vector2;

public:
	Stage(Vector2 pos);
	~Stage();
	void Move();
};

