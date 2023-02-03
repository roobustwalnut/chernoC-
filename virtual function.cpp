#include <iostream>
#include<string>

//虚函数，允许父类重写方法。
//虚函数引入一种dynamic dispatch的方法，其通过V表实现编译。
//v表包含所有的虚函数映射，运行时可以将它们映射到正确的覆写（override）函数
//虚函数的开销：1、需要额外内存存储v表；2、每次调用函数时需要循环v表来找到正确的函数。
class Entity
{
public:
	virtual std::string Getname() { return "Entity"; }//virtual即告诉编译器，这个函数为虚函数，子类可能会覆写
};

class Player :public Entity
{
private:
	std::string m_Name;//存储一个名字
public:
	Player(const std::string& name)//允许指定一个名字
		:m_Name(name){}//此处m_Name为初始化列表，name为成员变量
	//初始化列表是在构造函数的定义后面，以冒号开头。
	//它包含初始化表达式，将成员变量m_Name初始化为构造函数的参数name。
	std::string Getname() { return m_Name; }
};

void PrintName(Entity* entity)//调用方法时，如果是Entity，则会从Entity的类中寻找方法。
{
	std::cout << entity->Getname() << std::endl;
}
int main()
{
	Entity* e = new Entity();
	/*std::cout << e->Getname() << std::endl;*/
	PrintName(e);

	Player* p = new Player("cherno");
	/*std::cout << p->Getname() << std::endl;*/
	PrintName(p);//用函数PrintName可知，调动Getname时，即使它是Player，也会从父类调动方法。

	Entity* entity = p;//打印出entity，但我们希望是p，即打印Cherno。这是因为父类和子类都有同样的Getname，调用时先发现父类的就用了。
	std::cout << entity->Getname() << std::endl;
	std::cin.get();
}
