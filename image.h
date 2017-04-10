#pragma once

//インクルード
#include <d3d11.h>
#include <SimpleMath.h>

#include "Game\ObjectBase.h"

class image :public ObjectBase
{
private:

	using Vector2 = DirectX::SimpleMath::Vector2;

public:
	image(Vector2 pos);
	~image();
};

