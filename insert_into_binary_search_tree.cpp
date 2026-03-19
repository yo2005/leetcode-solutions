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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            return new TreeNode(val);
        }
        TreeNode* w = root;
        while(true){
            if(w->val<=val){
                if(w->right!=NULL){
                    w=w->right;
                }
                else{
                   w->right=new TreeNode(val);
                   break; 
                }
            }
            else{
                if(w->left!=NULL){
                    w=w->left;
                }
                else{
                    w->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;

    }
};
