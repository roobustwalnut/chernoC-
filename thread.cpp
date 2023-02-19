#include<iostream>
#include<thread>//线程类的

//用std::thread来创建一个线程对象，一个变量。
//线程对加速程序有帮助，主要目的是优化。

static bool s_Finished = false;
void DoWork()
{
	using namespace std::literals::chrono_literals;

	std::cout << "Started thread id =" << std::this_thread::get_id() << std::endl;
	while (!s_Finished)
	{
		std::cout << "Working……\n";//这个线程一直在打印Working
		//像这样多线程的事，以最快的速度打印会让cpu占用率达到100%，不太好。
		std::this_thread::sleep_for(1s);//打印完上面一行，会等待一秒。
		//this_thread用它来给当前线程下命令
	}
}
int main()
{
	std::thread worker(DoWork);

	std::cin.get();//这个线程一直在等待按下回车键。
	s_Finished = true;
	
	//调用join的目的是：在主线程上等待工作线程完成所有执行后，再进行主线程。
	worker.join();//join函数本质上是等待这个线程加进来。等待这个线程完成它的工作，阻塞当前线程，直到另一个线程完成它的工作。
	
	std::cout << "Started thread id =" << std::this_thread::get_id() << std::endl;//这一行的id与上面的不一样，它们工作的线程不一样。
	std::cout << "Finished." << std::endl;
	std::cin.get();
}
