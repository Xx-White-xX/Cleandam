//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   ObjectBase.cpp
//!
//! @brief  オブジェクトのソースファイル
//!
//! @date   日付
//!
//! @author 制作者名
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "ObjectBase.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;


void ObjectBase::Update()
{
	pos_x += spd_x;
	pos_y += spd_y;
}


void ObjectBase::Render()
{
	RECT rect;			//絵の左上の座標と右下の座標編集用

	rect = { grp_x, grp_y, grp_x + grp_w, grp_y + grp_h };

	g_spriteBatch->Draw(handle->m_pTexture,
		Vector2(pos_x, pos_y), &rect, Colors::White, 0.0f, Vector2(0, 0), 1.0f);

}

void ObjectBase::SetHandle(Texture texture)
{
	*handle = texture;
}

Texture ObjectBase::GetHandle()
{
	return *handle;
}

void ObjectBase::SetGrpX(int x)
{
	grp_x = x;
}

void ObjectBase::SetGrpY(int y)
{
	grp_y = y;
}

void ObjectBase::SetGrpW(int w)
{
	grp_w = w;
}

void ObjectBase::SetGrpH(int h)
{
	grp_h = h;
}

int ObjectBase::GetGrpX()
{
	return grp_x;
}

int ObjectBase::GetGrpY()
{
	return grp_y;
}

int ObjectBase::GetGrpH()
{
	return grp_h;
}

int ObjectBase::GetGrpW()
{
	return grp_w;
}

void ObjectBase::SetPosX(float x)
{
	pos_x = x;
}

void ObjectBase::SetPosY(float y)
{
	pos_y = y;
}

float ObjectBase::GetPosX()
{
	return pos_x;
}

float ObjectBase::GetPosY()
{
	return pos_y;
}

void ObjectBase::SetSpdX(float x)
{
	spd_x = x;
}

void ObjectBase::SetSpdY(float y)
{
	spd_y = y;
}

float ObjectBase::GetSpdX()
{
	return spd_x;
}

float ObjectBase::GetSpdY()
{
	return spd_y;
}

void ObjectBase::SatState(int s)
{
	state = s;
}

int ObjectBase::GetState()
{
	return state;
}