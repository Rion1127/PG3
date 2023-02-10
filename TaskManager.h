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
	//メニュー更新
	void MenuUpdate();
	//タスク追加
	void AddTask();
	//タスク削除
	void DeleteTask();
	//タスク表示
	void DisplayTask();
	//タスク更新
	void UpdateTask();
	//メンバー追加
	void AddMember();
	//メンバー削除
	void DeleteMember();
	//メンバー表示
	void DisplayMember();

private:
	//タスク
	std::map<int, Task> task_;

	//チームメンバー
	std::map<int, Manager> member_;
};

