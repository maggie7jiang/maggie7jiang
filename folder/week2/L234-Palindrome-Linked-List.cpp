//234. Palindrome Linked List
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
	ListNode* reverseList(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		ListNode *pointer = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return pointer;

	}
    bool isPalindrome(ListNode* head) {
        //slow and fast pointers to find the half of the list
        //reverse the second half of the list and compare with the first half
    	ListNode *slow = head;
    	ListNode *fast = head;
    	while (fast != NULL && fast->next != NULL)
    	{
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	slow = reverseList(slow);
    	while (slow != NULL)
    	{
    		if (slow->val != head->val)
    		{
    			return false;

    		}
    		slow = slow->next;
    		head = head->next;
    	}
    	return true;

    }
};
