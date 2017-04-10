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

bool collston(Enemy* enemy, Funnel* funnel0, Funnel* funnel1);
bool collston(Boss* boss, Funnel* funnel0, Funnel* funnel1);
bool collston(Player* player, Enemy* enemy);
bool collstonShot(Player* player, Enemy* enemy);
bool collstonShot(Player* player, Boss* boss);
//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
GamePlay::GamePlay()
	: enemy_count(50)
	, m_Life(3)
	, m_BossLife(100)
{

	enemy = new Enemy*[5];

	for (int i = 0; i < 5; i++)
	{
		Vector2 pos;
	
		pos.x = rand() % 300 + 300;
		pos.y = rand() % 480 - 32;
	
		enemy[i] = new Enemy(pos);
	}
	
	Vector2 pos2;
	pos2.x = 0;
	pos2.y = 0;

	stage = new Stage(pos2);


	Vector2 pos3;
	pos3.x = 360;
	pos3.y = 240;

	boss = new Boss(pos3);

	player = new Player();

	funnel = new Funnel*[2];

	funnel[0] = new Funnel(player->GetPosX() - 20.0f, player->GetPosY() - 30.0f);
	funnel[1] = new Funnel(player->GetPosX() - 20.0f, player->GetPosY() + 30.0f);

	a = 0;

	funnel_cnt = 0;
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
	
	for (int i = 0; i < 5; i++)
	{
		delete enemy[i];
	}
	delete[] enemy;

	delete stage;

	delete boss;

	for (int i = 0; i < 2; i++)
	{
		delete funnel[i];
	}

	delete[] funnel;

	delete player;
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
	stage->Move();

	if (enemy_count != 0)
	{
		//�G�l�~�[�̏���
		for (int i = 0; i < 5; i++)
		{
			if (enemy[i] != nullptr)
			{
				enemy[i]->Move();

				//�����G�l�~�[�����̏ꏊ�ɂ����Ȃ�
				if (enemy[i]->GetPosX() == 120)
				{
					int randm = 0;

					randm = rand() % 2;

					//�����_�����O�Ȃ��ނ���
					if (randm == 0)
					{
						//��ނ���
						enemy[i]->ChangeMobe();
					}
				}

				//��ʊO�ɂ��G�l�~�[�̍폜
				if ((enemy[i]->GetPosX() <= 0 - 32) ||
					(enemy[i]->GetPosX() >= 640))
				{
					EnemyLost(i);
				}
			}
			else
			{
				EnemyCreate(i);
			}
		}
	}


	for (int i = 0; i < 5; i++)
	{
		if (enemy[i] != nullptr)
		{
			if (collston(player, enemy[i]) == true)
			{
				m_Life--;
			}
		}
	}

	//�v���C���[�����֘A
	player->Update();

	for (int i = 0; i < 2; i++)
	{
		funnel[i]->Update();
	}

	if (a == 0)
	{
		if (g_keyTracker->pressed.Space)
		{
			funnel[0]->SetSpdX(8);
			funnel[1]->SetSpdX(8);
			funnel[0]->SetSpdY(-1);
			funnel[1]->SetSpdY(1);
			a = 1;

		}
	}
	if (funnel[0]->GetPosX()>player->GetPosX() + 100.0f&&
		funnel[1]->GetPosX()>player->GetPosX() + 100.0f&&
		a == 1)
	{
		funnel[0]->SetSpdX(0);
		funnel[1]->SetSpdX(0);
		funnel[0]->SetSpdY(3);
		funnel[1]->SetSpdY(-3);

		for (int i = 0; i < 5; i++)
		{
			if (enemy[i] != nullptr)
			{
				if (collston(enemy[i], funnel[0], funnel[1]) == true)
				{
					EnemyLost(i);
					enemy_count--;
				}
			}
		}

	}

	if (funnel[0]->GetPosX() - (funnel[0]->GetGrpW() / 2) <= funnel[1]->GetPosX() + (funnel[1]->GetGrpW() / 2) &&
		funnel[0]->GetPosX() + (funnel[0]->GetGrpW() / 2) >= funnel[1]->GetPosX() - (funnel[1]->GetGrpW() / 2) &&
		funnel[0]->GetPosY() - (funnel[0]->GetGrpH() / 2) <= funnel[1]->GetPosY() + (funnel[1]->GetGrpH() / 2) &&
		funnel[0]->GetPosY() + (funnel[0]->GetGrpH() / 2) >= funnel[1]->GetPosY() - (funnel[1]->GetGrpH() / 2))
	{
		funnel[0]->SetSpdY(0);
		funnel[1]->SetSpdY(0);
		funnel[0]->SetSpdX(0);
		funnel[1]->SetSpdX(0);
		a = 2;
	}


	if (a == 2)
	{
		funnel_cnt++;
	}

	if (funnel_cnt >= 50 && funnel_cnt <= 99)
	{
		funnel[0]->SetSpdY(-1);
		funnel[1]->SetSpdY(1);

	}
	else if (funnel_cnt >= 100)
	{
		a = 0;
	}

	if (a == 0)
	{
		funnel_cnt = 0;
		if (funnel[0]->GetPosX() > player->GetPosX() - 19 &&
			funnel[0]->GetPosX() < player->GetPosX() - 21)
		{
			funnel[0]->SetSpdX(player->GetSpdX());
		}
		else if (funnel[0]->GetPosX() > player->GetPosX() - 18)
		{
			funnel[0]->SetSpdX(-4);
		}
		else if (funnel[0]->GetPosX() < player->GetPosX() - 22)
		{
			funnel[0]->SetSpdX(4);
		}
		else
		{
			funnel[0]->SetSpdX(player->GetSpdX());
		}


		if (funnel[0]->GetPosY() > player->GetPosY() - 29 &&
			funnel[0]->GetPosY() < player->GetPosY() - 31)
		{
			funnel[0]->SetSpdY(player->GetSpdY());
		}
		else if (funnel[0]->GetPosY() > player->GetPosY() - 28)
		{
			funnel[0]->SetSpdY(-4);
		}
		else if (funnel[0]->GetPosY() < player->GetPosY() - 32)
		{
			funnel[0]->SetSpdY(4);
		}
		else
		{
			funnel[0]->SetSpdY(player->GetSpdY());
		}

		if (funnel[1]->GetPosY() > player->GetPosY() + 29 &&
			funnel[1]->GetPosY() < player->GetPosY() + 31)
		{
			funnel[1]->SetSpdY(player->GetSpdY());
		}
		else if (funnel[1]->GetPosY() > player->GetPosY() + 28)
		{
			funnel[1]->SetSpdY(-4);
		}
		else if (funnel[1]->GetPosY() < player->GetPosY() + 32)
		{
			funnel[1]->SetSpdY(4);
		}
		else
		{
			funnel[1]->SetSpdY(player->GetSpdY());
		}

		if (funnel[1]->GetPosX() > player->GetPosX() - 19 &&
			funnel[1]->GetPosX() < player->GetPosX() - 21)
		{
			funnel[1]->SetSpdX(player->GetSpdX());
		}
		else if (funnel[1]->GetPosX() > player->GetPosX() - 18)
		{
			funnel[1]->SetSpdX(-4);
		}
		else if (funnel[1]->GetPosX() < player->GetPosX() - 22)
		{
			funnel[1]->SetSpdX(4);
		}
		else
		{
			funnel[1]->SetSpdX(player->GetSpdX());
		}

	}


	//// �t�@���l���͏�Ƀv���C���[�ɂ��Ă���
	//funnel[0]->FunnelPos(player->GetPosX() - 20.0f, player->GetPosY() - 30.0f);
	//funnel[1]->FunnelPos(player->GetPosX() - 20.0f, player->GetPosY() + 30.0f);

	///////////////////////////////////
	///////		  �ړ����� �@   ///////
	///////////////////////////////////

	// �v���C���[�̍��E�ړ�
	if (g_key.Right && g_key.Left)
	{
		player->SetSpdX(0);
	}
	else if (g_key.Right)
	{
		player->SetSpdX(4);
	}
	else if (g_key.Left)
	{
		player->SetSpdX(-4);
	}
	else
	{
		player->SetSpdX(0);
	}

	// �v���C���[�̏㉺�ړ�
	if (g_key.Up && g_key.Down)
	{
		player->SetSpdY(0);
	}
	else if (g_key.Up)
	{
		player->SetSpdY(-4);
	}
	else if (g_key.Down)
	{
		player->SetSpdY(4);
	}
	else
	{
		player->SetSpdY(0);
	}

	///////////////////////////////////
	///////	   �����蔻�菈��   ///////
	///////////////////////////////////
	
	//�I�[�o�[����
	if (m_Life == 0)
	{
		return OVER;
	}

	//�N���A����
	if (boss == nullptr)
	{
		return CLEAR;
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
	stage->Render();

	if (enemy_count != 0)
	{
		for (int i = 0; i < 5; i++)
		{
			//�G��null�ł͂Ȃ��̂�Ȃ�
			if (enemy[i] != nullptr)
			{
				//�G��`��
				enemy[i]->Render();

				//�e�̎��Ԃ�������
				if (enemy[i]->BulletTime() == true && enemy[i]->GoShot() == false)
				{
					enemy[i]->Shot();
				}

				if (enemy[i]->GoShot() == true)
				{
					enemy[i]->on();
					enemy[i]->BulletMove();

					if (collstonShot(player, enemy[i]) == true)
					{
						m_Life--;
					}
				}

				//������
				if (enemy[i]->GoShot() == true)
				{
					enemy[i]->Lost();
				}

			}
		}
	}

	//�G���S�ł����Ȃ�
	if (enemy_count == 0)
	{
		boss->Render();

		if (boss->BulletTime() == true)
		{
			boss->Shot();
		}

		if (boss->GoShot() == true)
		{
			boss->on();
			boss->BulletMove();

			if (collstonShot(player, boss) == true)
			{
				m_Life--;
			}
		}

		//������
		if (boss->GoShot() == true)
		{
			boss->Lost();
		}
	}
	
	if (player->GetState() == 1)
	{
		player->Render();
	}

	for (int i = 0; i < 2; i++)
	{
		if (funnel[i]->GetState() == 1)
		{
			funnel[i]->Render();
		}
	}
	
}

void GamePlay::EnemyLost(int number)
{
	enemy[number] = nullptr;
}

void GamePlay::EnemyCreate(int number)
{
	Vector2 enemypos;

	enemypos.x = 640;
	enemypos.y = rand() % 480 - 32;

	enemy[number] = new Enemy(enemypos);
}

//�t�@���l���̂����蔻��
bool collston(Enemy* enemy, Funnel* funnel0, Funnel* funnel1)
{
	if (funnel0->GetPosY() + funnel0->GetGrpW() == funnel1->GetPosY())
	{
		if (enemy->GetPosX() <= funnel0->GetPosX() + funnel0->GetGrpW())
		{
			if (enemy->GetPosX() + enemy->GetGrpW() >= funnel0->GetPosX())
			{
				return true;
			}
		}
	}
	return false;
}

bool collston(Boss* boss, Funnel* funnel0, Funnel* funnel1)
{
	if (funnel0->GetPosY() + funnel0->GetGrpW() == funnel1->GetPosY())
	{
		if (boss->GetPosX() <= funnel0->GetPosX() + funnel0->GetGrpW())
		{
			if (boss->GetPosX() + boss->GetGrpW() >= funnel0->GetPosX())
			{
				return true;
			}
		}
	}
	return false;
}

//�G�̒e�Ǝ��@�̂����蔻��
bool collston(Player* player,Enemy* enemy)
{
	if((player->GetPosX() <= enemy->GetPosX()+ enemy->GetGrpW()) &&
		(player->GetPosX() + player->GetGrpW() >= enemy->GetPosX()) &&
		(player->GetPosY() <= enemy->GetPosY() + enemy->GetGrpH()) &&
		(player->GetPosY() + player->GetGrpH() >= enemy->GetPosY()))
	{
		return true;
	}
	return false;
}

bool collstonShot(Player* player, Enemy* enemy)
{
	if ((player->GetPosX() <= enemy->PossPosX() + enemy->PossGrpW()) &&
		(player->GetPosX() + player->GetGrpW() >= enemy->PossPosX()) &&
		(player->GetPosY() <= enemy->PossPosY() + enemy->PossGrpH()) &&
		(player->GetPosY() + player->GetGrpH() >= enemy->PossPosY()))
	{
		return true;
	}
	return false;
}

bool collstonShot(Player* player, Boss* boss)
{
	for (int i = 0; i < 30; i++)
	{
		if ((player->GetPosX() <= boss->PossPosX(i) + boss->PossGrpW()) &&
			(player->GetPosX() + player->GetGrpW() >= boss->PossPosX(i)) &&
			(player->GetPosY() <= boss->PossPosY(i) + boss->PossGrpH()) &&
			(player->GetPosY() + player->GetGrpH() >= boss->PossPosY(i)))
		{
			return true;
		}
	}
	return false;
}