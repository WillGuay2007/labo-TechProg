#include <stdio.h>
#include "labo.h"

void insert(Node* currNode, void* newData)
{
	Node* n = allocate(sizeof(Node));
	n->data = newData;
	n->next = NULL;

	if (currNode->next != NULL) {
		n->next = currNode->next;
	}
	currNode->next = n;

}

void insertHead(Node* head, void* newData)
{
	if (head->data == NULL) {
		head->data = newData;
	}
	else {
		insert(head, newData);
	}
}

Node* removeByData(Node* head, void* rmData)
{
	Node* CurrNode = head;
	Node* PreviousNode = NULL;
	while (CurrNode != NULL)
	{
		if (CurrNode->data == rmData) {

			if (PreviousNode != NULL) {
				PreviousNode->next = CurrNode->next;
				memset(CurrNode, 0, sizeof(CurrNode));
				return PreviousNode;
			}
			else {
				head = CurrNode->next;
				return NULL;
			}

		}
		PreviousNode = CurrNode;
		CurrNode = CurrNode->next;
	}
}

Node* removeByName(Node* head, char* name)
{
	Node* CurrNode = head;
	Node* PreviousNode = NULL;
	while (CurrNode != NULL)
	{
		Person* person = (Person*)CurrNode->data;
		if (strcmp(person->name, name) == 0) {
			if (PreviousNode != NULL) {
				PreviousNode->next = CurrNode->next;
				memset(CurrNode, 0, sizeof(CurrNode));
				return PreviousNode;
			}
			else {
				head = CurrNode->next;
				return NULL;
			}

		}
		PreviousNode = CurrNode;
		CurrNode = CurrNode->next;
	}

	return NULL;
}

void sort(Node* head)
{
	if (head == NULL) return;

	int Swapped = 1;
	Node* ptr1;
	Node* lptr = NULL;

	while (Swapped) {
		Swapped = 0;
		ptr1 = head;

		while (ptr1->next != lptr) {
			Person* p1 = (Person*)ptr1->data;
			Person* p2 = (Person*)ptr1->next->data;

			if (p1->age > p2->age) {
				Person* temp = ptr1->data;
				ptr1->data = ptr1->next->data;
				ptr1->next->data = temp;

				Swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}
