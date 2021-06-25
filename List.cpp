#include "List.h"

node::node() {
	next = NULL;
	data = NULL;
}

list::list() {
	first = NULL;
}

void list::update() {
	node* temp = first;
	while (temp != NULL) {
		temp->data->update();
		temp = temp->next;
	}
}