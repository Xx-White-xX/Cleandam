//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.h
//!
//! @brief  �Q�[���֘A�̃w�b�_�t�@�C��
//!
//! @date   2016/12/12
//!
//! @author T.ichioka
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

#include "GameBase.h"
#include "Enemy.h"
#include "Stage.h"
#include "Boss.h"
#include "Bullet.h"
#include "Player.h"

#include "Player.h"
#include "Funnel.h"

class GamePlay :public GameBase
{
private:

	Enemy** enemy;
	Stage* stage;
	Boss* boss;

	Player* player;
	
	Funnel** funnel;

	int a;

	int funnel_cnt;

	//�G�̐�
	int enemy_count;

	//���@�̐�
	int m_Life;

	int m_BossLife;

public:
	GamePlay();
	~GamePlay();
	int Update();
	void Render();

	void EnemyLost(int number);

	void EnemyCreate(int number);
};
