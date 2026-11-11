class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long need = min(need1, need2);
        long long cost = need * min(costBoth, cost1 + cost2);

        long long rem1 = need1 - need;
        long long rem2 = need2 - need;

        cost += rem1 * min(cost1, costBoth);
        cost += rem2 * min(cost2, costBoth);

        return cost;
    }
};