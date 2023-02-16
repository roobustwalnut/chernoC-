#include<iostream>
#include<string>

//宏（macro），指让CPU完成一系列操作的一条指令。这里谈到的是在C++中使用预处理器来“宏”化某些操作。
//编译C++代码时，首先预处理器会过一遍我们能看到的语句，以#开头，这是预编译指令符号。当预编译器评估完代码后，会把评估后的代码给编译器编译。
//我们可以自定义调用宏的方式，定义宏是如何展开的。是纯文本替换。
//跟templat有点不同，二者发生的时间不同。模板评估得更晚。
//可以在日志系统中使用宏，因为记录日志的方法可能会随着设置改变。
//可以通过宏在debug模式中保留日志，在release模式中去除日志。
//在预处理器中定义宏，可以用本项目的名称like HW_DEBUG=1，这可以区分其它项目，让我们知道这个宏是在这个项目下使用的。

#if 0//通过if 0和endif，可以禁用这块代码。

#if HW_DEBUG == 1//如果定义了宏，则执行下面的LOG(x)，否则就执行else的语句，即将LOG(x)定义为空，即抹去。另一种语法：ifdef HW_DEBUG
#define WAIT std::cin.get()//可以放在任何地方，但放在前面最好。btw这个定义不好，不要这样，直接写实际的代码即可。
#define LOG(x) std::cout<<x<<std::endl
#elif defined(HW_RELEASE)
#define LOG(x)//可以看到若是release的情况下，该行高亮而if的语句暗。即在release版本中不会发布日志信息。
#endif
#endif

//定义宏函数，反斜杠为换行符号。宏必须在同一行，反斜杠能让他们在同一行。如果反斜杠后加空格，那就是空格转义符。不要这样搞。
#define MAIN int main()\
{\
	std::cin.get();\
}

//int main()
//{
//	//LOG("Hello!");
//	std::cin.get();
//}

MAIN//直接打这行就是宏定义里的东西。
