class Solution {

public:
    static constexpr int DIRECTIONS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = queries.size();
        vector<int> result(n);
        int rows = grid.size();
        int cols = grid[0].size();

        int totalCells = rows*cols;
        vector<int> arr(totalCells+1);
        vector<vector<int>> ans(rows , vector<int>(cols, INT_MAX));
        ans[0][0] = grid[0][0];
        priority_queue<array<int, 3>, vector<array<int, 3>>,greater<array<int, 3>>>  minHeap;
        minHeap.push({grid[0][0], 0, 0});
        int visitedCells = 0;

        while (!minHeap.empty()) {
            array<int, 3> current = minHeap.top();
            minHeap.pop();

            arr[++visitedCells] = current[0];

            for (const auto& direction : DIRECTIONS) {
                int newRow = current[1] + direction[0];
                int newCol = current[2] + direction[1];

                if (newRow >= 0 && newRow < rows && newCol >= 0 &&
                    newCol < cols &&
                    ans[newRow][newCol] == INT_MAX) {
                    ans[newRow][newCol] =
                        max(current[0], grid[newRow][newCol]);
                    minHeap.push(
                        {ans[newRow][newCol], newRow, newCol});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int threshold = queries[i];
            int left = 0, right = totalCells;

            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (arr[mid] < threshold) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }

            result[i] = left;
        }

        return result;

    }
};