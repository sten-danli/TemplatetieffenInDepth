//用tamplate完成链表
#include<iostream>
using namespace std;

template<typename Type>
class List;

template<typename Type>
class ListNode//节点类
{
	friend class List<Type>;
public:
	ListNode() :data(Type()), next(NULL) {}										//默认构造函数
	ListNode(Type data, ListNode<Type>* next = NULL) :data(data), next(next) {}	//有参数构造函数
	~ListNode() {}	//析构函数
private:
	Type data;
	ListNode<Type>* next;
};


template<typename Type>//在定义类的时候要先在这里模板声明，因为是模板所以fist和last可以是任何数据类型。
class List
{
public:
	List();//构造函数在类外定义（下方）；
public:
	bool push_back(Type x);
public:
	void Show_List()const;

private:
	ListNode<Type>* first;
	ListNode<Type>* last;
	size_t size;
};

//List的构造函数
template<typename Type>//注意这里也要声明他是模板类型的；
List<Type>::List()
{
	first = last = (ListNode<Type>*)malloc(sizeof(ListNode<Type>));
	last->next = NULL;
	size = 0;
}

//push_back的函数实现
template<typename Type>
bool List<Type>::push_back(Type x)
{
	ListNode<Type>* s = (ListNode<Type>*)malloc(sizeof(ListNode<Type>));
	if (s == NULL)
		return false;
	s->data = x;
	s->next = NULL;

	last->next = s;
	last = s;
	return true;
}

//Show_List的函数实现
template<typename Type>
void List<Type>::Show_List()const
{
	ListNode<Type>* p = first->next;
	while (p)
	{
		cout << p->data << "-->";
		p = p->next;
	}
	cout << "Nul." << endl;
}


int main()
{
	List<int> mylist;
	//也可以是List<double> youlist;//因为上面用了模板语句所以这里可以是任何数据类型。
	//也可以是List<char> youlist;//因为上面用了模板语句所以这里可以是任何数据类型。
	
	for (int i = 1; i <= 10; ++i)
	{
		mylist.push_back(i);
	}
	
	mylist.Show_List();
}