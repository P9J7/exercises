#pragma once
#pragma once
#include <string>
#include <cmath>
#include<iostream>
using namespace std;

namespace ns2 {  //���������ռ�ns2
	class Student {
	public:
		Student(int n, string nam, char s) {  //���幹�캯��
			num = n; name = nam; sex = s;
		}

		void get_data(); //��Ա��������
	private:
		int num;
		string name;
		char sex;
	};

	void Student::get_data() { //�����Ա����

		cout << num << " " << name << " " << sex << endl;
	}

	double fun(double a, double b) { //�������ռ�ns1�ڶ���fun����
		return sqrt(a - b);
	}
}