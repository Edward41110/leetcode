/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(-1);
		ListNode *p = head;
		int carry = 0;
		while (l1 != NULL && l2 != NULL) {
			int x = l1->val + l2->val + carry;
			carry = 0;
			x = x >= 10 ? carry++, x - 10 : x;
			ListNode *NewNode = new ListNode(x);
			p->next = NewNode;
			p = p->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL) {
			int x = l1->val + carry;
			carry = 0;
			x = x >= 10 ? carry++, x - 10 : x;
			ListNode *NewNode = new ListNode(x);
			p->next = NewNode;
			p = p->next;
			l1 = l1->next;
		}
		while (l2 != NULL) {
			int x = l2->val + carry;
			carry = 0;
			x = x >= 10 ? carry++, x - 10 : x;
			ListNode *NewNode = new ListNode(x);
			p->next = NewNode;
			p = p->next;
			l2 = l2->next;
		}
		if (carry) {
			ListNode *NewNode = new ListNode(carry);
			p->next = NewNode;
		}
		return head->next;
	}
};

