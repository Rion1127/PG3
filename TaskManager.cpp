#include "TaskManager.h"

void TaskManager::Update()
{
	while (true) {
		//�������j���[���
		if (menuNum_ == MenuNum::Menu_) {
			MenuUpdate();
		}
		//�^�X�N�ǉ�
		else if (menuNum_ == MenuNum::AddTask_) {
			AddTask();
		}
		//�^�X�N�폜
		else if (menuNum_ == MenuNum::DeleteTask_) {
			DeleteTask();
		}
		//�^�X�N�\��
		else if (menuNum_ == MenuNum::DisplayTask_) {
			//�^�X�N�\��
			DisplayTask();
			//���j���[�ɖ߂�
			menuNum_ = MenuNum::Menu_;
		}
		//�^�X�N�X�V
		else if (menuNum_ == MenuNum::UpdateTask) {
			UpdateTask();
		}
		//�S���Ғǉ�
		else if (menuNum_ == MenuNum::AddMember) {
			AddMember();
		}
		//�S���ҍ폜
		else if (menuNum_ == MenuNum::DeleteMember) {
			DeleteMember();
		}
		//�S���ҕ\��
		else if (menuNum_ == MenuNum::DisplayMember) {
			DisplayMember();
			//���j���[�ɖ߂�
			menuNum_ = MenuNum::Menu_;
		}

		//4��I�񂾏ꍇ�I��
		if (menuNum_ == MenuNum::MenuNumEnd_)break;
	}
}
//���j���[�X�V
void TaskManager::MenuUpdate()
{
	//���j���[�̕\���^�C�v
	MenuType displayMenuType = MenuType::All;
	MenuNum menuNum;

	if (member_.size() <= 0)displayMenuType = MenuType::MemberAddOnly;
	if (member_.size() > 0 && task_.size() <= 0)displayMenuType = MenuType::TaskAddOnly;

	printf("\n[���j���[]\n");
	//�S���Ғǉ��̂ݕ\���i�S���҂��O���̎��j
	if (displayMenuType == MenuType::MemberAddOnly) {
		printf("%d.�S���Ғǉ�\n", MenuNum::AddMember);
		printf("%d.�I��\n", MenuNum::MenuNumEnd_);

		printf("\n---------------------------\n");
		printf("�����I�����Ă�������(���������)\n");
		while (true) {
			printf(">");
			scanf_s("%d", &menuNum);
			scanf_s("%*[^\n]%*c");
			
			if (menuNum != MenuNum::AddMember &&
				menuNum != MenuNum::MenuNumEnd_) {
				//�\������Ă��郁�j���[�ȊO��I��������
				printf("����ȑ���͂Ȃ���\n");
			}
			else break;
		}
	}
	//�^�X�N�ǉ��{�����o�[���ڂ��ׂĕ\���i�S���҂��P���ȏさ�^�X�N���O�j
	else if (displayMenuType == MenuType::TaskAddOnly) {
		printf("%d.�^�X�N�̒ǉ�\n", MenuNum::AddTask_);
		printf("%d.�S���Ғǉ�\n", MenuNum::AddMember);
		printf("%d.�S���ҍ폜\n", MenuNum::DeleteMember);
		printf("%d.�S���ҕ\��\n", MenuNum::DisplayMember);
		printf("%d.�I��\n", MenuNum::MenuNumEnd_);

		printf("\n---------------------------\n");
		printf("�����I�����Ă�������(���������)\n");
		while (true) {
			printf(">");
			scanf_s("%d", &menuNum);
			scanf_s("%*[^\n]%*c");

			if (menuNum != MenuNum::AddTask_ &&
				menuNum != MenuNum::AddMember &&
				menuNum != MenuNum::DeleteMember && 
				menuNum != MenuNum::DisplayMember &&
				menuNum != MenuNum::MenuNumEnd_) {
				//�\������Ă��郁�j���[�ȊO��I��������
				printf("����ȑ���͂Ȃ���\n");
			}
			else break;
		}
	}
	//���ׂĕ\��
	else if (displayMenuType == MenuType::All) {
		printf("%d.�^�X�N�̒ǉ�\n", MenuNum::AddTask_);
		printf("%d.�^�X�N�̍폜\n", MenuNum::DeleteTask_);
		printf("%d.�^�X�N�̕\��\n", MenuNum::DisplayTask_);
		printf("%d.�^�X�N�̍X�V\n", MenuNum::UpdateTask);
		printf("%d.�S���Ғǉ�\n", MenuNum::AddMember);
		printf("%d.�S���ҍ폜\n", MenuNum::DeleteMember);
		printf("%d.�S���ҕ\��\n", MenuNum::DisplayMember);
		printf("%d.�I��\n", MenuNum::MenuNumEnd_);

		printf("\n---------------------------\n");
		printf("�����I�����Ă�������(���������)\n");
		while (true) {
			printf(">");
			scanf_s("%d", &menuNum);
			scanf_s("%*[^\n]%*c");

			if (menuNum < 1 || menuNum > 8)printf("����ȑ���͂Ȃ���\n");
			else break;
		}
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
			printf(">");
			scanf_s("%d", &id_);
			scanf_s("%*[^\n]%*c");

			newTask_->id = id_;
		}
		else {
			printf("�S���҂����܂���\n");
			break;
		}

		DisplayMember();
		while (true) {
			printf("�S����ID����͂��Ă�������\n");

			int member;
			printf(">");
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
				printf("�S����ID����v���܂���ł���\n");
			}
		}

		printf("\n---------------------------\n");
		printf("�薼����͂��Ă�������\n");
		char title[20];
		printf(">");
		scanf_s("%s", title, 20);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->title, 20, title);

		printf("\n---------------------------\n");
		printf("���e����͂��Ă�������\n");
		char content[30];
		printf(">");
		scanf_s("%s", content, 30);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->content, 30, content);

		printf("\n---------------------------\n");
		printf("�D��x����͂��Ă�������\n");
		char priority[15];
		printf(">");
		scanf_s("%s", priority, 15);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->priority, 15, priority);

		printf("\n---------------------------\n");
		printf("��������͂��Ă�������\n");
		char time[10];
		printf(">");
		scanf_s("%s", time, 10);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->time, 10, time);

		strcpy_s(newTask_->status, 10, "������");

		task_.insert(std::make_pair(newTask_->id, *newTask_));

		printf("�^�X�N���ȉ��̓��e�Œǉ����܂���\n\n");
		printf("-----------------------------------------------\n");
		task_.at(newTask_->id).Draw();
		printf("-----------------------------------------------\n");

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
			printf(">");
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
		printf("-----------------------------------------------\n");
		for (auto itr = task_.begin(); itr != task_.end(); itr++) {
			itr->second.Draw();
			printf("-----------------------------------------------\n");

		}
	}
	else {
		printf("\n�^�X�N����\n\n");
	}
}
//�^�X�N�X�V
void TaskManager::UpdateTask()
{
	//�^�X�N������ꍇ
	if (task_.size() != 0) {
		while (true) {
			//�^�X�N�\��
			DisplayTask();
			printf("\n�^�X�NID����͂��Ă�������\n");
			printf("'0'�L�[�Ń��j���[�ɖ߂�܂�\n");


			int member;
			printf(">");
			scanf_s("%d", &member);
			scanf_s("%*[^\n]%*c");
			//���j���[�ɖ߂�
			if (member == 0) break;

			auto taskitr = task_.find(member);        // �^�X�N���ݒ肳��Ă��邩�T��
			if (taskitr != task_.end()) {
				//�ݒ肳��Ă���ꍇ�̏���
				while (true) {

					taskitr->second.Draw();
					printf("\n�ǂ̍��ڂ��X�V���܂���\n");
					TaskItem itemNum;	//����
					while (true) {
						printf("�X�V������e��I�����Ă�������(���������)\n");
						printf("%d.�S����\n"		,TaskItem::Manager_);
						printf("%d.�^�C�g��\n"		,TaskItem::Title_);
						printf("%d.���e\n"		,TaskItem::Content_);
						printf("%d.�D��x\n"		,TaskItem::Priority_);
						printf("%d.����\n"		,TaskItem::Time_);
						printf("%d.�X�e�[�^�X\n"	,TaskItem::Status_);
						printf(">");
						scanf_s("%d", &itemNum);
						scanf_s("%*[^\n]%*c");

						if (itemNum < TaskItem::Manager_ || itemNum > TaskItem::TaskItemEnd_)printf("����ȑ���͂Ȃ���\n");
						else break;
					}

					//�S����
					if (itemNum == TaskItem::Manager_) {
						DisplayMember();
						while (true) {
							printf("\n�S����ID����͂��Ă�������\n");

							int member;
							printf(">");
							scanf_s("%d", &member);
							scanf_s("%*[^\n]%*c");

							auto memberItr = member_.find(member);        // ID���ݒ肳��Ă��邩�T��
							if (memberItr != member_.end()) {
								//�ݒ肳��Ă���ꍇ�̏���
								taskitr->second.manager = member_.at(member);
								printf("�S���҂��X�V���܂���\n");
								break;
							}
							else {
								//�ݒ肳��Ă��Ȃ��ꍇ�̏���
								printf("�S����ID����v���܂���ł���\n");
							}
						}
					}
					//�^�C�g��
					else if (itemNum == TaskItem::Title_) {
						printf("\n�薼����͂��Ă�������\n");
						char title[20];
						printf(">");
						scanf_s("%s", title, 20);
						scanf_s("%*[^\n]%*c");

						strcpy_s(taskitr->second.title, 20, title);
					}
					//���e
					else if (itemNum == TaskItem::Content_) {
						printf("\n���e����͂��Ă�������\n");
						char content[30];
						printf(">");
						scanf_s("%s", content, 30);
						scanf_s("%*[^\n]%*c");

						strcpy_s(taskitr->second.content, 30, content);
					}
					//�D��x
					else if (itemNum == TaskItem::Priority_) {
						printf("\n�D��x����͂��Ă�������\n");
						char priority[15];
						printf(">");
						scanf_s("%s", priority, 15);
						scanf_s("%*[^\n]%*c");

						strcpy_s(taskitr->second.priority, 15, priority);
					}
					//����
					else if (itemNum == TaskItem::Time_) {
						printf("\n��������͂��Ă�������\n");
						char time[10];
						printf(">");
						scanf_s("%s", time, 10);
						scanf_s("%*[^\n]%*c");

						strcpy_s(taskitr->second.time, 10, time);
					}
					//�X�e�[�^�X
					else if (itemNum == TaskItem::Status_) {
						printf("\n�X�e�[�^�X����͂��Ă�������\n");
						printf("1.����\n");
						printf("2.�i�s��\n");
						printf("3.������\n");

						int status;
						while (true) {
							printf(">");
							scanf_s("%d", &status);
							scanf_s("%*[^\n]%*c");
							if (status < 1 || status > 3)printf("����ȑ���͂Ȃ���\n");
							else break;
						}
						const char* statusName = "����";
						if (status == 1)statusName = "����";
						if (status == 2)statusName = "�i�s��";
						if (status == 3)statusName = "������";

						strcpy_s(taskitr->second.status, 10, statusName);
					}

					//�ݒ肳��Ă��鎞�̏������I��
					break;
				}
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
//�S���Ғǉ�
void TaskManager::AddMember()
{
	Manager* manager = new Manager;
	manager->Init();

	while (true) {
		printf("\n---------------------------\n");
		printf("�S����id����͂��Ă�������\n");
		int id_;
		printf(">");
		scanf_s("%d", &id_);
		scanf_s("%*[^\n]%*c");

		manager->id = id_;

		printf("\n---------------------------\n");
		printf("��������͂��Ă�������\n");
		char name_[20];
		printf(">");
		scanf_s("%s", name_, 20);
		scanf_s("%*[^\n]%*c");

		strcpy_s(manager->managerName, 20, name_);

		printf("\n---------------------------\n");
		printf("�N���X����͂��Ă�������\n");
		char className_[10];
		printf(">");
		scanf_s("%s", className_, 10);
		scanf_s("%*[^\n]%*c");

		strcpy_s(manager->className, 10, className_);

		break;
	}
	

	member_.insert(std::make_pair(manager->id, *manager));

	printf("�S���҂�ǉ����܂���\n\n");
	printf("-----------------------------------------------\n");
	member_.at(manager->id).Draw();
	printf("-----------------------------------------------\n");

	menuNum_ = MenuNum::Menu_;
}
//�S���ҍ폜
void TaskManager::DeleteMember()
{
	if (member_.size() != 0) {
		DisplayMember();
		while (true) {
			printf("�S����ID����͂��Ă�������\n");

			int member;
			printf(">");
			scanf_s("%d", &member);
			scanf_s("%*[^\n]%*c");

			auto itr = member_.find(member);        // ID���ݒ肳��Ă��邩�T��
			if (itr != member_.end()) {
				//�ݒ肳��Ă���ꍇ�̏���
				member_.erase(itr->first);
				printf("�S���҂��폜���܂���\n");
				break;
			}
			else {
				//�ݒ肳��Ă��Ȃ��ꍇ�̏���
				printf("�S����ID����v���܂���ł���\n");
			}
		}
	}
	else {
		printf("�S���҂����܂���\n");
	}
	//���j���[�ɖ߂�
	menuNum_ = MenuNum::Menu_;
}
//�S���ҕ\��
void TaskManager::DisplayMember()
{
	if (member_.size() != 0) {
		printf("-----------------------------------------------\n");
		for (auto itr = member_.begin(); itr != member_.end(); itr++) {
			itr->second.Draw();
			printf("-----------------------------------------------\n");

		}
	}
	else {
		printf("�S���Җ���\n");
	}
}
