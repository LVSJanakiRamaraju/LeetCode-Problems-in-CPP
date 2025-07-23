class Solution {
    int maxPoint = 0;
private:
    void solve(string& s, string pair, int val){
        string newS = "";
        for(char ch : s){
            if(!newS.empty() && ch == pair[1] && newS.back() == pair[0]){
                newS.pop_back();
                maxPoint += val;
            }
            else   newS.push_back(ch);
        }
        s = newS;
    }
public:
    int maximumGain(string s, int x, int y) {
        if(x > y){
            solve(s, "ab", x);
            solve(s, "ba", y);
        }
        else{
            solve(s, "ba", y);
            solve(s, "ab", x);
        }

        return maxPoint;
    }
};