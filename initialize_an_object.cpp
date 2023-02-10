#include <iostream>
#include<string>

//C++可以在栈上分配空间，也可以在堆上分配空间。C#和Java常常在堆上分配空间。
//在堆上分配空间要花费更长时间，并且要手动释放被分配的内存。
using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity():m_Name("Unknown"){}//默认构造函数
	Entity(const String& name): m_Name(name){}

	const String& Getname() const { return m_Name; }
};


void Function()
{
	int a = 2;
	//这种构造在该函数到达右花括号后，这个entity就会在内存中被销毁。
	Entity entity = Entity("Swamp");
}
int main()
{
	Function();//调用这个函数时，就为该函数创造了一个栈结构。包含了该函数声明的所有变量。

	Entity entity;//这里的构造，与C#和Java不同。
	Entity entity("Cherno");//指定一个参数的做法。
	std::cout << entity.Getname() << std::endl;

	//一个例子，栈分配会让它在括号结束后销毁。如果想要扩大作用域，就得求助于堆分配。栈通常很小，而Entity可能很大。
	//一个Entity的指针，指向Entity的变量。
	Entity* e;
	{
		Entity entity("Smog");
		e = &entity;//为这个指针分配该entity的内存地址。
		std::cout << entity.Getname() << std::endl;
		//逐行运行会发现，在花括号结束后，内存地址里存储的东西为空。 
	}

	//解决方法，堆分配。
	Entity* en;
	{
		Entity* entity=new Entity("Smogy");//通过new关键字。指针。
		en = entity;//复制entity对象时，只复制内存地址。
		std::cout << (*entity).Getname() << std::endl;//逆向引用指针。
	}
	delete en;//释放内存空间 
	std::cin.get();
}
