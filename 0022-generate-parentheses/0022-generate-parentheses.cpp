class Solution {

void dp(int n, int left, int right, vector<char> &out, vector<string> &result){
    if(left >= n && right >= n){
        string outputStr(out.begin(), out.end());
        result.push_back(outputStr);
    }

    if(left < n){
        out.push_back('(');
        dp(n, left+1, right, out, result);
        out.pop_back();
    }

    if(right < left){
        out.push_back(')');
        dp(n, left, right+1, out, result);
        out.pop_back();
    }
}



public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<char> out;
        dp(n, 0 , 0, out, result);
        return result;
    }
};