#include <cstring>
#include<iostream>
using namespace std;

class String
{
public:
	String(const char* str = "") 
	{
		if (str == NULL)
		{
			data = new char[1];
			data[0] = '\0';
		}
		else
		{
			data = new char[strlen(str) + 1];
			strcpy(data, str);
		}
	}
	~String()
	{
		delete[]data;
		data = NULL;
	}

public:
	char* data;
};
void Show(String& s) { cout << s.data; }
int main()
{
	String* ps = new String ("Hallo");
	delete ps;

	
}