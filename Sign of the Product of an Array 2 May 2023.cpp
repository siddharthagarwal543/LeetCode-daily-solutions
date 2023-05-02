class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg=0;
        for(auto it:nums)
        {
            //counting number of negative elements
            if(it<0)
            neg++;
            //any number multiplied with zero will result in zero, so if any zero element is encountered simply return it
            if(it==0)
            return 0;
        }
        //if number of negative element is odd we will get neg result else we will get possitive result
        return (neg%2==0)?1:-1;
    }
};

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans=1;
        for(auto it:nums)
        {
           ans*=(it>0)?1:(it==0)?0:-1;
        }
        //if number of negative element is odd we will get neg result else we will get possitive result
        return ans;
    }
};