//leetcode solution link:https://leetcode.com/problems/koko-eating-bananas/solutions/3271914/c-binary-search/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //defining iterators for binary search
        int low=1,high=INT_MAX-1,ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            //finding required time to eat all the bananas if k is equal to mid 
            long long req=0;
            for(auto it:piles)
            {
                req+=it/mid;
                if(it%mid!=0)
                req++;
            }
            //if req time is greater than target time update low iterator
            if(req>h)
                low=mid+1;
            // else update high iterator, as we need speed equal to lower than mid
            else 
            {
                high=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};