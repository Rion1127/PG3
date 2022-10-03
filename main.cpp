#include <stdio.h>

template <typename T>
T Min(T a, T b) {
	if (a < b) return a;
	if (b < a) return b;
	return 0;
}
template <>

char Min(char a, char b) {
	printf("”šˆÈŠO‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ\n");
	return 0;
}

int a = 100;
int b = 500;

float e = 200;
float f = 300;

double g = 500;
double h = 600;

char c = 'a';
char d = 'b';

int main() {
	printf("%d\n", Min<int>(a, b));		//intŒ^
	printf("%f\n", Min<float>(e, f));	//floatŒ^
	printf("%lf\n", Min<double>(g, h));	//doubleŒ^
	printf("%c\n", Min<char>(c, d));	//charŒ^

	return 0;
}