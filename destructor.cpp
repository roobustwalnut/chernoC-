#include <iostream>

//destructor析构函数，用以删除变量或者清理内存。同时适用于栈和堆的分配对象

class Entity
{
public:

	float x, y;

	Entity()
	{
		x = 0.0f;
		y = 0.0f;
		std::cout << "Constructed Entity!" << std::endl;
	}

	~Entity()//构造析构函数
	{
		std::cout << "Destructed Entity." << std::endl;
	}
	void Print()
	{
		std::cout << x << "," << y << std::endl;
	}
};

void Function()//执行Entity相关操作
{
	Entity e;
	e.Print();
}

int main()
{
	Function();
	std::cin.get();
}
