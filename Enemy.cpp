#include "DxLib.h"
#include "Enemy.h"

bool Enemy::isAllDead = false;

void Enemy::Ini(Vector2 pos, Player* player)
{
	pos_ = pos;
	radius_ = 8;
	player_ = player;
}

void Enemy::Update()
{
	//�֐��|�C���^���s
	(this->*moveTable[phase_])();

	//�e�X�V
	for (std::unique_ptr<Bullet>& bullet : bullets_) {
		bullet->Update();
	}

	//�e���f���[�g����
	bullets_.remove_if([](std::unique_ptr<Bullet>& enemy)
		{
			return enemy->GetDead();
		});

	if (isDead_) {
		isAllDead = true;
	}

	colPos_ = pos_;
}

void Enemy::Draw()
{
	DrawCircle(pos_.x, pos_.y, radius_, color_, true);

	for (std::unique_ptr<Bullet>& bullet : bullets_) {
		bullet->Draw();
	}
}

void Enemy::Approach()
{
	Vector2 vec2Player;

	vec2Player = {
		player_->GetPos().x - pos_.x ,
		player_->GetPos().y - pos_.y ,
	};
	//X�AY���ɋ�����50�ȉ��ɂȂ�����ˌ��t�F�[�Y��
	if (vec2Player.x <= 50 && vec2Player.y <= 50) {
		phase_ = Shot_;
	}

	vec2Player = vec2Player.normalize();

	pos_ += vec2Player * 0.5f;

	color_ = 0xffaaaa;
}

void Enemy::Shot()
{
	//�N�[���^�C����0�ɂȂ�����
	if (bulletCoolTime_ <= 0) {
		bulletCoolTime_ = MaxCoolTime;

		//�x�N�g���擾
		Vector2 vec2Player;
		vec2Player = {
			player_->GetPos().x - pos_.x ,
			player_->GetPos().y - pos_.y ,
		};

		vec2Player = vec2Player.normalize();

		//�e����
		std::unique_ptr<Bullet> newbullet = std::make_unique<Bullet>();
		newbullet->Ini(pos_, vec2Player);

		bullets_.emplace_back(std::move(newbullet));
	}
	else {
		//�N�[���^�C�������炷
		bulletCoolTime_--;
	}

	//�ˌ��t�F�[�Y�̐�������
	if (shotTime_ <= 0) {
		shotTime_ = MaxShotTime;
		phase_ = Escape_;
	}
	else {
		shotTime_--;
	}

	color_ = 0xaaffaa;
}

void Enemy::Escape()
{
	Vector2 vec2Player;

	vec2Player = {
		player_->GetPos().x - pos_.x ,
		player_->GetPos().y - pos_.y ,
	};

	vec2Player = -vec2Player.normalize();

	pos_ += vec2Player * 0.5f;

	if (escapeTime_ <= 0) {
		escapeTime_ = 300;
		phase_ = Approach_;
	}
	else {
		escapeTime_--;
	}

	color_ = 0xaaaaff;
}

void(Enemy::* Enemy::moveTable[])()
= {
	&Enemy::Approach,	//�ڋ�
	&Enemy::Shot,		//�ˌ�
	&Enemy::Escape		//���E
};
