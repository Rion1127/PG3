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
void Delete(CELL* currentCELL);

int main() {
	char str[8];

	int selectMenu = menu::MENU;

	CELL head;
	head.next = nullptr;

	while (true) {
		//���j���[
		if (selectMenu == menu::MENU) {
			printf("\n[�v�f�̑���]\n");
			printf("1.�v�f�̈ꗗ�\��\n");
			printf("2.�Ō���ɗv�f�̑}��\n");
			printf("3.�Ō���̗v�f�̍폜\n");
			printf("\n---------------------\n");
			printf("�����I�����Ă�������\n");

			scanf_s("%d", &selectMenu);
			
			//�\������Ă��Ȃ��ԍ��ȊO����͂��ꂽ�������x���͂�����
			if (selectMenu < menu::DISPLAY_ ||
				selectMenu > menu::DELETE_)
			{
				printf("�G���[\n�\������Ă���ԍ���I�����Ă�������\n");
				selectMenu = menu::MENU;
			}
		}
		//�\��
		else if (selectMenu == menu::DISPLAY_) {
			//���X�g�ꗗ�̕\��
			Index(&head);

			printf("\n---------------------\n");

			printf("0.������ʂɖ߂�\n");
			scanf_s("%d", &selectMenu);

			//�\������Ă��Ȃ��ԍ��ȊO����͂��ꂽ�������x���͂�����
			if (selectMenu != 0)
			{
				printf("�G���[\n�\������Ă���ԍ���I�����Ă�������\n");
				selectMenu = menu::DISPLAY_;
			}
		}
		//�}��
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

			//�\������Ă��Ȃ��ԍ��ȊO����͂��ꂽ�������x���͂�����
			if (selectMenu != 0)
			{
				printf("�G���[\n�\������Ă���ԍ���I�����Ă�������\n");
				selectMenu = menu::INSERT_;
			}
		}
		//�폜
		else if (selectMenu == menu::DELETE_) {
			int select = 0;
			printf("\n[�v�f�̑���]\n");
			printf("1.�Ō���̗v�f���폜����\n");
			printf("2.������ʂɖ߂�\n");
			scanf_s("%d", &select);
			//�폜����
			if (select == 1) {

				Delete(&head);

				printf("�Ō���̗v�f���폜���܂���\n");

				printf("\n---------------------\n");
				printf("0.������ʂɖ߂�\n");
				scanf_s("%d", &selectMenu);

				//�\������Ă��Ȃ��ԍ��ȊO����͂��ꂽ�������x���͂�����
				if (selectMenu != 0)
				{
					printf("�G���[\n�\������Ă���ԍ���I�����Ă�������\n");
					selectMenu = menu::INSERT_;
				}
			}
			//���j���[�ɖ߂�
			else if (select == 2) {
				selectMenu = menu::MENU;
			}
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
	while (currentCELL->next != nullptr) {
		//���̃Z���̃A�h���X����
		currentCELL = currentCELL->next;
	}
	//�w�肵���Z���́u���̃Z���̃|�C���^�ɐV�K�Z���̃A�h���X�����v
	currentCELL->next = newCell;
}

void Index(CELL* endCell)
{
	int no = 0;
	printf("\n[�v�f�̈ꗗ�\��]\n");
	//next�ɃA�h���X��������胋�[�v
	printf("�v�f�ꗗ:{\n");
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d: %s,\n", no, endCell->str);
		no++;
	}
	printf("}\n");
	printf("\n�v�f��: %d\n", no);
}

void Delete(CELL* currentCELL)
{
	//���g�������Ă��鎞
	if (currentCELL->next) {
		while (currentCELL->next->next != nullptr) {
			//���̃Z���̃A�h���X����
			currentCELL = currentCELL->next;
		}
	}

	if (currentCELL->next != nullptr) {
		delete currentCELL->next;
		currentCELL->next = nullptr;
	}
}
