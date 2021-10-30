//141. Linked List Cycle
//fast runner and slow runner
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
    bool hasCycle(ListNode *head) {
        //hashmap
        //fast and slow runner
        if (head == NULL)
        {
            return false;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
        
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                return true;
            }

        }
        return false;
    }
};
