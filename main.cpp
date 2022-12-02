#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�o�������X�g�̍\���̂̒�`
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
/// �C�ӂ̈ʒu�܂ŁA�A�h���X�����ǂ�
/// </summary>
/// <param name="endCELL"></param>
/// <param name="iterator">�v�f��</param>
/// <returns></returns>
CELL* GetInsertListAddress(CELL* endCELL, int iterator);
int GetCellAllNum(CELL cell);
//���j���[�X�V
void MenuUpdate(const CELL cell, int& menuNum);
//�ꗗ�\���X�V
void DisplayUpdate(CELL cell, int& menuNum, int& selectNum);
void ShowCell(CELL* endCELL);
//�}���X�V
void InsertUpdate(CELL& cell, int& menuNum);
//�ҏW�X�V
void EditUpdate(CELL cell, int& menuNum);
//�폜�X�V
void DeleteUpdate(CELL cell, int& menuNum);

int main() {
	int menuNum = menu::MENU;
	int selectNum = 0;

	CELL head{};
	head.next = nullptr;

	while (true) {
		//���j���[
		if (menuNum == menu::MENU) {
			MenuUpdate(head, menuNum);
		}
		//�\��
		else if (menuNum == menu::DISPLAY_) {
			DisplayUpdate(head, menuNum, selectNum);
		}
		//�}��
		else if (menuNum == menu::INSERT_) {
			InsertUpdate(head, menuNum);
		}
		//�ҏW
		else if (menuNum == menu::EDIT_) {
			EditUpdate(head, menuNum);
		}
		//�폜
		else if (menuNum == menu::DELETE_) {
			DeleteUpdate(head, menuNum);
		}
		//���בւ�
		else if (menuNum == menu::SORTING_) {

		}
	}
	return 0;
}

