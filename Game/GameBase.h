//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameBase.h
//!
//! @brief  ��{�N���X�̃w�b�_�t�@�C��
//!
//! @date   2016/12/12
//!
//! @author T.ichioka
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

class GameBase
{
public:
	virtual ~GameBase() {}
	virtual int Update() = 0;
	virtual void Render() = 0;

private:

};