#include <stdio.h>
#include <stdlib.h>

//双方向リストの構造体の定義
typedef struct cell
{
	int val;
	struct cell* prev;
	struct cell* next;
}CELL;

enum menu {
	NONE,
	DISPLAY_,
	INSERT_,
	EDIT_,
	DELETE_,
	SORTING_
};

void Create(CELL* currentCELL, int val);
void Index(CELL* endCell);
/// <summary>
/// 任意の位置まで、アドレスをたどる
/// </summary>
/// <param name="endCELL"></param>
/// <param name="iterator">要素数</param>
/// <returns></returns>
CELL* GetInsertListAddress(CELL* endCELL, int iterator);

void DisplayUpdate(CELL* endCELL);

int main() {
	int iterator;
	int inputValue;
	CELL* insertCell;

	int menuNum;


	CELL head;
	head.next = nullptr;

	while (true) {

		printf("[要素の操作]\n");
		printf("1.要素の表示\n");
		printf("2.要素の挿入\n");
		printf("3.要素の編集\n");
		printf("4.要素の削除\n");

		printf("5.要素の並び替え(オプション)\n");
		printf("\n---------------------------\n");
		printf("操作を選択してください\n");
		scanf_s("%d", &menuNum);

		//表示
		if (menuNum == menu::DISPLAY_) {
			DisplayUpdate(&head);
		}
		//挿入
		else if (menuNum == menu::INSERT_) {

		}
		//編集
		else if (menuNum == menu::EDIT_) {

		}
		//削除
		else if (menuNum == menu::DELETE_) {

		}
		//並べ替え
		else if (menuNum == menu::SORTING_) {

		}




		printf("何番目のセルの後ろに挿入しますか？\n");
		scanf_s("%d", &iterator);

		printf("挿入する値を入力してください\n");
		scanf_s("%d", &inputValue);

		//任意のセルの後ろに追加
		insertCell = GetInsertListAddress(&head, iterator);
		Create(insertCell, inputValue);

		//リスト一覧の表示
		Index(&head);
	}


	return 0;
}

void Create(CELL* currentCELL, int val)
{
	//新規セルを作成
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	newCell->prev = currentCELL;
	newCell->next = currentCELL->next;
	//指定したセルに次のセルがある場合
	//次のセルの前のポインタに新規セルのアドレスを代入
	if (currentCELL->next) {
		//次のセルのアドレスを代入
		CELL* nextCell = currentCELL->next;
		//次のセルの前のポインタに新規セルのアドレスを代入
		nextCell->prev = newCell;
	}
	//指定したセルの「次のセルのポインタに新規セルのアドレスを代入」
	currentCELL->next = newCell;
}

void Index(CELL* endCell)
{
	int no = 1;
	//nextにアドレスがある限りループ
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("No : %d ", no);
		printf("prevAd : %p ", endCell->prev);
		printf("val : %d ", endCell->val);		//5桁まで右揃え
		printf("NowAd : (%p) ", endCell);
		printf("nextAd : %p\n", endCell->next);
		no++;
	}
}

CELL* GetInsertListAddress(CELL* endCELL, int iterator)
{
	//指定した数forループする
	for (int i = 0; i < iterator; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
		}
		else {
			//iteratorにセルの総数より大きな数字を入力されることがあるため、
			//最後尾まで到達したらforループから抜けるようにする
			break;
		}
	}

	return endCELL;
}

void DisplayUpdate(CELL* endCell)
{
	int allNum = 0;
	while (endCell->next != nullptr) {
		allNum++;
	}
	printf("[要素の一覧表示]\n");
	printf("要素数: %d\n", allNum);
	printf("要素一覧: {\n");

	int no = 0;
	//nextにアドレスがある限りループ
	while (endCell != nullptr) {
		endCell = endCell->next;
		printf("%d: ", no);
		printf("%d,", endCell->val);		//5桁まで右揃え
		no++;
	}
	printf("}\n");

	printf("\n---------------------------\n");
	printf("1.要素の表示に戻る\n");
	printf("2.要素の操作に戻る\n");
	//scanf_s("%d", &menuNum);
}
