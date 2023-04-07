class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i,int j)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!=1)
        return;
        grid[i][j]=-1;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
       int m=grid.size(),n=grid[0].size();
       //marking all the boundaries
       for(int i=0;i<m;i++)
       {
           dfs(grid,i,0);
           dfs(grid,i,n-1);
       }
       for(int j=0;j<n;j++)
       {
           dfs(grid,0,j);
           dfs(grid,m-1,j);
       }
       //counting unreachable land cells 
       int count=0;
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(grid[i][j]==1)
               count++;
           }
       }
       return count;
    }
};