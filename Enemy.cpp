#include "DxLib.h"
#include "Enemy.h"

bool Enemy::isAllDead = false;

void Enemy::Ini(Vector2 pos)
{
	pos_ = pos;
	radius_ = 8;
}

void Enemy::Update()
{
	if (isDead_) {
		isAllDead = true;
	}

	colPos_ = pos_;
}

void Enemy::Draw()
{
	DrawCircle(pos_.x, pos_.y, radius_, 0xffffff, true);
}

