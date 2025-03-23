#include "labo.h"
#include <stdio.h>

#define MAX_N 100
long long memo[MAX_N] = { 0 };

/*
* Programmer l'algorithme de fibonacci. Commencer par faire l'algorithme de base et par la suite ajouter la memoization.
* Faire attention lorsque vous utilisez un type pour une variable qui represente un nombre, int ne depasse pas 2^31-1 ou 2,147,483,647
*/

long long fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	if (memo[n] != 0) return memo[n];

	memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return memo[n];
}

/*
* Creer un Noeud, assigner lui la valeur de data, metter c'est reference a NULL et retourner le noeud.
*/
TreeNode* tree_create_node(void* data) {
	TreeNode* NewTreeNode = (TreeNode*)allocate(sizeof(TreeNode));
	NewTreeNode->data = data;
	NewTreeNode->right = NULL;
	NewTreeNode->left = NULL;
	return NewTreeNode;
}

/*
* Ajouter le noeud  node dans la propriete left ou right qui est NULL de root. On priorise de gauche a droite. Si right et left son NULL on le met dans left.
* Si jamais aucun des noeuds est NULL, ajouter rien.
*/
void tree_add_node(TreeNode* root, TreeNode* node) {

	if (root == NULL || node == NULL) {
		printf("Erreur: root ou node est NULL.\n");
		return;
	}

	if (root->left == NULL) {
		root->left = node;
		printf("Ajoute a gauche.\n");
	}
	else if (root->right == NULL) {
		root->right = node;
		printf("Ajoute a droite.\n");
	}
	else {
		printf("La root est deja pleine.\n");
	}
}

/*
* Programmer l'algorithme de depth first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une pile/stack, ca definition est fourni.
*/
int dfs(TreeNode* root, void* key) {
	Stack DFS_Stack = stack_init(1028);
	stack_push(&DFS_Stack, root);

	int VisitedNodes = 0;

	while (DFS_Stack.top > -1) {
		TreeNode* current = (TreeNode*)stack_pop(&DFS_Stack);
		VisitedNodes++;
		printf("Key de la node visitee: %s\n", (char*)current->data);
		if (current != NULL && current->data == key) {
			return VisitedNodes;
		}

		if (current->right != NULL) {
			stack_push(&DFS_Stack, current->right);
		}
		if (current->left != NULL) {
			stack_push(&DFS_Stack, current->left);
		}
	}

	return 0;

}

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
*/
int bfs(TreeNode* root, void* key) {
	Queue BFS_Queue;
	queue_init(&BFS_Queue);
	queue_push(&BFS_Queue, root);
	BFS_Queue.count++;

	int VisitedNodes = 0;
	while (BFS_Queue.count > 0) {
		TreeNode* Current = queue_pop(&BFS_Queue);
		VisitedNodes++;
		printf("Key de la node visitee: %s\n", (char*)Current->data);

		if (Current != NULL && Current->data == key) {
			return VisitedNodes;
		}

		if (Current->left != NULL) {
			queue_push(&BFS_Queue, Current->left);
			BFS_Queue.count++;
		}

		if (Current->right != NULL) {
			queue_push(&BFS_Queue, Current->right);
			BFS_Queue.count++;
		}
	}

	return 0;

}