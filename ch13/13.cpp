#include <iostream>
#include <cmath>
#include<iomanip>
#include<fstream>
#include <string>
#include <strstream>

using namespace std;

//��13.1 ��һԪ���η���ax^2+bx+c=0
//��cerr������й���Ϣ,��cerr����ʾ������ʾ������Ϣ
//cerr�ǲ�����������ֱ������ʾ��������й���Ϣ����clog�е���Ϣ����ڻ������У�
//���������������endlʱ����ʾ�����
int main13_1() {
	float a, b, c, disc;
	cout << "Please input a,b,c:";
	cin >> a >> b >> c;
	if (a == 0) {
		cerr << "a is equal to zero,error!" << endl;
	}
	else
		if ((disc = b*b - 4 * a*c) < 0)
			cerr << "disc=b*b-4*a*c<0" << endl;
		else {
			cout << "x1=" << (-b + sqrt(disc)) / (2 * a) << endl;
			cout << "x2=" << (-b - sqrt(disc)) / (2 * a) << endl;
		}

		cout <<endl<< setfill('*') << setw(10) << "xupei" << endl;
	
	return 0; 

}

//��13.2��������ĳ�Ա��������������ݸ�ʽ
int main13_2() {
	int a = 21;
	cout.setf(ios::showbase); //��ʾ��������(0x��0)
	cout << "dec:" << a << endl; //Ĭ����ʮ������ʽ���a
	cout.unsetf(ios::dec);  //��ֹʮ���Ƶĸ�ʽ����
	cout.setf(ios::hex);   //������ʮ�����������״̬
	cout << "hex:" << a << endl; //��ʮ��������ʽ���a
	cout.unsetf(ios::hex); //��ֹʮ�����Ƶĸ�ʽ����
	cout.setf(ios::oct);   //�����԰˽��������״̬
	cout << "oct:" << a << endl; //�԰˽�����ʽ���a
	char *pt = "China"; //ptָ���ַ���"China"
	cout.width(10);    //ָ�����Ϊ10
	cout << pt << endl; //����ַ���
	cout.width(10); //ָ�����Ϊ10
	cout.fill('*'); //ָ���հ״���'*'���
	cout << pt << endl;    //����ַ���
	double pi = 22.0 / 7.0;  //���piֵ
	cout.setf(ios::scientific); //ָ���ÿ�ѧ���������
	cout << "pi=";   //���"pi="
	cout.width(14); //ָ�����Ϊ14
	cout << pi << endl;  //���piֵ
	cout.unsetf(ios::scientific); //��ֹ��ѧ������״̬
	cout.setf(ios::fixed); //ָ���ö�����ʽ���
	cout.width(12); //ָ�����Ϊ12
	cout.setf(ios::showpos); //�������"+"��
	cout.setf(ios::internal); //�������������
	cout.precision(6); //����6λС��
	cout << pi << endl;  //���pi��ע������+��λ��
	return 0;
}

//��13.3 ��һ���ַ�����Ҫ���෴��˳�����
//����Ա���� cout.put('a')
int main13_3() {
	char *p = "BASIC";    //��ĸָ��ָ��'B'
	for (int i = 4; i >= 0; i--)     //�����һ���ַ���ʼ���
		cout.put(*(p + i));
		cout.put('\n');
	
	return 0;
}

//��13.4 ��get���������ַ�
//�޲�����get���� cin.get()
int main13_4() {
	int c;
	cout << "enter a sentence:" << endl;
	while ((c = cin.get()) != EOF)
		cout.put(c);
	return 0;
}

//��13.5 �������һ���ַ��������еķǿո��ַ����
int main13_5() {
	char c;
	while (!cin.eof()) //eof()Ϊ�ٱ�ʾδ�����ļ�������
		if ((c = cin.get()) != ' ') //��������ַ��Ƿ�Ϊ�ո��ַ�
			cout.put(c);
	return 0;
}

