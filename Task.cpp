#include "Task.h"

Task::~Task()
{
	delete manager;
}

void Task::Draw()
{
	printf("ID : %s\n", id);
	printf("担当者 : %s\n", manager->managerName);
	printf("題名 : %s\n", title);
	printf("内容 : %s\n", content);
	printf("優先度 : %s\n", priority);
	printf("期限 : %s\n", time);
	printf("ステータス : %s\n", status);
	
}

void Task::Init()
{
	id			= "00";
	manager		= new Manager;
	manager->Init();
	title		= "No Title";
	content		= "No Content";
	priority	= "No Proiority";
	time		= "No Time";
	status		= "No Status";
}

void Task::SetTask(Task task)
{
	id			= task.id;
	manager		= task.manager;
	title		= task.title;
	content		= task.content;
	priority	= task.priority;
	time		= task.time;
	status		= task.status;
}

void Manager::Init()
{
	id			= "00";
	managerName = "A";
	className	= "LE2A";
}
