/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution1 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if (p == NULL || q == NULL)
        {
            return false;
        }
        if (p -> val == q -> val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
        {
            return true;
        }
        return false;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> myQueue;
        myQueue.push(pair<TreeNode*, TreeNode*>(p, q));
        while (!myQueue.empty()) {
         p = myQueue.front().first;
         q = myQueue.front().second;
        if(!p ^ !q || (p && q && p->val != q->val))
            break;
        myQueue.pop();
        if(p && q) {
            myQueue.push(pair<TreeNode*, TreeNode*>(p->left, q->left));
            myQueue.push(pair<TreeNode*, TreeNode*>(p->right, q->right));
        }
    }
    return myQueue.empty();
    }
};
