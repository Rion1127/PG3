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
	//タスク
	std::vector<Task> task_;

	//チームメンバー
	std::vector<Manager> menber_;
};

