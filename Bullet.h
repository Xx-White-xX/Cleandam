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

class Bullet :public ObjectBase
{

public:

	Bullet(float x, float y);

	~Bullet();

	void BulletPos(float x, float y);

	void LostBullet();

};