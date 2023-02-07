#include <iostream>
#include<string>
#include<stdlib.h>

//字符串字面量永远保存在只读区域内。

int main()
{
	using namespace std::string_literals;
	//用string_literals，在双引号后面+s可以实现字符串加长拼接。
	std::string name0 = "Cherno"s + "hello";

	const char name[8] = "Che\0rno";
	//计算字符串长度，结果是3，因为只计算到\0前面的字节数。

	const char* name2 = "Cherno";
	//const保证不能操纵字符串。如果去掉const，那就是未定义行为，C++未定义该情况会发生什么，不同编译器会有不同行为。
	//原因是：取了一个指向字符串字面量内存位置的指针，而字符串字面量是存储在内存的只读部分的。
	//打开exe文件，可以发现该字符串被嵌入进二进制文件，指向一个无法编辑的常量区域。
	//char是一个字节的字符

	//宽字符，需要在双引号前面加上大写L,表明字符串字面值由宽字符组成
	const wchar_t* name3 = L"Cherno";
	//其它类型
	//char16是两个字节16个比特的字符
	const char16_t* name4 = u"Cherno";
	//char32是4个字节32个比特的字符
	const char32_t* name5 = U"Cherno";
	std::cout << strlen(name) << std::endl;
	std::cin.get();
}
