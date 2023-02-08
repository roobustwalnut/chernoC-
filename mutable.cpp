#include <iostream>
#include<string>

//mutable，让const中出现例外。
class Entity
{
private:
	//在类成员中使用mutable
	std::string m_name;
	mutable int m_DebugCount = 0;
public:
	const std::string& Getname() const 
	{ 
		m_DebugCount++;
		return m_name;
	}
};
int main()
{
	const Entity e;
	e.Getname();

	//lambda中用mutable，cherno都没见过哈哈哈。
	int x = 8;
	//在[]中引用发送或直接发送这个变量。一次性小函数？可以用[=]进行所有值传值传递，或者[&]将所有制引用传递。
	auto f = [=]()mutable
	{
		//若用值传递，x++不可行。此时的解决方法之一是建立一个局部变量，赋值为x。
		/*int y = x;
		y++;*/

		//有mutable就可以直接x++了。
		x++;
		std::cout << x << std::endl;
	};
	f();
	//x=8，因为不是引用传递，而是将8复制下来传递金lambda
	std::cin.get();
}
