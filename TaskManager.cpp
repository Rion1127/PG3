#include "TaskManager.h"

void TaskManager::Update()
{
	Manager manager;

	manager.id = "01";
	manager.managerName = "suzuki";
	manager.className = "LE2A";

	menber_.push_back(manager);

	while (true) {
		//�������j���[���
		if (menuNum_ == MenuNum::Menu_) {
			printf("\n[���j���[]\n");
			printf("1.�^�X�N�̒ǉ�\n");
			printf("2.�^�X�N�̍폜\n");
			printf("3.�^�X�N�̕\��\n");
			printf("4.�����o�[�ǉ�\n");
			printf("5.�I��\n");

			MenuNum menuNum;

			printf("\n---------------------------\n");
			printf("�����I�����Ă�������(���������)\n");
			while (true) {
				scanf_s("%d", &menuNum);
				scanf_s("%*[^\n]%*c");


				if (menuNum < 1 || menuNum > 5)printf("����ȑ���͂Ȃ���\n");
				else break;

			}
			//���j���[����
			menuNum_ = menuNum;

			//4��I�񂾏ꍇ�I��
			if (menuNum_ == MenuNum::End_)break;
		}
		//�ǉ�
		else if (menuNum_ == MenuNum::Add_) {
			
			AddUpdate();


		}
		//�폜
		else if (menuNum_ == MenuNum::Delete_) {

		}
		//�\��
		else if (menuNum_ == MenuNum::Display_) {
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

		}
	}
}

void TaskManager::AddUpdate()
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
		int member_;
		scanf_s("%d", &member_);
		scanf_s("%*[^\n]%*c");

		newTask_->manager = &menber_.at(0);

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
	task_.push_back(std::move(*newTask_));
	
	menuNum_ = MenuNum::Menu_;
}

void TaskManager::Add(Task task)
{
}

void TaskManager::Delete(int num)
{
}
