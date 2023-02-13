#include<iostream>
#include<string>

//拷贝是指拷贝数据

//用字符串类说明复制观点。
class String
{
private:
	char* m_Buffer;//指向字符缓冲区
	unsigned int m_Size;//保存string的大小
public:
	String(const char* string)//计算这个字符有多长，把该字符串复制到缓冲区
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size+1];//实际上还需要空终止符，即size+1。先看看会发生什么：会发生后面跟了乱码。
		//如果用strcpy则会自动分配空终止符。
		memcpy(m_Buffer, string, m_Size+1);
		m_Buffer[m_Size] = 0;//手动在最后添加一个终止符。
	}
	//分配了new char，因此有一个内存泄漏。

	//如果不想要拷贝构造函数，可以在该类里写如下构造指令：
	//String(const String& other)=delete;
	/*String(const String& other)
		:m_Buffer(other.m_Buffer), m_Size(other.m_Size)
	{
		//C++默认提供的拷贝构造函数
		//这样不行，我们不止想复制指针，还想复制指针所指的内存。
	}*/
	//more exciting
	/*
	String(const String& other)
	{
		memcopy(this,&other,sizeof(String));
	}
	*/

	//深拷贝构造函数
	String(const String& other)
		:m_Size(other.m_Size)
	{
		std::cout << "Copied String!" << std::endl;
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);//复制other的缓冲区
	}

	~String()
	{
		delete[] m_Buffer;
	}
	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	//把它定义为友元，则可以在下面的函数中直接读取m_Buffer。
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}
struct Vector2
{
	float x, y;
};

void PrintString(const String& string)//这样就不会复制那么多次啦
{
	//如果突然发现还是要复制，那么只要写：String copy = string;即可
	std::cout << string << std::endl;
}

int main()
{
	/*part1
	int a1 = 2;
	int b1 = a1;
	//a,b是两个独立的变量，它们有不同的内存地址。用struct类型也是同理。

	//两个指针，本质上有相同的值。
	Vector2* a = new Vector2();
	Vector2* b = a;
	b->x = 5;//修改指针指向的内存地址，此时会同时影响a和b（当然不是影响指针，而是其指向的内存地址）。
	*/

	String string = "Cherno";
	String second = string;//C++自动给second分配到一个新的内存地址里。但是两个string的char*值是相同的内存地址。
	//当程序到达作用域结束的时候，销毁的是同一块内存地址，但第二次销毁时，该内存已经被销毁了，程序不能销毁两次同样的内存块。
	//C++通常用的都是浅拷贝。在浅拷贝的情况下，复制的是指向原对象的指针或引用，而不是原对象的副本。因此，如果更改复制的对象，则也会更改原对象。
	
	second[2] = 'a';//把第3个字符改成a，两个string都会变。

	PrintString(string);
	PrintString(second);//传递到这个函数时，实际上做了两次复制。
	
	//std::cout << string << std::endl;
	//std::cout << second << std::endl;
	//这种复制到程序终止时会崩溃。这种复制是浅拷贝
	std::cin.get();
}
