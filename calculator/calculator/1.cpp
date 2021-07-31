//
////*************************************
////��ѧ���ʽ������
////*************************************
////Expression_Parser.cpp
//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//
//const double PI = 3.141592654;
//
////���Ƕ�ת���ɻ���
//double degTorad(double deg)
//{
//	return (2 * PI*deg) / 360;
//}
//
////����׺���ʽת��Ϊ��׺���ʽ(�沨��ʽ)
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
////����׺���ʽ(�沨��ʽ)��ֵ
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
////������ѧ���ʽ(�������õĽӿ�)
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
////���÷���
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
//	//cin>>exp>>endl;  //ȡ������ע�ͣ��ȴ��û�������ѧ���ʽ
//	result = Expression_Parser(exp);
//	cout << "���ʽ " << exp << " �ļ�����Ϊ��" << result << endl;
//
//	cin.get();
//	return 0;
//}
//
//
////***************************************
////ʹ��˵��
////***************************************
////��Խ�ԣ�
////1��֧�ֵ���ѧ������� + -*/ sin cos tan sqrt pow log10
////
////2��֧��С�����㣬������������Ϊdouble��˫���ȣ���
////
////3��֧��С���ţ���
////
////
////ʵ����
////a^b ��ʾ��a��b�η�
////
////va��av ��ʾ��aƽ����
////v(va)��avv�ȼ� ��ʾ��a������ƽ���������Դ����ƣ���a��ż�η�����
////
////s30 ��ʾ��30�������ֵ
////ע�����Ц�ֵȡ3.141592654
////
////L100 ��ʾ��100��10Ϊ�׵Ķ���
////ע��LҪ��д
////
////
////�����ԣ�
////1����֧�ָ�����
////����취�����Ҫ����ʽ - 5 * 9, �����д��(0 - 5) * 9 ����֮�ǿ��������Ž���ġ�
////
////2��δ���б��ʽ����ȷ����֤��
////
////
////�������ȼ���
////L
////v��^
////s��c��t
////*�� /
////+�� -
////
////ע��s��c��t �ֱ����sin��cos��tan��v��������^������ƽ����L������10Ϊ���������
////
////
////����һ����ȷ�ı��ʽ��t45 - c60 + s30 + (-6) * 3 ^ 4 + L100 + v4 - 8 / 2