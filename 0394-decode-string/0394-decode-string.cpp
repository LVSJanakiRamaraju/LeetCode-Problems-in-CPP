class Solution {
public:
    string decodeString(string s) {
        stack<string> stringStack;
        stack<int> numberStack;
        string current = "";
        int num = 0;
        for (char c : s){
            if (isdigit(c)) num = num * 10 + (c - '0');
            else if (c == '['){
                numberStack.push(num);
                stringStack.push(current);
                num = 0;
                current.clear();
            }
            else if (c == ']'){
                int k = numberStack.top();
                numberStack.pop();
                string prev = stringStack.top();
                stringStack.pop();
                string expanded;
                expanded.reserve(prev.size() + current.size() * k);
                expanded += prev;
                for (int i = 0; i < k; ++i) expanded += current;
                current = move(expanded);
            }
            else current.push_back(c);
        }
        return current;
    }
};