// Leetcode solution link: https://leetcode.com/problems/minimum-time-to-complete-trips/solutions/3267351/c-binary-search/

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=0,h=1e14,mid;
        while(l<=h)
        {
            mid=l+(h-l)/2;
            long long trip=0;
            //finding total number of trips for time value mid
            for(int i=0;i<time.size();i++)
                trip += mid / time[i];
            // the minimum time will be lesser than or equal to mid
            if(trip>=totalTrips)
            h=mid-1;
            // the minimu time will be greater than mid
            else
            l=mid+1;
        }
        return l;
    }
};