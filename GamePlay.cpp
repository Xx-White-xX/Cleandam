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
GamePlay::GamePlay()
{
	Vector2 pos;
	Vector2 pos2;

	pos.x = 0;
	pos.y = 0;
	pos2.x = 400;
	pos2.y = 150;

	enemy = new Enemy(pos);

	stage = new Stage(pos);

	boss = new Boss(pos2);

	


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

	stage->Move();

	//boss->move();

	if (g_keyTracker->pressed.Space)
	{
		return  CLEAR;
	}
	
	if (g_keyTracker->pressed.A)
	{
		return OVER;
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
	enemy->Render();

	stage->Render();

	boss->Render();
}