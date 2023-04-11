class Solution {
public:
    bool isValid(string s) {
      stack<char>st;
      for(auto it:s)
      {
          //if element is opening bracket we will store it
          if(it=='('||it=='{'||it=='[')
          st.push(it);
          //if element is closing bracket we will find most recent opening bracket and compare it
          else
          {
              if(st.empty())
              return false;
              if((it==')' and st.top()!='(')||(it=='}' and st.top()!='{')||(it==']' and st.top()!='['))
              return false;
              st.pop();
          }
      }
      return st.empty();  
    }
};