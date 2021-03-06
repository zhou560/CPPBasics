// LinkedList.cpp
//	

#include "stdafx.h"
#include <stdlib.h>
#include <malloc.h>

struct SNode {
	int data;
	SNode* next;
};

class SingleLL {
	/*Singly linked list class. Stores a single head pointer. Insertions and deletions
	can only be made at the head; thus, only push and pop operations are possible.
	Includes a print function to traverse and print the linked list.*/

private:
	SNode* head;

public:

	//Construct SingleLL object by initializing head to NULL
	SingleLL() {
		head = NULL;
	}

	//Delete SingleLL object and all of its nodes.
	~SingleLL() {
		while (head != NULL)
			pop();
	}

	//Print all nodes of the linked list.
	void printList() {
		if (head == NULL) {
			printf("Empty list.\n");
			return;
		}
		for (SNode* n = head; n != NULL; n = n->next) {
				printf("%d, ", n->data);
		}
	}

	//Insert a node at the beginning of the linked list
	void push(int data) {
		SNode* newNode = (SNode *)malloc(sizeof(SNode));
		newNode->data = data;
		newNode->next = head;
		head = newNode;
	}

	//Remove and return a node at the beginning of the linked list
	int pop() {
		int toReturn = head->data;
		SNode* toDelete = head;
		head = head->next;
		//Since these nodes were created using malloc, they must be freed
		free(toDelete);
		return toReturn;
	}
};


int main(){

	//Create a single linked list.
	SingleLL * single = new SingleLL;
	//Note: use a->b when a is a pointer to a heap object.
	//Use a.b when a is a temporary stack object.
	//b can be a (public) variable or method
	for (int i = 0; i < 10; i++) {
		single->push(rand() % 100);
	}

	printf("pop: %d\n", single->pop());

	single->printList();

	delete single;
    return 0;
}

