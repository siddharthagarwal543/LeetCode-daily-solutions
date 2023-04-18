class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        //add both strings alternatively till one comes to end
        for(int i=0;i<min(word1.length(),word2.length());i++)
        {
            ans+=word1[i];
            ans+=word2[i];
        }
        //word1 is of greater length than word2, add it till word1 ends
        if(word1.length()>word2.length())
        {
            for(int i=word2.length();i<word1.length();i++)
            ans+=word1[i];
        }
        //word2 is of greater length than word1,add it till word2 ends
        else if(word1.length()<word2.length())
        {
            for(int i=word1.length();i<word2.length();i++)
            ans+=word2[i];
        }
        return ans;
    }
};