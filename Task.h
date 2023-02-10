#pragma once
#include <stdio.h>
#include <string.h>
//�S����
struct Manager {
	const char* id;
	const char* managerName;
	const char* className;

	void Init();
};

struct Task
{
	~Task();
	char id[5];			//ID
	Manager* manager;	//�S����
	char title		[20];		//�薼
	char content	[30];		//���e
	char priority	[15];		//�D��x
	char time		[10];			//����
	char status		[10];		//�X�e�[�^�X(�����E������)

	void Init();

	void Draw();

	void SetTask(Task task);
};
