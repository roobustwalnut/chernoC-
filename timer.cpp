#include<iostream>
#include<thread>
#include<chrono>

struct Timer//使用整个对象生存期的范例，让其自动为我计时。
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f;//毫秒计数
		std::cout << "Timer took " << ms << "ms" << std::endl;
	}
};

void Function()
{
	Timer timer;
	for (int i = 0; i < 100; i++)//计算这个for循环要多久。
	{
		std::cout << "Hello\n" ;
	}
}

int main()
{
	Function();
	/*
	using namespace std::literals::chrono_literals;
	auto start = std::chrono::high_resolution_clock::now();//当前时间，类型巨长，用auto吧。

	//计时本身也有时间开销，这里计的不一定是1s。
	std::this_thread::sleep_for(1s);//线程休眠一秒。注意要用这个得使用命名空间（什么chrono）。
	auto end = std::chrono::high_resolution_clock::now();
	
	//高精度计时
	std::chrono::duration<float> duration = end - start;
	std::cout << duration.count() << "s" << std::endl;
	*/
	std::cin.get();
}
