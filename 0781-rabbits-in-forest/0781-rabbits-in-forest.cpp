class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        int result =0;
        for(int ele : answers)  mp[ele]++;
        for(int i=0; i<answers.size(); i++){
            if(answers[i] == 0)     result++;
            else if(mp[answers[i]] > 0){
                result += 1 + answers[i];
                mp[answers[i]] -= answers[i] + 1;
            }
        }
        return result;
    }
};