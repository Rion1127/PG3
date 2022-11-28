#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//双方向リストの構造体の定義
typedef struct cell
{
	char str[8];
	struct cell* next;
}CELL;

enum menu {
	MENU,
	DISPLAY_,
	INSERT_,
	DELETE_,
};

void Create(CELL* currentCELL, const char* buf);
void Index(CELL* endCell);
void Delete(CELL* currentCELL);

int main() {
	char str[8];

	int selectMenu = menu::MENU;

	CELL head;
	head.next = nullptr;

	while (true) {
		//メニュー
		if (selectMenu == menu::MENU) {
			printf("\n[要素の操作]\n");
			printf("1.要素の一覧表示\n");
			printf("2.最後尾に要素の挿入\n");
			printf("3.最後尾の要素の削除\n");
			printf("\n---------------------\n");
			printf("操作を選択してください\n");

			scanf_s("%d", &selectMenu);
			
			//表示されていない番号以外を入力されたらもう一度入力させる
			if (selectMenu < menu::DISPLAY_ ||
				selectMenu > menu::DELETE_)
			{
				printf("エラー\n表示されている番号を選択してください\n");
				selectMenu = menu::MENU;
			}
		}
		//表示
		else if (selectMenu == menu::DISPLAY_) {
			//リスト一覧の表示
			Index(&head);

			printf("\n---------------------\n");

			printf("0.初期画面に戻る\n");
			scanf_s("%d", &selectMenu);

			//表示されていない番号以外を入力されたらもう一度入力させる
			if (selectMenu != 0)
			{
				printf("エラー\n表示されている番号を選択してください\n");
				selectMenu = menu::DISPLAY_;
			}
		}
		//挿入
		else if (selectMenu == menu::INSERT_) {
			printf("\n[リスト要素の挿入]\n");
			printf("\n追加する文字を入力してください\n");
			scanf_s("%s", str, 8);
			printf("\n要素`%s`がリストの最後尾に挿入されました\n", str);
			//最後尾にセルを追加
			Create(&head, str);

			printf("\n---------------------\n");
			printf("0.初期画面に戻る\n");
			scanf_s("%d", &selectMenu);

			//表示されていない番号以外を入力されたらもう一度入力させる
			if (selectMenu != 0)
			{
				printf("エラー\n表示されている番号を選択してください\n");
				selectMenu = menu::INSERT_;
			}
		}
		//削除
		else if (selectMenu == menu::DELETE_) {
			int select = 0;
			printf("\n[要素の操作]\n");
			printf("1.最後尾の要素を削除する\n");
			printf("2.初期画面に戻る\n");
			scanf_s("%d", &select);
			//削除する
			if (select == 1) {

				Delete(&head);

				printf("最後尾の要素を削除しました\n");

				printf("\n---------------------\n");
				printf("0.初期画面に戻る\n");
				scanf_s("%d", &selectMenu);

				//表示されていない番号以外を入力されたらもう一度入力させる
				if (selectMenu != 0)
				{
					printf("エラー\n表示されている番号を選択してください\n");
					selectMenu = menu::INSERT_;
				}
			}
			//メニューに戻る
			else if (select == 2) {
				selectMenu = menu::MENU;
			}
		}
	}


	return 0;
}

void Create(CELL* currentCELL, const char* buf)
{
	//新規セルを作成
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->str, 8, buf);
	newCell->next = nullptr;
	//指定したセルに次のセルがある場合
	//次のセルの前のポインタに新規セルのアドレスを代入
	while (currentCELL->next != nullptr) {
		//次のセルのアドレスを代入
		currentCELL = currentCELL->next;
	}
	//指定したセルの「次のセルのポインタに新規セルのアドレスを代入」
	currentCELL->next = newCell;
}

void Index(CELL* endCell)
{
	int no = 0;
	printf("\n[要素の一覧表示]\n");
	//nextにアドレスがある限りループ
	printf("要素一覧:{\n");
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d: %s,\n", no, endCell->str);
		no++;
	}
	printf("}\n");
	printf("\n要素数: %d\n", no);
}

void Delete(CELL* currentCELL)
{
	//中身が入っている時
	if (currentCELL->next) {
		while (currentCELL->next->next != nullptr) {
			//次のセルのアドレスを代入
			currentCELL = currentCELL->next;
		}
	}

	if (currentCELL->next != nullptr) {
		delete currentCELL->next;
		currentCELL->next = nullptr;
	}
}
