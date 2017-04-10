//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Player.h
//!
//! @brief  プレイイヤー処理のヘッダファイル
//!
//! @date   2017/04/07
//!
//! @author Shuta Furukawa	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//多重インクルードの防止
#pragma once

//ヘッダファイルのインクルード
#include "GameBase.h"
#include "ObjectBase.h"
#include "Player.h"


class Bit : public ObjectBase
{
private:
	//モードの状態
	bool m_modeFlag;
	//ビットのはさむ判定
	bool m_sund;

public:
	//コンストラクタ
	Bit();
	//デストラクタ
	~Bit();

	//ビットの移動処理
	void BitMove(Bit* bits, Player* player, float dir);
	//モードチェンジによる座標変更
	void ChengePos();
	//ビットのはさむ処理
	void Sandwich();
};
