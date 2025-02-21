#include <stdio.h>
#include "labo.h"

void insert(Node* currNode, void* newData)
{
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

/*
* Creer un noeud et l'ajouter apres le noeud de fin. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/

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
		while (CurrNode->next != head)
		{
			CurrNode = CurrNode->next;
		}
		insert(CurrNode, newNode);
		newNode->next = head;
		head->prev = newNode;
	}
}

void insertHead(Node* head, void* newData)
{

}

Node* removeNode(Node* currNode)
{
	return NULL;
}

void alphabetise(Node* head, char* names[])
{

}