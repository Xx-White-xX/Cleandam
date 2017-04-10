//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.cpp
//!
//! @brief  �Q�[���v���C�����̃\�[�X�t�@�C��
//!
//! @date   ���t		
//!
//! @author ����Җ�	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GamePlay.h"
using namespace DirectX::SimpleMath;
using namespace DirectX;
//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
GamePlay::GamePlay():
	enemy_count(0)
{
	Vector2 pos;

	pos.x = 360;
	pos.y = 240;

	enemy = new Enemy(pos);
}

//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
GamePlay::~GamePlay()
{
	delete enemy;
}

//----------------------------------------------------------------------
//! @brief �Q�[���v���C����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
int GamePlay::Update(void)
{
	enemy->Move();

	if (enemy->GetPosX() == 120)
	{
		int randm =0;

		//randm = rand() % 2;
		{
			if (randm == 0)
			{
				enemy->ChangeMobe();
			}
		}
	}

	//if (g_keyTracker->pressed.Space)
	//{
	//	return  CLEAR;
	//}
	//
	//if (g_keyTracker->pressed.A)
	//{
	//	return OVER;
	//}

	return PLAY;
}



//----------------------------------------------------------------------
//! @brief �Q�[���v���C�`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void GamePlay::Render(void)
{
	//�����ŕ`��
	enemy->Render();

	if (g_keyTracker->released.Space)
	{
		enemy->Shot();
	}

	if (enemy->GoShot() == true)
	{
		enemy->on();
		enemy->BulletMove();
	}

	//������
	if (enemy->GoShot() == true)
	{
		enemy->Lost();
	}
}



int collston(Enemy* enemy , OBJECT B)
{
	float x1 = enemy->GetPosX() + (enemy->GetGrpW() / 2);		//���S���Wx
	float y1 = enemy->GetPosY() + (enemy->GetGrpH() / 2);		//���S���Wy
	float x2 = B.pos_x + (B.grp_w / 2);
	float y2 = B.pos_y + (B.grp_h / 2);

	float r1 = A.grp_w / 2;
	float r2 = B.grp_w / 2;

	if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) <= (r1 + r2)*(r1 + r2))
	{
		return 1;
	}
	return 0;
}