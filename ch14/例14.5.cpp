//��14.5 ���������ռ��������14.4�������ֳ�ͻ����
#include <iostream>
#include "header1.h"
#include "header2.h"

int main() {
	ns1::Student stud1(101, "Wang", 18); //ns1���Student�ඨ��stud1
	stud1.get_data();
	cout << ns1::fun(5, 3) << endl; //����ns1���fun����
	ns2::Student stud2(102, "Li", 'f'); //ns2�е��ඨ��stud2
	stud2.get_data();
	cout << ns2::fun(5, 3) << endl;
	system("pause");
	return 0;
}