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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        if(root==nullptr){
            return 0;
        }
        int leftH=height(root->left);
        int rightH=height(root->right);

        if(leftH==rightH){
            return root;
        }
        else if(leftH>rightH){
            return subtreeWithAllDeepest(root->left);
        }
        else{
            return subtreeWithAllDeepest(root->right);
        }
        
    }
    int height(TreeNode*root){
        if(root==nullptr){
            return 0;
        }

        return 1+max(height(root->left),height(root->right));
    }
};