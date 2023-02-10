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
	//タスク
	std::vector<Task> task_;

	//チームメンバー
	std::vector<Manager> member_;
};

