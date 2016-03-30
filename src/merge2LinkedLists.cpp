/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
void merge(struct node *head1, struct node *head2){
	struct node *temp;
	while (head1->next != NULL && head2 != NULL){
		if (head1->next->num > head2->num){
			temp = head1->next;
			head1->next = head2;
			head2 = head2->next;
			head1->next->next = temp;
		}
		head1 = head1->next;
	}
	if (head2 != NULL){
		head1->next = head2;
	}
}
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if(head1 == NULL)	return head2;
	if (head2 == NULL)	return head1;
	struct node *temp;
	if (head1->num < head2->num){ 
		temp = head1;
		merge(head1, head2); 
	}
	else{
		temp = head2;
		merge(head2, head1);
	}
	return temp;
}
