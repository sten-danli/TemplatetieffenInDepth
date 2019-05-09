//ʹ��tampelate���ջ��filo����
#include<iostream>
using namespace std;

template<typename Type>
class Stack
{
public:

	Stack(unsigned int size = 100);//Ĭ�Ϲ����ջ��Ĭ�ϴ�С��100
	~Stack();
	void Push(Type value);
	Type pop();

private:
	unsigned int size;	//ջ�Ĵ�С
	unsigned int sp;	//ջ�ڵ�ָ��
	Type* data;			//���ջ������
};
//Stack����
template<typename Type>
Stack<Type>::Stack(unsigned int size) 
{
	this->size = size;	//ջ���ܴ�С
	data = new Type[size]; //(Stack<Type>*)malloc(sizeof(Stack<Type>));//;Ҫ��ŵ�ջ���ݵĴ�С��c++�µ�д�� new Type[size];
	sp = 0;				//վ�ڵ�ָ��ָ��
}
//��������
template<typename Type>
Stack<Type>::~Stack()
{
	free(data);
}

//push����ʵ��
template<typename Type>
void Stack<Type>::Push(Type value)
{
	data[sp++] = value;
}

//pop����ʵ��
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

	Stack<int> charStack(100);

	charStack.Push(1);
	charStack.Push(2);
	charStack.Push(3);

	cout << charStack.pop() << endl;
	cout << charStack.pop() << endl;
	cout << charStack.pop() << endl;

	return 0;
	

}
