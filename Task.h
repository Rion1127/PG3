#pragma once
#include <stdio.h>

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
	const char* id;			//ID
	Manager* manager;	//�S����
	const char* title;		//�薼
	const char* content;		//���e
	const char* priority;		//�D��x
	const char* time;			//����
	const char* status;		//�X�e�[�^�X(�����E������)

	void Init();

	void Draw();

	void SetTask(Task task);
};
