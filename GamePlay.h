//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.h
//!
//! @brief  �Q�[���v���C�̃w�b�_�t�@�C��
//!
//! @date   ���t
//!
//! @author ����Җ�	�㓡���l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once


#include "GameBase.h"

#include "../Enemy.h"
#include "../Stage.h"
#include "../Boss.h"
#include "../Bullet.h"
#include "Player.h"
#include "Bullet.h"
#include "Item.h"
#include "Funnel.h"
#include "Enemy.h"

#define MAX_BULLET 30

class GamePlay :public GameBase
{
private:
	int cnt;				// �J�E���^
	int bullet_shot_cnt;	// �e����^�C�~���O�̕ϐ��𑝉��J�E���^
	int bullet_cllas_cnt;	// �e�̎�ނ̃J�E���^

	int a;

	int funnel_cnt;

	Player* player;
	Item* item;
	Bullet** bullet;
	Bullet** bullet_up;
	Bullet** bullet_down;

	Funnel** funnel;

	Enemy* enemy;


	int enemy_count;

public:
	GamePlay();		// �R���X�g���N�^
	~GamePlay();	// �f�X�g���N�^

	void Update();
	void Render();

};
