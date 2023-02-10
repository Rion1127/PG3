#pragma once
#include "Task.h"
#include <vector>
#include <map>

enum MenuNum {
	Menu_,
	AddTask_,
	DeleteTask_,
	DisplayTask_,
	UpdateTask,
	AddMenmber,
	DeleteMenmber,
	DisplayMenmber,
	MenuNumEnd_
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

