#include "labo.h"
#include <stdio.h>
#include <string.h>

char* sousTexte(char* texte, int from, int to)
{
	static char sousTab[256];
	for (int i = 0; i < (to - from); i++) {
		sousTab[i] = texte[from + i];
	}
	return sousTab;
}

void set_String(char* text, String* s)
{
	strcpy(s->characters, text);
	s->length = strlen(text);
}

int String_is_palindrome(String* s)
{
	for (int i = 0; i < s->length; i++) {
			if (s->characters[i] == s->characters[s->length - i - 1]) {
			}
			else {
				return 0;
			}
	}
	return 1;
}

void bubbleSort(int elements[], int n)
{
	int tempSwap;
	while (n > 1) {
		for (int i = 0; i < n; i++) {
			if (i + 1 <= n - 1) {
				if (elements[i] > elements[i + 1]) {
					tempSwap = elements[i];
					elements[i] = elements[i + 1];
					elements[i + 1] = tempSwap;
				}
			}
		}
		n--;
	}
}
