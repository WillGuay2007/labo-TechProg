#include <stdio.h>
#include "labo.h"

Stack* new_stack(size_t max_size) {
	Stack* newStack = allocate(sizeof(Stack));
	newStack->max_size = max_size;
	newStack->top = -1;
	newStack->data = (void**)allocate(sizeof(void*) * max_size);
	return newStack;
}

/*
* Ajouter l'element sur la stack. Prevener "l'overflow" de la stack.
*/
void push(Stack* s, void* newData) {
	if (s->top + 1 < s->max_size) {
		s->top += 1;
		s->data[s->top] = newData;
	}
	else {
		printf("Stack overflow\n");
	}
}

/*
* Enlever l'element de la stack et retourner l'information. Si jamais il n'y a pas d'element, retourner NULL.
*/
void* pop(Stack* s) {
	if (s->top <= -1) {
		return NULL;
	}
	else {
		return s->data[(s->top)--];
	}

}

/*
* Retourner l'element du top sans l'enlever de la stack. Si jamais il n'y a pas d'element, retourner NULL.
*/
void* peek(Stack* s) {
	if (s->top >= 0) {
		return s->data[s->top];
	}
	return NULL;
}

/*
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.Vous ne devez pas utilise la variable temp qui est une autre Stack.
*/
void reverseStack(Stack* s) {
	if (s->top <= -1) return;

	int start = 0;
	int end = s->top;
	while (start < end){
		Person* temp = s->data[start];
		s->data[start] = s->data[end];
		s->data[end] = temp;
		start++;
		end--;
	}
}

/*
* Triee la stack.La personne sur le haut/top est la plus jeune. Vous ne pouvez pas modifier la propriete data directement. Vous devez utiliser push,pop et/ou peek.
*/
void sortStack(Stack* s) {
	Stack* tempStack = new_stack(s->max_size);

	Person* Person1 = NULL;
	Person* Person2 = NULL;

	while (s->top > 0)
	{
		Person* Person1 = (Person*)pop(s); // Personne du top
		Person* Person2 = (Person*)pop(s); // Personne avant le top
		if (Person1->age < Person2->age) {
			push(tempStack, Person1);
			push(s, Person2);
		}
		else {
			push(tempStack, Person2);
			push(s, Person1);
		}
	}

	while (tempStack->top != -1)
	{
		if (tempStack->top == 0) {
			push(s, pop(tempStack));
			return;
		}
		Person1 = (Person*)pop(tempStack);
		Person2 = (Person*)pop(tempStack);
		if (Person1->age > Person2->age) {
			push(s, Person1);
			push(tempStack, Person2);
		}
		else {
			push(s, Person2);
			push(tempStack, Person1);
		}
	}
}