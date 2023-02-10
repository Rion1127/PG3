#include "TaskManager.h"

void TaskManager::Update()
{
	/*Manager manager;

	manager.id = 0;
	strcpy_s(manager.managerName, 20, "suzuki rion");
	strcpy_s(manager.className, 10, "LE2A");

	member2_.push_back(manager);*/

	while (true) {
		//�������j���[���
		if (menuNum_ == MenuNum::Menu_) {
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

			//4��I�񂾏ꍇ�I��
			if (menuNum_ == MenuNum::End_)break;
		}
		//�ǉ�
		else if (menuNum_ == MenuNum::Add_) {
			AddTask();
		}
		//�폜
		else if (menuNum_ == MenuNum::Delete_) {

		}
		//�\��
		else if (menuNum_ == MenuNum::Display_) {
			//�^�X�N�\��
			Display();
			printf("1.���j���[�֖߂�\n");

			printf("�����I�����Ă�������(���������)\n");
			int menuNum;
			while (true) {
				scanf_s("%d", &menuNum);
				scanf_s("%*[^\n]%*c");

				if (menuNum < 1 || menuNum > 1)printf("����ȑ���͂Ȃ���\n");
				else break;

			}
			//���j���[�ɖ߂�
			menuNum_ = MenuNum::Menu_;
		}
		//�����o�[�ǉ�
		else if (menuNum_ == MenuNum::AddMenmber) {
			AddMember();
		}
		//�����o�[�폜
		else if (menuNum_ == MenuNum::DeleteMenmber) {

		}
		//�����o�[�\��
		else if (menuNum_ == MenuNum::DisplayMenmber) {
			DisplayMember();

			printf("1.���j���[�֖߂�\n");

			printf("�����I�����Ă�������(���������)\n");
			int menuNum;
			while (true) {
				scanf_s("%d", &menuNum);
				scanf_s("%*[^\n]%*c");

				if (menuNum < 1 || menuNum > 1)printf("����ȑ���͂Ȃ���\n");
				else break;

			}
			//���j���[�ɖ߂�
			menuNum_ = MenuNum::Menu_;
		}
	}
}

void TaskManager::AddTask()
{
	Task* newTask_ = new Task;

	newTask_->Init();

	while (true) {
		printf("\n---------------------------\n");
		printf("�^�X�Nid����͂��Ă�������\n");
		int id_;
		scanf_s("%d", &id_);
		scanf_s("%*[^\n]%*c");

		newTask_->id = id_;

		printf("\n---------------------------\n");
		DisplayMember();
		while (true) {
			printf("�����o�[ID����͂��Ă�������\n");

			int member;
			scanf_s("%d", &member);
			scanf_s("%*[^\n]%*c");

			auto itr = member_.find(member);        // "xyz" ���ݒ肳��Ă��邩�H
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
		char title[21];
		scanf_s("%s", title, 20);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->title, 20, title);

		printf("\n---------------------------\n");
		printf("���e����͂��Ă�������\n");
		char content[31];
		scanf_s("%s", content, 30);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->content, 30, content);

		printf("\n---------------------------\n");
		printf("�D��x����͂��Ă�������\n");
		char priority[16];
		scanf_s("%s", priority, 15);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->priority, 15, priority);

		printf("\n---------------------------\n");
		printf("��������͂��Ă�������\n");
		char time[11];
		scanf_s("%s", time, 10);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->time, 10, time);

		strcpy_s(newTask_->status, 10, "������");

		break;
	}
	printf("�^�X�N��ǉ����܂���\n");

	task_.insert(std::make_pair(newTask_->id, *newTask_));

	menuNum_ = MenuNum::Menu_;
}

void TaskManager::Display()
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
		char name_[21];
		scanf_s("%s", name_, 20);
		scanf_s("%*[^\n]%*c");

		strcpy_s(manager->managerName, 20, name_);

		printf("\n---------------------------\n");
		printf("�N���X����͂��Ă�������\n");
		char className_[11];
		scanf_s("%s", className_, 10);
		scanf_s("%*[^\n]%*c");

		strcpy_s(manager->className, 10, className_);

		break;
	}
	printf("�����o�[��ǉ����܂���\n");

	member_.insert(std::make_pair(manager->id, *manager));

	menuNum_ = MenuNum::Menu_;
}

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

void TaskManager::Delete(int num)
{
}
