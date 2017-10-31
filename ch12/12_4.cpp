#include <iostream>
#include<string>
#include <stdlib.h>
#include<cstring>

using namespace std;

//Point->Circle(�������ݳ�Ա�뾶r��->Cylinder(�������ݳ�Ա��h��
//�����������Shape
class Shape {
public:
	virtual float area() const { return 0.0; } //�麯��
	virtual float volume() const { return 0.0; } //�麯��
	virtual void shapeName() const = 0; //���麯�� ���������麯��ʱ����ʼ��Ϊ0�ĺ�����
	
};




//����Point��
class Point:public Shape{ //Point����Shape��Ĺ���������
public:
	Point(float= 0, float = 0);   //�������캯��
	void setPoint(float, float);     //��������ֵ
	float getX() const { return x; }  //��x���꣬getX����Ϊ����Ա����
	float getY() const { return y; }  //��y���꣬getY����Ϊ����Ա����
	virtual void shapeName() const { cout << "Point:"; } //���麯�������ٶ���
	friend ostream&operator<<(ostream &, const Point &); //��Ԫ���������<<  ��������ǲ�̫�˽�

protected: //�ܱ�����Ա
	float x;
	float y;
};

Point::Point(float a, float b) { //���幹�캯��//��x,y��ʼ��
	x = a;
	y = b;
}

//����x,y������ֵ
void Point::setPoint(float a, float b) { //��x,y������ֵ
	x = a; y = b;
}

//�����������<<"��ʹ֮������������
ostream &operator<<(ostream &output, const Point &p) {
	output << "[" << p.x << "," << p.y << "]" << endl;
	return output;
}




class Circle :public Point { //Circle��Point��Ĺ���������
public:
	Circle(float x = 0, float y = 0, float r = 0);  //���캯��
	void setRadius(float); //���ð뾶ֵ
	float getRadius() const;  //��ȡ�뾶ֵ
	virtual float area() const; //���麯�������ٶ���
	virtual void shapeName() const 
	{ cout<< "Circle:"; }      //���麯�������ٶ���
	friend ostream &operator<<(ostream &, const Circle &);   //���������"<<"

protected:
	float radius;
};

//����Circle���Ա����
Circle::Circle(float a, float b, float r) :Point(a, b), radius(r) {}//���幹�캯��

void Circle::setRadius(float r) { radius = r; }

float Circle::getRadius() const { return radius; }

float Circle::area() const { return 3.14159*radius*radius; }

//���������"<<"��ʹ֮���涨����ʽ���Բ����Ϣ
ostream &operator<<(ostream &output, const Circle &c) {
	output << "Center=[" << c.x << "," << c.y
		<< "],r=" << c.radius  << endl;
	return output;
}


class Cylinder :public Circle {
public:
	Cylinder(float x = 0, float y = 0, float r = 0, float h = 0);  //���캯��
	void setHeight(float); //����Բ����
	
	virtual float area() const; //�����麯��
	virtual float volume() const; //�����麯��
	virtual void shapeName() const {cout<< "Cylinder:"; } //�����麯��
	friend ostream &operator<<(ostream &, const Cylinder &);   //���������"<<"

protected:
	float height; //Բ����
};

//���幹�캯��
Cylinder::Cylinder(float a, float b, float r, float h) :Circle(a, b, r), height(h) {}
//����Բ���ߵĺ���
void Cylinder::setHeight(float h)
{
	height = h;
}


//����Բ�����
float Cylinder::area() const { return 2 * Circle::area() + 2 * 3.14159*radius *height; }

//����Բ�����
float Cylinder::volume() const {
	return Circle::area()*height;
}

//���������"<<"
ostream &operator<<(ostream &output, const Cylinder &cy) {
	output << "Center=[" << cy.x << "," << cy.y
		<< "],r=" << cy.radius << ",h=" << cy.height <<
		"\narea=" << cy.area() << ",volume=" << cy.volume() << endl;
	return output;
}


int main() {
	Point point(3.2, 4.5);
	Circle circle(2.4, 1.2, 5.6);
	Cylinder cylinder(3.5, 6.4, 5.2, 10.5);
	point.shapeName();  //�ö�����������̬����
	cout << point << endl; //����������

	circle.shapeName();  //��̬����
	cout << circle << endl; //���Բ��������

	cylinder.shapeName();
	cout << cylinder << endl << endl;

	Shape *pt;
	pt = &point;
	pt->shapeName();
	cout << "x=" << point.getX() << ",y=" << point.getY() << "\narea=" << pt->area()
		<< "\nvolume=" << pt->volume() << "\n\n";

	pt = &circle;
	pt->shapeName();
	cout << "x=" << circle.getX() << ",y=" << circle.getY() << "\narea=" << pt->area()
		<< "\nvolume=" << pt->volume() << "\n\n";

	pt = &cylinder;
	pt->shapeName();
	cout << "x=" << cylinder.getX() << ",y=" << cylinder.getY() << "\narea=" << pt->area()
		<< "\nvolume=" << pt->volume() << "\n\n";

	

	system("pause");
	return 0;
}






