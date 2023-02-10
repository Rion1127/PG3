#pragma once
#include <stdio.h>
#include <string.h>
//担当者
struct Manager {
	int id;
	char managerName[21];
	char className[11];

	void Draw();
	void Init();
};

struct Task
{
	~Task();
	int id;			//ID
	Manager manager;	//担当者
	char title		[21];		//題名
	char content	[31];		//内容
	char priority	[16];		//優先度
	char time		[11];			//期限
	char status		[11];		//ステータス(完了・未完了)

	void Init();

	void Draw();

	void SetTask(Task task);
};
