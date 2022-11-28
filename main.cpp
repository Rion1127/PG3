#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�o�������X�g�̍\���̂̒�`
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
			printf("[�v�f�̑���]\n");
			printf("1.�v�f�̈ꗗ�\��\n");
			printf("2.�Ō���ɗv�f�̑}��\n");
			printf("3.�Ō���̗v�f�̍폜\n");
			printf("\n---------------------\n");
			printf("�����I�����Ă�������\n");
			scanf_s("%d", &selectMenu);
		}
		else if (selectMenu == menu::DISPLAY_) {
			//���X�g�ꗗ�̕\��
			Index(&head);

			printf("\n---------------------\n");
			while (true) {
				printf("0.������ʂɖ߂�\n");
				scanf_s("%d", &selectMenu);
				if (selectMenu == 0) {
					break;
				}
				
				if(selectMenu != 0) {
					printf("���̔ԍ��͎g�p�ł��܂���\n");
					scanf_s("%d", &selectMenu);
				}
			}
		}
		else if (selectMenu == menu::INSERT_) {
			printf("\n[���X�g�v�f�̑}��]\n");
			printf("\n�ǉ����镶������͂��Ă�������\n");
			scanf_s("%s", str, 8);
			printf("\n�v�f`%s`�����X�g�̍Ō���ɑ}������܂���\n", str);
			//�Ō���ɃZ����ǉ�
			Create(&head, str);

			printf("\n---------------------\n");
			printf("0.������ʂɖ߂�\n");
			scanf_s("%d", &selectMenu);
		}
		
	}


	return 0;
}

void Create(CELL* currentCELL, const char* buf)
{
	//�V�K�Z�����쐬
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	
	strcpy_s(newCell->str, 8, buf);
	newCell->next = nullptr;
	//�w�肵���Z���Ɏ��̃Z��������ꍇ
	//���̃Z���̑O�̃|�C���^�ɐV�K�Z���̃A�h���X����
	while(currentCELL->next != nullptr){
		//���̃Z���̃A�h���X����
		currentCELL = currentCELL->next;
	}
	//�w�肵���Z���́u���̃Z���̃|�C���^�ɐV�K�Z���̃A�h���X�����v
	currentCELL->next = newCell;
}

void Index(CELL* endCell)
{
	//next�ɃA�h���X��������胋�[�v
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%s\n", endCell->str);
	}
}