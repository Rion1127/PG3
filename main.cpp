#include <stdio.h>
#include "Circle.h"
#include "Rectangle.h"



int main() {
	Rectangle rect;
	Circle circle;

	rect.Draw();
	rect.Size();

	circle.Draw();
	circle.Size();

	return 0;
}