class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> result;
        unordered_map<int, int> colors, balls;

        for(auto q : queries){
            int ball = q[0], color = q[1];
            if(balls.find(ball) != balls.end()){
                int prev = balls[ball];
                colors[prev]--;
                if(colors[prev] == 0)   colors.erase(prev);
            }
            balls[ball] = color;
            colors[color]++;
            result.push_back(colors.size());
        }

        return result;
    }
};