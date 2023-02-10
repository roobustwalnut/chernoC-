#include<iostream>
#include<string>

//隐式构造函数和隐式转换。意味着模糊操作，C++会根据上下文编译。
//比如两个不同类型的数据，C++允许隐式进行强势转换，不需要cast。
//如果有一个explicit的构造函数，则不能进行隐式转换。如果要调用这个函数，则必须显式调用。
//写低级封装（low level warpping）时有用，防止数据类型被错误转换。


class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	Entity(const std::string& name)
		:m_Name(name),m_Age(-1){}
	explicit Entity(int age)//在前加上explicit，可以看到下面的b=20显示错误。explicit唯一的用途。
		:m_Name("Unknown"),m_Age(age){}
};

void PrintEntity(const Entity& entity)
{
	//Print
}
int main()
{
	PrintEntity(22);//C++认为这里可以适当将22转换为一个Entity
	PrintEntity(std::string("Cherno"));//同样不行，在这里需要两次隐式转换，一次const char到string，一次string到Entity。下面的同理（？）
	//修改的为加上std::string()
	Entity a("Cherno");
	Entity b(20);
	//还能如下表示，也就是隐式转换，其他语言不能这样。
	Entity a= "Cherno";//这是const char数组，而不是std::string，因此行不通。
	Entity b = 20;

	std::cin.get();
}
