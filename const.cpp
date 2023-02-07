#include <iostream>
#include<string>

//const，类似于类和对象的可见性，为了让代码更易读维护，是针对开发人员的规则。

//类中的const
class Entity
{
private:
	//注意：int* m_X, m_Y;该语句中，m_X为指针类型，但m_Y仍为整型。
	//若要让两者都为指针型，则应将m_Y改为*m_Y。
	int m_X, m_Y;
	//假设有一个变量，为了调试等原因，需要在const类型的方法中修改它，可以将它设为mutable，使该变量可被改变。
	mutable int var;
public:
	//在getter型函数()后加上const，意味着类中的成员变量不会改变，只能读不能写。
	//第一个const表示返回一个不能被修改的指针；第二个表示该指针不能改变；第三个表示方法不改变实际的Entity类
	//const int* const GetX()const
	int GetX() const
	{
		//例如，若有如下语句，会报错
		//m_X=2;
		//如果函数类型为指针，那么private中的也要声明为指针。
		var = 2;
		return m_X;
	}
	
	//由于const的特性，有时会有两个函数，即带const和不带const。在下面的调用const Entity的例子中，它会选择带const的函数调用。
	int GetX()
	{
		return m_X;
	}

	//若在setter型函数中，则不能在函数后声明const
	void SetX(int x)
	{
		m_X = x;
	}
};

//假设有一个函数要调用该类实例的方法，并用常量引用传递该值（对于只读变量，这可以避免复制）
//()内如果是指针，则可以改变指针本身，但不能改变其指针指向的内容。在这里指针与引用做的事情相同。
//const的Entity意味着可以调用任何Entity函数。
void PrintEntity(const Entity& e)
{
	//e = Entity();该语句是不允许的，这并不是重新分配这个引用，而是在改变这个对象。

	//如果GetX()没有标明const，那么调用e.GetX()会报错。因为此时该函数不能保证它的返回值不会被改变，而在该函数下，声明了引用对象e是const的。
	std::cout << e.GetX() << std::endl;
}

int main()
{
	//从语法上声明这个整数是常量
	const int MAX_AGE = 5;

	Entity e;
	int* a = new int;
	*a = 2;
	//有两种情况。可行：将const 变量地址赋给const 指针；不可行：将const 变量地址赋给（非const）指针
	//此时必须使用强制转换类型来突破该限制。即给指针a赋予MAX_AGE的整形地址时，在前加上(int*)。然后强制改变const量的值。
	a = (int*)&MAX_AGE;

	//const 与指针
	//const在*之前，意味着ptr本身可以改变，但ptr指向的内容不能通过指针ptr改变，即使当MAX_AGE为变量时。并且int const等于const in
	int const* ptr = &MAX_AGE;
	//*在const之后，意味着指针本身不能改变，但ptr指向的内容可以改变。
	int* const ptr1 = new int;
	//前后都加const，意味着两个层面都不可变。
	const int* const ptr2 = new int;
	std::cin.get();
}
