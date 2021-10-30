//1721. Swapping Nodes in a Linked List
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
//3 pass approach, two pointers and listLength
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
    
        int listLength = 0;
        ListNode* currentNode = head;
        while (currentNode != nullptr)
        {
            listLength++;
            currentNode = currentNode->next;
        }
        ListNode* frontNode = head;
        for (int i = 1; i<k; i++)
        {
            frontNode = frontNode->next;
        }
        ListNode* endNode = head;
        for (int i = 1; i <= listLength - k; i++)
        {
            endNode = endNode->next;
        }
        //swap the values of front node and end node
        swap(frontNode->val, endNode->val);
        return head;
    }
    
};

// improve the loop to optimize the iteration
//get frontNode while count the length of list

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
    
        int listLength = 0;
        ListNode* currentNode = head;
        ListNode* frontNode = head;
        ListNode* endNode = head;
        while (currentNode != nullptr)
        {
            listLength++;
            if (listLength == k)
            {
                frontNode = currentNode;
            }
            currentNode = currentNode->next;
        }
        for (int i = 1; i <= listLength - k; i++)
        {
            endNode = endNode->next;
        }
        //swap the values of front node and end node
        swap(frontNode->val, endNode->val);
        return head;
    }
    
};
