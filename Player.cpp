//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Player.cpp
//!
//! @brief  �v���C�C���[�����̃\�[�X�t�@�C��
//!
//! @date   2017/04/07
//!
//! @author Shuta Furukawa	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//�w�b�_�t�@�C���̃C���N���[�h
#include "GameMain.h"
#include "Player.h"
#include <d3d11.h>
#include <SimpleMath.h>

//���O���
using namespace DirectX::SimpleMath;
using namespace DirectX;

//�����o�֐��̒�`
//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �v���C���[�l�[��
//----------------------------------------------------------------------
Player::Player()
{
	Texture* PImage = new Texture(L"Resources\\Images\\gundam.jpg");

	handle = PImage;

	pos_x = 160;
	pos_y = 240;
	spd_x = 0.0f;
	spd_y = 0.0f;

	grp_w = 48;
	grp_h = 48;
	grp_x = 98;
	grp_y = 98;

	state = 1;

	m_lives = 3;
}

//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//----------------------------------------------------------------------
Player::~Player()
{

}

//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
//= @brief �X�e�[�^�X�����߂�
//=
//= @param[in] �e�\��
//=
//= @return �X�e�[�^�X�l
//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
void Player::PlayerMove(Player* player, float dir)
{
	//�L�[���͏���
	if (g_keyTracker->lastState.Right)
	{
		if (player->GetPosX() <= SCREEN_WIDTH)
		{
			player->SetSpdX(dir);
			player->SetSpdY(0);
		}
		else
		{
			player->SetSpdX(0);
			player->SetSpdY(0);

		}
	}
	else if (g_keyTracker->lastState.Left)
	{
		if (player->GetPosX() >= 0)
		{
			player->SetSpdX(-dir);
			player->SetSpdY(0);
		}
		else
		{
			player->SetSpdX(0);
			player->SetSpdY(0);

		}

	}
	else if (g_keyTracker->lastState.Up)
	{
		if (player->GetPosY() >= 0)
		{
			player->SetSpdY(-dir);
			player->SetSpdX(0);
		}
		else
		{
			player->SetSpdX(0);
			player->SetSpdY(0);

		}

	}
	else if (g_keyTracker->lastState.Down)
	{
		if (player->GetPosY() <= SCREEN_HEIGHT)
		{
			player->SetSpdY(dir);
			player->SetSpdX(0);
		}
		else
		{
			player->SetSpdX(0);
			player->SetSpdY(0);

		}
	}
	else
	{
		//���x�O
		player->SetSpdX(0);
		player->SetSpdY(0);
	}
}

//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
//= @brief �X�e�[�^�X�����߂�
//=
//= @param[in] �e�\��
//=
//= @return �X�e�[�^�X�l
//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
void Player::PlayerDeath(PBullet* collender)
{
	if (collender->distinction() == true)
	{
		m_lives--;

		if (m_lives == 0)
		{
			g_NextScene = OVER;
		}
	}
}
