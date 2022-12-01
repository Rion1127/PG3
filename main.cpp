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
	MENU,
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

	int menuNum = menu::MENU;
	int selectNum = 0;


	CELL head;
	head.next = nullptr;

	while (true) {

		if (menuNum == menu::MENU) {
			selectNum = 0;
			printf("\n[�v�f�̑���]\n");
			printf("1.�v�f�̕\��\n");
			printf("2.�v�f�̑}��\n");
			printf("3.�v�f�̕ҏW\n");
			printf("4.�v�f�̍폜\n");

			printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");
			printf("\n---------------------------\n");
			printf("�����I�����Ă�������\n");
			scanf_s("%d", &menuNum);
		}
		//�\��
		else if (menuNum == menu::DISPLAY_) {
			//�v�f�̕\��
			if (selectNum == 0) {
				printf("\n[�v�f�̕\��]\n");
				printf("1.�v�f�̈ꗗ�\��\n");
				printf("2.���Ԃ��w�肵�ėv�f��\��\n");
				printf("3.�v�f����ɖ߂�\n");

				scanf_s("%d", &selectNum);

				if (selectNum == 3) {
					menuNum = menu::MENU;
				}
			}
			//�v�f�̈ꗗ�\��
			else if (selectNum == 1) {

				DisplayUpdate(&head);

				printf("\n---------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");

				scanf_s("%d", &selectNum);
				//�v�f�̕\���ɖ߂�
				if (selectNum == 1) {
					selectNum = 0;
				}
				//�v�f�̑���ɖ߂�
				else if (selectNum == 2) {
					menuNum = menu::MENU;
				}
			}
			//���Ԃ��w�肵�ėv�f��\��
			else if (selectNum == 2) {


				printf("\n---------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");

				scanf_s("%d", &selectNum);

				//�v�f�̕\���ɖ߂�
				if (selectNum == 1) {
					selectNum = 0;
				}
				//�v�f�̑���ɖ߂�
				else if (selectNum == 2) {
					menuNum = menu::MENU;
				}
			}


		}
		//�}��
		else if (menuNum == menu::INSERT_) {
			printf("���Ԗڂ̃Z���̌��ɑ}�����܂����H\n");
			scanf_s("%d", &iterator);

			printf("�}������l����͂��Ă�������\n");
			scanf_s("%d", &inputValue);

			//�C�ӂ̃Z���̌��ɒǉ�
			insertCell = GetInsertListAddress(&head, iterator);
			Create(insertCell, inputValue);

			menuNum = menu::MENU;
		}
		//�ҏW
		else if (menuNum == menu::EDIT_) {
			printf("\n[�v�f�̕ҏW]\n");

			printf("�ҏW�������v�f�̔ԍ����w�肵�Ă�������\n");
			scanf_s("%d", &iterator);

			insertCell = GetInsertListAddress(&head, iterator);
			//x�Ԗڂ�����ꍇ
			if (insertCell->next != nullptr) {
				printf("x�Ԗڂ̗v�f�̕ύX����l����͂��Ă�������\n");
				scanf_s("%d", &inputValue);

				insertCell->next->val = inputValue;
				printf("%d�Ԗڂ̗v�f�̒l��`%d`�ɕύX����܂���\n", iterator, inputValue);
			}
			//x�Ԗڂ��Ȃ��ꍇ
			else {
				printf("x�Ԗڂ̗v�f��������܂���ł���\n");
			}

			menuNum = menu::MENU;

		}
		//�폜
		else if (menuNum == menu::DELETE_) {
			printf("\n[�v�f�̍폜]\n");

			printf("�폜�������v�f�̔ԍ����w�肵�Ă�������\n");
			scanf_s("%d", &iterator);

			insertCell = GetInsertListAddress(&head, iterator);
			//x�Ԗڂ�����ꍇ
			if (insertCell->next != nullptr) {

				CELL* p = &head;

				for (int i = 0; i < iterator + 1; i++) {
					p = p->next;
				}

				p->prev->next = p->next;
				//p->next������ꍇ
				if (p->next != nullptr) {
					p->next->prev = p->prev;
				}
				p->next = nullptr;
				p->prev = nullptr;


				printf("%d�Ԗڂ̗v�f`%d`���폜���܂���\n", iterator, inputValue);
			}
			//x�Ԗڂ��Ȃ��ꍇ
			else {
				printf("x�Ԗڂ̗v�f��������܂���ł���\n");
			}

			menuNum = menu::MENU;
		}
		//���בւ�
		else if (menuNum == menu::SORTING_) {

		}
		////���X�g�ꗗ�̕\��
		//Index(&head);
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
	printf("\n[�v�f�̈ꗗ�\��]\n");
	printf("�v�f�ꗗ: {\n");

	int no = 0;
	//next�ɃA�h���X��������胋�[�v
	while (endCell->next != nullptr) {

		endCell = endCell->next;
		printf("%d: ", no);
		printf("%d,\n", endCell->val);		//5���܂ŉE����
		no++;

	}
	printf("}\n");
	printf("\n�v�f��: %d\n", no);
}
