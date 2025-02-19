class Solution {
private:
    void find(string& str, vector<string>& result, int n, int k){
        if(result.size() >= k)  return;

        if(str.size() == n){
            result.push_back(str);
            return;
        }

        for(int i=0; i<3; i++){
            if(str.empty() || str.back() != 'a' + i){
                str.push_back('a' + i);
                find(str, result, n, k);
                str.pop_back();
            }
        }
    }



public:
    string getHappyString(int n, int k) {
        vector<string> result;
        string str;
        find(str, result, n, k);
        if(result.size() >= k)  return result[k-1];
        return "";
    }
};