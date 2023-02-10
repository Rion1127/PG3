#include "Task.h"

Task::~Task()
{
	//delete manager;
}

void Task::Draw()
{
	printf("ID : %d\n", id);
	printf("�S���� : %s\n", manager.managerName);
	printf("�薼 : %s\n", title);
	printf("���e : %s\n", content);
	printf("�D��x : %s\n", priority);
	printf("���� : %s\n", time);
	printf("�X�e�[�^�X : %s\n", status);
	
}

void Task::Init()
{
	manager.Init();
	id = 0;
	strcpy_s(title,9,"No Title");
	strcpy_s(content, 11, "No Content");
	strcpy_s(priority, 13, "No Proiority");
	strcpy_s(time, 8, "No Time");
	strcpy_s(status, 10, "No Status");
}

void Task::SetTask(Task task)
{
	manager		= task.manager;

	id = task.id;
	strcpy_s(title, 20, task.title);
	strcpy_s(content, 30, task.content);
	strcpy_s(priority, 15, task.priority);
	strcpy_s(time, 10, task.time);
	strcpy_s(status, 10, task.status);
}

void Manager::Draw()
{
	printf("ID : %d\n", id);
	printf("���� : %s\n",managerName);
	printf("�N���X : %s\n", className);
}

void Manager::Init()
{
	id = 0;
	strcpy_s(managerName,20,"A");
	strcpy_s(className,10,"LE2A");
}
