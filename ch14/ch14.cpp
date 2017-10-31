#include <iostream>
#include<cmath>
#include<string>

using namespace std;

//��14.1 �����쳣����������������������ߣ�������������
int main14_1() {
	double triangle(double, double, double);
	double a, b, c;
	cin >> a >> b >> c;
	try
	{
		while (a > 0 && b > 0 && c > 0) {
			cout << triangle(a, b, c) << endl;
			cin >> a >> b >> c;
		}
	}
	catch (double) {
		cout << "a=" << a << ",b=" << b << ",c=" << c << ",that is not a triangle!" << endl;
	}
	cout << "end" << endl;
	return 0;
}

double triangle(double a, double b, double c) {
	double s = (a + b + c) / 2;
	if (a + b <= c || b + c <= a || a + c <= b) throw a;
	return sqrt(s*(s - a)*(s - b)*(s - c));
}

//��14.2 �ں���Ƕ�׵�����¼���쳣����
int main14_2() {
	void f1();
	try
	{
		f1(); //����f1()
	}
	catch (double) {
		cout << "error0!!" << endl;
	}
	cout << "end0" << endl;
	return 0;
}

void f1() {
	void f2();
	try { f2(); } //����f2()
	catch (char) {
		cout << "error1 !!" << endl;
	}
	cout << "end1" << endl;
}

void f2() {
	void f3();
	try { f3(); } //����f3()
	catch (int) {
		cout << "error2 !!" << endl;
	}
	cout << "end2" << endl;
}

void f3() {
	double a = 0;
	try { throw a; }  //�׳�double�����쳣
	//catch (double)
	catch (float) {
		cout << "error3 !!" << endl;
	//	throw;
	}
	cout << "end3" << endl;
}

//��14.3 ���쳣�����д�����������
class Student {
public:
	Student(int n, string nam) {  //���幹�캯��
		cout << "constructor -" << n << endl;
		num = n; name = nam;
	}
	~Student() { cout << "destructor -" << num << endl; } //������������
	void get_data(); //��Ա��������
private:
	int num;
	string name;
};

void Student::get_data() { //�����Ա����
	if (num == 0)throw num; //��num=0���׳�int�ͱ���num
	else cout << num << " " << name << endl; //��num������0�����num,name
	cout << "in get_data()" << endl; //��ʾĿǰ��get_data������
}

void fun() {
	Student stud1(1101, "Tan"); //��������stud1
	stud1.get_data(); //����stud1��get_data����
	Student stud2(0, "Li"); //��������stud2
	stud2.get_data(); //����stud2��get_data����
}

//��14.3 ���쳣�����д�����������
int main14_3() {
	cout << "main begin" << endl;   //��ʾ��������ʼ��
	cout << "call fun()" << endl; //��ʾ����fun����
	try {
		fun();
	}
	catch (int n) {
		cout << "num=" << n << ",error!" << endl; //��ʾnum=0����
	}
	cout << "main end" << endl; //��ʾ����������
	return 0;
}

/* 14.3���н��Ϊ��
main begin
call fun()
constructor -1101
1101 tan
in get_data()
constructor -0 
destructor -0 //����stud2����������
destructor -1101 //����stud1����������
num=0,error!
main end
*/





int main() {
	main14_3();
	system("pause");
	return 0;
}