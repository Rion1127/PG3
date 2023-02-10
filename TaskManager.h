#pragma once
#include "Task.h"
#include <vector>

enum MenuNum {
	Menu_,
	Add_,
	Delete_,
	Display_,
	AddMenmber,
	End_
};

class TaskManager
{
public:

	void Update();

private:

	MenuNum menuNum_;

	void AddUpdate();

private:
	void Add(Task task);

	void Delete(int num);
	//�^�X�N
	std::vector<Task> task_;

	//�`�[�������o�[
	std::vector<Manager> menber_;
};

