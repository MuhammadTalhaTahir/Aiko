#include "List.h"

Node::Node() {
	next = NULL;
	data = NULL;
}

list::list(){
	first = NULL;
	objectCount = 0;
}

void list::insert(object* d){
	if (first==NULL) {
		first = new Node;
		first->data = d;
		objectCount++;
	}
	else {
		Node* temp = first;
		while (temp->next!=NULL) {
			temp = temp->next;
		}
		temp->next = new Node;
		temp->next->data = d;
		objectCount++;
	}
}

void list::remove(object* d){
	Node* temp = first;
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
		Node* t = temp->next;
		if(temp->next->next!=NULL)temp->next = temp->next->next;
		delete t;
		objectCount--;
	}
}

int list::getObjectCount()const {
	return objectCount;
}

void list::updateObjects() {
	Node* temp = first;
	while (temp != NULL) {
		temp->data->update();
		temp=temp->next;
	}
}
