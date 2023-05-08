class Solution {
public:
    //time complexity: O(mat.size()), Space Complexity: O(1)
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        //adding all elements 
        for(int i=0;i<mat.size();i++)
        {
            sum+=mat[i][i]+mat[i][mat.size()-i-1];
        }
        //if product is odd means both are odd, if mat size is odd then only middle elemennt will be added twice
        if((mat.size()*mat.size())%2!=0)
        sum-=mat[mat.size()/2][mat.size()/2];
        return sum;
    }
};