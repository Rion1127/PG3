#include "TaskManager.h"

void TaskManager::Update()
{
	while (true) {
		//�������j���[���
		if (menuNum_ == MenuNum::Menu_) {
			MenuUpdate();
		}
		//�ǉ�
		else if (menuNum_ == MenuNum::Add_) {
			AddTask();
		}
		//�폜
		else if (menuNum_ == MenuNum::Delete_) {
			DeleteTask();
		}
		//�\��
		else if (menuNum_ == MenuNum::Display_) {
			//�^�X�N�\��
			DisplayTask();
			//���j���[�ɖ߂�
			menuNum_ = MenuNum::Menu_;
		}
		//�����o�[�ǉ�
		else if (menuNum_ == MenuNum::AddMenmber) {
			AddMember();
		}
		//�����o�[�폜
		else if (menuNum_ == MenuNum::DeleteMenmber) {
			DeleteMember();
		}
		//�����o�[�\��
		else if (menuNum_ == MenuNum::DisplayMenmber) {
			DisplayMember();
			//���j���[�ɖ߂�
			menuNum_ = MenuNum::Menu_;
		}

		//4��I�񂾏ꍇ�I��
		if (menuNum_ == MenuNum::End_)break;
	}
}
//���j���[�X�V
void TaskManager::MenuUpdate()
{
	printf("\n[���j���[]\n");
	printf("1.�^�X�N�̒ǉ�\n");
	printf("2.�^�X�N�̍폜\n");
	printf("3.�^�X�N�̕\��\n");
	printf("4.�����o�[�ǉ�\n");
	printf("5.�����o�[�폜\n");
	printf("6.�����o�[�\��\n");
	printf("7.�I��\n");

	MenuNum menuNum;

	printf("\n---------------------------\n");
	printf("�����I�����Ă�������(���������)\n");
	while (true) {
		scanf_s("%d", &menuNum);
		scanf_s("%*[^\n]%*c");

		if (menuNum < 1 || menuNum > 7)printf("����ȑ���͂Ȃ���\n");
		else break;
	}
	//���j���[����
	menuNum_ = menuNum;
}
//�^�X�N�ǉ�
void TaskManager::AddTask()
{
	Task* newTask_ = new Task;
	newTask_->Init();

	while (true) {
		if (member_.size() != 0) {
			printf("\n---------------------------\n");
			printf("�^�X�Nid����͂��Ă�������\n");
			int id_;
			scanf_s("%d", &id_);
			scanf_s("%*[^\n]%*c");

			newTask_->id = id_;
		}
		else {
			printf("�����o�[�����܂���\n");
			break;
		}

		printf("\n---------------------------\n");

		DisplayMember();
		while (true) {
			printf("�����o�[ID����͂��Ă�������\n");

			int member;
			scanf_s("%d", &member);
			scanf_s("%*[^\n]%*c");

			auto itr = member_.find(member);        // ID���ݒ肳��Ă��邩�T��
			if (itr != member_.end()) {
				//�ݒ肳��Ă���ꍇ�̏���
				newTask_->manager = member_.at(member);
				break;
			}
			else {
				//�ݒ肳��Ă��Ȃ��ꍇ�̏���
				printf("�����o�[ID����v���܂���ł���\n");
			}
		}

		printf("\n---------------------------\n");
		printf("�薼����͂��Ă�������\n");
		char title[20];
		scanf_s("%s", title, 20);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->title, 20, title);

		printf("\n---------------------------\n");
		printf("���e����͂��Ă�������\n");
		char content[30];
		scanf_s("%s", content, 30);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->content, 30, content);

		printf("\n---------------------------\n");
		printf("�D��x����͂��Ă�������\n");
		char priority[15];
		scanf_s("%s", priority, 15);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->priority, 15, priority);

		printf("\n---------------------------\n");
		printf("��������͂��Ă�������\n");
		char time[10];
		scanf_s("%s", time, 10);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->time, 10, time);

		strcpy_s(newTask_->status, 10, "������");

		printf("�^�X�N��ǉ����܂���\n");

		task_.insert(std::make_pair(newTask_->id, *newTask_));

		break;
	}
	menuNum_ = MenuNum::Menu_;
}
//�^�X�N�폜
void TaskManager::DeleteTask()
{
	//�^�X�N������ꍇ
	if (task_.size() != 0) {
		//�^�X�N�\��
		DisplayTask();
		while (true) {
			printf("�^�X�NID����͂��Ă�������\n");

			int member;
			scanf_s("%d", &member);
			scanf_s("%*[^\n]%*c");

			auto itr = task_.find(member);        // �^�X�N���ݒ肳��Ă��邩�T��
			if (itr != task_.end()) {
				//�ݒ肳��Ă���ꍇ�̏���
				task_.erase(itr->first);
				printf("�^�X�N���폜���܂���\n");
				break;
			}
			else {
				//�ݒ肳��Ă��Ȃ��ꍇ�̏���
				printf("�^�X�NID����v���܂���ł���\n");
			}
		}
	}
	//�^�X�N���Ȃ��ꍇ
	else {
		printf("�^�X�N������܂���\n");
	}
	//���j���[�ɖ߂�
	menuNum_ = MenuNum::Menu_;
}
//�^�X�N�\��
void TaskManager::DisplayTask()
{
	if (task_.size() != 0) {
		for (auto itr = task_.begin(); itr != task_.end(); itr++) {
			printf("\n");
			itr->second.Draw();
			printf("\n");
		}
	}
	else {
		printf("\n�^�X�N����\n\n");
	}
}
//�^�X�N�X�V
void TaskManager::UpdateTask()
{
}
//�����o�[�ǉ�
void TaskManager::AddMember()
{
	Manager* manager = new Manager;
	manager->Init();

	while (true) {
		printf("\n---------------------------\n");
		printf("�����o�[id����͂��Ă�������\n");
		int id_;
		scanf_s("%d", &id_);
		scanf_s("%*[^\n]%*c");

		manager->id = id_;

		printf("\n---------------------------\n");
		printf("��������͂��Ă�������\n");
		char name_[20];
		scanf_s("%s", name_, 20);
		scanf_s("%*[^\n]%*c");

		strcpy_s(manager->managerName, 20, name_);

		printf("\n---------------------------\n");
		printf("�N���X����͂��Ă�������\n");
		char className_[10];
		scanf_s("%s", className_, 10);
		scanf_s("%*[^\n]%*c");

		strcpy_s(manager->className, 10, className_);

		break;
	}
	printf("�����o�[��ǉ����܂���\n");

	member_.insert(std::make_pair(manager->id, *manager));

	menuNum_ = MenuNum::Menu_;
}
//�����o�[�폜
void TaskManager::DeleteMember()
{
	if (member_.size() != 0) {
		DisplayMember();
		while (true) {
			printf("�����o�[ID����͂��Ă�������\n");

			int member;
			scanf_s("%d", &member);
			scanf_s("%*[^\n]%*c");

			auto itr = member_.find(member);        // ID���ݒ肳��Ă��邩�T��
			if (itr != member_.end()) {
				//�ݒ肳��Ă���ꍇ�̏���
				member_.erase(itr->first);
				printf("�����o�[���폜���܂���\n");
				break;
			}
			else {
				//�ݒ肳��Ă��Ȃ��ꍇ�̏���
				printf("�����o�[ID����v���܂���ł���\n");
			}
		}
	}
	else {
		printf("�����o�[�����܂���\n");
	}
	//���j���[�ɖ߂�
	menuNum_ = MenuNum::Menu_;
}
//�����o�[�\��
void TaskManager::DisplayMember()
{
	if (member_.size() != 0) {
		for (auto itr = member_.begin(); itr != member_.end(); itr++) {
			printf("\n");
			itr->second.Draw();
			printf("\n");
		}
	}
	else {
		printf("�����o�[����\n");
	}
}
