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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal_inorder(root,result);
        return result;
    }
    void traversal_inorder(TreeNode* node,vector<int>& record){
        if(node==nullptr){
            return;
        }
        traversal_inorder(node->left,record);
        record.push_back(node->val);
        traversal_inorder(node->right,record);
    }
};