class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> pos;
        int i=0;
        for(char ch : s){
            if(ch  == '1')  pos.push_back(i);
            i++;
        }
        string ans = "";
        int n = pos.size();
        if(n < k)   return ans;

        for(int i=0; i < n - k +1; i++){
            int start = pos[i], end = pos[i + k -1];

            string curr = s.substr(start, end-start +1);

            if(ans == "" || curr.size() < ans.size() || (curr.size() == ans.size() && curr < ans))  ans= curr;

        }

        return ans;
        
    }
};