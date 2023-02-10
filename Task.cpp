#include "Task.h"

Task::~Task()
{
	delete manager;
}

void Task::Draw()
{
	printf("ID : %s\n", id);
	printf("�S���� : %s\n", manager->managerName);
	printf("�薼 : %s\n", title);
	printf("���e : %s\n", content);
	printf("�D��x : %s\n", priority);
	printf("���� : %s\n", time);
	printf("�X�e�[�^�X : %s\n", status);
	
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
