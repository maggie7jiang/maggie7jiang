//21. Merge Two Sorted Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode dummy(0);
       ListNode *tail =&dummy;
       while (l1 !=nullptr && l2 !=nullptr)
       {
       	if (l1->val < l2->val)
       	{
       		tail->next = l1;
       		l1 = l1->next;
       	}
       	else
       	{
       		tail->next =l2
       		l2 = l2->next;
       	}
       	tail = tail->next;
       }  
       if (l1 != nullptr)
       {
       	tail->next = l1;
       }
       if (l2 != nullptr)
       {
       	tail->nexxt = l2;
       }
       return dummy.next;
    }
};

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if (!l1 || !l2)
    	{
    		return l1 ? l1 : l2;
    	}
    	if (l1->val < l2->val)
    	{
    		l1->next = mergeTwoLists(l2->next, l2);
    		return l1;
    	}
    	else
    	{
    		l2->next = mergeTwoLists(l1, l2->next);
    		return l2;
    	}

	}
}
