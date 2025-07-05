class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        int lucky = -1;
        for(int num : arr)    freq[num]++;

        for(auto [num, f] : freq){
            if(num == f)    lucky = max(lucky, num);
        }

        return lucky;
    }
};