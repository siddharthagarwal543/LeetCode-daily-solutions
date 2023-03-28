// Recursive code
class Solution {
public:
     int numdays(vector<int>&days,int idx,int ticket)
     {
         int target=days[idx]+ticket-1;
         for(int i=idx+1;i<days.size();i++)
         {
             if(days[i]>target)
             return i;
         }
        return days.size();
     }
     int rec(vector<int>&days,vector<int>costs,int i)
     {
         if(i>=days.size())
         return 0;
         int mn=INT_MAX;
         for(int it=0;it<3;it++)
         {
             int ticket;
             if(it==0)
             ticket=1;
             else if(it==1)
             ticket=7;
             else
             ticket=30;
             int nextday=numdays(days,i,ticket);
             mn=min(mn,costs[it]+rec(days,costs,nextday));
         }
         return mn;
     }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return rec(days,costs,0);
    }
};

//Memorization code
class Solution {
public:
    int t[366];
     int numdays(vector<int>&days,int idx,int ticket)
     {
         int target=days[idx]+ticket-1;
         for(int i=idx+1;i<days.size();i++)
         {
             if(days[i]>target)
             return i;
         }
        return days.size();
     }
     int rec(vector<int>&days,vector<int>costs,int i)
     {
         if(i>=days.size())
         return 0;
         int mn=INT_MAX;
         for(int it=0;it<3;it++)
         {
             int ticket;
             if(it==0)
             ticket=1;
             else if(it==1)
             ticket=7;
             else
             ticket=30;
             int nextday;
            nextday=numdays(days,i,ticket);
            if(t[nextday]==-1)
            t[nextday]=rec(days,costs,nextday);
             mn=min(mn,costs[it]+t[nextday]);
         }
         return mn;
     }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(int i=0;i<=365;i++)
        {
            t[i]=-1;
        }
        return rec(days,costs,0);
    }
};