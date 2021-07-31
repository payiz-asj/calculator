//
////*************************************
////数学表达式解析类
////*************************************
////Expression_Parser.cpp
//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//
//const double PI = 3.141592654;
//
////将角度转换成弧度
//double degTorad(double deg)
//{
//	return (2 * PI*deg) / 360;
//}
//
////将中缀表达式转换为后缀表达式(逆波兰式)
//void trans(char a[], char b[])
//{
//	char stock[128] = { 0 };
//
//	int top = 0;
//	int len = 0;
//	int i = 0;
//	int j = 0;
//
//	top = -1;
//	j = -1;
//	len = strlen(a);
//
//	for (i = 0; i<len; i++)
//	{
//		switch (a[i])
//		{
//		case '(':
//			stock[++top] = '(';
//			break;
//
//		case '+':
//		case '-':
//			while (top >= 0 && stock[top] != '(')
//			{
//				b[++j] = stock[top--];
//			}
//			stock[++top] = ' ';
//			stock[++top] = a[i];
//			break;
//
//		case '*':
//		case '/':
//			while (top >= 0 && stock[top] != '(' && stock[top] != '+' && stock[top] != '-')
//			{
//				b[++j] = stock[top--];
//			}
//			stock[++top] = ' ';
//			stock[++top] = a[i];
//			break;
//
//		case 's':
//		case 'c':
//		case 't':
//			while (top >= 0 && stock[top] != '(' && stock[top] != '+' && stock[top] != '-' && stock[top] != '*' && stock[top] != '/')
//			{
//				b[++j] = stock[top--];
//			}
//			stock[++top] = ' ';
//			stock[++top] = a[i];
//			break;
//
//		case 'v':
//		case '^':
//			while (top >= 0 && stock[top] != '(' && stock[top] != '+' && stock[top] != '-' && stock[top] != '*' && stock[top] != '/' && stock[top] != 's' && stock[top] != 'c' && stock[top] != 't')
//			{
//				b[++j] = stock[top--];
//			}
//			stock[++top] = ' ';
//			stock[++top] = a[i];
//			break;
//
//		case 'L':
//			while (top >= 0 && stock[top] != '(' && stock[top] != '+' && stock[top] != '-' && stock[top] != '*' && stock[top] != '/' && stock[top] != 's' && stock[top] != 'c' && stock[top] != 't' && stock[top] != 'v' && stock[top] != '^')
//			{
//				b[++j] = stock[top--];
//			}
//			stock[++top] = ' ';
//			stock[++top] = a[i];
//			break;
//
//		case')':
//			while (stock[top] != '(')
//			{
//				b[++j] = stock[top--];
//			}
//			top--;
//			break;
//
//		default:
//			b[++j] = a[i];
//			if (i == len - 1 || a[i + 1]<'0' || a[i + 1]>'9')
//			{
//				if (a[i + 1] != '.')
//				{
//					b[++j] = ' ';
//				}
//			}
//			break;
//		}
//	}
//
//	while (top >= 0)
//	{
//		b[++j] = stock[top--];
//	}
//
//	b[++j] = '\0';
//}
//
////求解后缀表达式(逆波兰式)的值
//double compvalue(char exp[])
//{
//	int top = 0;
//	int len = 0;
//	int i = 0;
//	int c = 0;
//
//	double sum = 0;
//	double digit[128] = { 0 };
//
//	char str_num_temp[128] = { 0 };
//
//	top = -1;
//	len = strlen(exp);
//
//	for (i = 0; i<len; i++)
//	{
//		switch (exp[i])
//		{
//		case ' ':
//			break;
//
//		case '+':
//			sum = digit[top] + digit[top - 1];
//			digit[--top] = sum;
//			break;
//
//		case '-':
//			sum = digit[top - 1] - digit[top];
//			digit[--top] = sum;
//			break;
//
//		case '*':
//			sum = digit[top] * digit[top - 1];
//			digit[--top] = sum;
//			break;
//
//		case '/':
//			sum = digit[top - 1] / digit[top];
//			digit[--top] = sum;
//			break;
//
//		case 's':
//			sum = sin(degTorad(digit[top]));
//			digit[top] = sum;
//			break;
//
//		case 'c':
//			sum = cos(degTorad(digit[top]));
//			digit[top] = sum;
//			break;
//
//		case 't':
//			sum = tan(degTorad(digit[top]));
//			digit[top] = sum;
//			break;
//
//		case 'v':
//			sum = sqrt(digit[top]);
//			digit[top] = sum;
//			break;
//
//		case '^':
//			sum = pow(digit[top - 1], digit[top]);
//			digit[--top] = sum;
//			break;
//
//		case 'L':
//			sum = log10(digit[top]);
//			digit[top] = sum;
//			break;
//
//		default:
//			c = 0;
//			memset(str_num_temp, 0, sizeof(str_num_temp));
//			while (exp[i] >= '0' && exp[i] <= '9' || exp[i] == '.')
//			{
//				str_num_temp[c++] = exp[i];
//				i++;
//			}
//			str_num_temp[c] = '\0';
//			digit[++top] = atof(str_num_temp);
//			break;
//		}
//	}
//
//	return digit[0];
//}
//
////解析数学表达式(供外界调用的接口)
//double Expression_Parser(char *Expression)
//{
//	char temp[128] = { 0 };
//
//	trans(Expression, temp);
//	return compvalue(temp);
//}
//
//
////**************************************************************************
////调用方法
////*************************************************************************
//
////main.cpp
//
//#include <iostream>
//using namespace std;
//
//double Expression_Parser(char *Expression);
//
//int main()
//{
//	double result = 0;
//
//	char exp[] = "t45-c60+s30+(-6)*3^4+L100+v4-8/2";
//	//cin>>exp>>endl;  //取消改行注释，等待用户输入数学表达式
//	result = Expression_Parser(exp);
//	cout << "表达式 " << exp << " 的计算结果为：" << result << endl;
//
//	cin.get();
//	return 0;
//}
//
//
////***************************************
////使用说明
////***************************************
////优越性：
////1、支持的数学运算符： + -*/ sin cos tan sqrt pow log10
////
////2、支持小数运算，运算数据类型为double（双精度）型
////
////3、支持小括号（）
////
////
////实例：
////a^b 表示求a的b次方
////
////va或av 表示求a平方根
////v(va)与avv等价 表示对a求两次平方根，可以此类推，求a的偶次方根。
////
////s30 表示求30°的正弦值
////注：其中π值取3.141592654
////
////L100 表示求100以10为底的对数
////注：L要大写
////
////
////局限性：
////1、不支持负数。
////解决办法：如果要求表达式 - 5 * 9, 则可以写成(0 - 5) * 9 。总之是可以用括号解决的。
////
////2、未进行表达式的正确性验证。
////
////
////符号优先级：
////L
////v、^
////s、c、t
////*、 /
////+、 -
////
////注：s、c、t 分别代表sin、cos、tan，v代表开方，^代表求平方，L代表以10为底求对数。
////
////
////举例一个正确的表达式：t45 - c60 + s30 + (-6) * 3 ^ 4 + L100 + v4 - 8 / 2