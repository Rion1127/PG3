#include <stdio.h>


// 再帰的な賃金
int RecursiveWage(int value,int hour) {
	if (hour <= 0) {
		return value;
	}
	
	return (RecursiveWage(value * 2 - 50,hour - 1));
}
//一般的な賃金
int GeneralWage(int value, int hour) {
	return value * hour;
}

int main() {
	int wage = 1072;	//一般的な時給
	int hour = 10;		//時間
	int result;			//結果を代入

	//一般的な賃金を代入
	result = GeneralWage(wage, hour);
	printf("一般的な賃金\n%d円\n", result);
	//再帰的な賃金を代入
	result = RecursiveWage(100,hour);
	printf("再帰的な賃金\n%d円\n", result);

	//一般的な賃金のほうが高いとき
	if (RecursiveWage(100, hour) < GeneralWage(wage, hour))
	{
		printf("\n一般的な賃金の方が儲かる\n");
	}
	//再帰的な賃金のほうが高い
	else if (RecursiveWage(100, hour) > GeneralWage(wage, hour))
	{
		printf("\n再帰的な賃金の方が儲かる\n");
	}
	else {
		printf("\nどちらも一緒\n");
	}

	return 0;
}