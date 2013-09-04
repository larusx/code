#ifndef MYSTACK_H
#define MYSTACK_H
typedef struct mystack{
	int data;
	struct mystack* next;
}mystack;

class Stack{
public:
	Stack();
	~Stack();
	void PushStack(int data);
	int PopStack();
	int GetSum();
	int GetNum();
	void PrintStack();
private:
	mystack* head;
	int sum;
	int num;
};
#endif
