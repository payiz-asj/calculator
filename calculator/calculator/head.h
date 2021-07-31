#pragma   once  
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>
#include<math.h>
#include<vector>
#include <sstream> 
#include<fstream>
//#include<unistd.h>
using namespace std;

#ifndef AAAA
#define AAAA

#define pi  3.141592654
class jiegou;
double deg_To_rad(double deg);
void biaodashi_jiexi(string c, vector <string> &b);
double solve(string c);
void manu();
void control();
int compare(jiegou &fu, int d);  //这里更改了
int jiance(string c,unsigned &i);
int divide(char c,char a,char b);
int devide2(string c);
string calculate(string a, string f, string b);
int  print_error(int n);

void main_cal();
void  exit_all();
void flase_input();
void history();
int zhiling(string aa);
void help();
void save(string a, double num);


class jiegou
{
	vector <int> elem ;
	
public:
	jiegou(){}
	~jiegou(){}
	void set(int c)
	{
		elem.push_back(c);
	}
	int get()
	{
		if (elem.size() >= 1){
			int shuchu = elem[elem.size() - 1];
			return shuchu;
		}	
		else{
			//cout << "运算符栈空!";
			return -1;
		}
			
	}
	int out()
	{
		if (elem.size() >= 1){
			int shuchu = elem[elem.size() - 1];
			elem.pop_back();
			return shuchu;
		}

		else{
			//cout << "运算符栈空!";
			return -1;
		}

	}
	int com()
	{
		if (elem.size() >= 1)
		{
			int shuchu=9;
			int d= elem[elem.size() - 1];
			if (d == 1 || d == 2)
				shuchu = 6;
			else if (d == 3 || d == 4)
				shuchu = 5;
			else if (d == 12 || d == 13)
				shuchu = 4;
			else if (d == 7 || d == 8 || d == 9 || d == 10 || d == 11)
				shuchu = 3;
			else if (d == 30 || d == 31)
				shuchu = 2;
			else if (d == 5)
				shuchu = 1;
			return shuchu;
		}
		else{
			//cout << "运算符栈空!";
			return -1;
		}
	}


};

#endif 