#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	struct ListNode* head, *p1, *p2;
	if (l1->val > l2->val)
	{
		head = l2;
		p2 = l1;
		p1 = l2;
	}
	else
	{
		head = l1;
		p1 = l1;
		p2 = l2;
	}
	while (p2 != NULL)
	{
		if (p1->next == NULL)
		{
			p1->next = p2;
			break;
		}
		if (p1->next->val <= p2->val)
			p1 = p1->next;
		else
		{
			struct ListNode* pNew = (struct ListNode *)malloc(sizeof(struct ListNode));
			pNew->val = p2->val;
			pNew->next = p1->next;
			p1->next = pNew;
			p2 = p2->next;
		}
	}
	return l1->val>l2->val?l2:l1;
}

int main()
{
	struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l1->val = 2;
	struct ListNode* p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p1->val = 5;
	l1->next = p1;
	struct ListNode* p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p2->val = 11;
	p1->next = p2;
	p2->next = NULL;
	
	struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2->val = 1;
	struct ListNode* p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p3->val = 6;
	l2->next = p3;
	struct ListNode*  p4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p4->val = 9;
	p3->next = p4;
	p4->next = NULL;
	struct ListNode* pResult = mergeTwoLists(l1, l2);
	struct ListNode* q;
	for (q = pResult;q != NULL;q = q->next)
		printf("%d->", q->val);
	printf("\n");
	getchar();
	return 0;
}
