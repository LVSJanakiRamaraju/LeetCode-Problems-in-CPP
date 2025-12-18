    long long minMoves(vector<int>& A) {
        int n = A.size(), j = -1;
        long long total = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            total += A[i];
            if (A[i] < 0) {
                j = i;
            }
        }
        if (j == -1) return 0;
        if (total < 0) return -1;
        for (int d = 1; A[j] < 0; ++d) {
            long long storage = A[(j + d) % n] + A[(j - d % n + n) % n];
            res += fmin(-A[j], storage) * d;
            A[j] += storage;
        }
        return res;
    }