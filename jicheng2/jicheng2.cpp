#include<iostream>
using namespace std;

class Base1
{
public:
	Base1(int x):m_x(x)//也可以用缺省值Base1(int x=0):m_x(x)
	{
		cout << "Create Base1" << endl;
	}
	~Base1()
	{
		cout<<"Free Base1" << endl;
	}
private: int m_x;
};
class Base2
{
private:
	int m_y;
public:
	Base2(int y):m_y(y)
	{
		cout << "Create Base2" << endl;
	}
	~Base2()
	{
		cout << "Free Base2" << endl;
	}
};

class Base3
{
private:
	int m_z;
public:
	Base3(int z):m_z(z)
	{
		cout << "Create  Base3" << endl;
	}
	~Base3()
	{
		cout << "Free Basde3" << endl;
	}

};

//Class D 派生类(Vererbung)
class D :public Base1, public Base2, public Base3
{
public://当用父类参数列表值给出时像这样：Base1(int x=0):m_x(x)，那么派生类D(int data)后面的的初始化就可以省略：
	//D(int data):Base1(data),Base2(data),Base3(data),b1(data),b2(data),b3(data)
	D(int data):Base1(data),Base2(data),Base3(data),b1(data),b2(data),b3(data)
	{
		cout << "Create D" << endl;
	}
	~D()
	{
		cout << "Free D" << endl;
	}
private:
	Base1 b1;
	Base2 b2;
	Base3 b3;
};
int main()
{
	D d(10);


}