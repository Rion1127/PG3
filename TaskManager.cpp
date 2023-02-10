#include "TaskManager.h"

void TaskManager::Update()
{
	Manager manager;

	manager.id = "01";
	manager.managerName = "suzuki";
	manager.className = "LE2A";

	menber_.push_back(manager);

	while (true) {
		//初期メニュー画面
		if (menuNum_ == MenuNum::Menu_) {
			printf("\n[メニュー]\n");
			printf("1.タスクの追加\n");
			printf("2.タスクの削除\n");
			printf("3.タスクの表示\n");
			printf("4.メンバー追加\n");
			printf("5.終了\n");

			MenuNum menuNum;

			printf("\n---------------------------\n");
			printf("操作を選択してください(数字を入力)\n");
			while (true) {
				scanf_s("%d", &menuNum);
				scanf_s("%*[^\n]%*c");


				if (menuNum < 1 || menuNum > 5)printf("そんな操作はないよ\n");
				else break;

			}
			//メニューを代入
			menuNum_ = menuNum;

			//4を選んだ場合終了
			if (menuNum_ == MenuNum::End_)break;
		}
		//追加
		else if (menuNum_ == MenuNum::Add_) {
			
			AddUpdate();


		}
		//削除
		else if (menuNum_ == MenuNum::Delete_) {

		}
		//表示
		else if (menuNum_ == MenuNum::Display_) {
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

		}
	}
}

void TaskManager::AddUpdate()
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
		int member_;
		scanf_s("%d", &member_);
		scanf_s("%*[^\n]%*c");

		newTask_->manager = &menber_.at(0);

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
	task_.push_back(std::move(*newTask_));
	
	menuNum_ = MenuNum::Menu_;
}

void TaskManager::Add(Task task)
{
}

void TaskManager::Delete(int num)
{
}
