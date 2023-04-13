//Explanation link:https://leetcode.com/problems/validate-stack-sequences/solutions/3411529/c-stack/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int j=0;
        int n=pushed.size();
        for(auto it:pushed)
        {
            //push element into stack
            st.push(it);
            //if last pushed item is equal to current popped item , then remove it from stack and increment popped pointer
            while(j<=n&&!st.empty()&&popped[j]==st.top())
            {
                st.pop();
                j++;
            }
        }
        //if j=n then we have founded all the elements in sequence
        return j==n;
    }
};