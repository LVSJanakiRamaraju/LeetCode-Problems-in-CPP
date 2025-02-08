class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int i = 0, j = plants.size() - 1, A = capacityA, B = capacityB,
            result = 0;
        while (i < j) {
            result += (A < plants[i]) + (B < plants[j]);
            A = A < plants[i] ? capacityA : A;
            B = B < plants[j] ? capacityB : B;
            A -= plants[i++];
            B -= plants[j--];
        }
        return result + (i == j && max(A, B) < plants[i]);
    }
};