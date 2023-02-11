#include<iostream>
#include<string>

//the this
//通过this可以访问成员函数，成员函数是属于某个类的函数或者方法。
//this是一个指向当前对象实例的指针，该方法属于这个对象实例。

//一个例子，假设在Entity内有一个外部函数，想要引用Entity作为参量。我们希望在类中调用这个函数。
void PrintEntity(Entity* e);//在这里声明，在下面定义。好离谱。

class Entity
{
public:
	int x, y;

	Entity(int x, int y)
	{
		Entity* const e = this;//this的类型Entity*，并且是const的。
		//Entity*& const e = this; 也不能把this赋值给这里的引用。
		//应该为：Entity* const & e = this;

		this->x = x;
		this->y = y;

		Entity& e = *this;//可以通过逆向引用赋值。

		PrintEntity(this);//希望用Entity类的当前实例传入这个函数。
		//传入this，则会将当前设置的x和y传入这个函数。
		//如果是void PrintEntity(const Entity* e)的传入类型，则该语句变为：PrintEntity(*this)逆向引用
	}
	int GetX() const
	{
		const Entity* e = this;//该函数是const的，因此不能修改Entity，要在前面加上const
		return x;
	}
};

void PrintEntity(Entity* e)
{
	//Print
}

int main()
{
	std::cin.get();
}
