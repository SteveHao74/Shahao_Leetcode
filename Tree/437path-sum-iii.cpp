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
    int pathSum(TreeNode* root, int targetSum) {
        queue<TreeNode*> tree_que;
        tree_que.push(root);
        int path_num = 0;
        if(root==nullptr)return path_num;
        while(!tree_que.empty()){
            TreeNode* temp_root = tree_que.front();
            tree_que.pop();
            if(temp_root->left)tree_que.push(temp_root->left);
            if(temp_root->right)tree_que.push(temp_root->right);
            path_num += recursive(temp_root,targetSum);
        }
        return path_num;
    }

    int recursive(TreeNode* sub_root, long long target){
        int num = 0;
        if(sub_root==nullptr){
            return 0;          
        }
        if(sub_root->val==target){
            num += 1;
        }

        

        num += recursive(sub_root->left,target-sub_root->val)+recursive(sub_root->right,target-sub_root->val);
        return num;
    }

};