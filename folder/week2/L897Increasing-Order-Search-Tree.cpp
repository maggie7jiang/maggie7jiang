//897. Increasing Order Search Tree

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
//recursion - in order traversal and get all node in order and construct new tree
class Solution {
private:
    TreeNode *newroot, *current;
public:
    TreeNode* increasingBST(TreeNode* root) {
        //in order traversal and get all nodes in order and construct new nodes using increasing value
        if (root == nullptr)
        {
            return NULL;
        }
        increasingBST(root->left);
        if (newroot == nullptr)
        {
            newroot = new TreeNode(root->val);
            current = newroot;
        }
        else
        {
            current->right = new TreeNode(root->val);
            current = current->right;
        }
        increasingBST(root->right);
        return newroot;
        
        
    }
};
