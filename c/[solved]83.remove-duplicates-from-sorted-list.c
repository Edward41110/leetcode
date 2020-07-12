//¿ìÂıÖ¸Õë·¨ 

#include <stdio.h> 
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};
 
struct ListNode* deleteDuplicates(struct ListNode* head){
	int i;
	int cnt = 1;
	struct ListNode* p = head;
	if ( p == NULL || p->next == NULL )
		return head;
	
	struct ListNode* slow2 = p;
	struct ListNode* slow = p->next;
	struct ListNode* quick = p->next;
	while (quick != NULL)
	{
		if (quick->val != slow2->val)
		{
			slow->val = quick->val;
			slow2 = slow;
			slow = slow->next;
			cnt++;
		}
		quick = quick->next;
	}
	slow2->next = NULL; 
	return head;
}

int main()
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->val = 1;
	struct ListNode* p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p1->val = 1;
	head->next = p1;
	struct ListNode* p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p2->val = 2;
	p1->next = p2;
	p2->next = NULL;
	
	struct ListNode* pHead = deleteDuplicates(head);
	
	struct ListNode* p;
	
	for(p = pHead;p!=NULL;p=p->next)
		printf("%d ", p->val);
	return 0;
}
