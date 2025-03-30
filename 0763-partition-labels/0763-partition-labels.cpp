class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);
        for(int i=0; i<s.size(); i++){
            last[s[i] - 'a'] = i;
        }

        int left = 0, right =0;
        vector<int> result;

        for(int i=0; i<s.size(); i++){
            right = max(right, last[s[i] - 'a']);
            if(i == right){
                result.push_back(right - left +1);
                left = right + 1;
            }
        }

        return result;
    }
};