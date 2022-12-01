#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//双方向リストの構造体の定義
typedef struct cell
{
	char val[8];
	struct cell* prev;
	struct cell* next;
}CELL;

enum menu {
	MENU,
	DISPLAY_,
	INSERT_,
	EDIT_,
	DELETE_,
	SORTING_
};

void Create(CELL* currentCELL, const char* val);
void Index(CELL* endCell);
/// <summary>
/// 任意の位置まで、アドレスをたどる
/// </summary>
/// <param name="endCELL"></param>
/// <param name="iterator">要素数</param>
/// <returns></returns>
CELL* GetInsertListAddress(CELL* endCELL, int iterator);
//メニュー更新
void MenuUpdate(const CELL cell, int& menuNum);
//一覧表示更新
void DisplayUpdate(CELL cell,int& menuNum,int& selectNum);
void ShowCell(CELL* endCELL);
//挿入更新
void InsertUpdate(CELL& cell, int& menuNum);
//編集更新
void EditUpdate(CELL cell, int& menuNum);
//削除更新
void DeleteUpdate(CELL cell, int& menuNum);

int main() {
	int menuNum = menu::MENU;
	int selectNum = 0;

	CELL head{};
	head.next = nullptr;

	while (true) {
		//メニュー
		if (menuNum == menu::MENU) {
			MenuUpdate(head, menuNum);
		}
		//表示
		else if (menuNum == menu::DISPLAY_) {
			DisplayUpdate(head,menuNum,selectNum);
		}
		//挿入
		else if (menuNum == menu::INSERT_) {
			InsertUpdate(head, menuNum);
		}
		//編集
		else if (menuNum == menu::EDIT_) {
			EditUpdate(head, menuNum);
		}
		//削除
		else if (menuNum == menu::DELETE_) {
			DeleteUpdate(head, menuNum);
		}
		//並べ替え
		else if (menuNum == menu::SORTING_) {

		}
	}
	return 0;
}

