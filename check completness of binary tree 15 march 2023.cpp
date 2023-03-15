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
    bool isCompleteTree(TreeNode* root) {
        //Initalize a queue and insert head into it
        queue<TreeNode*>q;
        q.push(root);
        bool flag=false;
        while(!q.empty())
        {
            int nodes=q.size();
            //flag=false;
            // traverse all the nodes of a particular level
            while(nodes--)
            {
                
                //if we found a NULL node we will check that whether it is rightmost node
                if(q.front()==NULL)
                flag=true;
                else
                {
                    //if flag is true and we encounter another node it implies that the NULL node is not right most
                    if(flag)
                    return false;
                    else
                    {
                        q.push(q.front()->left);
                        q.push(q.front()->right);
                    }
                }
                q.pop();
            }
        }
                    return true;
    }
};