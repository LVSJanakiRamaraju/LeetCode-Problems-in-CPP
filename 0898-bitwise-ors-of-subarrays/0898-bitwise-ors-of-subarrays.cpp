class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> curr;
        for(int x : arr){
            unordered_set<int> next;
            next.insert(x);
            for(int y : curr){
                next.insert(x | y);
            }
            result.insert(next.begin(), next.end());

            curr = next;
        }
        return result.size();
    }
};