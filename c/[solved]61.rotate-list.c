#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }
    int i, length = 1;
    struct ListNode* p;
    for (p = head;p->next != NULL;p = p->next) {
        length++;
    }
    p->next = head;
    k %= length;
    k = length - k;
    for(i = 0;i < k;i++) {
        p = p->next;
    }
    head = p->next;
    p->next = NULL;
    return head;
}

void printList(struct ListNode* head)
{
	struct ListNode *p;
	for (p = head;p != NULL;p = p->next)
		printf("%d\t", p->val);
}

struct ListNode* NodeConstructor(struct ListNode* last, int value)
{
	struct ListNode* pNew = (struct ListNode*)malloc(sizeof(struct ListNode));
	last->next = pNew;
	pNew->next = NULL;
	pNew->val = value;
	return pNew;
} 

int main()
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->val = 1;
	NodeConstructor(head, 2);
	head = rotateRight(head, 1);
	printList(head);
	return 0;
}
