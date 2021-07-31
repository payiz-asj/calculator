#include"head.h"



//enum      fuhao { .  , +  , -  , *  , /  , (  , )  , sin  , cos  , tan  , lg  , ln ,  ^  ,  sqr ,shu};
//int fuhao[16] = { 0  , 1  ,2/30, 3  , 4  , 5  , 6  ,  7   ,  8   ,  9   ,  10  , 11 ,  12 ,   13 ,14 };

string DoubleToString(double Input)
{
	stringstream Oss;
	Oss << Input;
	return Oss.str();
}
string IntToString(int Input)
{
	stringstream Oss;
	Oss << Input;
	return Oss.str();
}

double StringToDouble(string Input)
{
	double Result;
	stringstream Oss;
	Oss << Input;
	Oss >> Result;
	return Result;
}
int  StringToInt(string Input)
{
	int  Result;
	stringstream Oss;
	Oss << Input;
	Oss >> Result;
	return Result;
}

//检测输入合法性
int jiance(string c,unsigned &i)
{
	unsigned  fanhui = 0;
	unsigned xiaoshudian = 0, zuokuohao = 0, youkuohao = 0;
	if ((c[1] >= '0'&&c[1] <= '9') ||c[1]=='p'|| c[1] == 's' || c[1] == 'c' || c[1] == 't' || c[1] == 'l' || c[1] == '('||(c[1]=='-'&&c[2]!='+'&&c[2]!='-'&&c[2]!='*'&&c[2]!='/'&&c[2]!='^'&&c[2]!=')'))
	{
		fanhui= 1; //开头合法
		if ((c[c.size() - 5] >= '0'&&c[c.size() - 5] <= '9') ||c[c.size ()-5]=='i'|| c[c.size() - 5] == ')')
		{
			fanhui = 1; //结尾合法
			while (i <(c.size() - 4))
			{
				if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/')
				{
					xiaoshudian = 0;
					if ((c[i + 1] >= '0'&&c[i + 1] <= '9') ||c[i+1]=='p'|| c[i + 1] == '(' || c[i + 1] == 's' || c[i+1] == 'c' || c[i+1] == 't' || c[i+1] == 'l')
						fanhui = 1; //加减乘除合法
					else
						return -3; //加减乘除运算符格式错误
				}
				else if (c[i] == 's')
				{
					if (c[i - 1] != 'o')
					{
						xiaoshudian = 0;
						if (c[i + 1] == 'i')
						{
							if (c[i + 2] == 'n')
							{
								fanhui = 1;//三角函数合法
								if ((c[i + 3] >= '0'&&c[i + 3] <= '9') || c[i + 3] == 'p' || c[i + 3] == '(' || c[i + 3] == 's' || c[i + 3] == 'c' || c[i + 3] == 't' || c[i + 3] == 'l' || c[i + 3] == '-')
									fanhui = 1;
								else return -4;
							}
							else return -4;//三角函数错误
						}
						else if (c[i + 1] == 'q')
						{
							if (c[i + 2] == 'r')
							{
								fanhui = 1;//开方函数合法
								if ((c[i + 3] >= '0'&&c[i + 3] <= '9') || c[i + 3] == 'p' || c[i + 3] == '(' || c[i + 3] == 's' || c[i + 3] == 'c' || c[i + 3] == 't' || c[i + 3] == 'l' || c[i + 3] == '-')
									fanhui = 1;
								else return -5;
							}

							else return -5; //开方函数错误
						}
						else
							return -4;
					}
				}
				else if (c[i] == 'c')
				{
					xiaoshudian = 0;
					if (c[i + 1] == 'o')
					{
						if (c[i + 2] == 's')
						{
							fanhui = 1;//三角函数合法
							if ((c[i + 3] >= '0'&&c[i + 3] <= '9') || c[i + 3] == 'p' || c[i + 3] == '(' || c[i + 3] == 's' || c[i + 3] == 'c' || c[i + 3] == 't' || c[i + 3] == 'l' || c[i + 3] == '-')
								fanhui = 1;
							else return -4;
						}
						else return -4;//三角函数错误
					}
					else return -4;//三角函数错误
				}
				else if (c[i] == 't')
				{
					xiaoshudian = 0;
					if (c[i + 1] == 'a')
					{
						if (c[i + 2] == 'n')
						{
							fanhui = 1;//三角函数合法
							if ((c[i + 3] >= '0'&&c[i + 3] <= '9') || c[i + 3] == 'p' || c[i + 3] == '(' || c[i + 3] == 's' || c[i + 3] == 'c' || c[i + 3] == 't' || c[i + 3] == 'l' || c[i + 3] == '-')
								fanhui = 1;
							else return -4;
						}
						else return -4;//三角函数错误
					}
					else return -4;//三角函数错误
				}
				else if (c[i] == 'l')
				{
					xiaoshudian = 0;
					if (c[i + 1] == 'g')
					{
						if ((c[i + 2] > '0'&&c[i + 2] <= '9') || c[i + 2] == 'p' || c[i + 2] == '(' || c[i + 2] == 's' || c[i + 2] == 'c' || c[i + 2] == 't' || c[i + 2] == 'l')
							fanhui = 1;//对数函数合法
						else return -6;//对数函数错误
					}
					else if (c[i + 1] == 'n')
					{
						if ((c[i + 2] > '0'&&c[i + 2] <= '9') || c[i + 2] == 'p' || c[i + 2] == '(' || c[i + 2] == 's' || c[i + 2] == 'c' || c[i + 2] == 't' || c[i + 2] == 'l')
							fanhui = 1;//对数函数合法
						else return -6;
					}
					else
						return -6;//对数函数错误
				}
				else if (c[i] == '^')
				{
					xiaoshudian = 0;
					if ((c[i + 1] >= '0'&&c[i + 1] <= '9') || c[i + 1] == 'p' || c[i + 1] == '(' || c[i + 1] == 's' || c[i + 1] == 'c' || c[i + 1] == 't' || c[i + 1] == 'l')
						fanhui = 1;//乘方函数合法
					else return -7;
				}
				else if (c[i] == '(')
				{
					xiaoshudian = 0;
					zuokuohao++;
					if ((c[i + 1] >= '0'&&c[i + 1] <= '9') || c[i + 1] == 'p' || c[i + 1] == '(' || c[i + 1] == 's' || c[i + 1] == 'c' || c[i + 1] == 't' || c[i + 1] == 'l'||c[i+1]=='-')
						fanhui = 1;//左括号合法
					else return -8;
				}
				else if (c[i] == ')')
				{
					xiaoshudian = 0;
					youkuohao++;
					if (c[i + 1] == ')' || c[i + 1] == '+' || c[i + 1] == '-' || c[i + 1] == '*' || c[i + 1] == '/'||c[i+1]=='#')
						fanhui = 1;//右括号合法
					else return -9;
				}
				else if (c[i] == '.')
				{
					if (c[i + 1] >= '0'&&c[i + 1] <= '9')
					{
						fanhui = 1;//小数点合法
						xiaoshudian = 1;
					}
					else return -10;  //小数点错误
				}
				else if (c[i] > '0'&&c[i] <= '9')
				{
					if (xiaoshudian == 0)
					{
						if ((c[i + 1] >= '0'&&c[i + 1] <= '9')  || c[i + 1] == ')'||c[i+1]=='.'||c[i+1]=='+'||c[i+1]=='-'||c[i+1]=='*'||c[i+1]=='/'||c[i+1]=='^'||c[i+1]=='#')
							fanhui = 1;//实数合法
						else return -11;//实数错误
					}
					else
					{
						if ((c[i + 1] >= '0'&&c[i + 1] <= '9') || c[i + 1] == ')' || c[i + 1] == '+' || c[i + 1] == '-' || c[i + 1] == '*' || c[i + 1] == '/' || c[i + 1] == '^' || c[i + 1] == '#')
							fanhui = 1;//实数合法
						else return -11;//实数错误
					}
					
				}
				else if (c[i] == 'p')
				{
					if (c[i + 1] == 'i' && ( c[i + 2] == ')' || c[i + 2] == '+' || c[i + 2] == '-' || c[i + 2] == '*' || c[i + 2] == '/' || c[i + 2] == '^' || c[i + 2] == '#'))
						fanhui = 1;
					else
						return -13;
				}
				
				if (zuokuohao < youkuohao)
					return -12;  //括号不匹配
				i++;
			}
		}
		else
			return -2;  //结尾错误
	}
	else
		return -1;//开头错误

	if (zuokuohao != youkuohao)
		return -12;  //括号不匹配

	return fanhui;

}
//输出检测结果
int  print_error(int n)
{
	switch (n)
	{
	case 1: //正确
		cout << endl << "表达式正确！" << endl;
		return 1;
	case-1: //开头错误
		cout << endl << "开头错误！" << endl;
		return -1;
	case -2: //结尾错误
		cout << endl << "结尾错误！" << endl;
		return -1;
	case-3://加减乘除运算符格式错误
		cout << endl << "加减乘除运算符使用错误！" << endl;
		return -1;
	case-4:
		cout << endl << "三角函数使用错误！" << endl;
		return -1;
	case-5:
		cout << endl << "开方运算符使用错误！" << endl;
		return -1;
	case-6:
		cout << endl << "对数运算符使用错！" << endl;
		return -1;
	case-7:
		cout << endl << "乘方运算符使用错！" << endl;
		return -1;
	case-8:
		cout << endl << "左括号使用错误！" << endl;
		return -1;
	case-9:
		cout << endl << "右括号使用错误！" << endl;
		return -1;
	case-10:
		cout << endl << "小数点使用错误！" << endl;
		return -1;
	case-11:
		cout << endl << "实数输入错误！" << endl;
		return -1;
	case-12:
		cout << endl << "左右括号不匹配！" << endl;
		return -1;
	case -13:
		cout << endl << "pi使用错误！" << endl;
		return -1;
	default:
		return 0;
	}
}
//各种分类
int divide(char c, char a, char b)
{
	if (a >= '0' && a <= '9')
		return 14;
	else if (a == '.')
		return 0;
	else if (a == '+')
		return 1;
	else if (a == '-')
	{
		if (c == '#' || c == 'n' || c == 's' || c == 'g' || c == '^' || c == '(')
			return 30;      //负号
		else return 2;      //减号
	}		
	else if (a == '*')
		return 3;
	else if (a == '/')
		return 4;
	else if (a == '(')
		return 5;
	else if (a == ')')
		return 6;
	else if (a == 's'&&b=='i')
		return 7;
	else if (a == 'c')
		return 8;
	else if (a == 't')
		return 9;
	else if (a == 'l'&&b=='g')
		return 10;
	else if (a == 'l'&&b == 'n')
		return 11;
	else if (a == '^')
		return 12;
	else if (a == 's'&&b == 'q')
		return 13;
	else if (a == '#')
		return 99;//结束中缀变后缀的转换
	else if (a == 'p'&&b == 'i')
		return 31;
	else
		return 100;   //没意义
}
int devide2(string c)
{
	if (c == "|7|" || c == "|8|" || c == "|9|" || c == "|10|" || c == "|11|" || c == "|30|" || c == "|13|"||c=="|31|")
		return 1;    //单目
	else if (c == "|1|" || c == "|2|" || c == "|3|" || c == "|4|" || c == "|12|")
		return 2;    //双目
	else
		return 3;    //实数
}
//比较优先级
int compare(jiegou &fu ,int d)
{
	int gc_ysfu;//刚才的运算符
	int dq_ysfu;//当前运算符
	gc_ysfu = fu.com();
	if (d == 1 || d == 2)
		dq_ysfu = 6;
	else if (d == 3 || d == 4)
		dq_ysfu = 5;
	else if (d == 12||d==13)
		dq_ysfu = 4;
	else if (d == 7 || d == 8 || d == 9 || d == 10 || d == 11)
		dq_ysfu = 3;
	else if (d == 30||d==31)
		dq_ysfu = 2;
	else if (d == 5)
		dq_ysfu = 1;
	//开始比较
	if (gc_ysfu == -1||gc_ysfu==1)
		return 1;
	else {
		if (gc_ysfu< dq_ysfu)
			return -1; //b的级别低
		else if (dq_ysfu == gc_ysfu)
			return 0;  //相等
		else
			return 1;  //b的级别高
	}

}
//中缀变后缀
void biaodashi_jiexi(string c , vector <string> &b)
{
	jiegou ys_fu;  //运算符栈
	unsigned i = 1;
	int d = 0;
	string shuzi;
	int flag = 0;
	int first = 0;
	while (i < c.size()-3)
	{
		d = divide(c[i-1],c[i],c[i+1]);

		if (d == 14 || d == 0)
		{
			shuzi.push_back(c[i]);
			flag = 0;
			first = 1;
			i++; 
		}
		else 
		{ 
			if (first==1)
				flag++;
			if (flag == 1)
			{
				b.push_back(shuzi);
				shuzi.clear();
			}
			if (d == 99)
			{
				int k = 9;
				k = ys_fu.out();
				while (k > 0)
				{
					string temp;
					temp.push_back('|');
					temp += IntToString(k);
					temp.push_back('|');
					b.push_back(temp);
					k = ys_fu.out();
				}
				i++;
			}
			else if (d == 1 || d == 2 || d == 3 || d == 4 || d == 5 || d == 12 || d == 30)
			{
				int what = 9;
				what = compare(ys_fu, d);
				if (what == 1)
				{
					ys_fu.set(d);
					i++;
				}
				else if (what == 0 || what == -1)
				{
					int k = ys_fu.get();
					if (k == 7 || k == 8 || k == 9 || k == 10 || k == 11 || k == 12 || k == 13)
					{
						while (k == 7 || k == 8 || k == 9 || k == 10 || k == 11 || k == 12 || k == 13)
						{
							string temp;
							k = ys_fu.out();
							temp.push_back('|');
							temp += IntToString(k);
							temp.push_back('|');
							b.push_back(temp);
							k = ys_fu.get();
						}
						ys_fu.set(d);
					}
					else
					{
						string temp;
						int k = ys_fu.out();
						temp.push_back('|');
						temp += IntToString(k);
						temp.push_back('|');
						b.push_back(temp);
						ys_fu.set(d);
					}
					i++;
				}
			}
			else if (d == 6)
			{
				//shuzi.clear();
				//flag = 1;
				int k = ys_fu.out();
				while (k != 5)
				{
					string temp;
					temp.push_back('|');
					temp += IntToString(k);
					temp.push_back('|');
					b.push_back(temp);
					k = ys_fu.out();
				}
				k = ys_fu.get();
				if (k == 7 || k == 8 || k == 9 || k == 10 || k == 11||k==12||k==13)
				{
					while (k == 7 || k == 8 || k == 9 || k == 10 || k == 11 || k == 12 || k == 13)
					{
						string temp;
						k = ys_fu.out();
						temp.push_back('|');
						temp += IntToString(k);
						temp.push_back('|');
						b.push_back(temp);
						k = ys_fu.get();
					} 
				}
				i++;

			}
			else if (d == 7 || d == 8 || d == 9 || d == 13)
			{
				//shuzi.clear();
				//flag = 1;
				int what = 9;
				what = compare(ys_fu, d);
				if (what == 1)
				{
					ys_fu.set(d);
					i += 3;
				}
				else if (what == 0 || what == -1)
				{
					if (flag == 1)
					{
						int k = ys_fu.get();
						if (k == 7 || k == 8 || k == 9 || k == 10 || k == 11 || k == 12 || k == 13)
						{
							while (k == 7 || k == 8 || k == 9 || k == 10 || k == 11 || k == 12 || k == 13)
							{
								string temp;
								k = ys_fu.out();
								temp.push_back('|');
								temp += IntToString(k);
								temp.push_back('|');
								b.push_back(temp);
								k = ys_fu.get();
							}
							ys_fu.set(d);
						}
						else
						{
							string temp;
							int k = ys_fu.out();
							temp.push_back('|');
							temp += IntToString(k);
							temp.push_back('|');
							b.push_back(temp);
							ys_fu.set(d);
							
						}
						i += 3;
					}
					else
					{
						ys_fu.set(d);
						i += 3;
					}
					
				}

			}
			else if (d == 10 || d == 11||d==31)
			{
				//shuzi.clear();
				//flag = 1;
				int what = 9;
				what = compare(ys_fu, d);
				if (what == 1)
				{
					ys_fu.set(d);
					i += 2;
				}
				else if (what == 0 || what == -1)
				{
					if (flag == 1)
					{
						int k = ys_fu.get();
						if (k == 7 || k == 8 || k == 9 || k == 10 || k == 11 || k == 12 || k == 13)
						{
							while (k == 7 || k == 8 || k == 9 || k == 10 || k == 11 || k == 12 || k == 13)
							{
								string temp;
								k = ys_fu.out();
								temp.push_back('|');
								temp += IntToString(k);
								temp.push_back('|');
								b.push_back(temp);
								k = ys_fu.get();
							}
							ys_fu.set(d);
						}
						else
						{
							string temp;
							int k = ys_fu.out();
							temp.push_back('|');
							temp += IntToString(k);
							temp.push_back('|');
							b.push_back(temp);
							ys_fu.set(d);
						}
						
						i += 2;
					}
					else
					{
						ys_fu.set(d);
						i += 2;
					}
				}
			}
		}
	}//while 结束
}
//运算后缀表达式
double solve(string c)
{
	double result=0;
	vector <string> b,bb;
	string shu_a, shu_b, fix,da;            //shu_a,shu_b值前后两个运算数。fix是当前运算符。da是运算后的结果。
	biaodashi_jiexi(c,b);
	//开始运算后缀表达式
	vector<string>::iterator p;
	p = b.begin();
	for (; p != b.end(); p++)
	{
		int n=devide2(*p);
		if (n == 3)
			bb.push_back(*p);
		else if (n == 2)
		{
			fix =*p;
			shu_b = bb[bb.size() - 1];
			bb.pop_back();
			shu_a = bb[bb.size() - 1];
			bb.pop_back();
			da = calculate(shu_a, fix, shu_b);
			bb.push_back(da);
		}
		else if (n == 1)
		{
			fix = *p;
			if (bb.size() == 0)
			{
				da = calculate(shu_a, fix, "no");
				bb.push_back(da);
			}
			else
			{
				shu_a = bb[bb.size() - 1];
				if (fix == "|31|")
				{
					da = calculate(shu_a, fix, "no");
					bb.push_back(da);
				}
				else {
					bb.pop_back();
					da = calculate(shu_a, fix, "no");
					bb.push_back(da);
				}
				
			}
			
		}

	}
	
	cout << "转换成后缀表达式后：";
	for (unsigned i = 0; i < b.size(); i++)
		cout << b[i]<<"  ";
	result = StringToDouble(bb[bb.size() - 1]);
	cout << endl<<endl << "结果为：" << fixed << setprecision(8) << result << endl;
	string ff;
	for (unsigned i = 1; i < c.size() - 4; i++)
			ff.push_back(c[i]);
	save(ff, result);
	return 0;
}
//算数运算
string calculate(string a, string f, string b)
{
	double  _result;    //局部答案
	string out;
	if (b == "no")     //单目
	{
		double aa = StringToDouble(a);
		if (f == "|7|")
			_result = sin(StringToDouble(a));
		else if (f == "|7|")
			_result = sin(StringToDouble(a));
		else if (f == "|8|")
			_result = cos(StringToDouble(a));
		else if (f == "|9|")
			_result = tan(StringToDouble(a));
		else if (f == "|10|")
			_result = log10(StringToDouble(a));
		else if (f == "|11|")
			_result = log(StringToDouble(a));
		else if (f == "|30|")
			_result = (-1)*(StringToDouble(a));
		else if (f == "|13|")
			_result = pow(StringToDouble(a), 0.5);
		else if (f == "|31|")
			_result = pi;
	}
	else               //双目
	{
		if (f == "|1|")
			_result = StringToDouble(a) + StringToDouble(b);
		else if (f == "|2|")
			_result = StringToDouble(a) - StringToDouble(b);
		else if (f == "|3|")
			_result = StringToDouble(a) * StringToDouble(b);
		else if (f == "|4|")
			_result = StringToDouble(a) / StringToDouble(b);
		else if (f == "|12|")
			_result = pow(StringToDouble(a), StringToDouble(b));
	}
	out = DoubleToString(_result);
	return out;
}
//计算器入口及输出答案
void main_cal()
{
	system("cls");
loop1:
	{
		string begin, end, b, input;
		//cout << endl << endl << "\t\t\t计算器" << endl << endl;
		cout << endl << endl;
		cout << "请输入表达式：（输入0代表退出） ";
		cin >> b;
		//b= "tan45-cos60+sin30+(-6)*3^4+log100+sqr4-8/2";
		if (b != "0")
		{
			begin = "#";
			end = "####";
			input = begin + b + end;
			//cout << "start";
			unsigned i = 1;
			int n = jiance(input, i);
			cout << "------------------------------------------" << endl;
			print_error(n);
			cout << endl;
			if (n == 1)
				solve(input);
			else
				cout << "出错位置：" << i << endl << endl;

			goto loop1;
		}
	}
}
//开始菜单
void manu()
{
	//菜单
	system("cls");
	cout << "\n\n\n   \t\t★---------------------------------------★" << endl;
	cout << "   \t\t┋           PAYIZ  超级计算器           ┋" << endl;
	cout << "   \t\t★---------------------------------------★" << endl;
	cout << "   \t      ♀                      \t\t\t   ♀" << endl;
	cout << "   \t    ♀                    舒适\t\t\t     ♀" << endl;
	cout << "   \t  ♀                          \t\t\t       ♀" << endl;
	cout << "   \t♀                        准确\t\t\t         ♀" << endl;
	cout << "   \t  ♀                           \t\t               ♀" << endl;
	cout << "   \t    ♀                   功能多样\t\t     ♀" << endl;
	cout << "   \t      ♀                         \t\t   ♀" << endl;
	cout << "   \t\t♀ ♀ ♀ ♀ ♀ ♀  ♀  ♀ ♀ ♀ ♀ ♀ ♀ ♀  " << endl;
	//usleep(4000000);
}
//控制
void control()
{
	string bb;
	while (1)
	{
		cout << endl << "sudo:～$";
		cin >> bb;
		if (zhiling(bb) == 1)
		{
			system("cls");
			main_cal();
		}
		else if (zhiling(bb) == 2)
		{
			system("cls");
			history();
		}
		else if (zhiling(bb) == 3)
		{
			system("cls");
			exit_all();
			break;
		}
		else if (zhiling(bb) == 4)
		{
			system("cls");
		}
		else if (zhiling(bb) == 5)
		{
			help();
		}
		else if (zhiling(bb) == 0)
		{
			system("cls");
			flase_input();
		}
	}
}
//指令
int zhiling(string aa)
{

	if (aa == "CAL")return 1;
	else if (aa == "HIS")return 2;
	else if (aa == "EXIT")return 3;
	else if (aa == "CLEAR")return 4;
	else if (aa == "HELP")return  5;
	else	 return 0;
}
//输错提示
void flase_input()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl << "\t\t\t\t不是标准指令！" << endl;
	cout << endl << "\t\t\t输入 \" HELP \" 查阅常用命令列表！ " << endl;
	//usleep(3000000);
}
//退出
void  exit_all()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t★---------------------------------------------★" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout << "\t\t|\t\t    谢谢使用！\t\t\t|" << endl;
	cout << "\t\t|\t          欢迎下次再来\t\t\t|" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout << "\t\t★---------------------------------------------★" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	//usleep(3000000);
}
//帮助
void help()
{
	cout << endl << "\t\t\t\t\t常用命令列表:" << endl;
	cout << "\t\t★-------------------------------------------------------★" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\tCAL                 ->  计算" << endl;
	cout << "\t\t\tHIS                 ->  查看历史" << endl;
	cout << "\t\t\tEXIT                ->  保存并退出游戏" << endl;
	cout << "\t\t\tCLEAR               ->  清屏" << endl;
	cout << "\t\t\tHELP                ->  显示常用命令列表" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t" << endl;
	cout << "\t\t★-------------------------------------------------------★" << endl;
	//usleep(5000000);
}
//查阅记录
void history()
{
	ifstream p;
	string a, b;
	int i = 1;
	p.open("result.txt", ios::in);
	if (!p)
	{
		cout << "\" result.txt \" 文件打开失败！"<<endl;
	}
	else 
	{
		cout << "历史记录：" << endl;
		while (!p.eof())
		{
			p >> a >> b;
			cout << i << "." << endl;
			cout << "表达式：" << a << endl;
			cout << "计算结果:" << b << endl;
			i++;
		}

	}
	
}
//保存记录
void save(string a,double num)
{
	ofstream p;
	p.open("result.txt", ios::app);
	if (!p)
	{
		p.open("result.txt", ios::out);
		p << a;
		p << endl << num;
		
	}
	else 
	{
		p << endl << a;
		p << endl << num;
	}
	p.close();
}

//附加功能

//void select()
//{
//	cout << endl;
//	cout << endl;
//	cout << endl;
//	cout << endl << "\t\t\t请选择:" << endl;
//	cout << "\t\t★---------------------------------------------★" << endl;
//	cout << "\t\t\t\t\t\t\t\t" << endl;
//	cout << "\t\t\t1.科学计算器\t\t\t" << endl;
//	cout << "\t\t\t2.汇率转换器\t\t\t" << endl;
//	cout << "\t\t\t3.\t\t\t" << endl;
//	cout << "\t\t\t\t\t\t\t\t" << endl;
//	cout << "\t\t★---------------------------------------------★" << endl;
//}