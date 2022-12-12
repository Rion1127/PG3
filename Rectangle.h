#pragma once
#include "IShape.h"
class Rectangle : 
	public IShape
{
public:
	void Size() override;
	void Draw() override;
private:
	float height = 16;
	float widht = 8;
};

