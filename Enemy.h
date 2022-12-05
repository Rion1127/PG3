#pragma once
#include "Vector2.h"
class Enemy
{
public:
	void Ini(Vector2 pos);

	void Update();

	void Draw();

	void SetIsDead() { isDead_ = true; }

	bool GetAllDead() { return isAllDead; }

	Vector2 GetColPos() { return colPos_; }

	int radius_;

	static bool isAllDead;
private:

	bool isDead_ = false;

	Vector2 pos_;
	Vector2 colPos_;
};

