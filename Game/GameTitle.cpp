//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitle.cpp
//!
//! @brief  �^�C�g�������̃\�[�X�t�@�C��
//!
//! @date   ���t		
//!
//! @author ����Җ�	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GameTitle.h"
//#include "..\ADX2Le.h"
//#include "CueSheet_0.h"

#pragma comment(lib, "cri_ware_pcx86_LE_import.lib")
using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
GameTitle::GameTitle()
{
	Vector2 pos;

	pos.x = 0;
	pos.y = 0;

	title = new image(pos);
}

//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
GameTitle::~GameTitle()
{
	delete title;
}

//----------------------------------------------------------------------
//! @brief �^�C�g������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
int GameTitle::Update(void)
{
	if (g_keyTracker->pressed.Space)
	{
		return PLAY;
	}

	return TITLE;
}

//----------------------------------------------------------------------
//! @brief �^�C�g���`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void GameTitle::Render(void)
{
	swprintf_s(buf, L"Title");
	g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(0, 20));

	title->Render();
}