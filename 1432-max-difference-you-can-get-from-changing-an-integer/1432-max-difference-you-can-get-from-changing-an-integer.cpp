class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        string max = "", min = "";
        char maxC = ' ', minC = ' ';
        for(char c : str ){
            if(c != '9'){
                maxC = c;
                break;
            }
        }
        if(str[0] != '1')   minC = str[0];
        else{
            for(int i=1; i<str.size(); i++){
                if(str[i] != '0' && str[i] != '1'){
                    minC = str[i];
                    break;
                }
            }
        }

        for(char ch : str){
            if(ch == maxC)  max.push_back('9');
            else            max.push_back(ch);
            if(ch == minC && str[0] != '1')  min.push_back('1');
            else if(ch == minC) min.push_back('0');
            else            min.push_back(ch);
        }

        return stoi(max) - stoi(min);



    }
};