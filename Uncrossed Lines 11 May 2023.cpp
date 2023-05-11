class Solution {
public:
//Similar to longest common subsequence
    int dp[501][501]; //creating array to storing recursion results
    int solve(int i,int j,vector<int>&nums1,vector<int>&nums2)
    {
        if(i==nums1.size()||j==nums2.size())//if iterators are out of bound
        return 0;
        if(dp[i][j]!=-1)//the result is calculated and stored in dp array
        return dp[i][j];
        if(nums1[i]==nums2[j])//we have founded a line
        return dp[i][j]=1+solve(i+1,j+1,nums1,nums2);
        return dp[i][j]=max(solve(i+1,j,nums1,nums2),solve(i,j+1,nums1,nums2));//we have to let go one element in any one of the array
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<=nums1.size();i++)
        {
            for(int j=0;j<=nums2.size();j++)
            {
                dp[i][j]=-1;
            }
        }
        return solve(0,0,nums1,nums2);

    }
};