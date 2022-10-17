#include <stdio.h>
#include <Windows.h>
#include <random>
#include <functional>

typedef void (*PFunc)(int*);

void callback1(int* s) {
	printf("%d秒後に実行されるよ\n", *s);
}

void setTimeout(PFunc p, int second) {
	p(&second);

	Sleep(1000 * second);
}

int main(int argc,const char*argv[]) {
	

	srand(time(nullptr));
	int number = 0;
	int randNum = 0;
	printf("数字を入力してください\n");
	scanf_s("%d", &number);	//入力
	//3秒待つ
	std::function<int(int)> setTimeout = [](int i) {
		printf("%d秒後に実行されるよ\n", i);
		Sleep(1000 * i);
		return 0;
	};
	auto fx2 = [](int i) {
		printf("%d秒後に実行されるよ\n", i);
		Sleep(1000 * i);
		return 0;
	};

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