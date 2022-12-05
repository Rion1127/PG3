#include "DxLib.h"
#include "Bullet.h"

void Bullet::Ini(Vector2 pos, Vector2 shotVec)
{
	pos_ = pos;

	shotVec_ = shotVec;

	aliveTime_ = 180;
}

void Bullet::Update()
{
	pos_ += shotVec_;

	if (aliveTime_ <= 0) {
		isDead_ = true;
	}
	else {
		aliveTime_--;
	}
}

void Bullet::Draw()
{
	DrawCircle(pos_.x, pos_.y, 4, 0x50ff50, true);
}
