#pragma once
#include <stdio.h>
#include <string.h>
//�S����
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
	Manager manager;	//�S����
	char title		[21];		//�薼
	char content	[31];		//���e
	char priority	[16];		//�D��x
	char time		[11];			//����
	char status		[11];		//�X�e�[�^�X(�����E������)

	void Init();

	void Draw();

	void SetTask(Task task);
};
