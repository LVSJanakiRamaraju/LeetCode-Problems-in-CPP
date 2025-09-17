class Solution {
private:
    int solve(int r, int c, vector<vector<int>>& dungeon, vector<vector<int>>& dp){
        int curr = dungeon[r][c];
        if(r +1 >= dungeon.size() && c + 1 >= dungeon[0].size()){
            int res = curr >= 0 ? 1 : abs(curr) + 1;
            return dp[r][c] = res;
        }
        int right = INT_MAX, down = INT_MAX;
        if(r+1 < dungeon.size()){
            if(dp[r+1][c] != INT_MAX)    down = dp[r+1][c];
            else    down = solve(r+1, c, dungeon, dp);
        }

        if(c+1 < dungeon[0].size()){
            if(dp[r][c+1] != INT_MAX)   right = dp[r][c+1];
            else    right = solve(r, c+1, dungeon, dp);
        }
        int minVal = min(right, down);
        if(curr < minVal)   curr = (minVal - curr);
        else curr = 1;

        return dp[r][c]= curr;
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int minHealth = INT_MAX;
        int n = dungeon.size(), m = dungeon[0].size();

        vector<vector<int>> dp(n, vector<int>(m, minHealth));

        return abs(solve(0, 0, dungeon, dp));
    }
};