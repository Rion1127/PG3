#pragma once
#include "Vector2.h"
#include "Player.h"
#include "Bullet.h"
#include <list>
#include <memory>

class Enemy
{
public:
	void Ini(Vector2 pos, Player* player);

	void Update();

	void Draw();

	void SetIsDead() { isDead_ = true; }

	bool GetAllDead() { return isAllDead; }

	Vector2 GetColPos() { return colPos_; }

	int radius_;

	static bool isAllDead;

private:
	//�֐��|�C���^
	static void (Enemy::* moveTable[])();
	//�ڋ�
	void Approach();

	//�ˌ�
	void Shot();
	//�ˌ����鎞��
	const int MaxShotTime = 300;
	int shotTime_ = MaxShotTime;
	const int MaxCoolTime = 50;
	int bulletCoolTime_ = MaxCoolTime;
	std::list<std::unique_ptr<Bullet>> bullets_;

	//���E
	void Escape();
	//�����鎞��
	int escapeTime_ = 300;

	enum MoveTable {
		Approach_,
		Shot_,
		Escape_
	}phase_ = Approach_;

	Player* player_;

	bool isDead_ = false;

	Vector2 pos_;
	Vector2 colPos_;

	int color_ = 0xffffff;
};

