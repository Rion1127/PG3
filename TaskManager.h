#pragma once
#include "Task.h"
#include <vector>
#include <map>

enum MenuNum {
	Menu_,
	Add_,
	Delete_,
	Display_,
	AddMenmber,
	DeleteMenmber,
	DisplayMenmber,
	End_
};

class TaskManager
{
public:

	void Update();

private:

	MenuNum menuNum_;
	//���j���[�X�V
	void MenuUpdate();
	//�^�X�N�ǉ�
	void AddTask();
	//�^�X�N�폜
	void DeleteTask();
	//�^�X�N�\��
	void DisplayTask();
	//�^�X�N�X�V
	void UpdateTask();
	//�����o�[�ǉ�
	void AddMember();
	//�����o�[�폜
	void DeleteMember();
	//�����o�[�\��
	void DisplayMember();

private:
	//�^�X�N
	std::map<int, Task> task_;

	//�`�[�������o�[
	std::map<int, Manager> member_;
};

