#pragma once
#include "Task.h"
#include <vector>
#include <map>

enum MenuNum {
	Menu_,			//メニュー
	AddTask_,		//タスク追加
	DeleteTask_,	//タスク削除
	DisplayTask_,	//タスク表示
	UpdateTask,		//タスク更新
	AddMember,		//担当者追加
	DeleteMember,	//担当者削除
	DisplayMember,	//担当者表示
	MenuNumEnd_		//これ以下に入力しないように
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

