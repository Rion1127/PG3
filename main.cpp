#include <stdio.h>
#include <Windows.h>
#include <random>
#include <functional>

typedef void (*PFunc)(int*);

void callback1(int* s) {
	printf("%d�b��Ɏ��s������\n", *s);
}

void setTimeout(PFunc p, int second) {
	p(&second);

	Sleep(1000 * second);
}

int main(int argc,const char*argv[]) {
	

	srand(time(nullptr));
	int number = 0;
	int randNum = 0;
	printf("��������͂��Ă�������\n");
	scanf_s("%d", &number);	//����
	//3�b�҂�
	std::function<int(int)> setTimeout = [](int i) {
		printf("%d�b��Ɏ��s������\n", i);
		Sleep(1000 * i);
		return 0;
	};
	auto fx2 = [](int i) {
		printf("%d�b��Ɏ��s������\n", i);
		Sleep(1000 * i);
		return 0;
	};

	while (true) {
		//�����̗�����Ԃ�
		if (number % 2 == 0) {
			randNum = rand();
			if (randNum % 2 == 0) break;	//�����Ȃ烋�[�v�𔲂���
		}
		//��̗�����Ԃ�
		else {
			randNum = rand();
			if (randNum % 2 == 1) break;	//��Ȃ烋�[�v�𔲂���
		}
	}
	printf("%d\n", randNum);


	return 0;
}