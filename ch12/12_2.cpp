#include<iostream>
#include<string>

using namespace std;

//����������������ͬ������

class Student {       //��������Student
public:                     //���๫�ó�Ա
	Student(int, string, float); //�������캯��
    virtual void display(); //�����������. �麯���ޣ�������鿴P401
	//�˴���virtualҲ�������Graduate��wage������

protected:       //���ౣ����Ա����������Է���
	int num;
	string name;
	float score;
};

//Student���Ա������ʵ��
Student::Student(int n, string nam, float s) { //���幹�캯��
	num = n;
	name = nam;
	score = s;
}

void Student::display() { //�����������
	cout << endl << " num:" << num << endl;
	cout << " name:" << name << endl;
	cout << " score:" << score << endl;
}

class Graduate :public Student {          //��public��ʽ����������Graduate
public:
	Graduate(int, string, float, float);  //�������캯��
	void display();  //��������������������������ͬ��
private:
	float wage; //����
};

//Graduate���Ա������ʵ��
Graduate::Graduate(int n, string nam, float s, float w) :Student(n, nam, s), wage(w) {} //���幹�캯��


void Graduate::display() { //�����������
	
	cout  << " \n\nnum:" << num << "\n name:" << name << " \nscore:" 
		<< score <<  "\n wage:" << wage << endl;
}

//������
int main() {
	Student stud1(1001, "Li", 87.5);  //����Student�����stud1
	Graduate grad1(2001, "Wang", 98.5, 1000); //����Graduate�����grad1
	Student *pt = &stud1;  //����ָ��Student������ָ�벢ָ��stud1
	pt->display(); //����stud1.display����
	pt = &grad1;  //ָ��ָ��grad1
	pt->display();  //����grad1.display����
	
	system("pause");
	return 0;
}