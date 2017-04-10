//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   PBullet.h
//!
//! @brief  �v���C���[�̒e�֘A�̃w�b�_�t�@�C��
//!
//! @date   2016/12/12
//!
//! @author T.ichioka
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

#include "GameBase.h"
#include "ObjectBase.h"

class PBullet :public ObjectBase
{
private:
	//�e�̐�
	bool m_col;

public:
	PBullet();
	~PBullet();

	//�e�̔���
	bool distinction();
};
