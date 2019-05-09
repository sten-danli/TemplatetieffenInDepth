//使用tampelate完成栈的filo方法
#include<iostream>
using namespace std;

template<typename Type>
class Stack
{
public:

	Stack(unsigned int size = 100);//默认构造的栈的默认大小是100
	~Stack();
	void Push(Type value);
	Type pop();

private:
	unsigned int size;	//栈的大小
	unsigned int sp;	//栈内的指针
	Type* data;			//存放栈的数据
};

//Stack构造
template<typename Type>
Stack<Type>::Stack(unsigned int size) 
{
	this->size = size;		//栈的总大小
	data = new Type[size];	//(Stack<Type>*)malloc(sizeof(Stack<Type>));//;要存放到栈数据的大小，c++新的写法 new Type[size];
	sp = 0;					//站内的指针指向
}
//析构函数
template<typename Type>
Stack<Type>::~Stack()
{
	free(data);				//c++ 写法delet []data;
}

//push方法实现
template<typename Type>
void Stack<Type>::Push(Type value)
{
	data[sp++] = value;
}

//pop方法实现
template<typename Type>
Type Stack<Type>::pop()
{
	return data[--sp];
}

int main()
{/*
	Stack<char> charStack(100);

	charStack.Push('A');
	charStack.Push('B');
	charStack.Push('C');
	*/

	Stack<int> intStack(100);

	intStack.Push(1);
	intStack.Push(2);
	intStack.Push(3);

	cout << intStack.pop() << endl;
	cout << intStack.pop() << endl;
	cout << intStack.pop() << endl;

	return 0;
	

}
