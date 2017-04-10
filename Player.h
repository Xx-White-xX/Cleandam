//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Player.h
//!
//! @brief  �v���C�C���[�����̃w�b�_�t�@�C��
//!
//! @date   2017/04/07
//!
//! @author Shuta Furukawa	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//���d�C���N���[�h�̖h�~
#pragma once

//�w�b�_�t�@�C���̃C���N���[�h
#include "GameBase.h"
#include "ObjectBase.h"
#include "PBullet.h"

class Player: public ObjectBase
{
private:
	//�v���C���[�̈ړ����x
	static float m_speed;
	//�v���C���[�̎c�@
	int m_lives;

	//�e�̐�
	int m_bullet;

public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	//�v���C���[�̈ړ�����
	void PlayerMove(Player* player, float dir);
	//�v���C���[�̎��S����
	void PlayerDeath(PBullet* collender);

};
