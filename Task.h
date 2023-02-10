#pragma once
#include <stdio.h>

//担当者
struct Manager {
	const char* id;
	const char* managerName;
	const char* className;

	void Init();
};

struct Task
{
	~Task();
	const char* id;			//ID
	Manager* manager;	//担当者
	const char* title;		//題名
	const char* content;		//内容
	const char* priority;		//優先度
	const char* time;			//期限
	const char* status;		//ステータス(完了・未完了)

	void Init();

	void Draw();

	void SetTask(Task task);
};
