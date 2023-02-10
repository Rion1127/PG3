#pragma once
#include "Task.h"
#include <vector>
class TaskManager
{
public:

	void Update();

private:
	void Add(Task task);

	void Delete(int num);

	std::vector<Task> task_;
};

