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
    int oopiwoopizoo(TreeNode* root, int& maxi){
        if(root==NULL){
            return 0;
        }
        int l=max(0,oopiwoopizoo(root->left,maxi));
        int r=max(0,oopiwoopizoo(root->right,maxi));
        maxi=max(root->val+l+r,maxi);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        oopiwoopizoo(root,maxi);
        return maxi;
        
    }
};
