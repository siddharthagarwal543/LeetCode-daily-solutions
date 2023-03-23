//Leetcode Solution:https://leetcode.com/problems/number-of-operations-to-make-network-connected/solutions/3330734/c-dfs/
class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<bool>&vis,int e)
    {
        vis[e]=true;
        for(auto it:adj[e])
        {
            if(!vis[it])
            dfs(adj,vis,it);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //the minimum number of vertex required to join n edges is n-1
        if(connections.size()<n-1)
        return -1;
        //making adjacency list
        vector<vector<int>>v(n);
        for(auto it:connections)
        {
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,false);
        int components=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                //if this condition occurs, means it is a independent computer
                components++;
                dfs(v,vis,i);
            }
        }
        return components-1;
    }
};