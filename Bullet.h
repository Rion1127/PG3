#pragma once
#include "Vector2.h"
class Bullet
{
public:

	void Ini(Vector2 pos, Vector2 shotVec);

	void Update();

	void Draw();

	bool GetDead() { return isDead_; }

private:
	Vector2 pos_;
	Vector2 shotVec_;

	bool isDead_;
	int aliveTime_;
};