//��13.6 peek������putback�������÷�
int main13_6() {
	char c[20];
	int ch;
	cout << "please enter a sentence:" << endl;
	cin.getline(c, 15, '/');
	cout << "The first part is:" << c << endl;
	ch = cin.peek();
	cout << "The next charactor(ASCII code)is:" << ch << endl;
	cin.putback(c[0]);
	cin.getline(c, 15, '/');
	cout << "The second part is:" << c << endl;
	return 0;
}

//��13.8 ��һ���������飬��10��Ԫ�أ��Ӽ�������10�����������飬
//���������͵������ļ��д��
int main13_8() {
	int a[10];
	ofstream outfile("f1.dat", ios::out); //�����ļ������󣬴򿪴����ļ�f1.dat
	if (!outfile) {
		cerr << "open error!" << endl;//�����ʧ�ܣ�outfile����0ֵ
		exit(1);
	}
	cout << "enter 10 interger numbers:" << endl;
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		outfile << a[i] << " "; //������ļ�f1.dat�������
	}
	outfile.close();
	return 0;
}

//��13.9 ����13.8�����������ļ�f1.dat�ж���10���������������У�
//�ҳ������10�����е�����ߺ����������е����
int main13_9() {
	int a[10], max, i, order;
	ifstream infile("f1.dat", ios::in | ios::_Nocreate);
	//���������ļ������������뷽ʽ�򿪴����ļ�f1.dat
	if (!infile) {
		cerr << "open error!" << endl;
		exit(1);
	}
	for (i = 0; i < 10; i++) {
		infile >> a[i];
		cout << a[i] << " ";
	}
	cout << endl;
	max = a[0];
	order = 0;
	for (i = 0; i < 10; i++)
		if (a[i]>max) {
			max = a[i];
			order = i;
		}
	cout << "max=" << max << endl << "order=" << order << endl;
	infile.close();
	return 0;
}

/*
��13.10 �Ӵ��̶���һ���ַ��������е���ĸ�ַ����δ���ڴ����ļ�f2.dat�С�
�ٰ����Ӵ����ļ�������򣬽����е�Сд��ĸ��Ϊ��д��ĸ���ٴ�������ļ�f3.dat
*/

//save_to_file�����Ӽ��̶���һ���ַ��������е���ĸ��������ļ�
void save_to_file() {
	ofstream outfile("f2.dat");
	//��������ļ�������outfile���������ʽ�򿪴����ļ�f2.dat
	if (!outfile) {
		cerr << "open f2.dat error!" << endl;
		exit(1);
	}
	char c[80];
	cin.getline(c, 80); //�Ӽ��̶���һ���ַ�
	for (int i = 0; c[i] != 0;i++)//���ַ��������ֱ��������/0��Ϊֹ
		if (c[i] >= 65 && c[i] <= 90 || c[i] >= 97 && c[i] <= 122) { //�������ĸ�ַ�
			outfile.put(c[i]);//����ĸ�ַ���������ļ�f2.dat
			cout << c[i]; //ͬʱ����ʾ����ʾ
		}
	cout << endl;
	outfile.close();  //�ر�f2.dat
	
}

//�Ӵ����ļ�f2.dat������ĸ�ַ��������е�Сд��ĸ��Ϊ��д��ĸ���ٴ���f3.dat
void get_from_file() {
	char ch;
	ifstream infile("f2.dat",ios::in|ios::_Nocreate);
	//���������ļ���infile,�����뷽ʽ�򿪴����ļ�f2.dat
	if (!infile) {
		cerr << "open f2.dat error!" << endl;
		exit(1);
	}
	ofstream outfile("f3.dat");
	//��������ļ�������outfile���������ʽ�򿪴����ļ�f2.dat
	if (!outfile) {
		cerr << "open f3.dat error!" << endl;
		exit(1);
	}
	while (infile.get(ch)) {
		if (ch >= 97 && ch <= 122) //�ж�ch�Ƿ�ΪСд��ĸ
			ch = ch - 32; //��Сд��ĸ��Ϊ��д��ĸ
		outfile.put(ch); //����д��ĸ��������ļ�f3.dat
		cout << ch; //ͬʱ����ʾ�����
	}
	cout << endl;
	infile.close(); //�رմ����ļ�f2.dat
	outfile.close(); //�رմ����ļ�f3.dat
	
}

