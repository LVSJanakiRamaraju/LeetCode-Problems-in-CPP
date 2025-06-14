class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        char c = 'a';
        int idx = 0;
        for(char ch : str){
            if(ch != '9'){
                c = ch;
                break;
            }
            idx++;
        }

        if(c == 'a')   return num;

        for(int i =0; i<str.size(); i++){
            if(str[i] == '9' && idx >= i)   continue;
            if(str[i] == c) str[i] = '9';
            else str[i] = '0';
        }

        return stoi(str);
    }
};