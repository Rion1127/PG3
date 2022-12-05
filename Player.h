#pragma once
#include "Vector2.h"

class Player
{
public:
	void Ini();

	void Update(char* keys);

	void Draw();

	void Oncollision();

	Vector2 GetColPos() { return colPos_; }

	int color = 0xff0000;
	int radius;
private:
	Vector2 pos_;
	Vector2 colPos_;
	

};

