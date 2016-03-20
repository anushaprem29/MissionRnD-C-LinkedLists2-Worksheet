/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	int count = 0;
	struct node *fast = head, *slow = head;
	if (fast == NULL)	return -1;
	fast = fast->next->next;
	while (fast->next != NULL){
		count++;
		slow = slow->next;
		fast = fast->next->next;
	}
	if (!count % 2)
		return (int)(slow->next + slow->next->num) / 2;
	return slow->next->num;

}
