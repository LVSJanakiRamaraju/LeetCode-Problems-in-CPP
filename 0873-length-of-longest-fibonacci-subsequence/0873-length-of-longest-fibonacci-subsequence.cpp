class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int maxLen =0, n = arr.size();
        unordered_set<int> set;
        for(int num : arr){
            set.insert(num);
        }
        for(int i=0; i<n; i++){
            for(int j =i+1; j<n; j++){
                int prev = arr[i];
                int curr = arr[j];
                int len =2;

                while(set.find(prev + curr) != set.end()){
                    len++;
                    curr += prev;
                    prev = curr - prev;
                    maxLen = max(maxLen, len);
                }
            }
        }


        return maxLen;
    }
};