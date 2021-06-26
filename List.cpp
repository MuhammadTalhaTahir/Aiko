#include "List.h"

node::node() {
	next = NULL;
	data = NULL;
}

list::list() {
	first = NULL;
}

void list::insert(object* d)
{
	node* temp = new node;
	temp->data = d;
	if (!first) {
		first = temp;
	}
	else {
		temp->next = first;
		first = temp;
	}
}

void list::remove(object* d)
{
	node* temp = first;
	if (first->data == d)
	{
		first = first->next;
		delete temp;
	}
	else {
		while (temp->next->data != d)
		{
			temp = temp->next;
		}
		node* t = temp->next;
		temp->next = temp->next->next;
		delete t;
	}
}

void list::update() {
	node* temp = first;
	while (temp != NULL) {
		temp->data->update();
		temp = temp->next;
	}
}