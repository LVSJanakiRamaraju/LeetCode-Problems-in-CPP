class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int first, second;
        int notMatch = first = second=0;

        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i])  {
                notMatch++;
                if(notMatch > 2)    return false;
                else if(notMatch == 1)  first = i;
                else     second =i;
            }
        }
        return s1[first] == s2[second] && s1[second] == s2[first];
    }
};