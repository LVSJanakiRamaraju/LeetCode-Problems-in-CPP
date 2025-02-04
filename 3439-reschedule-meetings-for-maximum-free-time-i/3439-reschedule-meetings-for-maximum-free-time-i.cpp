class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> spaces(n+1);

        spaces[0] = startTime[0];
        spaces[n] = eventTime - endTime[n-1];
        for(int i=1; i<n;i++){
            spaces[i] = startTime[i] - endTime[i-1];
        }

        int maxSpaces = 0;
        for(int i=0; i<=k; i++){
            maxSpaces += spaces[i];
        }

        int ans = maxSpaces;
        for(int i = k+1; i<=n;i++){
            ans += spaces[i] - spaces[i - k-1];
            maxSpaces = max(maxSpaces, ans);
        }

        return maxSpaces;
    }
};