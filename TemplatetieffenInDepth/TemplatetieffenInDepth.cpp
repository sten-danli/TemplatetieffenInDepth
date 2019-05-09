//��tamplate�������
#include<iostream>
using namespace std;

template<typename Type>
class List;

template<typename Type>
class ListNode//�ڵ���
{
	friend class List<Type>;
public:
	ListNode() :data(Type()), next(NULL) {}										//Ĭ�Ϲ��캯��
	ListNode(Type data, ListNode<Type>* next = NULL) :data(data), next(next) {}	//�в������캯��
	~ListNode() {}	//��������
private:
	Type data;
	ListNode<Type>* next;
};


template<typename Type>//�ڶ������ʱ��Ҫ��������ģ����������Ϊ��ģ������fist��last�������κ��������͡�
class List
{
public:
	List();//���캯�������ⶨ�壨�·�����
public:
	bool push_back(Type x);
public:
	void Show_List()const;

private:
	ListNode<Type>* first;
	ListNode<Type>* last;
	size_t size;
};

//List�Ĺ��캯��
template<typename Type>//ע������ҲҪ��������ģ�����͵ģ�
List<Type>::List()
{
	first = last = (ListNode<Type>*)malloc(sizeof(ListNode<Type>));
	last->next = NULL;
	size = 0;
}

//push_back�ĺ���ʵ��
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

//Show_List�ĺ���ʵ��
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
	//Ҳ������List<double> youlist;//��Ϊ��������ģ�������������������κ��������͡�
	//Ҳ������List<char> youlist;//��Ϊ��������ģ�������������������κ��������͡�
	
	for (int i = 1; i <= 10; ++i)
	{
		mylist.push_back(i);
	}
	
	mylist.Show_List();
}