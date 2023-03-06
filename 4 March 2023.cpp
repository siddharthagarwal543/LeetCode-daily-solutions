//https://leetcode.com/problems/count-subarrays-with-fixed-bounds/solutions/3256843/c-solution-modified-windowing-approach/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int left=-1,mini=-1,maxi=-1,right=0,i=0;
        long long ans=0;
        while(i<nums.size())
        {
            if(nums[i]>=minK&&nums[i]<=maxK)
            {
                if(nums[i]==minK)
                    mini=i;
                if(nums[i]==maxK)
                    maxi=i;
                ans+=max(0,min(mini,maxi)-left);
            }
            if(nums[i]>maxK||nums[i]<minK)
            {
               
                   left=i;
                    mini=-1;
                    maxi=-1;
            }
            i++;
        }
        return ans;
    }
};