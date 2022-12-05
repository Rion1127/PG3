#include "DxLib.h"
#include "Player.h"

void Player::Ini()
{
	pos_ = { 200,300 };
	radius = 8;
}

void Player::Update(char* keys)
{
	int speed = 5;
	if (keys[KEY_INPUT_W]) {
		pos_.y -= speed;
	}
	if (keys[KEY_INPUT_S]) {
		pos_.y += speed;
	}
	if (keys[KEY_INPUT_A]) {
		pos_.x -= speed;
	}
	if (keys[KEY_INPUT_D]) {
		pos_.x += speed;
	}

	colPos_ = pos_;
	color = 0xff0000;
}

void Player::Draw()
{
	DrawCircle(pos_.x, pos_.y, radius, color, true);
}

void Player::Oncollision()
{
	color = 0x00ffff;
}
