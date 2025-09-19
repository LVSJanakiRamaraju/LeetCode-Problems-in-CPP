class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> first(n+1, 0), last(n+1, 0);
        for(int i=1; i<=n; i++){
            first[i] += (customers[i-1]=='N' ? 1 : 0) + first[i-1];
        }
        last[n] = (customers[n-1]=='Y' ? 1 : 0);
        for(int i=n-1; i>=0; i--){
            last[i] += (customers[i]=='Y' ? 1 : 0) + last[i+1];
        }
        int idx = -1, result =INT_MAX;
        for(int i=0; i<=n; i++){
            if(first[i] + last[i] < result){
                result = first[i] + last[i];
                idx = i;
            }
        }
        return idx;
    }
};