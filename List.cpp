#include "List.h"

node::node() {
	next = NULL;
	data = NULL;
}

list::list() {
	first = NULL;
	objectCount = 0;
}

void list::insert(object* d)
{
	if (first==NULL) {
		first = new node;
		first->data = d;
		objectCount++;
	}
	else {
		node* temp = first;
		while (temp->next!=NULL) {
			temp = temp->next;
		}
		temp->next = new node;
		temp->next->data = d;
		objectCount++;
	}
}

void list::remove(object* d)
{
	node* temp = first;
	if (first->data == d)
	{
		if(first->next!=NULL)first = first->next;
		delete temp;
		objectCount--;
	}
	else {
		while (temp->next->data != d)
		{
			temp = temp->next;
		}
		node* t = temp->next;
		if(temp->next->next!=NULL)temp->next = temp->next->next;
		delete t;
		objectCount--;
	}
}
int list::getObjectCount()const {
	return objectCount;
}

void list::update() {
	node* temp = first;
	while (temp != NULL) {
		temp->data->update();
		temp = temp->next;
	}
}