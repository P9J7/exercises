#pragma once
#include <string>
#include <cmath>
#include<iostream>
using namespace std;

namespace ns1 {  //���������ռ�ns1
	class Student {
	public:
		Student(int n, string nam,int a) {  //���幹�캯��
			num = n; name = nam; age = a;
		}
		
		void get_data(); //��Ա��������
	private:
		int num;
		string name;
		int age;
	};

	void Student::get_data() { //�����Ա����
		
		cout << num << " " << name << " " << age << endl;
	}

	double fun(double a,double b) { //�������ռ�ns1�ڶ���fun����
		return sqrt(a + b);
	}
}