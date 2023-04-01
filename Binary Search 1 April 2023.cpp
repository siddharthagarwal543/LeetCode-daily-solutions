class Solution {
public:
    int search(vector<int>& nums, int target) {
        // range[0,n-1]
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            //finding middle element of range
            int mid=(low+high)/2;
            //if middle element equal to target return middle element index
            if(nums[mid]==target)
            return mid;
            //if middle element greater than target the target element will lie in left of middle
            if(nums[mid]>target)
            high=mid-1;
            //if middle element smaller than target,the target element will lie in left of middle 
            else
            low=mid+1;
        }
        return -1;
    }
};