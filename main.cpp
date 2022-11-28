#include <stdio.h>
#include <stdlib.h>

//�o�������X�g�̍\���̂̒�`
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
/// �C�ӂ̈ʒu�܂ŁA�A�h���X�����ǂ�
/// </summary>
/// <param name="endCELL"></param>
/// <param name="iterator">�v�f��</param>
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

		printf("[�v�f�̑���]\n");
		printf("1.�v�f�̕\��\n");
		printf("2.�v�f�̑}��\n");
		printf("3.�v�f�̕ҏW\n");
		printf("4.�v�f�̍폜\n");

		printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");
		printf("\n---------------------------\n");
		printf("�����I�����Ă�������\n");
		scanf_s("%d", &menuNum);

		//�\��
		if (menuNum == menu::DISPLAY_) {
			DisplayUpdate(&head);
		}
		//�}��
		else if (menuNum == menu::INSERT_) {

		}
		//�ҏW
		else if (menuNum == menu::EDIT_) {

		}
		//�폜
		else if (menuNum == menu::DELETE_) {

		}
		//���בւ�
		else if (menuNum == menu::SORTING_) {

		}




		printf("���Ԗڂ̃Z���̌��ɑ}�����܂����H\n");
		scanf_s("%d", &iterator);

		printf("�}������l����͂��Ă�������\n");
		scanf_s("%d", &inputValue);

		//�C�ӂ̃Z���̌��ɒǉ�
		insertCell = GetInsertListAddress(&head, iterator);
		Create(insertCell, inputValue);

		//���X�g�ꗗ�̕\��
		Index(&head);
	}


	return 0;
}

void Create(CELL* currentCELL, int val)
{
	//�V�K�Z�����쐬
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
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
		printf("val : %d ", endCell->val);		//5���܂ŉE����
		printf("NowAd : (%p) ", endCell);
		printf("nextAd : %p\n", endCell->next);
		no++;
	}
}

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

void DisplayUpdate(CELL* endCell)
{
	int allNum = 0;
	while (endCell->next != nullptr) {
		allNum++;
	}
	printf("[�v�f�̈ꗗ�\��]\n");
	printf("�v�f��: %d\n", allNum);
	printf("�v�f�ꗗ: {\n");

	int no = 0;
	//next�ɃA�h���X��������胋�[�v
	while (endCell != nullptr) {
		endCell = endCell->next;
		printf("%d: ", no);
		printf("%d,", endCell->val);		//5���܂ŉE����
		no++;
	}
	printf("}\n");

	printf("\n---------------------------\n");
	printf("1.�v�f�̕\���ɖ߂�\n");
	printf("2.�v�f�̑���ɖ߂�\n");
	//scanf_s("%d", &menuNum);
}
