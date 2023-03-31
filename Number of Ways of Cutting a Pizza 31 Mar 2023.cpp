//LeetCode solution link: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/solutions/3362516/recursive-memorization/
//Recursive
class Solution {
public:
    long long MOD=1000000007;
    bool isValid(int srow,int erow,int scol, int ecol,vector<string>&pizza)
    {
        for(int i=srow;i<=erow;i++)
        {
            for(int j=scol;j<=ecol;j++)
            {
                if(pizza[i][j]=='A')
                return true;
            }
        }
        return false;
    }
    int solve(vector<string>&pizza,int srow, int scol, int cutsleft)
    {
        int m=pizza.size(),n=pizza[0].size();
        if(cutsleft==0)
        return 1;
        long long ans=0;
        for(int i=srow;i<m-1;i++)
        {
            bool upper=isValid(srow,i,scol,n-1,pizza);
            bool lower=isValid(i+1,m-1,scol,n-1,pizza);
            if(upper&&lower)
            {
                int next=solve(pizza,i+1,scol,cutsleft-1);
                ans=(ans+next)%MOD;
            }
        }
        for(int i=scol;i<n-1;i++)
        {
            bool left=isValid(srow,m-1,scol,i,pizza);
            bool right=isValid(srow,m-1,i+1,n-1,pizza);
            if(left&&right)
            {
                int next=solve(pizza,srow,i+1,cutsleft-1);
                ans=(ans+next)%MOD;
            }
        }
        return (int)ans;
    }
    int ways(vector<string>& pizza, int k) {
        int ans=solve(pizza,0,0,k-1);
        return ans;

    }
};

//Memorization
class Solution {
public:
    long long MOD=1000000007;
    int t[51][51][11];
    //if a piece contains atleast one apple it will be a valid cut
    bool isValid(int srow,int erow,int scol, int ecol,vector<string>&pizza)
    {
        for(int i=srow;i<=erow;i++)
        {
            for(int j=scol;j<=ecol;j++)
            {
                if(pizza[i][j]=='A')
                return true;
            }
        }
        return false;
    }
    int solve(vector<string>&pizza,int srow, int scol, int cutsleft)
    {
        int m=pizza.size(),n=pizza[0].size();
        if(cutsleft==0)
        return 1;
        long long ans=0;
        if(t[srow][scol][cutsleft]!=-1)
        return t[srow][scol][cutsleft];
        //making cuts horizontally
        for(int i=srow;i<m-1;i++)
        {
            bool upper=isValid(srow,i,scol,n-1,pizza);
            bool lower=isValid(i+1,m-1,scol,n-1,pizza);
            if(upper&&lower)
            {
                int next=solve(pizza,i+1,scol,cutsleft-1);
                ans=(ans+next)%MOD;
            }
        }
        //making cuts vertically
        for(int i=scol;i<n-1;i++)
        {
            bool left=isValid(srow,m-1,scol,i,pizza);
            bool right=isValid(srow,m-1,i+1,n-1,pizza);
            if(left&&right)
            {
                int next=solve(pizza,srow,i+1,cutsleft-1);
                ans=(ans+next)%MOD;
            }
        }
        return t[srow][scol][cutsleft]=(int)ans;
    }
    int ways(vector<string>& pizza, int k) {
        for(int i=0;i<=50;i++)
        {
            for(int j=0;j<=50;j++)
            {
                for(int k=0;k<=10;k++)
                t[i][j][k]=-1;
            }
        }
        //we have passed k-1 bcoz we need to make k-1 cuts for k pieces
        int ans=solve(pizza,0,0,k-1);
        return ans;

    }
};