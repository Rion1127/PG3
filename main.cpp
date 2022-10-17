#include <stdio.h>
#include <Windows.h>
#include <random>


typedef void (*PFunc)(int*);

void callback1(int* s) {
	printf("%d秒後に実行されるよ\n", *s);
}

void setTimeout(PFunc p, int second) {
	p(&second);

	Sleep(1000 * second);
}

int main() {
	srand(time(nullptr));

	int number = 0;
	int randNum = 0;

	printf("数字を入力してください\n");
	scanf_s("%d", &number);	//入力

	//3秒待つ
	PFunc p;
	p = callback1;
	setTimeout(p, 3);	

	while (true) {
		//偶数の乱数を返す
		if (number % 2 == 0) {
			randNum = rand();
			if (randNum % 2 == 0) break;	//偶数ならループを抜ける
		}
		//奇数の乱数を返す
		else {
			randNum = rand();
			if (randNum % 2 == 1) break;	//奇数ならループを抜ける
		}
	}

	printf("%d\n", randNum);

	return 0;
}