//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Player.h
//!
//! @brief  �v���C�C���[�����̃w�b�_�t�@�C��
//!
//! @date   2017/04/07
//!
//! @author Shuta Furukawa	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//���d�C���N���[�h�̖h�~
#pragma once

//�w�b�_�t�@�C���̃C���N���[�h
#include "GameBase.h"
#include "ObjectBase.h"
#include "Player.h"


class Bit : public ObjectBase
{
private:
	//���[�h�̏��
	bool m_modeFlag;
	//�r�b�g�̂͂��ޔ���
	bool m_sund;

public:
	//�R���X�g���N�^
	Bit();
	//�f�X�g���N�^
	~Bit();

	//�r�b�g�̈ړ�����
	void BitMove(Bit* bits, Player* player, float dir);
	//���[�h�`�F���W�ɂ����W�ύX
	void ChengePos();
	//�r�b�g�̂͂��ޏ���
	void Sandwich();
};
