#include<iostream>
#include<string>

class Entity
{
public:
	int x;
public:
	void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr
{
private:
	Entity* m_obj;
public:
	ScopedPtr(Entity* entity)
		:m_obj(entity)
	{

	}
	~ScopedPtr()
	{
		delete m_obj;
	}

	const Entity* operator->() const
	{
		return m_obj;
	}
};

struct Vector3
{
	float x, z, y;//在类中，(x,y,z)和(x,z,y)没什么不同，但在struct中，内存分配有不同。
};

int main()
{
	int offset = (int)&((Vector3*)0)->y;//首先，将0转换为Vector3指针，然后用箭头访问y，用&获得y的内存地址。结果是一个指针，表示从结构体首地址到y的偏移量。
	std::cout << offset << std::endl;

	Entity e;
	e.Print();

	Entity* ptr=&e;
	Entity& entity = *ptr;//逆向引用
	entity.Print();
	(*ptr).Print();//跟上面一行等价

	ptr->Print();//直接箭头调用。即逆向引用，然后调用Print()。
	ptr->x = 2;//赋值x=2也可以用箭头操作符。

	const ScopedPtr entity1 = new Entity();//标记成const后，Print也必须是const的。
	//ScopedPtr里的对象是entity类型，但不能直接调用entity.Print()，因为Print函数是Entity类里的，而创建的entity是ScopedPtr类里的。
	//可以在ScopedPtr里写一个GetObject函数，来调用Print，但这样太乱了。我们希望用类似Entity调用的方法来调用ScopedPtr类的对象。这就需要重载箭头操作符。
	entity1->Print();//经过重载操作符
	
	std::cin.get();
}
