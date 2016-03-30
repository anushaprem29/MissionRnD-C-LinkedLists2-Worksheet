/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if(head==NULL || K<=0)	return NULL;
	int save = K;
	struct node* iter = head, *newNode;
	while (K-- != 0 && iter->next != NULL){
		if (K != 0)
			iter = iter->next;
		if (K == 1 || K == 0){
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->next = iter->next;
			newNode->num=save;
			iter->next = newNode;
			iter = newNode->next;
			K = save;
		}
	}
	if (K == 0){
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->next = iter->next;
		newNode->num = save;
		iter->next = newNode;
		iter = newNode->next;
	}
	return head;
}
