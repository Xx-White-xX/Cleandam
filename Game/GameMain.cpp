//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  �Q�[���֘A�̃\�[�X�t�@�C��
//!
//! @date   ���t		
//!
//! @author ����Җ�	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#define _GAMEMAIN_
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "GameMain.h"

#include "GameClear.h"
#include "GameLogo.h"
#include "GameOver.h"
#include "GamePlay.h"
#include "GameTitle.h"
#include "GameBase.h"
using namespace std;


#pragma comment(lib, "cri_ware_pcx86_LE_import.lib")

using namespace DirectX::SimpleMath;
using namespace DirectX;

// �֐��̒�` ==============================================================

GameMain::GameMain()
	:m_scene(0)
	, m_nextScene(0)
{

}

GameMain::~GameMain()
{
	delete m_base;
}

//----------------------------------------------------------------------
//! @brief �Q�[���̏���������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void GameMain::InitializeGame(void)
{
	srand(static_cast<unsigned int>(time(nullptr)));

	m_base = new GamePlay();

	//m_scene = LOGO;
}



//----------------------------------------------------------------------
//! @brief �Q�[���̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
bool GameMain::UpdateGame(void)
{
	//ADX2Le::Update();

	//�V�[���Ǘ�
	if (m_nextScene != m_scene)
	{
		m_scene = m_nextScene;

		delete m_base;

		//�V�[�����Ƃ̌Ăяo��
		switch (m_scene)
		{
		case LOGO:
			m_base = new GameLogo();
			break;

		case TITLE:
			m_base = new GameTitle();
			break;

		case PLAY:
			m_base = new GamePlay();
			break;

		case CLEAR:
			m_base = new GameClear();
			break;

		case OVER:
			m_base = new GameOver();
			break;
		}
	}

	m_nextScene = m_base->Update();

	m_key_old = m_key_code;

	return true;
}



//----------------------------------------------------------------------
//! @brief �Q�[���̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void GameMain::RenderGame(void)
{
	m_base->Render();
}



//----------------------------------------------------------------------
//! @brief �Q�[���̏I������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void GameMain::FinalizeGame(void)
{

}