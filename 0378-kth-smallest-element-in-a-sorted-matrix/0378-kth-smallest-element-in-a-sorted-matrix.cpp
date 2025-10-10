class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

        for(int i=0; i<min(n, k); i++){
            minHeap.push({matrix[i][0], {i, 0}});
        }
        int ans = matrix[0][0];
        for(int i=0; i<k; i++){
            auto [val, idx] = minHeap.top();
            minHeap.pop();
            int r = idx.first, c = idx.second;
            if(c+1 < m) minHeap.push({matrix[r][c+1], {r, c+1}});
            ans = val;
        }
        return ans;
    }
};