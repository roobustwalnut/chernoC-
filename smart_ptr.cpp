#include<iostream>
#include<string>
#include<memory>//访问智能指针所需要的头文件

//智能指针实际上是原始指针的包装。最简单的unique_ptr。
//不能复制unique_ptr。如果复制，则有两个同样的指针指向同一个内存块，当其中一个释放了该内存块，另一个仍指向该（已被释放）的内存块，会有错误。
//shared_ptr使用的是引用计数。它需要分配另一块内存，叫做控制块，来存储引用计数。
//假如创建一个Entity，并将它分配给shared_ptr，那么它会创造两个内存块，一个存储Entity，另一个为shared_ptr的控制块内存。make_shared会整合这两次操作。
//要多多尝试使用智能指针，它能让内存管理自动化，防止忘记调用delete

class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}
	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
	void Print()
	{}
};

int main()
{
	{
		std::shared_ptr<Entity> e0;
		{//新建一个大作用域，用unique_ptr来分配Entity。其模板参数为Entity，名字为entity
			/*std::unique_ptr<Entity> entity(new Entity());//注意，不能做这种构造：entity = new Entity()。因为unique_ptr的函数是explicit的。
			//另一个构造方法（最好的办法）。主要原因是出于异常安全，不会让我们得到引用的悬空指针，造成内存泄漏。
			std::unique_ptr<Entity> entity = std::make_unique<Entity>();

			//std::unique_ptr<Entity> e0 = entity;//不能这样做。因为unique_ptr的拷贝构造函数及其操作符被删除了。
			*/

			std::shared_ptr<Entity> SharedEntity = std::make_shared<Entity>();
			//std::shared_ptr<Entity> SharedEntity(new Entity());//这样构造也可以。
			//std::shared_ptr<Entity> e0 = SharedEntity;//这样也可以

			//这里做的和sharedentity所做的一样，但之前会增加引用计数，而这里不会。
			//把一个shared_ptr赋值给一个shared_ptr会增加引用计数，把一个shared_ptr赋值给一个weak_ptr就不会。
			std::weak_ptr<Entity> weakentity = SharedEntity;

			e0 = SharedEntity;

			//entity->Print();//可以通过箭头访问该函数。
		}//在第一个作用域里， SharedEntity die了。但没有析构Entity。因为e0仍然是活的，能够引用Entity
	}//第二个作用域结束，引用也消失了，此时Entity也析构了。
	


	std::cin.get();
}
