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
class Solution {
public:
    

    void flatten(TreeNode* root) {
        if(root == nullptr) return;

        flatten(root->left);
        flatten(root->right);

        if(root->left == nullptr) return;
        TreeNode* tmp = root->right;
        root->right = root->left;        
        TreeNode* n = root->right;
        for( ; n->right != nullptr; n = n->right) { }
        n->right = tmp;

        root->left = nullptr;
    }
};