class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        int n = words.size();
        for(int i=0; i<n; i++){
            string str = words[i];
            for(char ch : str){
                if(ch == x){
                    result.push_back(i);
                    break;
                }
            }
        }


        return result;
    }
};