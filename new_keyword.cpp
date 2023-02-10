#include <iostream>
#include<string>

//new分配内存。例如new int，则要找到四个字节的连续内存，还要在一行内存中找到4个字节的连续地址。 
//并不像激光逐条扫描这样。而是有一个空闲列表，维护有空闲字节的地址。

using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity():m_Name("Unknown"){}
	Entity(const String&name):m_Name(name){}

	const String& Getname()const { return m_Name; }
};

int main()
{
	int a = 2;
	int* b = new int;//b存储着指向内存空间的地址。
	int* b1 = new int[50];//若想分配数组，就加方括号并在里面写上大小。50需要200bytes。

	Entity* e = new Entity[50];//会在内存中连续得到50个entity。不仅调用内存，也调用构造函数。
	malloc(50);//调用new会调用隐藏在里面的c函数，代表内存分配。即传入一个size，返回一个void指针。
	//实际上是：
	Entity* e = (Entity*)malloc(sizeof(Entity));//与上面那行代码仅有的区别是，上面的调用了构造函数。

	//用了new记得要用delete，delete调用了free函数。否则该内存空间就不会被调用回空闲列表。
	delete e;
	delete[] b;//如果new为数组操作符，那么为如左代码。

	//还有一种placement new，我们可以用它指定内存空间来分配函数。
	//只需要调用函数，然后在该空间上初始化自己的entity。语法如下：
	Entity* e = new(b1) Entity();

	std::cin.get();
}
