class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int result=0, last = 0;
        for(auto it : meetings){
            if(it[0] > last+1){
                result += it[0] - last-1; 
            }
            last = max(last, it[1]);
        }
        result += days - last;
        return result;
    }
};