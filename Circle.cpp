#include <stdio.h>
#include "Circle.h"

void Circle::Size()
{
	float size;
	size = radius * radius * 3.1415f;
	printf("size : %f", size);
}

void Circle::Draw()
{
	printf("Circle\n");
}
