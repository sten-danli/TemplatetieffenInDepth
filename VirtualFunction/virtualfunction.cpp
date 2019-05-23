#include<iostream>
using namespace std;

class Base
{
public :
	virtual void show()
	{
		cout << "This is Base show()" << endl;
	}
};

class D : public Base
{
public:
	void show()
	{
		cout << "This is D show()" << endl;
	}
	void show(int)
	{
		cout << "This is D show(int)" << endl;
	}
	void print()
	{
		cout << "This is D print()" << endl;
	}
};

class C : public D
{
public:
	void show()
	{
		cout << "This is C show()" << endl;
	}
	void show(int)
	{
		cout << "This is C show(int)" << endl;
	}
};

int main()
{
	C c;
	D* pd = &c;
	pd->show(0);
}