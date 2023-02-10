#include "Task.h"

Task::~Task()
{
	//delete manager;
}

void Task::Draw()
{
	printf("ID : %d\n", id);
	printf("担当者 : %s\n", manager.managerName);
	printf("題名 : %s\n", title);
	printf("内容 : %s\n", content);
	printf("優先度 : %s\n", priority);
	printf("期限 : %s\n", time);
	printf("ステータス : %s\n", status);
	
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
	printf("氏名 : %s\n",managerName);
	printf("クラス : %s\n", className);
}

void Manager::Init()
{
	id = 0;
	strcpy_s(managerName,20,"A");
	strcpy_s(className,10,"LE2A");
}
