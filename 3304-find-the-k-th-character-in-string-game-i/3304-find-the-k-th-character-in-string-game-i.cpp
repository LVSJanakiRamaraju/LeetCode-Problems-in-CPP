class Solution {
public:
    char kthCharacter(int k) {
        vector<int> arr;
        arr.push_back(0);
        while(arr.size() < k){
            int n = arr.size();
            for(int i=0; i<n; i++){
                arr.push_back((arr[i]+1)%26);
            }
        }

        return arr[k-1]+ 'a';
    }
};