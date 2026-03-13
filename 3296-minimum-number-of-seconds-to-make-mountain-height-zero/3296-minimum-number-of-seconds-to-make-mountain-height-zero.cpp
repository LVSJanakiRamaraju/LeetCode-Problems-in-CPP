class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime = *max_element(workerTimes.begin(), workerTimes.end());

        long long l =1 , r = static_cast<long long>(maxTime) * mountainHeight * (mountainHeight + 1)/2, ans =0;
        while(l <= r){
            long long mid = l + (r-l)/2;
            int count =0;
            for(int i : workerTimes){
                long long work = mid/i;
                int x = (-1 + sqrt(1 + 8*work))/2;
                count += x;
            }

            if(count >= mountainHeight){
                ans = mid;
                r = mid-1;
            }
            else    l = mid+1;
        }
        return ans;

    }
};