//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   �e�ۂ̏���
//!
//! @brief 
//!
//! @date   ���t
//!
//! @author ����Җ�	�㓡���l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

#include "ObjectBase.h"
#include <d3d11.h>
#include <SimpleMath.h>

class Bullet :public ObjectBase
{
private:

public:

	Bullet(float x, float y);

	~Bullet();

	void BulletPos(float x, float y);

	void LostBullet();

	void ShotMove();	//�ʏ�e

	void CurveShot(int pos_y);

};