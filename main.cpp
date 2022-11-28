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

int main() {
	char str[8];

	int selectMenu = menu::MENU;

	CELL head;
	head.next = nullptr;

	while (true) {

		if (selectMenu == menu::MENU) {
			printf("[要素の操作]\n");
			printf("1.要素の一覧表示\n");
			printf("2.最後尾に要素の挿入\n");
			printf("3.最後尾の要素の削除\n");
			printf("\n---------------------\n");
			printf("操作を選択してください\n");
			scanf_s("%d", &selectMenu);
		}
		else if (selectMenu == menu::DISPLAY_) {
			//リスト一覧の表示
			Index(&head);

			printf("\n---------------------\n");
			while (true) {
				printf("0.初期画面に戻る\n");
				scanf_s("%d", &selectMenu);
				if (selectMenu == 0) {
					break;
				}
				
				if(selectMenu != 0) {
					printf("その番号は使用できません\n");
					scanf_s("%d", &selectMenu);
				}
			}
		}
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
	while(currentCELL->next != nullptr){
		//次のセルのアドレスを代入
		currentCELL = currentCELL->next;
	}
	//指定したセルの「次のセルのポインタに新規セルのアドレスを代入」
	currentCELL->next = newCell;
}

void Index(CELL* endCell)
{
	//nextにアドレスがある限りループ
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%s\n", endCell->str);
	}
}