//��13.10
int main13_10() {
	save_to_file();
	//����save_to_file(),�Ӽ��̶���һ���ַ��������е���ĸ��������ļ�f2.dat
	get_from_file(); //����get_from_file()����f2.dat������ĸ�ַ�����Ϊ��д��ĸ���ٴ���f3.dat
	
	return 0;
}

//��13.11 ��һ�������Զ�������ʽ����ڴ����ļ���
struct student {
	char name[20];
	int num;
	int age;
	char sex;
};

int main13_11() {
	student stud[] = { "Li",1001,18,'f',"Fang",1002,19,'m',"Wang",1004,17,'f' };
	ofstream outfile("stud.dat", ios::binary);
	if (!outfile) {
		cerr << "open error!" << endl;
		abort(); //�˳�����
	}
	for (int i = 0; i < 3; i++) {
		outfile.write((char *)&stud[i], sizeof(stud[i]));
		cout << stud[i].name <<"  "<< stud[i].num << "  " 
			<< stud[i].age << "  " << stud[i].sex << endl; //������û��д��ȥ����Ϊ�������밡
	}
		
	outfile.close();
	return 0;
}

//��13.12 ��ִ����13.11����ʱ����ڴ����ļ��еĶ�������ʽ�����ݶ����ڴ沢����ʾ������ʾ


int main13_12() {
	student stud[3];
	int i;
	ifstream infile("stud.dat", ios::binary);
	if (!infile) {
		cerr << "open error!" << endl;
		abort(); //�˳�����
	}
	for (i = 0; i < 3; i++){
		infile.read((char *)&stud[i], sizeof(stud[i]));
	
	
		cout << "NO." << i + 1 << endl;
		cout << "name:" << stud[i].name << endl;
		cout << "num:" << stud[i].num << endl;
		cout << "age:" << stud[i].age << endl;
		cout << "sex:" << stud[i].sex << endl;
		cout << endl;
	}
	infile.close();
	return 0;
}

//��13.14 ��һ�����ݱ������ַ�������
struct student1 {
	int num;
	char name[20];
	float score;
};

//��13.14 ��һ�����ݱ������ַ�������
int main13_14() {
	student1 stud[3] = { 1001,"Li",78,1002,"Wang",89.5,1004,"Fang",90 };
	char c[30]; //�û�������ַ�����
	ostrstream strout(c, 30);//��������ַ�������������c������ϵ����������30
	for (int i = 0; i < 3; i++) //���ַ�����cд3��ѧ��������
		strout << stud[i].num  << stud[i].name  << stud[i].score << endl;
	strout << ends; //ends��C++��I/O������������һ��'\0'
	cout << "array c:" <<endl<< c << endl; //��ʾ�ַ�����c�е��ַ�
	return 0;
}

//��13.15 ��һ���ַ�����c�д����10���������Կո�������Ҫ�����Ƿŵ����������У�
//�ٰ���С����Ȼ���ٴ�Ż��ַ�����c�С�
int main13_15() {
	char c[50] = "12 34 65 -23 -32 33 61 99 321 32";
	int a[10], i, j;
	int temp = 0;
	cout << "array c:" << c << endl; //��ʾ�ַ������е��ַ���
	istrstream strin(c, sizeof(c)); //�������봮������strin�����ַ�����c����
	for (i = 0; i < 10; i++) {
		strin >> a[i];
	}
	cout << "array a:";
	for (i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	for (i = 0; i < 9; i++){
		for (j = i+1; j < 10; j++) 
			if (a[i]>a[j]) { //ѡ������
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
	}
	ostrstream strout(c, sizeof(c)); 
	for (i = 0; i < 10; i++)
		strout << a[i] << " ";
	strout << ends;  //����'\0'
	cout << "array c:" << c << endl; //��ʾ�ַ�����c
	return 0;
}









int main() {
	main13_15();
	system("pause");
	return 0;

}