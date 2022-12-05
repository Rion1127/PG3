#include "Vector2.h"
#include <cmath>    // sqrt

// �R���X�g���N�^
// ��x�N�g���ɏ�����
Vector2::Vector2() : x(0), y(0) {} 

// x,y�������w�肵�Ă̐���
Vector2::Vector2(float x, float y) : x(x), y(y) {}

// �x�N�g���̃m����(����)�����߂�
float Vector2::length() const
{
	return sqrt(x * x + y * y);
}

// �x�N�g���𐳋K��
Vector2& Vector2::normalize()
{
	float len = length();
	Vector2 vec = *this;
	if (len != 0)
	{
		return vec /= len;
	}
	return vec;
}

// ���ς����߂�
float Vector2::dot(const Vector2& v) const
{
	return x * v.x + y * v.y;
}

// �O�ς����߂�
float Vector2::cross(const Vector2& v) const
{
	return x * v.y - y * v.x;
}

// �P�����Z�q�I�[�o�[���[�h
//�P�����Z�q+���g����悤�ɂ���
Vector2 Vector2::operator+() const	
{
	return *this;
}
//	�V	�@-���g����悤�ɂ���
Vector2 Vector2::operator-() const	
{
	return Vector2(-x, -y);
}

// ������Z�q�I�[�o�[���[�h
//+=���g�p�ł���悤�ɂ���
Vector2& Vector2::operator+=(const Vector2& v)	
{
	x += v.x;
	y += v.y;
	return *this;
}
//-=���g�p�ł���悤�ɂ���
Vector2& Vector2::operator-=(const Vector2& v)	
{
	x -= v.x;
	y -= v.y;
	return *this;
}
//�x�N�g����S�{�ɂ���
Vector2& Vector2::operator*=(float s)	
{
	x *= s;
	y *= s;
	return *this;
}
//�x�N�g����1/S�{�ɂ���
Vector2& Vector2::operator/=(float s)	
{
	x /= s;
	y /= s;
	return *this;
}

bool Vector2::operator==(const Vector2& v)
{
	if (x == v.x && y == v.y) {
		return true;
	}
	else {
		return false;
	}
}

bool Vector2::operator<(const Vector2& v)
{
	if (x < v.x && y < v.y) {
		return true;
	}
	else {
		return false;
	}
}

bool Vector2::operator>(const Vector2& v)
{
	if (x > v.x && y > v.y) {
		return true;
	}
	else {
		return false;
	}
}

bool Vector2::operator<=(const Vector2& v)
{
	if (x <= v.x && y <= v.y) {
		return true;
	}
	else {
		return false;
	}
}

bool Vector2::operator>=(const Vector2& v)
{
	if (x >= v.x && y >= v.y) {
		return true;
	}
	else {
		return false;
	}
}

// 2�����Z�q�I�[�o�[���[�h
// �������Ȉ����̃p�^�[���ɑΉ����邽�߁A�ȉ��̂悤�ɏ������Ă���
//�����Z���ł���悤�ɂ���
const Vector2 operator+(const Vector2& v1, const Vector2& v2)
{
	Vector2 temp(v1);
	return temp += v2;
}
//�����Z���ł���悤�ɂ���
const Vector2 operator-(const Vector2& v1, const Vector2& v2)
{
	Vector2 temp(v1);
	return temp -= v2;
}
//S�{���v�Z�ł���悤�ɂ���
const Vector2 operator*(const Vector2& v, float s)
{
	Vector2 temp(v);
	return temp *= s;
}
//S�{���v�Z�ł���悤�ɂ���i��Ƃ̓I�y�����h�̈ʒu���t�j
const Vector2 operator*(float s, const Vector2& v)
{
	return v * s;
}
//�x�N�g����1/S�{���v�Z�ł���悤�ɂ���
const Vector2 operator/(const Vector2& v, float s)
{
	Vector2 temp(v);
	return temp /= s;
}