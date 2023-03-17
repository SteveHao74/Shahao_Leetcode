// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 //前序遍历

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal_preorder(root,result);
        return result;
    }

    void traversal_preorder(TreeNode* node,vector<int>& record){
        if(node==nullptr){
            return;
        }
        record.push_back(node->val);
        traversal_preorder(node->left,record);
        traversal_preorder(node->right,record);
    }
    
    void traversal_posorder(TreeNode* node,vector<int>& record){
        if(node==nullptr){
            return;
        }

        traversal_posorder(node->left,record);
        traversal_posorder(node->right,record);
        record.push_back(node->val);
    }


};