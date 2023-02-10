#pragma once
#include <stdio.h>
#include <string.h>
//担当者
struct Manager {
	int id;
	char managerName[20];
	char className[10];

	void Draw();
	void Init();
};

struct Task
{
	~Task();
	int id;			//ID
	Manager manager;	//担当者
	char title		[20];		//題名
	char content	[30];		//内容
	char priority	[15];		//優先度
	char time		[10];			//期限
	char status		[10];		//ステータス(完了・未完了)

	void Init();

	void Draw();

	void SetTask(Task task);
};
