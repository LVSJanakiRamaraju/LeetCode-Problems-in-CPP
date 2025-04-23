class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> freq;
        int maxFreq =0;
        for(int i=1; i<=n; i++){
            int val = i, sum =0;
            while(val){
                sum += val%10;
                val /= 10;
            }
            freq[sum]++;
            maxFreq = max(maxFreq, freq[sum]);
        }
        int count =0;
        for(int i=0; i<10; i++){
            if(maxFreq == freq[i])  count++;
        }

        return count;
    }
};