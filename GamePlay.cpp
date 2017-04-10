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
#include "../Player.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

bool collston(Enemy* enemy, Funnel* funnel1, Funnel* funnel2);
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
	if (enemy != nullptr)
	{
		enemy->Move();

		if (enemy->GetPosX() == 120)
		{
			int randm = 0;

			randm = rand() % 2;

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

		enemy->BulletDown();

		//�t�@���l����A��������
		if (/*(collston(enemy, funnnel[0], funnnel[1]) == true) ||*/
			(enemy->GetPosX() <= 0) ||
			(enemy->GetPosX() >= 640))
		{
			EnemyLost();
		}
	}

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
	if (enemy != nullptr)
	{
		//�����ŕ`��
		enemy->Render();

		enemy->Shot();

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
}

void GamePlay::EnemyCreate()
{
	Vector2 enemypos;

	enemypos.x = 0;
	enemypos.y = 0;

	enemy = new Enemy(enemypos);
}

void GamePlay::EnemyLost()
{
	enemy = nullptr;
	delete enemy;
}



bool collston(Enemy* enemy , Funnel* funnel0, Funnel* funnel1)
{
	if ((funnel0->GetPosY() + funnel0->GetGrpW() == enemy->GetSpdY() && funnel0->GetPosX() <= enemy->GetPosX() && funnel0->GetPosX() + funnel0->GetGrpW() >= enemy->GetPosX()) &&
		(funnel1->GetPosY() == enemy->GetPosY() + enemy->GetGrpH() && funnel1->GetPosX() <= enemy->GetPosX() && funnel1->GetPosX() + funnel1->GetGrpW() >= enemy->GetPosX()))
	{
		return true;
	}

	return false;
}