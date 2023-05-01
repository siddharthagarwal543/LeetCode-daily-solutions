class Solution {
public:
    double average(vector<int>& salary) {
        double ans=0;
        //mn for storing minimum element of array and mx for storing maximum element of array
        int mn=INT_MAX,mx=INT_MIN;
        // calculate sum, mn, mx
        for(auto it:salary)
        {
            ans+=it;
            mn=min(mn,it);
            mx=max(mx,it);
        }
        // exclude mn & mx and get the avg 
        return (ans-mn-mx)/(salary.size()-2);
    }
};

class Solution {
public:
    double average(vector<int>& salary) {
        double ans=0;
        //mn for storing minimum element of array and mx for storing maximum element of array
        int mn=INT_MAX,mx=INT_MIN;
        // calculate sum, mn, mx
        for(auto it:salary)
        {
            ans+=it;
            mn=min(mn,it);
            mx=max(mx,it);
        }
        // exclude mn & mx and get the avg 
        return (ans-mn-mx)/(salary.size()-2);
    }
};