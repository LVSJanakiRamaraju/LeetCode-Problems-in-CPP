class Solution {
  private:
    void helper(vector<int>& digits, int i, unordered_set<int>& result){
        int n = digits.size();
        for(int j=0; j<n; j++){
            if(j == i || digits[j] == 0) continue;
            for(int k=0; k<n; k++){
                if(k == i)  continue;
                if(k == j)  continue;
                result.insert(digits[j]*100 + digits[k]*10 + digits[i]);

            }
        }
    }


public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();

        unordered_set<int> result;
        for(int i=0; i<n; i++){
            if(digits[i]%2==0){
                helper(digits, i, result);
            }
        }


        vector<int> ans;
        for(int i : result){
            ans.push_back(i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};