#include <stdio.h>
#include <Windows.h>
#include <random>


typedef void (*PFunc)(int);

void callback1(int number) {
	int randNum = 0;

	randNum = rand() % 6 + 1;
	printf("結果 : %d\n", randNum);
	if (number % 2 == randNum % 2) {
		printf("プレイヤー勝ち");
	}
	else {
		printf("プレイヤー負け");
	}
}

void setTimeout(PFunc p, int second,int number) {
	printf("%d秒後に実行されるよ\n", second);

	Sleep(1000 * second);

	p(number);
}

int main() {
	srand(time(nullptr));

	int number = 0;

	printf("数字を入力してください\n0 : 偶数　1 : 奇数\n");
	while (true) {
		scanf_s("%d", &number);	//入力
		//0か1以外を入力されたらもう一度入力させる
		if (number != 0 && number != 1) {
			printf("エラー\n0 : 偶数　1 : 奇数\n");
		}
		else {
			break;
		}
	}
	//3秒待つ
	PFunc p;
	p = callback1;
	setTimeout(p, 3,number);

	return 0;
}