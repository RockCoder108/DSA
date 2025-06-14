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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        stack<TreeNode*>  st;
        st.push(root);
        int ans=1;
        while(!st.empty()){
            int size=st.size();
            ans=max(ans,size);
            for(int i=0;i<size;i++){
                TreeNode* node=st.top();
                st.pop();
                st.push(node->right);
                st.push(node->left);
            }
        }
        return ans;
    }
};