class Solution {
private:
    bool find(int i, int n, vector<int>& result, vector<bool>& used) {
        if (i == result.size())
            return true;

        if (result[i] != 0) {
            return find(i + 1, n, result, used);
        }

        for (int curr = n; curr >= 1; curr--) {
            if (used[curr])
                continue;
            used[curr] = true;
            result[i] = curr;

            if (curr == 1) {
                if (find(i + 1, n, result, used))
                    return true;
            } else if (i + curr < result.size() && result[i + curr] == 0) {
                result[i + curr] = curr;
                if (find(i + 1, n, result, used))
                    return true;

                result[i + curr] = 0;
            }

            result[i] = 0;
            used[curr] = false;
        }
        return false;
    }

public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        find(0, n, result, used);
        return result;
    }
};