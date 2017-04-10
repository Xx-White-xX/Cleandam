//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.cpp
//!
//! @brief  �Q�[���v���C�����̃\�[�X�t�@�C��
//!
//! @date   ���t		
//!
//! @author ����Җ�	�㓡���l	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GamePlay.h"
#include "GameStageSelect.h"

#include "..\ADX2Le.h"
#include "CueSheet_0.h"

#include <ctime>

#pragma comment(lib,"cri_ware_pcx86_LE_import.lib")

using namespace DirectX::SimpleMath;
using namespace DirectX;


//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//----------------------------------------------------------------------
GamePlay::GamePlay()
{
	// �v���C���[
	player = new Player();

	item = new Item();

	bullet = new Bullet*[MAX_BULLET];
	bullet_up = new Bullet*[MAX_BULLET];
	bullet_down = new Bullet*[MAX_BULLET];


	for (cnt = 0; cnt < MAX_BULLET; cnt++)
	{
		bullet[cnt] = new Bullet(player->GetPosX(), player->GetPosY());
		bullet_up[cnt] = new Bullet(player->GetPosX(), player->GetPosY());
		bullet_down[cnt] = new Bullet(player->GetPosX(), player->GetPosY());
	}


	funnel = new Funnel*[2];


	funnel[0] = new Funnel(player->GetPosX() - 20.0f, player->GetPosY() - 30.0f);
	funnel[1] = new Funnel(player->GetPosX() - 20.0f, player->GetPosY() + 30.0f);

	enemy = new Enemy();


	bullet_cllas_cnt = 0;

	bullet_shot_cnt = 0;

	a = 0;

	funnel_cnt = 0;

}




//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//----------------------------------------------------------------------
GamePlay::~GamePlay()
{
	delete player;
	delete item;
	for (int i = 0; i < MAX_BULLET; i++)
	{
		delete bullet[i];
		delete bullet_up[i];
		delete bullet_down[i];
	}

	for (int i = 0; i < 2; i++)
	{
		delete funnel[i];
	}

	delete enemy;
}


//----------------------------------------------------------------------
//! @brief �Q�[���v���C����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------

