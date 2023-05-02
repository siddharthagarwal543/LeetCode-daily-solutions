//Recursive Solution
class Solution {
public:
    int solve(int n,int idx,vector<int>&group,vector<int>&profit,int minProfit)
    {
        if(n<0)// we have taken all the members
        return 0;
        if(idx==group.size())//we have explored all the options
        {
            if(minProfit<=0)
            return 1;
            return 0;
        }
        int ans=0;
        ans+=solve(n-group[idx],idx+1,group,profit,minProfit-profit[idx]);//case when we take current option
         ans+=solve(n,idx+1,group,profit,minProfit);//case when we don't take current option
        return ans;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        return solve(n,0,group,profit,minProfit);
    }
};


//DP Solution
class Solution {
public:
    int dp[101][101][101];//n,group.size(),profit
     const int mod = 1e9 + 7;
    int solve(int n,int idx,vector<int>&group,vector<int>&profit,int minProfit)
    {
        if(n<0)//we have used all the members
        return 0;
        if(idx==group.size()) //we have explored all the options
        {
            if(minProfit<=0)
            return 1;
            else
            return 0;
        }
        if(dp[n][idx][minProfit]!=-1)//the ans is pre calculated
        return dp[n][idx][minProfit];

        return dp[n][idx][minProfit]=(solve(n-group[idx],idx+1,group,profit,max(minProfit-profit[idx],0))+(long long)(solve(n,idx+1,group,profit,minProfit)))%mod;//first case when we take current option and the second case when we don't take current option
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,group,profit,minProfit);
    }
};
