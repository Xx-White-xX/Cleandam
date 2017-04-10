//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.h
//!
//! @brief  �Q�[���֘A�̃w�b�_�t�@�C��
//!
//! @date   ���t
//!
//! @author ����Җ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

#include <Windows.h>
#include <d3d11.h>
#include <SimpleMath.h>
#include <iostream>
#include <string>
#include "../DirectXTK.h"
#include "Texture.h"
#include "GameBase.h"

#ifndef _GAMEMAIN_
#define EXTERN extern
#else
#define EXTERN
#endif



// �萔�̒�` ==============================================================

// �Q�[���^�C�g��
#define GAME_TITLE "thousand"

// �Q�[�����
#define SCREEN_WIDTH  640    // ��[pixel]
#define SCREEN_HEIGHT 480    // ����[pixel]

					//�@�񋓌^�錾
enum SCENE
{
	LOGO,
	TITLE,
	PLAY,
	CLEAR,
	OVER
};

// �O���[�o���ϐ��̐錾 ====================================================
EXTERN Texture* g_enemy;

EXTERN int g_init;				//�������Ǘ�


class GameMain
{
protected:

	GameBase* m_base;	//�Q�[���x�[�X

	int m_nextScene;	//���̃V�[��
	int m_scene;		//���̃V�[��

	int m_key_code;			//�L�[���
	int m_key_old;			//�O�t���[���̃L�[���

public:
	GameMain();
	~GameMain();
	// �֐��̐錾 ==============================================================
	// �Q�[���̏�����
	void InitializeGame(void);

	// �Q�[���̍X�V
	bool UpdateGame(void);

	// �Q�[���̕`��
	void RenderGame(void);

	// �Q�[���̏I��
	void FinalizeGame(void);
};