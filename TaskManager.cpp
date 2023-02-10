#include "TaskManager.h"

void TaskManager::Update()
{
	while (true) {
		//初期メニュー画面
		if (menuNum_ == MenuNum::Menu_) {
			MenuUpdate();
		}
		//タスク追加
		else if (menuNum_ == MenuNum::AddTask_) {
			AddTask();
		}
		//タスク削除
		else if (menuNum_ == MenuNum::DeleteTask_) {
			DeleteTask();
		}
		//タスク表示
		else if (menuNum_ == MenuNum::DisplayTask_) {
			//タスク表示
			DisplayTask();
			//メニューに戻る
			menuNum_ = MenuNum::Menu_;
		}
		//タスク更新
		else if (menuNum_ == MenuNum::UpdateTask) {
			UpdateTask();
		}
		//担当者追加
		else if (menuNum_ == MenuNum::AddMember) {
			AddMember();
		}
		//担当者削除
		else if (menuNum_ == MenuNum::DeleteMember) {
			DeleteMember();
		}
		//担当者表示
		else if (menuNum_ == MenuNum::DisplayMember) {
			DisplayMember();
			//メニューに戻る
			menuNum_ = MenuNum::Menu_;
		}

		//4を選んだ場合終了
		if (menuNum_ == MenuNum::MenuNumEnd_)break;
	}
}
//メニュー更新
void TaskManager::MenuUpdate()
{
	//メニューの表示タイプ
	MenuType displayMenuType = MenuType::All;
	MenuNum menuNum;

	if (member_.size() <= 0)displayMenuType = MenuType::MemberAddOnly;
	if (member_.size() > 0 && task_.size() <= 0)displayMenuType = MenuType::TaskAddOnly;

	printf("\n[メニュー]\n");
	//担当者追加のみ表示（担当者が０名の時）
	if (displayMenuType == MenuType::MemberAddOnly) {
		printf("%d.担当者追加\n", MenuNum::AddMember);
		printf("%d.終了\n", MenuNum::MenuNumEnd_);

		printf("\n---------------------------\n");
		printf("操作を選択してください(数字を入力)\n");
		while (true) {
			printf(">");
			scanf_s("%d", &menuNum);
			scanf_s("%*[^\n]%*c");
			
			if (menuNum != MenuNum::AddMember &&
				menuNum != MenuNum::MenuNumEnd_) {
				//表示されているメニュー以外を選択したら
				printf("そんな操作はないよ\n");
			}
			else break;
		}
	}
	//タスク追加＋メンバー項目すべて表示（担当者が１名以上＆タスクが０個）
	else if (displayMenuType == MenuType::TaskAddOnly) {
		printf("%d.タスクの追加\n", MenuNum::AddTask_);
		printf("%d.担当者追加\n", MenuNum::AddMember);
		printf("%d.担当者削除\n", MenuNum::DeleteMember);
		printf("%d.担当者表示\n", MenuNum::DisplayMember);
		printf("%d.終了\n", MenuNum::MenuNumEnd_);

		printf("\n---------------------------\n");
		printf("操作を選択してください(数字を入力)\n");
		while (true) {
			printf(">");
			scanf_s("%d", &menuNum);
			scanf_s("%*[^\n]%*c");

			if (menuNum != MenuNum::AddTask_ &&
				menuNum != MenuNum::AddMember &&
				menuNum != MenuNum::DeleteMember && 
				menuNum != MenuNum::DisplayMember &&
				menuNum != MenuNum::MenuNumEnd_) {
				//表示されているメニュー以外を選択したら
				printf("そんな操作はないよ\n");
			}
			else break;
		}
	}
	//すべて表示
	else if (displayMenuType == MenuType::All) {
		printf("%d.タスクの追加\n", MenuNum::AddTask_);
		printf("%d.タスクの削除\n", MenuNum::DeleteTask_);
		printf("%d.タスクの表示\n", MenuNum::DisplayTask_);
		printf("%d.タスクの更新\n", MenuNum::UpdateTask);
		printf("%d.担当者追加\n", MenuNum::AddMember);
		printf("%d.担当者削除\n", MenuNum::DeleteMember);
		printf("%d.担当者表示\n", MenuNum::DisplayMember);
		printf("%d.終了\n", MenuNum::MenuNumEnd_);

		printf("\n---------------------------\n");
		printf("操作を選択してください(数字を入力)\n");
		while (true) {
			printf(">");
			scanf_s("%d", &menuNum);
			scanf_s("%*[^\n]%*c");

			if (menuNum < 1 || menuNum > 8)printf("そんな操作はないよ\n");
			else break;
		}
	}
	
	

	

	
	//メニューを代入
	menuNum_ = menuNum;
}
//タスク追加
void TaskManager::AddTask()
{
	Task* newTask_ = new Task;
	newTask_->Init();

	while (true) {
		if (member_.size() != 0) {
			printf("\n---------------------------\n");
			printf("タスクidを入力してください\n");
			int id_;
			printf(">");
			scanf_s("%d", &id_);
			scanf_s("%*[^\n]%*c");

			newTask_->id = id_;
		}
		else {
			printf("担当者がいません\n");
			break;
		}

		DisplayMember();
		while (true) {
			printf("担当者IDを入力してください\n");

			int member;
			printf(">");
			scanf_s("%d", &member);
			scanf_s("%*[^\n]%*c");

			auto itr = member_.find(member);        // IDが設定されているか探す
			if (itr != member_.end()) {
				//設定されている場合の処理
				newTask_->manager = member_.at(member);
				break;
			}
			else {
				//設定されていない場合の処理
				printf("担当者IDが一致しませんでした\n");
			}
		}

		printf("\n---------------------------\n");
		printf("題名を入力してください\n");
		char title[20];
		printf(">");
		scanf_s("%s", title, 20);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->title, 20, title);

		printf("\n---------------------------\n");
		printf("内容を入力してください\n");
		char content[30];
		printf(">");
		scanf_s("%s", content, 30);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->content, 30, content);

		printf("\n---------------------------\n");
		printf("優先度を入力してください\n");
		char priority[15];
		printf(">");
		scanf_s("%s", priority, 15);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->priority, 15, priority);

		printf("\n---------------------------\n");
		printf("期限を入力してください\n");
		char time[10];
		printf(">");
		scanf_s("%s", time, 10);
		scanf_s("%*[^\n]%*c");

		strcpy_s(newTask_->time, 10, time);

		strcpy_s(newTask_->status, 10, "未完了");

		task_.insert(std::make_pair(newTask_->id, *newTask_));

		printf("タスクを以下の内容で追加しました\n\n");
		printf("-----------------------------------------------\n");
		task_.at(newTask_->id).Draw();
		printf("-----------------------------------------------\n");

		break;
	}
	menuNum_ = MenuNum::Menu_;
}
//タスク削除
void TaskManager::DeleteTask()
{
	//タスクがある場合
	if (task_.size() != 0) {
		//タスク表示
		DisplayTask();
		while (true) {
			printf("タスクIDを入力してください\n");

			int member;
			printf(">");
			scanf_s("%d", &member);
			scanf_s("%*[^\n]%*c");

			auto itr = task_.find(member);        // タスクが設定されているか探す
			if (itr != task_.end()) {
				//設定されている場合の処理
				task_.erase(itr->first);
				printf("タスクを削除しました\n");
				break;
			}
			else {
				//設定されていない場合の処理
				printf("タスクIDが一致しませんでした\n");
			}
		}
	}
	//タスクがない場合
	else {
		printf("タスクがありません\n");
	}
	//メニューに戻る
	menuNum_ = MenuNum::Menu_;
}
//タスク表示
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
		printf("\nタスク無し\n\n");
	}
}
//タスク更新
void TaskManager::UpdateTask()
{
	//タスクがある場合
	if (task_.size() != 0) {
		while (true) {
			//タスク表示
			DisplayTask();
			printf("\nタスクIDを入力してください\n");
			printf("'0'キーでメニューに戻ります\n");


			int member;
			printf(">");
			scanf_s("%d", &member);
			scanf_s("%*[^\n]%*c");
			//メニューに戻る
			if (member == 0) break;

			auto taskitr = task_.find(member);        // タスクが設定されているか探す
			if (taskitr != task_.end()) {
				//設定されている場合の処理
				while (true) {

					taskitr->second.Draw();
					printf("\nどの項目を更新しますか\n");
					TaskItem itemNum;	//項目
					while (true) {
						printf("更新する内容を選択してください(数字を入力)\n");
						printf("%d.担当者\n"		,TaskItem::Manager_);
						printf("%d.タイトル\n"		,TaskItem::Title_);
						printf("%d.内容\n"		,TaskItem::Content_);
						printf("%d.優先度\n"		,TaskItem::Priority_);
						printf("%d.期限\n"		,TaskItem::Time_);
						printf("%d.ステータス\n"	,TaskItem::Status_);
						printf(">");
						scanf_s("%d", &itemNum);
						scanf_s("%*[^\n]%*c");

						if (itemNum < TaskItem::Manager_ || itemNum > TaskItem::TaskItemEnd_)printf("そんな操作はないよ\n");
						else break;
					}

					//担当者
					if (itemNum == TaskItem::Manager_) {
						DisplayMember();
						while (true) {
							printf("\n担当者IDを入力してください\n");

							int member;
							printf(">");
							scanf_s("%d", &member);
							scanf_s("%*[^\n]%*c");

							auto memberItr = member_.find(member);        // IDが設定されているか探す
							if (memberItr != member_.end()) {
								//設定されている場合の処理
								taskitr->second.manager = member_.at(member);
								printf("担当者を更新しました\n");
								break;
							}
							else {
								//設定されていない場合の処理
								printf("担当者IDが一致しませんでした\n");
							}
						}
					}
					//タイトル
					else if (itemNum == TaskItem::Title_) {
						printf("\n題名を入力してください\n");
						char title[20];
						printf(">");
						scanf_s("%s", title, 20);
						scanf_s("%*[^\n]%*c");

						strcpy_s(taskitr->second.title, 20, title);
					}
					//内容
					else if (itemNum == TaskItem::Content_) {
						printf("\n内容を入力してください\n");
						char content[30];
						printf(">");
						scanf_s("%s", content, 30);
						scanf_s("%*[^\n]%*c");

						strcpy_s(taskitr->second.content, 30, content);
					}
					//優先度
					else if (itemNum == TaskItem::Priority_) {
						printf("\n優先度を入力してください\n");
						char priority[15];
						printf(">");
						scanf_s("%s", priority, 15);
						scanf_s("%*[^\n]%*c");

						strcpy_s(taskitr->second.priority, 15, priority);
					}
					//期限
					else if (itemNum == TaskItem::Time_) {
						printf("\n期限を入力してください\n");
						char time[10];
						printf(">");
						scanf_s("%s", time, 10);
						scanf_s("%*[^\n]%*c");

						strcpy_s(taskitr->second.time, 10, time);
					}
					//ステータス
					else if (itemNum == TaskItem::Status_) {
						printf("\nステータスを入力してください\n");
						printf("1.完了\n");
						printf("2.進行中\n");
						printf("3.未完了\n");

						int status;
						while (true) {
							printf(">");
							scanf_s("%d", &status);
							scanf_s("%*[^\n]%*c");
							if (status < 1 || status > 3)printf("そんな操作はないよ\n");
							else break;
						}
						const char* statusName = "完了";
						if (status == 1)statusName = "完了";
						if (status == 2)statusName = "進行中";
						if (status == 3)statusName = "未完了";

						strcpy_s(taskitr->second.status, 10, statusName);
					}

					//設定されている時の処理を終了
					break;
				}
			}
			else {
				//設定されていない場合の処理
				printf("タスクIDが一致しませんでした\n");
			}
		}
	}
	//タスクがない場合
	else {
		printf("タスクがありません\n");
	}
	//メニューに戻る
	menuNum_ = MenuNum::Menu_;
}
//担当者追加
void TaskManager::AddMember()
{
	Manager* manager = new Manager;
	manager->Init();

	while (true) {
		printf("\n---------------------------\n");
		printf("担当者idを入力してください\n");
		int id_;
		printf(">");
		scanf_s("%d", &id_);
		scanf_s("%*[^\n]%*c");

		manager->id = id_;

		printf("\n---------------------------\n");
		printf("氏名を入力してください\n");
		char name_[20];
		printf(">");
		scanf_s("%s", name_, 20);
		scanf_s("%*[^\n]%*c");

		strcpy_s(manager->managerName, 20, name_);

		printf("\n---------------------------\n");
		printf("クラスを入力してください\n");
		char className_[10];
		printf(">");
		scanf_s("%s", className_, 10);
		scanf_s("%*[^\n]%*c");

		strcpy_s(manager->className, 10, className_);

		break;
	}
	

	member_.insert(std::make_pair(manager->id, *manager));

	printf("担当者を追加しました\n\n");
	printf("-----------------------------------------------\n");
	member_.at(manager->id).Draw();
	printf("-----------------------------------------------\n");

	menuNum_ = MenuNum::Menu_;
}
//担当者削除
void TaskManager::DeleteMember()
{
	if (member_.size() != 0) {
		DisplayMember();
		while (true) {
			printf("担当者IDを入力してください\n");

			int member;
			printf(">");
			scanf_s("%d", &member);
			scanf_s("%*[^\n]%*c");

			auto itr = member_.find(member);        // IDが設定されているか探す
			if (itr != member_.end()) {
				//設定されている場合の処理
				member_.erase(itr->first);
				printf("担当者を削除しました\n");
				break;
			}
			else {
				//設定されていない場合の処理
				printf("担当者IDが一致しませんでした\n");
			}
		}
	}
	else {
		printf("担当者がいません\n");
	}
	//メニューに戻る
	menuNum_ = MenuNum::Menu_;
}
//担当者表示
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
		printf("担当者無し\n");
	}
}
