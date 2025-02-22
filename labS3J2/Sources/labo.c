#include <stdio.h>
#include "labo.h"

void insert(Node* currNode, void* newData) {
	//Je sais pas pourquoi ca marche pas
	if (currNode == NULL) {
		return;
	}

	Node* n = allocate(sizeof(Node));
	n->data = newData;
	n->prev = NULL;
	n->next = NULL;

	if (currNode->next != NULL) {
		n->next = currNode->next;
		currNode->next->prev = n;
	}
	currNode->next = n;
	n->prev = currNode;
}

void insertTail(Node* head, void* newData)
{
	Node* CurrNode;
	if (head->data == NULL) {
		head->data = newData;
		head->next = head;
		head->prev = head;
	}
	else {
		Node* newNode = allocate(sizeof(Node));
		newNode->data = newData;
		CurrNode = head;
		while (CurrNode->next != NULL)
		{
			CurrNode = CurrNode->next;
		}
		insert(CurrNode, newData);
	}
}

void insertHead(Node* head, void* newData)
{
	if (head->data == NULL) {
		head->data = newData;
		head->next = head;
		head->prev = head;
	}
	else {
		Node* newNode = allocate(sizeof(Node));
		newNode->data = newData;

		newNode->next = head;
		head->prev = newNode;


	}
}

Node* removeNode(Node* currNode)
{
	if (currNode == NULL) return NULL;
	currNode->prev->next = currNode->next;
	currNode->next->prev = currNode->prev;
	currNode->prev = NULL;
	currNode->next = NULL;

	return currNode;
}

void alphabetise(Node* head, char* names[])
{
	// je suis censé sort le data des nodes ou sort le tableau de strings?
}