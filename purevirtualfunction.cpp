#include <iostream>
#include<string>

//纯虚函数，允许我们在基类中定义一个没有实现的函数，然后在子类中强制实现它。
//引入纯虚函数时，基类无法实例化，只有子类将该函数完善后才能创建实例。基类知道应该有一个函数，但也许不同的子类实现方法不一样。
//类似动物类别中有猪马牛羊，可以实例一个猪、马等，但不能实例一个动物。
//接口interface，作为模板，提供未实现的方法。interface只是C++的类，其它语言中interface为关键字

//创建一个virtual字符串函数，返回一个字符串。
class Printable
{
public:
	virtual std::string GetClassName() = 0;//纯虚函数。并不表示函数返回0，只是一个形式，告诉编译器这是纯虚函数。此时基类不再能实例化。
};

class Entity:public Printable//实现接口
{
public:
	virtual std::string Getname() { return "Entity"; };
	std::string GetClassName() override { return "Entity!"; };
};

class Player :public Entity//Player是Entity的子类，因此实现接口，若非子类，则需要加上“,Printable”
{
private:
	std::string m_Name;//存储一个名字
public:
	Player(const std::string& name)//允许指定一个名字
		:m_Name(name) {}//此处m_Name为初始化列表，name为成员变量
	//初始化列表是在构造函数的定义后面，以冒号开头。
	//它包含初始化表达式，将成员变量m_Name初始化为构造函数的参数name。
	std::string Getname() override { return m_Name; }//override可去，但最好加上，因为它可以帮助我们检查子类函数名是否写错、父类函数是否标为虚函数。
	std::string GetClassName() override { return "Player"; }//注意，在这里要重新定义Player，否则打印出来是Entity
};

void PrintName(Entity* entity)//调用方法时，如果是Entity，则会从Entity的类中寻找方法。
{
	std::cout << entity->Getname() << std::endl;
}

void Print(Printable* obj)//这里的*为何不加上不行？
{
	std::cout << obj->GetClassName() << std::endl;//需要一个类型，提供getclassname函数，即接口（？）
}

int main()
{
	Entity* e = new Entity();
	Print(e);

	Player* p = new Player("cherno");
	Print(p);

	Entity* entity = p;//打印出entity，但我们希望是p，即打印Cherno。这是因为父类和子类都有同样的Getname，调用时先发现父类的就用了。
	std::cout << entity->Getname() << std::endl;
	std::cin.get();
}
