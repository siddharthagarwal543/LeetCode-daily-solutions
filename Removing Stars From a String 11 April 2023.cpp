class Solution {
public:
    string removeStars(string s) {
        int n=s.length();
        vector<bool>v(n,false);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            //if current element is non start push it into stack
            if(s[i]!='*')
            st.push(i);
            //else mark top element of stack and star element as removed  
            else
            {
                if(!s.empty())
                {
                    v[st.top()]=true;
                    v[i]=true;
                    st.pop();
                }
            }
        }
        string ans="";
        //if element is not removed, add it into answer string
        for(int i=0;i<n;i++)
        {
            if(!v[i])
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};