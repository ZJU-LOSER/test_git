// 20200319B1094.cpp : �������̨Ӧ�ó������ڵ㡣
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
	string tmp = str.substr(k, n);//ȡ���жϵ��Ӵ�
	int last = tmp[n - 1] - '0';//ȡ���һλ
	int num = stoi(tmp);//���ַ���ת��Ϊ����
	if (n == 1 || num < 10) {//ͬʱ����nֻȡһλ�������0002��������
		if (num == 2 || num == 3 || num == 5 && num == 7)
			return 1;
		else
			return 0;
	}
	int flag = 1;
	if (last % 2 == 0 || last % 5 == 0) {//��ɸ
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
	int index = 0;//����Ƿ�������������������
	for (int i = 0; i + n <=len; i++) {
		if (judge(i) == 1) {
			index++;
			res = str.substr(i, n);//ȡ�Ӵ�
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