void Create(CELL* currentCELL, const char* val)
{
	//�V�K�Z�����쐬
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	//newCell->val = val;
	strcpy_s(newCell->val, 8, val);
	newCell->prev = nullptr;
	newCell->prev = currentCELL;
	newCell->next = currentCELL->next;
	//�w�肵���Z���Ɏ��̃Z��������ꍇ
	//���̃Z���̑O�̃|�C���^�ɐV�K�Z���̃A�h���X����
	if (currentCELL->next) {
		//���̃Z���̃A�h���X����
		CELL* nextCell = currentCELL->next;
		//���̃Z���̑O�̃|�C���^�ɐV�K�Z���̃A�h���X����
		nextCell->prev = newCell;
	}
	//�w�肵���Z���́u���̃Z���̃|�C���^�ɐV�K�Z���̃A�h���X�����v
	currentCELL->next = newCell;
}
void Index(CELL* endCell)
{
	int no = 1;
	//next�ɃA�h���X��������胋�[�v
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("No : %d ", no);
		printf("prevAd : %p ", endCell->prev);
		printf("val : %s ", endCell->val);		//5���܂ŉE����
		printf("NowAd : (%p) ", endCell);
		printf("nextAd : %p\n", endCell->next);
		no++;
	}
}
// �C�ӂ̈ʒu�܂ŁA�A�h���X�����ǂ�
CELL* GetInsertListAddress(CELL* endCELL, int iterator)
{

	//�w�肵����for���[�v����
	for (int i = 0; i < iterator; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
		}
		else {
			//iterator�ɃZ���̑������傫�Ȑ�������͂���邱�Ƃ����邽�߁A
			//�Ō���܂œ��B������for���[�v���甲����悤�ɂ���
			break;
		}
	}

	return endCELL;
}
int GetCellAllNum(CELL cell)
{
	int allNum = 0;
	CELL* insertCell = &cell;
	while (insertCell->next != nullptr)
	{
		insertCell = insertCell->next;
		allNum++;
	}

	return allNum;
}
//���j���[�X�V
void MenuUpdate(CELL cell, int& menuNum)
{
	printf("\n[�v�f�̑���]\n");
	printf("1.�v�f�̕\��\n");
	printf("2.�v�f�̑}��\n");
	//���g���Ȃ��ꍇ�͕\�����Ȃ�
	if (cell.next != nullptr) {
		printf("3.�v�f�̕ҏW\n");
		printf("4.�v�f�̍폜\n");
	}

	//printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");
	printf("\n---------------------------\n");
	printf("�����I�����Ă�������(���������)\n");
	while (true) {
		scanf_s("%d", &menuNum);
		scanf_s("%*[^\n]%*c");

		//���g������Ƃ�
		if (cell.next != nullptr) {
			//���j���[
			if (menuNum < 1 || menuNum > 4)printf("����ȑ���͂Ȃ���\n");
			else break;
		}
		//���g���Ȃ��Ƃ�
		else {
			if (menuNum < 1 || menuNum > 2)printf("����ȑ���͂Ȃ���\n");
			else break;
		}
	}
}
//�ꗗ�\���X�V
void ShowCell(CELL* endCell)
{
	int no = 0;

	printf("\n[�v�f�̈ꗗ�\��]\n");
	printf("�v�f�ꗗ: {\n");
	//next�ɃA�h���X��������胋�[�v
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d: ", no);
		printf("`%s`,\n", endCell->val);		//5���܂ŉE����
		no++;
	}
	printf("}\n");
	printf("\n�v�f��: %d\n", no);
}
void DisplayUpdate(CELL cell, int& menuNum, int& selectNum)
{
	//�v�f�̕\��
	if (selectNum == 0) {
		printf("\n[�v�f�̕\��]\n");
		printf("1.�v�f�̈ꗗ�\��\n");
		printf("2.���Ԃ��w�肵�ėv�f��\��\n");
		printf("9.�v�f����ɖ߂�\n");

		while (true) {
			selectNum = 0;
			scanf_s("%d", &selectNum);
			scanf_s("%*[^\n]%*c");
			//�I���ł��郁�j���[�ȊO����͂�����
			if (selectNum != 1 && selectNum != 2 && selectNum != 9) printf("����ȑ���͂Ȃ���\n");
			else break;
		}

		if (selectNum == 9) {
			menuNum = menu::MENU;
			selectNum = 0;
		}
	}
	//�v�f�̈ꗗ�\��
	else if (selectNum == 1) {

		ShowCell(&cell);

		printf("\n---------------------------\n");
		printf("1.�v�f�̕\���ɖ߂�\n");
		printf("2.�v�f�̑���ɖ߂�\n");

		while (true) {
			selectNum = 0;
			scanf_s("%d", &selectNum);
			scanf_s("%*[^\n]%*c");

			if (selectNum != 1 && selectNum != 2)printf("����ȑ���͂Ȃ���\n");
			else break;
		}
		//�v�f�̕\���ɖ߂�
		if (selectNum == 1) {
			selectNum = 0;
		}
		//�v�f�̑���ɖ߂�
		else if (selectNum == 2) {
			menuNum = menu::MENU;
			selectNum = 0;
		}
	}
	//�v�f���w�肵�ĕ\��
	else if (selectNum == 2) {
		int displauNum = 0;

		int maxNum = GetCellAllNum(cell);

		printf("\n[�\���������v�f���w��]\n");
		printf("�\���������v�f���w�肵�Ă�������\n");
		while (true) {
			scanf_s("%d", &displauNum);
			scanf_s("%*[^\n]%*c");

			//�w�肵���v�f�����݂�����
			if (displauNum < maxNum) {

				CELL* displayCell = &cell;
				for (int i = 0; i < displauNum + 1; i++) {
					displayCell = displayCell->next;
				}
				//�\��
				printf("%d : %s\n", displauNum, displayCell->val);
			}
			else {
				printf("���̗v�f�͑��݂��Ȃ���\n");
			}
			break;
		}

		printf("\n---------------------------\n");
		printf("1.�v�f�̕\���ɖ߂�\n");
		printf("2.�v�f�̑���ɖ߂�\n");

		//�����I��
		while (true) {
			selectNum = 0;
			scanf_s("%d", &selectNum);
			scanf_s("%*[^\n]%*c");

			if (selectNum != 1 && selectNum != 2) printf("����ȑ���͂Ȃ���\n");
			else break;
		}
		//�v�f�̕\���ɖ߂�
		if (selectNum == 1) {
			selectNum = 0;
		}
		//�v�f�̑���ɖ߂�
		else if (selectNum == 2) {
			menuNum = menu::MENU;
			selectNum = 0;
		}
	}
}
//�}���X�V
void InsertUpdate(CELL& cell, int& menuNum)
{
	int iterator = -1;
	const char inputValue[8]{};

	int allNum = GetCellAllNum(cell);

	CELL* insertCell;

	printf("\n[���X�g�̗v�f�̑}��]\n");
	printf("\n�v�f��ǉ�����ꏊ���w�肵�Ă�������\n");
	printf("(�w�萔���v�f�����������ꍇ�A�Ō���ɒǉ�����܂�)\n");
	while (true) {
		scanf_s("%d", &iterator);
		scanf_s("%*[^\n]%*c");

		if (iterator < 0) {
			printf("��������͂��Ă�\n");
		}
		else {
			break;
		}
	}

	printf("�ǉ�����l����͂��Ă�������\n");
	scanf_s("%s", &inputValue, 8);

	//�C�ӂ̃Z���̌��ɒǉ�
	insertCell = GetInsertListAddress(&cell, iterator);
	Create(insertCell, inputValue);


	int insertNum = 0;
	//�w�萔���v�f����葽���Ƃ�
	if (allNum < iterator)insertNum = allNum;
	//�v�f�����w�萔��葽���Ƃ�
	else insertNum = iterator;

	printf("\n�v�f`%s`��%d�Ԗڂɑ}������܂���\n", inputValue, insertNum);

	menuNum = menu::MENU;
}
//�ҏW�X�V
void EditUpdate(CELL cell, int& menuNum)
{
	int iterator = -1;
	const char inputValue[8]{};
	CELL* insertCell;

	printf("\n[�v�f�̕ҏW]\n");

	printf("�ҏW�������v�f�̔ԍ����w�肵�Ă�������\n");
	while (true) {
		scanf_s("%d", &iterator);
		scanf_s("%*[^\n]%*c");

		if (iterator < 0) {
			printf("��������͂��Ă�\n");
		}
		else {
			break;
		}
	}

	insertCell = GetInsertListAddress(&cell, iterator);
	//x�Ԗڂ�����ꍇ
	if (insertCell->next != nullptr) {
		printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă�������\n", iterator);
		scanf_s("%s", inputValue, 8);

		strcpy_s(insertCell->next->val, 8, inputValue);
		printf("%d�Ԗڂ̗v�f�̒l��`%s`�ɕύX����܂���\n", iterator, inputValue);
	}
	//x�Ԗڂ��Ȃ��ꍇ
	else {
		printf("%d�Ԗڂ̗v�f��������܂���ł���\n", iterator);
	}

	menuNum = menu::MENU;

}
//�폜�X�V
void DeleteUpdate(CELL cell, int& menuNum)
{
	int iterator = -1;
	CELL* insertCell;
	printf("\n[�v�f�̍폜]\n");

	printf("�폜�������v�f�̔ԍ����w�肵�Ă�������\n");
	while (true) {
		scanf_s("%d", &iterator);
		scanf_s("%*[^\n]%*c");

		if (iterator < 0) {
			printf("��������͂��Ă�\n");
		}
		else {
			break;
		}
	}

	insertCell = GetInsertListAddress(&cell, iterator);
	//x�Ԗڂ�����ꍇ
	if (insertCell->next != nullptr) {
		CELL* p = &cell;

		for (int i = 0; i < iterator + 1; i++) {
			p = p->next;
		}

		printf("%d�Ԗڂ̗v�f`%s`���폜���܂���\n", iterator, p->val);

		p->prev->next = p->next;
		//p->next������ꍇ
		if (p->next != nullptr) {
			p->next->prev = p->prev;
		}
		p->next = nullptr;
		p->prev = nullptr;
	}
	//x�Ԗڂ��Ȃ��ꍇ
	else {
		printf("%d�Ԗڂ̗v�f��������܂���ł���\n", iterator);
	}

	menuNum = menu::MENU;
}