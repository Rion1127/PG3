#include "TaskManager.h"

void TaskManager::Update()
{
	Manager manager;

	strcpy_s(manager.id, 3, "00");
	strcpy_s(manager.managerName, 20, "suzuki rion");
	strcpy_s(manager.className, 10, "LE2A");

	member_.push_back(manager);

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
		else if (menuNum_ == MenuNum::AddMenmber) {
			AddMember();
		}
		else if (menuNum_ == MenuNum::DeleteMenmber) {
			
		}
		else if (menuNum_ == MenuNum::DisplayMenmber) {
			if (member_.size() != 0) {
				for (auto& member : member_) {
					printf("\n");
					member.Draw();
					printf("\n");
				}
			}
			else {
				printf("�����o�[����\n");
			}

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
		char id_[5];
		scanf_s("%s", id_,5);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->id,5, id_);

		printf("\n---------------------------\n");
		printf("�����o�[����͂��Ă�������\n");
		int member;
		scanf_s("%d", &member);
		scanf_s("%*[^\n]%*c");

		newTask_->manager = member_.at(0);

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

		strcpy_s(newTask_->status, 10,"������");

		break;
	}
	printf("�^�X�N��ǉ����܂���\n");
	task_.push_back(*newTask_);
	
	menuNum_ = MenuNum::Menu_;
}

void TaskManager::Display()
{
	if (task_.size() != 0) {
		for (auto& task : task_) {
			printf("\n");
			task.Draw();
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
		char id_[5];
		scanf_s("%s", id_, 5);
		scanf_s("%*[^\n]%*c");

		strcpy_s(manager->id, 5, id_);

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

		strcpy_s(manager->className, 20, className_);

		break;
	}
	printf("�����o�[��ǉ����܂���\n");
	member_.push_back(*manager);

	menuNum_ = MenuNum::Menu_;
}

void TaskManager::Delete(int num)
{
}
