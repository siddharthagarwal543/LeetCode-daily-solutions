class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool>ans(n,false);
        //finding maximum value
        int mx=0;
        for(auto it:candies)
        {
            mx=max(mx,it);
        }
        //finding threshold value which will be eligible to be true
        mx-=extraCandies;
        //finding which elements are greater or equal to threshold
        for(int i=0;i<n;i++)
        {
            ans[i]=candies[i]>=mx?true:false;
        }
        return ans;
    }
};