void Create(CELL* currentCELL, const char* val)
{
	//新規セルを作成
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	//newCell->val = val;
	strcpy_s(newCell->val, 8, val);
	newCell->prev = nullptr;
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
		printf("val : %s ", endCell->val);		//5桁まで右揃え
		printf("NowAd : (%p) ", endCell);
		printf("nextAd : %p\n", endCell->next);
		no++;
	}
}
// 任意の位置まで、アドレスをたどる
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
//メニュー更新
void MenuUpdate(CELL cell, int& menuNum)
{
	printf("\n[要素の操作]\n");
	printf("1.要素の表示\n");
	printf("2.要素の挿入\n");
	//中身がない場合は表示しない
	if (cell.next != nullptr) {
		printf("3.要素の編集\n");
		printf("4.要素の削除\n");
	}

	//printf("5.要素の並び替え(オプション)\n");
	printf("\n---------------------------\n");
	printf("操作を選択してください(数字を入力)\n");
	while (true) {
		scanf_s("%d", &menuNum);
		scanf_s("%*[^\n]%*c");

		//中身があるとき
		if (cell.next != nullptr) {

			if (menuNum < 1 || menuNum > 4) {
				printf("そんな操作はないよ\n");
			}
			else {
				break;
			}
		}
		//中身がないとき
		else {
			if (menuNum < 1 || menuNum > 2) {
				printf("そんな操作はないよ\n");
			}
			else {
				break;
			}
		}
	}
}
//一覧表示更新
void ShowCell(CELL* endCell)
{
	printf("\n[要素の一覧表示]\n");
	printf("要素一覧: {\n");

	int no = 0;
	//nextにアドレスがある限りループ
	while (endCell->next != nullptr) {

		endCell = endCell->next;
		printf("%d: ", no);
		printf("%s,\n", endCell->val);		//5桁まで右揃え
		no++;

	}
	printf("}\n");
	printf("\n要素数: %d\n", no);
}
void DisplayUpdate(CELL cell, int& menuNum, int& selectNum)
{
	//要素の表示
	if (selectNum == 0) {
		printf("\n[要素の表示]\n");
		printf("1.要素の一覧表示\n");
		printf("2.順番を指定して要素を表示\n");
		printf("9.要素操作に戻る\n");

		scanf_s("%d", &selectNum);
		scanf_s("%*[^\n]%*c");

		if (selectNum == 9) {
			menuNum = menu::MENU;
			selectNum = 0;
		}
	}
	//要素の一覧表示
	else if (selectNum == 1) {

		ShowCell(&cell);

		printf("\n---------------------------\n");
		printf("1.要素の表示に戻る\n");
		printf("2.要素の操作に戻る\n");

		scanf_s("%d", &selectNum);
		scanf_s("%*[^\n]%*c");
		//要素の表示に戻る
		if (selectNum == 1) {
			selectNum = 0;
		}
		//要素の操作に戻る
		else if (selectNum == 2) {
			menuNum = menu::MENU;
			selectNum = 0;
		}
	}
	//要素を指定して表示
	else if (selectNum == 2) {
		int displauNum = 0;

		printf("\n[表示したい要素を指定]\n");
		printf("表示したい要素を指定してください\n");
		scanf_s("%d", &displauNum);
		CELL* displayCell = GetInsertListAddress(&cell, displauNum + 1);
		//表示
		printf("%d : %s\n", displauNum, displayCell->val);

		printf("\n---------------------------\n");
		printf("1.要素の表示に戻る\n");
		printf("2.要素の操作に戻る\n");

		scanf_s("%d", &selectNum);
		scanf_s("%*[^\n]%*c");
		//要素の表示に戻る
		if (selectNum == 1) {
			selectNum = 0;
		}
		//要素の操作に戻る
		else if (selectNum == 2) {
			menuNum = menu::MENU;
			selectNum = 0;
		}
	}
}
//挿入更新
void InsertUpdate(CELL& cell, int& menuNum)
{
	int iterator;
	const char inputValue[8]{};

	CELL* insertCell;

	printf("\n[リストの要素の挿入]\n");
	printf("何番目のセルの後ろに挿入しますか？\n");
	scanf_s("%d", &iterator);
	scanf_s("%*[^\n]%*c");

	printf("挿入する値を入力してください\n");
	scanf_s("%s", &inputValue, 8);

	//任意のセルの後ろに追加
	insertCell = GetInsertListAddress(&cell, iterator);
	Create(insertCell, inputValue);

	printf("\n`%s`が%d番目に挿入されました\n", inputValue, iterator);

	menuNum = menu::MENU;
}
//編集更新
void EditUpdate(CELL cell, int& menuNum)
{
	int iterator = 0;
	const char inputValue[8]{};
	CELL* insertCell;

	printf("\n[要素の編集]\n");

	printf("編集したい要素の番号を指定してください\n");
	scanf_s("%d", &iterator);
	scanf_s("%*[^\n]%*c");

	insertCell = GetInsertListAddress(&cell, iterator);
	//x番目がある場合
	if (insertCell->next != nullptr) {
		printf("x番目の要素の変更する値を入力してください\n");
		scanf_s("%s", inputValue, 8);

		//insertCell->next->val = inputValue;
		strcpy_s(insertCell->next->val, 8, inputValue);
		printf("%d番目の要素の値が`%s`に変更されました\n", iterator, inputValue);
	}
	//x番目がない場合
	else {
		printf("%d番目の要素が見つかりませんでした\n", iterator);
	}

	menuNum = menu::MENU;

}
//削除更新
void DeleteUpdate(CELL cell, int& menuNum)
{
	int iterator;
	CELL* insertCell;
	printf("\n[要素の削除]\n");

	printf("削除したい要素の番号を指定してください\n");
	scanf_s("%d", &iterator);
	scanf_s("%*[^\n]%*c");

	insertCell = GetInsertListAddress(&cell, iterator);
	//x番目がある場合
	if (insertCell->next != nullptr) {
		CELL* p = &cell;

		for (int i = 0; i < iterator + 1; i++) {
			p = p->next;
		}

		printf("%d番目の要素`%s`を削除しました\n", iterator, p->val);

		p->prev->next = p->next;
		//p->nextがある場合
		if (p->next != nullptr) {
			p->next->prev = p->prev;
		}
		p->next = nullptr;
		p->prev = nullptr;
	}
	//x番目がない場合
	else {
		printf("%d番目の要素が見つかりませんでした\n", iterator);
	}

	menuNum = menu::MENU;
}
