class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        //for storing the starting and ending of maximum subarray
        long long left=0,right=0;
        long long n=nums.size();
        long long ans=0;
        while(left<n&&right<n)
        {
            //iterate till you don't find start of subarray
            if((nums[left]!=0))
            left++;
            else
            {
                right=left;
                //iterate till you don't find end of subarray
                while((right<n)&&(nums[right]==0))
                right++;
                long long size=right-left;
                cout<<size<<endl;
                //the total subarray possible will be summation of 1,2 till i where i is equal to size of max length subarray
                ans+=(long long)((size)*(size+1))/2;
                left=right+1;
            }
        }
        return ans;
    }
};