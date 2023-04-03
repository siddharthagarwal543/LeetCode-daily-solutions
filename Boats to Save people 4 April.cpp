//leetcode article link: https://leetcode.com/problems/boats-to-save-people/solutions/3374665/c-two-pointers/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
         //low will point to lighest person and high will point to heaviest person
        int low=0,high=people.size()-1,ans=0;
        while(low<=high)
        {
            //weight of both under limit, we will take both in a single trip
            if(people[low]+people[high]<=limit)
            {
                low++;
                high--; 
            }
            //weight of both is above limit, we will take only heavier person in a trip
            else
            {
                high--;
            }
            ans++;
        }
        return ans;
    }
};