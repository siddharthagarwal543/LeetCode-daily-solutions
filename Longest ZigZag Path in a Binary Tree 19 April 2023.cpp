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
    int mxlen=0;
    void solve(TreeNode* root,int dir,int len)
    {
        //we reached at the end of tree, base condition
        if(root==NULL)
        return;
        mxlen=max(mxlen,len);
        //dir = 1, then we have to traverse left for zig zag flow
        // checking for both children of present node
        solve(root->right,1,dir==1?1:len+1);
        solve(root->left,0,dir==0?1:len+1);
        return;
    }
    int longestZigZag(TreeNode* root) {
        //checking for right traversal from root node
        solve(root,0,0);
        //checking for left traversal from root node
        solve(root,1,0);
        return mxlen;
    }
};