class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> mp;
        int result =0;
        double curr = 0;
        for(int i=0; i<position.size(); i++)    mp[-position[i]] = (double)(target-position[i])/speed[i];
        for(auto it : mp){
            if(it.second > curr){
                result++;
                curr = it.second;
            }
        }
        return result;
    }
};