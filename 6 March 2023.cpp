//Leetcode link: https://leetcode.com/problems/kth-missing-positive-number/solutions/3262975/c-hashing-binary-search/

//Brute force using hashing
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int hash[2001]={0}; //for storing occurence
       for(auto it:arr) // noting occurence of elements present in arr
       {
           hash[it]++;
       }
       for(int i=1;i<=2000;i++) 
       {
           if(hash[i]==0) // we had encountered a element that is not present in arr
           {
               k--;
               //cout<<i<<" ";
           }
           if(k==0) // we had reached the req element
           return i;
       }
       return -1;// this condition will never occur, don't worry
    }
};

//Binary search
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int l=0,h=arr.size();
     while(l<h)
     {
         int mid=l+(h-l)/2;
         if(arr[mid]-mid>k)
         h=mid;
         else
         l=mid+1;
     }
     return l+k;
    }
};