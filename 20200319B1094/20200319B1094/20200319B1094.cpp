// 20200319B1094.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
string str;
int n;
int len;
int judge(int k) {
	string tmp = str.substr(k, n);//取待判断的子串
	int last = tmp[n - 1] - '0';//取最后一位
	int num = stoi(tmp);//将字符串转换为数字
	if (n == 1 || num < 10) {//同时考虑n只取一位的情况与0002这类的情况
		if (num == 2 || num == 3 || num == 5 && num == 7)
			return 1;
		else
			return 0;
	}
	int flag = 1;
	if (last % 2 == 0 || last % 5 == 0) {//初筛
		flag = 0;
		return 0;
	}
	else {
		for (int i = 3; i <= sqrt(1.0*num); i++) {
			if (num%i == 0) {
				flag = 0;
				break;
			}
		}
		return flag;
	}
}
int main()
{
	cin >> len >> n;
	cin >> str;
	string res;
	int index = 0;//标记是否出现了最早的连续素数
	for (int i = 0; i + n <=len; i++) {
		if (judge(i) == 1) {
			index++;
			res = str.substr(i, n);//取子串
			break;
		}
	}
	if (index) {
		cout << res << endl;
	}
	else
		cout << "404" << endl;
    return 0;
}

