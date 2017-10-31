#include<iostream>
#include<string>
using namespace std;


//��11.1 ���ʹ��л���ĳ�Ա
class Student{       //��������
public:                     //���๫�ó�Ա
	void get_value() {              //����������ݵĳ�Ա����
		cin >> num >> name >> sex;
	}
	void display() {       //����������ݵĳ�Ա����
		cout << " num:" << num << endl;
		cout << " name:" << name << endl;
		cout << " sex:" << sex << endl;
	}
private:       //����˽�г�Ա
	int num;
	string name;
	char sex;
};

class Student1 :public Student {          //��public��ʽ����������Student1
public:
	void get_value_1() { cin >> age >> addr; } //��������������
	void display_1() {
		cout << " age:" << age << endl;   //�����������˽�г�Ա����ȷ
		cout << " address:" << addr << endl;       //�����������˽�г�Ա����ȷ
	}
private:
	int age;
	string addr;
};

//��11.1 ���ʹ��л���ĳ�Ա �ֱ���û����display�������������е�display_1���� �Ⱥ����5������
int main11_1() {
	Student1 stud;  //����������Student1�Ķ���stud
	stud.get_value();
	stud.get_value_1();
	stud.display();
	stud.display_1();
	return 0;
}

//��11.2 ����11.1�еĹ��ü̳з�ʽ��Ϊ˽�м̳з�ʽ������Student����
class Student2 :private Student {          //��private��ʽ����������Student2
public:
	void get_value_1()
	{
		get_value();     //���û���Ĺ��ú�����������3������
		cin >> age >> addr; } //��������������
	void display_1() {
		display();     //���û���Ĺ��ó�Ա�������3�����ݳ�Ա��ֵ
		cout << " age:" << age << endl;   //�����������˽�г�Ա����ȷ
		cout << " address:" << addr << endl;       //�����������˽�г�Ա����ȷ
	}
private:
	int age;
	string addr;
};

//��11.2 ����11.1�еĹ��ü̳з�ʽ��Ϊ˽�м̳з�ʽ������Student����
int main11_2() {
	Student2 stud;  //����������Student1�Ķ���stud
	stud.get_value_1();
	stud.display_1();
	return 0;
}

//��11.3 �������������ñ�����Ա
class Student3 {    //��������
public:    //�����޹��ó�Ա
protected:   //���ౣ����Ա
	int num;
	string name;
	char sex;
};

class Student31 :protected Student3 {  //��protected��ʽ����������Student31
public:
	void get_value1();  //�����๫�ó�Ա����
	void display1();     //�����๫�ó�Ա����
private:
	int age;     //������˽�����ݳ�Ա
	string addr;  //������˽�����ݳ�Ա
};

void Student31::get_value1() {     //���������๫�ó�Ա����
	cin >> num >> name >> sex;      //���뱣���������ݳ�Ա
	cin >> age >> addr;      //�������������ݳ�Ա
} 

void Student31::display1() {        //���������๫�ó�Ա����
	cout << " num:" << num << endl;  //���û���ı�����Ա
	cout << " name:" << name << endl;  //���û���ı�����Ա
	cout << " sex:" << sex << endl;                 //���û���ı�����Ա
	cout << " age:" << age << endl;   //�����������˽�г�Ա
	cout << " address:" << addr << endl;    //�����������˽�г�Ա
}

//��11.3 �������������ñ�����Ա
int main11_3() {
	Student31 stud1;        //stud1��������Student31��Ķ���
	stud1.get_value1(); //get_value1���������еĹ��ó�Ա��������������
	stud1.display1();         //display1���������еĹ��ó�Ա�������������
	return 0;
}

//��11.4 �༶�����ķ������� A��B�Ĺ��û��� B��C�ı�������...���Գ��õ��ǹ��ü̳�..
class A {   //����
public:
	int i;
protected:
	void f1();
	int j;
private:
	int k;
};

class B:public A {   //����
public:
	void f2();
protected:
	void f3();
private:
	int m;
};

class C :protected B{   //����
public:
	void f4();
private:
	int n;
};

//��11.5 ����򵥵�������Ĺ��캯��
class Student5 {             //��������Student5
public:
	Student5(int n, string nam, char s) {     //�������Ĺ��캯��
		num = n;
		name = nam;
		sex = s;
	}
	~Student5(){}      //������������
protected:  //��������
	int num;
	string name;
	char sex;
};

class Student51 :public Student5 {   //��������������Student51
public:     //������Ĺ��ò���
	Student51(int n, string nam, char s, int a, string ad) :Student5(n, nam, s) { //���������๹�캯��
		age = a; //�ں�������ֻ�����������������ݳ�Ա��ʼ��
		addr = ad;
	}
	void show() {
		cout << "num:" << num << endl;
		cout << " name:" << name << endl;  
		cout << " sex:" << sex << endl;                 
		cout << " age:" << age << endl;  
		cout << " address:" << addr << endl;
	}
	~Student51(){}   //��������������
private:         //�������˽�в���
	int age;
	string addr;
};

//��11.5 ����򵥵�������Ĺ��캯��
int main11_5() {
	Student51 stud1(10010, "Wang-li", 'f', 19, "115 Beijing Road,Shanghai");
	Student51 stud2(10011, "Zhang-fang", 'm', 21, "213 Shanghai Road,Beijing");
	stud1.show();  //�����һ��ѧ��������
	stud2.show();  //����ڶ���ѧ��������
	return 0;
}

//��11.6 �����Ӷ����������Ĺ��캯��
class Student6 { //��������
public:  //���ò���
	Student6(int n, string nam) {   //���๹�캯��������11.5��ͬ
		num = n;
		name = nam;
	}
	void display() {    //��Ա����������������ݳ�Ա
		cout << "num:" << num << endl << "name:" << name << endl;
	}
protected:    //��������
	int num;
	string name;
};

class Student61 :public Student6 {  //��������������student61
public:
	Student61(int n, string nam, int n1, string nam1, int a, string ad)
		:Student6(n, nam), monitor(n1, nam1) {      //�����๹�캯��
		age = a;
		addr = ad;
	}
	void show() {
		cout << "This student is:" << endl;
		display();              //���num��name
		cout << "age:" << age << endl;   //���age
		cout << "address" << addr << endl << endl; //���addr
	}
	void show_monitor() {       //��Ա����������Ӷ���
		cout << endl << "Class monitor is:" << endl;
		monitor.display();
	}
private:       //�������˽������
	Student6 monitor;   //�����Ӷ��󣨰೤�� ����c++��ĺö�仯�����о���������������
	int age;
	string addr;
};

//��11.6 �����Ӷ����������Ĺ��캯��
int main11_6() {
	Student61 stud1(10010, "Wang-li",10001,"Li_sun",19,"115 Beijing Road,Shanghai");
	stud1.show(); //���ѧ��������
	stud1.show_monitor(); //����Ӷ��������
	return 0;
}





int main(){
	main11_6();
	system("pause");
	return 0;
}
 













