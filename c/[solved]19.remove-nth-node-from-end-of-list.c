#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	if (head->next == NULL) return NULL;
	int len = 1;
	struct ListNode *p, *q;
	for (p = head;p->next != NULL;len++,p = p->next);
	p = head;
	int i = 0, idx = len - n;
	if (idx)
	{
		for (p = q = head;i < idx;i++,q = p, p = p->next);
		if (p->next == NULL)
			q->next = NULL;
		else
			q->next = p->next;
	}
	else
		head = p->next;
	free(p);
	return head;
}

int main()
{
	struct ListNode *p0 = (struct ListNode *)malloc(sizeof(struct ListNode));
	p0->val = 1;
	struct ListNode *p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	p1->val = 2;
	p0->next = p1;
	struct ListNode *p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	p2->val = 3;
	p1->next = p2;
	struct ListNode *p3 = (struct ListNode *)malloc(sizeof(struct ListNode));
	p3->val = 4;
	p2->next = p3;
	struct ListNode *p4 = (struct ListNode *)malloc(sizeof(struct ListNode));
	p4->val = 5;
	p3->next = p4;
	p4->next = NULL;
	
	struct ListNode *head = removeNthFromEnd(p0, 2);
	struct ListNode *p;
	for (p = head;p != NULL;p = p->next)
		printf("%d ", p->val);
	return 0;
}
