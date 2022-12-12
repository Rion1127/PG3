#include <stdio.h>
#include "Rectangle.h"

void Rectangle::Size()
{
	float size;

	size = widht * height;
	printf("Size : %f\n",size);
}

void Rectangle::Draw()
{
	printf("Rectangle\n");
}
