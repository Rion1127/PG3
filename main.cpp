#include <stdio.h>
#include <Windows.h>
#include <random>


typedef void (*PFunc)(int);

void callback1(int number) {
	int randNum = 0;

	randNum = rand() % 6 + 1;
	printf("���� : %d\n", randNum);
	if (number % 2 == randNum % 2) {
		printf("�v���C���[����");
	}
	else {
		printf("�v���C���[����");
	}
}

void setTimeout(PFunc p, int second,int number) {
	printf("%d�b��Ɏ��s������\n", second);

	Sleep(1000 * second);

	p(number);
}

int main() {
	srand(time(nullptr));

	int number = 0;

	printf("��������͂��Ă�������\n0 : �����@1 : �\n");
	while (true) {
		scanf_s("%d", &number);	//����
		//0��1�ȊO����͂��ꂽ�������x���͂�����
		if (number != 0 && number != 1) {
			printf("�G���[\n0 : �����@1 : �\n");
		}
		else {
			break;
		}
	}
	//3�b�҂�
	PFunc p;
	p = callback1;
	setTimeout(p, 3,number);

	return 0;
}