void GamePlay::Update(void)
{
	// rand���g���̂ŕK�v
	srand(static_cast<unsigned int>(time(nullptr)));


	player->Update();
	item->Update();
	enemy->Update();
	for (cnt = 0; cnt < MAX_BULLET; cnt++)
	{
		bullet[cnt]->Update();
		bullet_up[cnt]->Update();
		bullet_down[cnt]->Update();
	}

	for (int i = 0; i < 2; i++)
	{
		funnel[i]->Update();
	}
	
	if (a == 0)
	{
		if (g_keyTracker->pressed.C)
		{
			funnel[0]->SetSpdX(8);
			funnel[1]->SetSpdX(8);
			funnel[0]->SetSpdY(-1);
			funnel[1]->SetSpdY(1);
			a = 1;

		}
	}
	if (funnel[0]->GetPosX()>player->GetPosX()+100.0f&&
		funnel[1]->GetPosX()>player->GetPosX() + 100.0f&&
		a==1)
	{
		funnel[0]->SetSpdX(0);
		funnel[1]->SetSpdX(0);
		funnel[0]->SetSpdY(3);
		funnel[1]->SetSpdY(-3);
		
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

	if(funnel_cnt>=50&& funnel_cnt <= 99)
	{
		funnel[0]->SetSpdY(-1);
		funnel[1]->SetSpdY(1);
		
	}
	else if (funnel_cnt >= 100)
	{
		a = 0;
	}
	
	if(a==0)
	{
		funnel_cnt = 0;
		if (funnel[0]->GetPosX() > player->GetPosX() - 19&&
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


		if (funnel[0]->GetPosY() > player->GetPosY() - 29&&
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

		if (funnel[1]->GetPosY() > player->GetPosY() + 29&&
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

		if (funnel[1]->GetPosX() > player->GetPosX() - 19&&
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

	// space�L�[����������e�𔭎˂��鏈��
	if (g_key.Space)
	{
		bullet_shot_cnt++;// �e����^�C�~���O�̕ϐ��𑝉�

		///////////////////////////////////
		/////// �e��state��0���T�[�`///////
		///////////////////////////////////

		// �e�̎�ނ̃J�E���^��0�̎�
		if (bullet_cllas_cnt == 0 || bullet_cllas_cnt == 4)
		{
			for (cnt = 0; cnt < MAX_BULLET; cnt++)
			{
				if (bullet[cnt]->GetState() == 0)
				{
					break;
				}
			}
		}
		// �e�̎�ނ̃J�E���^��1��3�̎�
		else if (bullet_cllas_cnt == 1 || bullet_cllas_cnt == 3 || bullet_cllas_cnt == 5)
		{
			for (cnt = 0; cnt < MAX_BULLET; cnt++)
			{
				if (bullet[cnt]->GetState() == 0)
				{
					break;
				}
			}
			for (cnt = 0; cnt < MAX_BULLET; cnt++)
			{
				if (bullet_up[cnt]->GetState() == 0)
				{
					break;
				}
			}
			for (cnt = 0; cnt < MAX_BULLET; cnt++)
			{
				if (bullet_down[cnt]->GetState() == 0)
				{
					break;
				}
			}
		}
		// �e�̎�ނ̃J�E���^��2�̎�
		else if (bullet_cllas_cnt == 2)
		{
			for (cnt = 0; cnt < MAX_BULLET; cnt++)
			{
				if (bullet_up[cnt]->GetState() == 0)
				{
					break;
				}
			}
			for (cnt = 0; cnt < MAX_BULLET; cnt++)
			{
				if (bullet_down[cnt]->GetState() == 0)
				{
					break;
				}
			}
		}

		//////////////////////////////////


		 // �e�̐ݒ�
		if (cnt < MAX_BULLET)
		{
			// �e����^�C�~���O�̕ϐ���15�ȏ�̎�
			if (bullet_shot_cnt >= 15)
			{
				// �e�̎�ނ̃J�E���^��0�̎�
				if (bullet_cllas_cnt == 0)
				{
					// �e�̈ʒu���v���C���[�̑O�ɐݒ�
					bullet[cnt]->BulletPos(player->GetPosX(), player->GetPosY());
					bullet[cnt]->SetSpdX(8);		// X���W�̃X�s�[�h��8(��)
					bullet[cnt]->SetSpdY(0);
					bullet[cnt]->SetState(1);	// state��1(�\��)
					bullet_shot_cnt = 0;
				}
				// �e�̎�ނ̃J�E���^��1�̎�
				else if (bullet_cllas_cnt == 1)
				{
					// �e�̈ʒu���v���C���[�̑O�ɐݒ�
					bullet[cnt]->BulletPos(player->GetPosX(), player->GetPosY());
					bullet_up[cnt]->BulletPos(player->GetPosX(), player->GetPosY());
					bullet_down[cnt]->BulletPos(player->GetPosX(), player->GetPosY());

					bullet[cnt]->SetSpdX(8);		// X���W�̃X�s�[�h��8(��)
					bullet_up[cnt]->SetSpdX(8);		// X���W�̃X�s�[�h��8(��)
					bullet_down[cnt]->SetSpdX(8);		// X���W�̃X�s�[�h��8(��)

					bullet_up[cnt]->SetSpdY(-4);
					bullet_down[cnt]->SetSpdY(4);
					bullet[cnt]->SetSpdY(0);

					bullet[cnt]->SetState(1);	// state��1(�\��)
					bullet_up[cnt]->SetState(1);	// state��1(�\��)
					bullet_down[cnt]->SetState(1);	// state��1(�\��)


					bullet_shot_cnt = 0;
				}
				// �e�̎�ނ̃J�E���^��2�̎�
				else if (bullet_cllas_cnt == 2)
				{
					// �e�̈ʒu���t�@���l���̑O�ɐݒ�
					bullet_down[cnt]->BulletPos(funnel[0]->GetPosX(), funnel[0]->GetPosY());
					bullet_up[cnt]->BulletPos(funnel[1]->GetPosX(), funnel[1]->GetPosY());

					bullet_up[cnt]->SetSpdX(8);		// X���W�̃X�s�[�h��8(��)
					bullet_down[cnt]->SetSpdX(8);		// X���W�̃X�s�[�h��8(��)

					bullet_up[cnt]->SetSpdY(0);
					bullet_down[cnt]->SetSpdY(0);
					bullet[cnt]->SetSpdY(0);

					bullet_up[cnt]->SetState(1);	// state��1(�\��)
					bullet_down[cnt]->SetState(1);	// state��1(�\��)


					bullet_shot_cnt = 0;
				}
				// �e�̎�ނ̃J�E���^��3�̎�
				else if (bullet_cllas_cnt == 3)
				{
					// �e�̈ʒu���v���C���[�ƃt�@���l���̑O�ɐݒ�
					bullet[cnt]->BulletPos(player->GetPosX(), player->GetPosY());
					bullet_down[cnt]->BulletPos(funnel[0]->GetPosX(), funnel[0]->GetPosY());
					bullet_up[cnt]->BulletPos(funnel[1]->GetPosX(), funnel[1]->GetPosY());

					bullet[cnt]->SetSpdX(8);		// X���W�̃X�s�[�h��8(��)
					bullet_up[cnt]->SetSpdX(8);		// X���W�̃X�s�[�h��8(��)
					bullet_down[cnt]->SetSpdX(8);		// X���W�̃X�s�[�h��8(��)

					bullet_up[cnt]->SetSpdY(0);
					bullet_down[cnt]->SetSpdY(0);
					bullet[cnt]->SetSpdY(0);

					bullet[cnt]->SetState(1);	// state��1(�\��)
					bullet_up[cnt]->SetState(1);	// state��1(�\��)
					bullet_down[cnt]->SetState(1);	// state��1(�\��)


					bullet_shot_cnt = 0;
				}
				
			}
			// �e�̎�ނ̃J�E���^��4�̎�
			if (bullet_cllas_cnt == 4)
			{
				// �e����^�C�~���O�̕ϐ���40�ȏ�̎�
				if (bullet_shot_cnt >= 40)
				{
					// �e�̈ʒu���v���C���[�̑O�ɐݒ�
					bullet[cnt]->BulletPos(player->GetPosX(), player->GetPosY());
					bullet[cnt]->SetSpdX(3);		// X���W�̃X�s�[�h��8(��)
					bullet[cnt]->SetState(1);	// state��1(�\��)
					bullet_shot_cnt = 0;
				}
			}
			// �e�̎�ނ̃J�E���^��5�̎�
			else if (bullet_cllas_cnt == 5)
			{
				// �e����^�C�~���O�̕ϐ���40�ȏ�̎�
				if (bullet_shot_cnt >= 30)
				{
					// �e�̈ʒu���v���C���[�ƃt�@���l���̑O�ɐݒ�
					bullet[cnt]->BulletPos(player->GetPosX(), player->GetPosY());
					bullet_down[cnt]->BulletPos(funnel[0]->GetPosX(), funnel[0]->GetPosY());
					bullet_up[cnt]->BulletPos(funnel[1]->GetPosX(), funnel[1]->GetPosY());

					bullet[cnt]->SetSpdX(10);		// X���W�̃X�s�[�h��8(��)
					bullet_up[cnt]->SetSpdX(18);		// X���W�̃X�s�[�h��8(��)
					bullet_down[cnt]->SetSpdX(18);		// X���W�̃X�s�[�h��8(��)

					bullet_up[cnt]->SetSpdY(6);
					bullet_down[cnt]->SetSpdY(-6);
					bullet[cnt]->SetSpdY(0);

					bullet[cnt]->SetState(1);	// state��1(�\��)
					bullet_up[cnt]->SetState(1);	// state��1(�\��)
					bullet_down[cnt]->SetState(1);	// state��1(�\��)


					bullet_shot_cnt = 0;
				}
			}
		}
	}
	

	// �e�X�g�pA�L�[�������ƃA�C�e����\������
	if (g_keyTracker->pressed.A)
	{
		item->SetState(1);
	}

	// �z�[�~���O�e�̏���
	if (bullet_cllas_cnt == 4)
	{
		for (cnt = 0; cnt < MAX_BULLET; cnt++)
		{
			if (bullet[cnt]->GetPosY() < enemy->GetPosY())
			{
				bullet[cnt]->SetSpdY(1.5f);
			}
			else if (bullet[cnt]->GetPosY() > enemy->GetPosY())
			{
				bullet[cnt]->SetSpdY(-1.5f);
			}
		}
	}

	// �悭�킩��Ȃ��e�̏���
	if (bullet_cllas_cnt == 5)
	{
		for (cnt = 0; cnt < MAX_BULLET; cnt++)
		{
			if (bullet_up[cnt]->GetPosX() >= player->GetPosX() + 50.0f&&
				bullet_up[cnt]->GetPosX() <= player->GetPosX() + 99.0f)
			{
				bullet_up[cnt]->SetSpdY(-8);
				bullet_up[cnt]->SetSpdX(4);
			}
			else if (bullet_up[cnt]->GetPosX() >= player->GetPosX() + 100.0f&&
				bullet_up[cnt]->GetPosX() <= player->GetPosX() + 149.0f)
			{
				bullet_up[cnt]->SetSpdY(2);
				bullet_up[cnt]->SetSpdX(2);
			}
			else if (bullet_up[cnt]->GetPosX() >= player->GetPosX() + 150.0f)
			{
				bullet_up[cnt]->SetSpdY(-1);
				bullet_up[cnt]->SetSpdX(10);
			}

			if (bullet_down[cnt]->GetPosX() >= player->GetPosX() + 50.0f&&
				bullet_down[cnt]->GetPosX() <= player->GetPosX() + 99.0f)
			{
				bullet_down[cnt]->SetSpdY(8);
				bullet_down[cnt]->SetSpdX(4);
			}
			else if (bullet_down[cnt]->GetPosX() >= player->GetPosX() + 100.0f&&
				bullet_down[cnt]->GetPosX() <= player->GetPosX() + 149.0f)
			{
				bullet_down[cnt]->SetSpdY(-2);
				bullet_down[cnt]->SetSpdX(2);
			}
			else if (bullet_down[cnt]->GetPosX() >= player->GetPosX() + 150.0f)
			{
				bullet_down[cnt]->SetSpdY(1);
				bullet_down[cnt]->SetSpdX(10);
			}
		}
	}

	
	// �e�����̂Ƃ���܂Ői�ނƏ����鏈��
	for (cnt = 0; cnt < MAX_BULLET; cnt++)
	{
		bullet[cnt]->LostBullet();
		bullet_up[cnt]->LostBullet();
		bullet_down[cnt]->LostBullet();
	}

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
		player->SetGrpX(96);
	}
	else if (g_key.Left)
	{
		player->SetSpdX(-4);
		player->SetGrpX(64);
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
		player->SetGrpX(0);
	}
	else if (g_key.Down)
	{
		player->SetGrpX(32);
		player->SetSpdY(4);
	}
	else
	{
		player->SetSpdY(0);
	}

	// �e�X�g�p�G�̈ړ�
	if (enemy->GetPosY() <= 100.0f)
	{
		enemy->SetSpdY(3);
	}
	else if (enemy->GetPosY() >= 400.0f)
	{
		enemy->SetSpdY(-3);
	}


	///////////////////////////////////
	///////	   �����蔻�菈��   ///////
	///////////////////////////////////
	// �v���C���[�ƃA�C�e���̓����蔻��
	if (player->GetState() == 1 && item->GetState() == 1)
	{
		if (player->GetPosX() - (player->GetGrpW() / 2) <= item->GetPosX() + (item->GetGrpW() / 2) &&
			player->GetPosX() + (player->GetGrpW() / 2) >= item->GetPosX() - (item->GetGrpW() / 2) &&
			player->GetPosY() - (player->GetGrpH() / 2) <= item->GetPosY() + (item->GetGrpH() / 2) &&
			player->GetPosY() + (player->GetGrpH() / 2) >= item->GetPosY() - (item->GetGrpH() / 2))
		{
			item->SetState(0);				// state��0(��\��)
			bullet_cllas_cnt = rand() % 6;	// �e�̎�ނ������_���ŕω�
		}
	}

	// �e�ƃA�C�e���̓����蔻��
	for (cnt = 0; cnt < MAX_BULLET; cnt++)
	{
		// �ʏ�̒e
		if (bullet[cnt]->GetState() == 1 && item->GetState() == 1)
		{
			if (bullet[cnt]->GetPosX() - (bullet[cnt]->GetGrpW() / 2) <= item->GetPosX() + (item->GetGrpW() / 2) &&
				bullet[cnt]->GetPosX() + (bullet[cnt]->GetGrpW() / 2) >= item->GetPosX() - (item->GetGrpW() / 2) &&
				bullet[cnt]->GetPosY() - (bullet[cnt]->GetGrpH() / 2) <= item->GetPosY() + (item->GetGrpH() / 2) &&
				bullet[cnt]->GetPosY() + (bullet[cnt]->GetGrpH() / 2) >= item->GetPosY() - (item->GetGrpH() / 2))
			{
				bullet[cnt]->SetState(0);
			}
		}

		// �A�C�e���Œǉ������e
		if (bullet_up[cnt]->GetState() == 1 && item->GetState() == 1)
		{
			if (bullet_up[cnt]->GetPosX() - (bullet_up[cnt]->GetGrpW() / 2) <= item->GetPosX() + (item->GetGrpW() / 2) &&
				bullet_up[cnt]->GetPosX() + (bullet_up[cnt]->GetGrpW() / 2) >= item->GetPosX() - (item->GetGrpW() / 2) &&
				bullet_up[cnt]->GetPosY() - (bullet_up[cnt]->GetGrpH() / 2) <= item->GetPosY() + (item->GetGrpH() / 2) &&
				bullet_up[cnt]->GetPosY() + (bullet_up[cnt]->GetGrpH() / 2) >= item->GetPosY() - (item->GetGrpH() / 2))
			{
				bullet_up[cnt]->SetState(0);
			}
		}
		if (bullet_down[cnt]->GetState() == 1 && item->GetState() == 1)
		{
			if (bullet_down[cnt]->GetPosX() - (bullet_down[cnt]->GetGrpW() / 2) <= item->GetPosX() + (item->GetGrpW() / 2) &&
				bullet_down[cnt]->GetPosX() + (bullet_down[cnt]->GetGrpW() / 2) >= item->GetPosX() - (item->GetGrpW() / 2) &&
				bullet_down[cnt]->GetPosY() - (bullet_down[cnt]->GetGrpH() / 2) <= item->GetPosY() + (item->GetGrpH() / 2) &&
				bullet_down[cnt]->GetPosY() + (bullet_down[cnt]->GetGrpH() / 2) >= item->GetPosY() - (item->GetGrpH() / 2))
			{
				bullet_down[cnt]->SetState(0);
			}
		}
	}

	// �e�ƓG�̓����蔻��
	for (cnt = 0; cnt < MAX_BULLET; cnt++)
	{
		// �ʏ�̒e
		if (bullet[cnt]->GetState() == 1)
		{
			if (bullet[cnt]->GetPosX() - (bullet[cnt]->GetGrpW() / 2) <= enemy->GetPosX() + (enemy->GetGrpW() / 2) &&
				bullet[cnt]->GetPosX() + (bullet[cnt]->GetGrpW() / 2) >= enemy->GetPosX() - (enemy->GetGrpW() / 2) &&
				bullet[cnt]->GetPosY() - (bullet[cnt]->GetGrpH() / 2) <= enemy->GetPosY() + (enemy->GetGrpH() / 2) &&
				bullet[cnt]->GetPosY() + (bullet[cnt]->GetGrpH() / 2) >= enemy->GetPosY() - (enemy->GetGrpH() / 2))
			{
				bullet[cnt]->SetState(0);
			}
		}

		// �A�C�e���Œǉ������e
		if (bullet_up[cnt]->GetState() == 1)
		{
			if (bullet_up[cnt]->GetPosX() - (bullet_up[cnt]->GetGrpW() / 2) <= enemy->GetPosX() + (enemy->GetGrpW() / 2) &&
				bullet_up[cnt]->GetPosX() + (bullet_up[cnt]->GetGrpW() / 2) >= enemy->GetPosX() - (enemy->GetGrpW() / 2) &&
				bullet_up[cnt]->GetPosY() - (bullet_up[cnt]->GetGrpH() / 2) <= enemy->GetPosY() + (enemy->GetGrpH() / 2) &&
				bullet_up[cnt]->GetPosY() + (bullet_up[cnt]->GetGrpH() / 2) >= enemy->GetPosY() - (enemy->GetGrpH() / 2))
			{
				bullet_up[cnt]->SetState(0);
			}
		}
		if (bullet_down[cnt]->GetState() == 1 )
		{
			if (bullet_down[cnt]->GetPosX() - (bullet_down[cnt]->GetGrpW() / 2) <= enemy->GetPosX() + (enemy->GetGrpW() / 2) &&
				bullet_down[cnt]->GetPosX() + (bullet_down[cnt]->GetGrpW() / 2) >= enemy->GetPosX() - (enemy->GetGrpW() / 2) &&
				bullet_down[cnt]->GetPosY() - (bullet_down[cnt]->GetGrpH() / 2) <= enemy->GetPosY() + (enemy->GetGrpH() / 2) &&
				bullet_down[cnt]->GetPosY() + (bullet_down[cnt]->GetGrpH() / 2) >= enemy->GetPosY() - (enemy->GetGrpH() / 2))
			{
				bullet_down[cnt]->SetState(0);
			}
		}
	}

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
	// �v���C���[
	if (player->GetState() == 1)
	{
		player->Render();
	}


	if (item->GetState() == 1)
	{
		item->Render();
	}

	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (bullet[i]->GetState() == 1)
		{
			bullet[i]->Render();
		}

		if (bullet_up[i]->GetState() == 1)
		{
			bullet_up[i]->Render();
		}

		if (bullet_down[i]->GetState() == 1)
		{
			bullet_down[i]->Render();
		}
	}


	for (int i = 0; i < 2; i++)
	{
		if (funnel[i]->GetState() == 1)
		{
			funnel[i]->Render();
		}
	}


	enemy->Render();

}


