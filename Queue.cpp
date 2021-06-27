#include "Queue.h"

template <typename T>
Queue<T>::Queue() 
{
	head = NULL;
}
template <typename T>
void Queue<T>::enQueue(T data)
{
	Node<T>* node = new Node<T>(data);
	if (isEmpty())
	{
		head = node;
	}
	else {
		Node<T>* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = node;
	}
}

template <typename T>
T Queue<T>::deQueue()
{
	if (!isEmpty())
	{
		T data = head->getdata();
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		return data;
	}
}
template <typename T>
bool Queue<T>::isEmpty() 
{
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}
template <typename T>
Queue<T>::~Queue() 
{
	Node<T>* temp = head;
	if (temp != NULL)
	{
		do {
			head = temp->next;
			delete temp;
			temp = head;
		} while (temp != NULL);
	}
}