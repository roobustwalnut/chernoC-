#include<iostream>
#include<string>

//作用域，粗浅地理解成花括号。
//作用域指针，基本是一个类，是指针的包装器，在构造函数时分配指针，然后在析构中删除指针。

class Entity
{
public:
	Entity()//构造函数中创建Entity
	{
		std::cout << "Created Entity!" << std::endl;
	}
	~Entity()//析构函数中销毁Entity
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
};


int* CreatArray()//在函数中创建数组
{
	/*如果有如下语句，只有两个选择。
	int array[50];
	return array;
	*/

	//选择一：转换为数组，确保它的生存期一直存在
	int* array = new int[50];
}
//选择二：将上行创建的数据复制给一个栈作用域之外存在的变量
void CreatA(int* array)
{
	//Fill the array.该函数只传递一个指针。
}

class ScopedPtr
{
private:
	Entity* m_Ptr;
public:
	ScopedPtr(Entity* ptr)
		:m_Ptr(ptr)
	{

	}
	~ScopedPtr()
	{
		delete m_Ptr;//析构函数中，删除它。
	}
};
int main()
{
	{
		Entity e;//设置断点会发现，Create和destroy都出现了。

		{
			ScopedPtr e = new Entity();//这个在超出作用域时会自动删除，即使它在堆分配。
			Entity* e = new Entity();//转换成指针。此时运行只有create。
			//用unique_ptr，使其在超出作用域时能够删除。
		}

	}
	std::cin.get();
}
