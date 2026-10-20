class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int ans = 0;
        for(int k=1; k*k<= n; k++){
            if(n%k) continue;

            if(check(k, nums, sorted)) ans += k;

            if(k != n/k && check(n/k, nums, sorted))  ans += n/k;
        }
        return ans;
    }


    bool check(int k, vector<int>& mapped, vector<int>& sorted){
        int n = mapped.size();
        if(k == 1)  return is_sorted(mapped.begin(), mapped.end());
        for(int i=0; i<n; i+= k){
            int drops =0;
            int mn = mapped[i];
            int mx = mapped[i];
            for(int j=i; j<i+k-1; j++){
                if(mapped[j] > mapped[j+1]) drops++;
                mn = min(mn, mapped[j]);
                mx = max(mx, mapped[j]);
                if(drops > 1) return false;
            }
            mn = min(mn, mapped[i + k -1]);
            mx = max(mx, mapped[i+ k -1]);
            if(mapped[i+k -1] > mapped[i]) drops++;

            if(drops > 1) return false;
            if(mn  != sorted[i]) return false;
            if(mx != sorted[i + k -1]) return false;
        }
        return true;
    }
   
};