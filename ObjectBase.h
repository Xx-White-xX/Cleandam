#pragma once

#include "Texture.h"

class ObjectBase
{
protected:
	Texture *handle;	//グラフィックハンドル 
	int grp_x;		//元画像のｘ座標 
	int grp_y;		//元画像のｙ座標 
	int grp_w;		//元画像の幅 
	int grp_h;		//元画像の高さ 
	float pos_x;	//座標x 
	float pos_y;	//座標y 
	float spd_x;	//速度x 
	float spd_y;	//速度y 
	int state;		//状態

public:

	void Update();
	void Render();

	void SetHandle(Texture texture);
	Texture GetHandle();
	void SetGrpX(int x);
	int GetGrpX();
	void SetGrpY(int y);
	int GetGrpY();
	void SetGrpW(int w);
	int GetGrpW();
	void SetGrpH(int h);
	int GetGrpH();
	void SetPosX(float x);
	float GetPosX();
	void SetPosY(float y);
	float GetPosY();
	void SetSpdX(float x);
	float GetSpdX();
	void SetSpdY(float y);
	float GetSpdY();
	void SatState(int s);
	int GetState();

};