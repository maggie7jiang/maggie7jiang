//only find two solutions iteratives and recursive
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *tempNode;
        while (current != nullptr)
        {
        	tempNode = current->next;
        	current->next = prev;
        	prev = current;
        	current = tempNode;
        }
        return prev;

    }
};
class SolutionRecursive {
public:
	ListNode* reverseListRecursive(ListNode* head){
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode *node = reverseListRecursive(head->next);
		head->next->next = head;
		head->next = nullptr;
		return node;
	}
}
