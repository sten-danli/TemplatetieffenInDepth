#include<iostream>
using namespace std;

class Base
{
public:
	Base():x(0){}
	~Base(){}
public:
	void SetBaseX(int data)
	{
		x = data;
	}
public:
	void Show_Base()
	{
		cout << "Show_Base = " << x << endl;
	}
protected:
//public:
	void Print_Base()
	{
		cout << "Print_Base = " << x << endl;
	}

private:
	int x;
};

class D:private Base
{

public:
	void setData(int data)
	{
		y = data;
		SetBaseX(data);
	}
public:
	void Show_D()
	{
		cout << "Show D = " << y << endl;
		SetBaseX(99);
		Show_Base();
		Print_Base();//在子类里面可以访问父类中的protected的成员函数；
		
	}
public:
	void ShowBasePrint()
	{
		Print_Base();//在子类里面可以访问父类中的protected的成员函数；
	}
public:
	void Print_D()
	{
		cout << "Print D= " << y << endl;
	}
public:
	D() :y(0) {}
	~D() {}
private: int y;
	
};
int main()
{
	D d;
	d.Show_D();

	
	

}