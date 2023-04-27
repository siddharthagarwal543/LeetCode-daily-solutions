class Solution {
public:
// any bulb will be on if it will have odd number of factors
// any number can be defined as number=a*b where number will have a and b both as factors
// now to have odd number of factors a and b both should be equal , i.e number should be a perfect square
    bool num_fact(int num)
    {
        int s=sqrt(num);
        return num==s*s;
    }
    int bulbSwitch(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(num_fact(i))
            ans++;
        }
        return ans;
    }
};