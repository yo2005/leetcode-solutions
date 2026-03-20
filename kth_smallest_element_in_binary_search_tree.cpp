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
        vector<int> inorder(TreeNode* root){
            vector<int>x;
            if(root==NULL){
                return x;

            }
            stack<TreeNode*>st;
            TreeNode* z=root;
            while(true){
                if(z!=NULL){
                    st.push(z);
                    z=z->left;
                }
                else{
                    if(st.empty()==true){
                        break;
                    }
                    else{
                        z=st.top();
                        st.pop();
                        x.push_back(z->val);
                        z=z->right;
                    }
                }
            }
            return x;
        }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>res=inorder(root);
        return res[k-1];
        
    }
};
