//160. Intersection of Two Linked Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//   a1 a2
// 			 c1 c2 c3
//b1 b2 b3
class Solution_LinkedList {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while (headA != nullptr)
        {
        	ListNode *pointerB = headB;
        	while (pointerB != nullptr)
        	{
        		if (pointerB == headA)
        		{
        			return headA;
        		}
        		pointerB = pointerB->next;
        	}
        	headA = headA->next;
        }
        return NULL;
    }
};
//time complexity: O(N*M)
//space complexity: O(1)
//length different solution:
class Solution_length_different_Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		//length of A and b
		int n = 0;
		int m = 0;
		ListNode *pointerA = headA;
		ListNode *pointerB = headB;
		while (pointerA != nullptr)
		{
			n++;
			pointerA = pointerA->next;
		}
		while (pointerB != nullptr)
		{
			m++;
			pointerB = pointerB->next;
		}
		int t = abs(n-m);
		if (n>m)
		{
			while(t != 0)
			{
				headA = headA->next;
				t--;
			}
		}
		else
		{
			while (t !=0)
			{
				headB = headB->next;
				t--;
			}
		}
		while (headA != nullptr && headB !=nullptr)
		{
			if (headA == headB)
			{
				return headA;
			}
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;


	}
}

//TWO pointers solution
//pointerA: a1, a2, c1, c2, c3, b1, b2, b3, c1
//pointerB: b1, b2, b3, c1, c2, c3, a1, a3, c1
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *pointerA;
		ListNode *pointerB;
		while (pointerA != pointerB)
		{
			if (pointerA == nullptr)
			{
				pointerA = headB;
			}
			else
			{
				pointerA = pointerA->next;
			}
			if (pointerB == nullptr)
			{
				pointerB = headA;
			}
			else
			{
				pointerB = pointerB->next;
			}
		}
		return pointerA;
	}
}

//time complexity: O(N)
//space complexity: O(1)

//hashmap solution:
//Time complexity: O(N)
//space complexity: O(N) - need to use container to save the node
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_map<ListNode*, int> m;
		while(headA != NULL){
			m[headA]++;
			headA = headA -> next;
		}
		while(headB != NULL){
			if(m[headB] > 0){
				return headB;
			}
			headB = headB -> next;
		}
		return NULL;
	}
};
