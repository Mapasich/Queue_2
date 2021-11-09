#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
struct queue
{
	int data;
	queue* next;
}
*head, * tail;
//указатели на начало и конец очереди

bool Empty(queue* head)
{
	return (head == NULL) ? true : false;
}
void Enqueue(int data)
{
	queue* temp = new queue;
	temp->data = data;
	temp->next = NULL;
	if (Empty(head))
		head = tail = temp;
	else {
		tail->next = temp;
		tail = temp;
	}
}
void Create()
{
	int element;
	queue* q = NULL;
	cout << "Enter element" << endl;
	cin >> element;
	Enqueue(element);
	cout << "Element \n\n " << element << " is add to queuee " << endl;
};
void Dequeue()
{
	if (head == NULL)
	{
		cout << "Queue empty " << endl;
	}
	else
	{
		queue* q;
		int t;
		q = head;
		head = head->next;
		t = q->data;
		delete q;
	}
};

void Show()
{
	queue* Head = NULL;
	queue* tempQueue = new queue;
	queue* tempHead = NULL;
	Head = head;
	if (Empty(head))
	{
		cout << "Queue empty" << endl;
		return;
	}
	tempQueue->data = NULL;
	tempQueue->next = NULL;
	tempHead = tempQueue;
	while (head != NULL)
	{
		cout << "Element " << head->data << endl;
		tempQueue->next = new queue;
		tempQueue->next->data = head->data;
		tempQueue->next->next = NULL;
		tempQueue = tempQueue->next;
		Dequeue();
	}
	tempQueue = tempHead->next;
	while (tempQueue)
	{
		Enqueue(tempQueue->data);
		tempQueue = tempQueue->next;
	}
	Head = tempHead->next;
	while (Head)
	{
		tempQueue = Head;
		Head = Head->next;
		delete tempQueue;
	}
}
int main()
{
	char a;
	bool command = true;
	while (command)
	{
		cout << "Choose the number of command" << endl;
		cout << "1 - Add" << endl;
		cout << "2 - Delete" << endl;
		cout << "3 - Print" << endl;
		cout << "0 - Exit" << endl;
		a = _getch();
		switch (a)
		{
		case '0':
			command = false;
			break;
		case '1':
			Create();
			break;
		case '2':
			Dequeue();
			break;
		case '3':
			Show();
			break;
		default:
			cout << "try";
		}
	};
};