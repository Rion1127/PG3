#include <stdio.h>

template <typename T>
T Min(T a, T b) {
	if (a < b) return a;
	if (b < a) return b;
	return 0;
}
template <>
char Min(char a, char b) {
	return printf("�����ȊO�͑���ł��܂���\n");
}

int main() {
	int hour = 10;







	return 0;
}