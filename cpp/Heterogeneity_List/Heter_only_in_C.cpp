#include <iostream>
#include <string>

using namespace std;

#ifndef   _LIST_H_
#define   _LIST_H_

// https://www.ibm.com/developerworks/cn/linux/kernel/l-chain/
// http://www.cnblogs.com/skywang12345/p/3562146.html
/*
���ȶ���һ��ָ��ָ�����ָ�룬Ȼ��ͨ�����������ı������������ṹ��ƫ��ַ��
Ȼ�����ָ��ƫ�ƻ��������յ�ַ����ת��Ϊ���������͵�ָ�룬�����������ָ����ָ�뵽������ָ���ת��.
*/

struct list_head
{
	struct list_head *next, *prev;
};

// head �ڵ��Լ�ָ���Լ�,���洢����
#define INIT_LIST_HEAD(ptr) do { \
        (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while(0)

#define list_empty(ptr)	((ptr)->next ==(ptr))? 1:0
#define list_entry(ptr, type, member) \
        ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member))) 

/*
* Insert a new entry between two known consecutive entries.
*
* This is only for internal list manipulation where we know
* the prev/next entries already!
*/
static inline void __list_add(struct list_head *new_node, struct list_head *prev,
	struct list_head *next)
{
	next->prev = new_node;
	new_node->next = next;
	new_node->prev = prev;
	prev->next = new_node;
}

static inline void list_add_tail(struct list_head *add, struct list_head *head)
{
	__list_add(add, head->prev, head);
}

// list_for_each(pos, head)ͨ�����ڻ�ȡ�ڵ㣬�������õ�ɾ���ڵ�ĳ�����
#define list_for_each(pos, head)  for (pos = (head)->next; pos != (head); pos = pos->next) 

//list_for_each_safe(pos, n, head)ͨ��ɾ���ڵ�ĳ���
#define list_for_each_safe(pos, n, head) \
    for (pos = (head)->next, n = pos->next; pos != (head); \
        pos = n, n = pos->next)

/**
* list_add - add a new entry
* @new: new entry to be added
* @head: list head to add it after
*
* Insert a new entry after the specified head.
* This is good for implementing stacks.
*/
static inline void list_add(struct list_head *new_node, struct list_head *head)
{
	__list_add(new_node, head, head->next);
}

/*
* Delete a list entry by making the prev/next entries
* point to each other.
*
* This is only for internal list manipulation where we know
* the prev/next entries already!
*/
static inline void __list_del(struct list_head * prev, struct list_head * next)
{
	next->prev = prev;
	prev->next = next;
}

/**
* list_del - deletes entry from list.
* @entry: the element to delete from the list.
* Note: list_empty on entry does not return true after this, the entry is
* in an undefined state.
*/
static inline void list_del(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
}


#endif

enum class Type { Type_A=0, Type_B=1};

// class A,B ��һ��ԱΪ������Ϣ���ڶ����ڵ�Ϊ����ڵ�
typedef struct A {
	const Type type_ = Type::Type_A;
	struct list_head list_;
	string name_;
	A(const string& name) : name_(name) { }
	void display() {
		cout << "I am class A, my name is: " << name_ << "\n";
	}
}A_;

typedef struct B {
	const Type type_ = Type::Type_B;
	struct list_head list_;
	int id_;
	B(const int& id):id_(id) {}
	void display() {
		cout << "I am class B, my ID is: " << id_ << "\n";
	}
}B_;


void play(list_head* head) {
	list_head *pos;
	list_for_each(pos, head)
	{
		A_ *p = list_entry(pos, A_, list_);

		switch (p->type_)
		{
		case Type::Type_A:
			// real type is A
			p->display();
			break;
		case Type::Type_B:
			// real type is B
			B_ *pp = list_entry(pos, B_, list_);
			pp->display();
			break;
		}
	}
}

int main()
{
	list_head head;
	A_ a_head("class A1");
	B_ b_mid(1);
	A_ a_tail("class A2");
	// ��ʼ��˫����ı�ͷ 
	INIT_LIST_HEAD(&head);
	// ��ӽڵ�
	list_add_tail(&a_head.list_, &head);
	list_add_tail(&b_mid.list_, &head);
	list_add_tail(&a_tail.list_, &head);
	// ��������
	list_head *pos,*next;
	cout << "-----------iterator------------\n";
	play(&head);

	cout << "\n--------- delete node B which id is 1 ----------\n";
	list_for_each_safe(pos, next, &head)
	{
		B_ *pp = list_entry(pos, B_, list_);
		if (pp->type_ == Type::Type_B && pp->id_ == 1)
		{
			list_del(pos);
			//free class
		}
	}
	cout << "\n------------iterator------------\n";
	play(&head);

	getchar();
	return 0;
}