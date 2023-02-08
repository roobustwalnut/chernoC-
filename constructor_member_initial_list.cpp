#include <iostream>
#include<string>

//构造函数中初始化类成员的一种方式。
//从代码风格上来说，初始化列表更简洁干净。
//功能上的区别，可以看Example类这个例子。
//对于整数类型，不会被初始化，除非赋值。
class Example
{
public:
	Example()
	{
		std::cout << "Created Entity!" << std::endl;
	}
	Example(int y)
	{
		std::cout << "Created Entity with " << y << std::endl;
	}
};

class Entity
{
private:
	std::string m_Name;
	int m_Score;
	Example m_example;
public:
	//初始化，若未传入参数，则为unknown
	Entity()
		:m_Name("Unknown"),m_Score(0),m_example(8)//m_example(Example(8))两个是一样的
		//初始化列表，也可以不另起一行
		//注意，不管怎么写初始化列表的顺序，初始化的顺序是按照类成员定义的顺序。
		//因此要确保定义顺序和初始化顺序一致，否则会产生各种依赖性问题。 
		//在Example类的例子中，用初始化列表不会有下面那种情况。
		
	{
		//将该类成员变量设为参数为8的类对象。这里Example创建了一个新的实例，并将它赋值给m_example
		m_example = Example(8);

		//m_Name = "Unknown";
		//上面语句跟冒号后二选一。这里有一个功能上的区别，如果不用初始化列表，那么m_Name这个变量会被构造两次。
		//一个是默认构造函数，一个是"Unknown"参数。事实上会有m_Name=std::string("Unknown")
	}

	Entity(const std::string& name)
		:m_Name(name)
	{
		//m_Name = name;
	}
	const std::string& Getname() const//给m_Name赋值
	{
		return m_Name;
	}
};
int main()
{
	Entity e0;
	/*std::cout << e0.Getname() << std::endl;

	Entity e1("Cherno");
	std::cout << e1.Getname() << std::endl;*/
	std::cin.get();
}
