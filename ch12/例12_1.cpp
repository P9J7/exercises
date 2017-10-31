#include<iostream>
#include<string>

using namespace std;
   
//Point->Circle(�������ݳ�Ա�뾶r��->Cylinder(�������ݳ�Ա��h��

//��������Point��
class Point {
public:
	Point(float x = 0, float y = 0);   //��Ĭ�ϲ����Ĺ��캯��
	void setPoint(float, float);     //��������ֵ
	float getX() const { return x; }  //��x���꣬getX����Ϊ����Ա����
	float getY() const { return y; }  //��y���꣬getY����Ϊ����Ա����
	friend ostream&operator<<(ostream &, const Point &); //��Ԫ���������<<  ��������ǲ�̫�˽�
	 
protected: //�ܱ�����Ա
	float x;
	float y;
};

Point::Point(float a, float b) { //��x,y��ʼ��
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

/*
  //����point
int main() { 
	Point p(3.5, 6.4);
	cout << "x=" << p.getX() << ",y=" << p.getY() << endl; //���p������ֵx,y
	p.setPoint(8.5, 6.8);
	cout << "p(new):" << p << endl;

	system("pause");
	return 0;
}
*/

class Circle:public Point { //Circle��Point��Ĺ���������
public:
	Circle(float x = 0, float y = 0, float r = 0);  //���캯��
	void setRaius(float); //���ð뾶ֵ
	float getRadius() const;  //��ȡ�뾶ֵ
	float area() const; //����Բ���
	friend ostream &operator<<(ostream &, const Circle &);   //���������"<<"

protected:
	float radius;
};

//���幹�캯������Բ������Ͱ뾶��ʼ��
Circle::Circle(float a,float b,float r):Point(a,b),radius(r){}
//���ð뾶ֵ
void Circle::setRaius(float r) 
{ radius = r; }
//��ȡ�뾶ֵ
float Circle::getRadius() const { return radius; }

//����Բ���
float Circle::area() const { return 3.14159*radius*radius; }

//���������"<<"��ʹ֮���涨����ʽ���Բ����Ϣ
ostream &operator<<(ostream &output, const Circle &c) {
	output << "Center=[" << c.x << "," << c.y 
		<< "],r=" << c.radius << ",area=" << c.area() << endl;
	return output;
}

/*
//����Circle
int main() { 
	Circle c(3.5, 6.4, 5.2);
	cout << "original circle:\nx=" << c.getX() << ",y=" << c.getY() << ",r=" << c.getRadius()
		<< ",area=" << c.area() << endl; //���Բ�����꣬�뾶�����
	c.setRaius(7.5);  //���ð뾶ֵ
	c.setPoint(5, 5); //����Բ������x,y

	
	cout << "new circle:\n" << c << endl; //�����������"<<"���Բ�������Ϣ

	Point &pRef = c; //pRef��Point������ã���c��ʼ��
	cout << "pRef:" << pRef; //���pRef����Ϣ


	system("pause");
	return 0;
}
*/


class Cylinder :public Circle {
public:
	Cylinder(float x = 0, float y = 0, float r = 0,float h=0);  //���캯��
	void setHeight(float); //����Բ����
	float getHeight() const;  //��ȡԲ����
	float area() const; //����Բ�����
	float volume() const; //����Բ�����
	friend ostream &operator<<(ostream &, const Cylinder &);   //���������"<<"

protected:
	float height; //Բ����
};

//���幹�캯��
Cylinder::Cylinder(float a, float b, float r, float h) :Circle(a, b,r),height(h) {}
//����Բ���ߵĺ���
void Cylinder::setHeight(float h)
{
	height = h;
}
//��ȡԲ���ߵĺ���
float Cylinder::getHeight() const { return height; }

//����Բ�����
float Cylinder::area() const { return 2 * Circle::area() + 2 * 3.14159*radius *height; }

//����Բ�����
float Cylinder::volume() const {
	return Circle::area()*height;
}

//���������"<<"
ostream &operator<<(ostream &output, const Cylinder &cy) {
	output << "Center=[" << cy.x << "," << cy.y
		<< "],r=" << cy.radius <<",h="<<cy.height<<
		"\narea=" << cy.area() << ",volume=" << cy.volume()<<endl;
	return output;
}

//����Cylinder
int main() {
	Cylinder cy1(3.5, 6.4, 5.2, 10);
	cout << "original Cylinder:\nx=" << cy1.getX() << ",y=" << cy1.getY() << ",r=" << cy1.getRadius()
		<<",h="<<cy1.getHeight()<< "\narea=" << cy1.area() 
		<< ",volume=" << cy1.volume() << endl; //���Բ��cy1������
	cy1.setHeight(15);  //����Բ����
	cy1.setRaius(7.5);  //����Բ�뾶ֵ
	cy1.setPoint(5, 5); //����Բ������x,y


	cout << "new cylinder:\n" << cy1 << endl; //�����������"<<"���Բ�������Ϣ

	Point &pRef = cy1; //pRef��Point������ã���c��ʼ��
	cout << "pRef as a point:" << pRef; //���pRef����Ϣ

	Circle &cRef = cy1; //cRef��Circle�������
	cout << "cRef as a circle:" << cRef; //���cRef����Ϣ,��Ϊһ��Բ���

	system("pause");
	return 0;
}






