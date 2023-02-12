#pragma once
#include "Task.h"
#include <vector>
#include <map>

enum MenuNum {
	Menu_,			//���j���[
	AddTask_,		//�^�X�N�ǉ�
	DeleteTask_,	//�^�X�N�폜
	DisplayTask_,	//�^�X�N�\��
	UpdateTask,		//�^�X�N�X�V
	AddMember,		//�S���Ғǉ�
	DeleteMember,	//�S���ҍ폜
	DisplayMember,	//�S���ҕ\��
	MenuNumEnd_		//����ȉ��ɓ��͂��Ȃ��悤��
};

class TaskManager
{
public:

	void Update();

private:

	MenuNum menuNum_;
	//���j���[�X�V
	void MenuUpdate();
	//�^�X�N�ǉ�
	void AddTask();
	//�^�X�N�폜
	void DeleteTask();
	//�^�X�N�\��
	void DisplayTask();
	//�^�X�N�X�V
	void UpdateTask();
	//�����o�[�ǉ�
	void AddMember();
	//�����o�[�폜
	void DeleteMember();
	//�����o�[�\��
	void DisplayMember();

private:
	//�^�X�N
	std::map<int, Task> task_;

	//�`�[�������o�[
	std::map<int, Manager> member_;
};

