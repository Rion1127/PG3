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

	void MenuUpdate();

	void AddTask();

	void DeleteTask();

	void Display();

	void AddMember();

	void DeleteMember();

	void DisplayMember();

private:
	//タスク
	std::map<int, Task> task_;

	//チームメンバー
	std::map<int, Manager> member_;
};

