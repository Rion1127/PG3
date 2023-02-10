#include "TaskManager.h"

void TaskManager::Update()
{
	Manager manager;

	strcpy_s(manager.id, 3, "00");
	strcpy_s(manager.managerName, 20, "suzuki rion");
	strcpy_s(manager.className, 10, "LE2A");

	member_.push_back(manager);

	while (true) {
		//初期メニュー画面
		if (menuNum_ == MenuNum::Menu_) {
			printf("\n[メニュー]\n");
			printf("1.タスクの追加\n");
			printf("2.タスクの削除\n");
			printf("3.タスクの表示\n");
			printf("4.メンバー追加\n");
			printf("5.メンバー削除\n");
			printf("6.メンバー表示\n");
			printf("7.終了\n");

			MenuNum menuNum;

			printf("\n---------------------------\n");
			printf("操作を選択してください(数字を入力)\n");
			while (true) {
				scanf_s("%d", &menuNum);
				scanf_s("%*[^\n]%*c");


				if (menuNum < 1 || menuNum > 7)printf("そんな操作はないよ\n");
				else break;

			}
			//メニューを代入
			menuNum_ = menuNum;

			//4を選んだ場合終了
			if (menuNum_ == MenuNum::End_)break;
		}
		//追加
		else if (menuNum_ == MenuNum::Add_) {
			AddTask();
		}
		//削除
		else if (menuNum_ == MenuNum::Delete_) {

		}
		//表示
		else if (menuNum_ == MenuNum::Display_) {
			//タスク表示
			Display();
			printf("1.メニューへ戻る\n");

			printf("操作を選択してください(数字を入力)\n");
			int menuNum;
			while (true) {
				scanf_s("%d", &menuNum);
				scanf_s("%*[^\n]%*c");

				if (menuNum < 1 || menuNum > 1)printf("そんな操作はないよ\n");
				else break;

			}
			//メニューに戻る
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
				printf("メンバー無し\n");
			}

			printf("1.メニューへ戻る\n");

			printf("操作を選択してください(数字を入力)\n");
			int menuNum;
			while (true) {
				scanf_s("%d", &menuNum);
				scanf_s("%*[^\n]%*c");

				if (menuNum < 1 || menuNum > 1)printf("そんな操作はないよ\n");
				else break;

			}
			//メニューに戻る
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
		printf("タスクidを入力してください\n");
		char id_[5];
		scanf_s("%s", id_,5);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->id,5, id_);

		printf("\n---------------------------\n");
		printf("メンバーを入力してください\n");
		int member;
		scanf_s("%d", &member);
		scanf_s("%*[^\n]%*c");

		newTask_->manager = member_.at(0);

		printf("\n---------------------------\n");
		printf("題名を入力してください\n");
		char title[20];
		scanf_s("%s", title, 20);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->title, 20, title);

		printf("\n---------------------------\n");
		printf("内容を入力してください\n");
		char content[30];
		scanf_s("%s", content, 30);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->content, 30, content);

		printf("\n---------------------------\n");
		printf("優先度を入力してください\n");
		char priority[15];
		scanf_s("%s", priority, 15);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->priority, 15, priority);

		printf("\n---------------------------\n");
		printf("期限を入力してください\n");
		char time[10];
		scanf_s("%s", time, 10);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->time, 10, time);

		strcpy_s(newTask_->status, 10,"未完了");

		break;
	}
	printf("タスクを追加しました\n");
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
		printf("\nタスク無し\n\n");
	}
}

void TaskManager::AddMember()
{

	Manager* manager = new Manager;

	manager->Init();

	while (true) {
		printf("\n---------------------------\n");
		printf("メンバーidを入力してください\n");
		char id_[5];
		scanf_s("%s", id_, 5);
		scanf_s("%*[^\n]%*c");

		strcpy_s(manager->id, 5, id_);

		printf("\n---------------------------\n");
		printf("氏名を入力してください\n");
		char name_[20];
		scanf_s("%s", name_, 20);
		scanf_s("%*[^\n]%*c");

		strcpy_s(manager->managerName, 20, name_);

		printf("\n---------------------------\n");
		printf("クラスを入力してください\n");
		char className_[10];
		scanf_s("%s", className_, 10);
		scanf_s("%*[^\n]%*c");

		strcpy_s(manager->className, 20, className_);

		break;
	}
	printf("メンバーを追加しました\n");
	member_.push_back(*manager);

	menuNum_ = MenuNum::Menu_;
}

void TaskManager::Delete(int num)
{
}
