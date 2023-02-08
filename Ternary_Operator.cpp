#include <iostream>
#include<string>

//语法糖：三元运算符。用:?处理特定条件下的变量赋值
static int s_Level = 1;
static int s_Speed = 2;
int main()
{
	if (s_Level > 5)
		s_Speed = 10;
	else
		s_Speed = 5;

	//用三元运算符。可以看到，目的是将s_Speed赋值。
	s_Speed = s_Level > 5 ? 10 : 5;

	//可以对三元运算符进行嵌套。但cherno本人不这样写。
	s_Speed = s_Level > 5 && s_Level < 100 ? s_Level>10 ? 15:10:5;
	//运算顺序从左到右。&&操作最先。

	//例如给玩家赋予称号
	std::string rank = s_Level > 5 ? "Master" : "Beginner";
	//对比不使用三元运算符。在这种情况下，会创建一个空字符串，然后用新对象覆盖它。
	//下面这种情况性能慢了，因为创建了一个临时变量又立即销毁它。
	std::string otherrank;
	if (s_Level > 10)
		otherrank = "Master";
	else
		otherrank = "Beginner";
	std::cin.get();
}
