#pragma once
#include "Task.h"
#include <vector>

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

	void AddTask();

	void Display();

	void AddMember();

private:

	void Delete(int num);
	//�^�X�N
	std::vector<Task> task_;

	//�`�[�������o�[
	std::vector<Manager> member_;
};

