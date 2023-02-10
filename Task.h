#pragma once
#include <stdio.h>
#include <string.h>
//�S����
struct Manager {
	int id;
	char managerName[20];
	char className[10];

	void Draw();
	void Init();
};

enum TaskItem {
	None_,			//����
	Manager_,		//�S����
	Title_,			//�薼
	Content_,		//���e
	Priority_,		//�D��x
	Time_,			//����
	Status_,		//�X�e�[�^�X
	TaskItemEnd_	//End_�ȍ~��enum��ǉ����Ȃ��悤��
};

struct Task
{
	~Task();
	int id;			//ID
	Manager manager;	//�S����
	char title		[20];		//�薼
	char content	[30];		//���e
	char priority	[15];		//�D��x
	char time		[10];			//����
	char status		[10];		//�X�e�[�^�X(�����E������)

	void Init();

	void Draw();
};
