//Leetcode article link:https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solutions/3303852/using-recursion-and-unordered-map/
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
    //we will declare it globally because it's value will change in every recursive call
    int end;
     TreeNode* solve(int l,int r,unordered_map<int,int>&mp,vector<int>&postorder)
     {
         if(l>r)
         return NULL;
         //value of last element will be our root value
         int val=postorder[end--];
         //we will divide inorder array on the root value
         int pivot=mp[val];
         TreeNode* res=new TreeNode(val);
         // right side to root value in inorder vector will be right roots
         res->right=solve(pivot+1,r,mp,postorder);
        // left side to root value in inorder vector will be left roots
         res->left=solve(l,pivot-1,mp,postorder);
         return res;
     }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //we will store index in a map to make our program inex pensiove in terms of time complexity
        unordered_map<int,int>idx;
        end=postorder.size()-1;
        for(int i=0;i<inorder.size();i++)
        idx[inorder[i]]=i;
        return solve(0,inorder.size()-1,idx,postorder);
    }
};