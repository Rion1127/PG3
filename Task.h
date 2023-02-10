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

enum TaskItem {
	None_,			//無し
	Manager_,		//担当者
	Title_,			//題名
	Content_,		//内容
	Priority_,		//優先度
	Time_,			//期限
	Status_,		//ステータス
	TaskItemEnd_	//End_以降にenumを追加しないように
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
};
