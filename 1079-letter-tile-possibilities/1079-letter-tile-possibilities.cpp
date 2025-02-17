class Solution {
private:

    int find(vector<int> freq){
        int count =0;
        for(int i=0; i<26; i++){
            if(freq[i]){
                count++;
                freq[i]--;
                count += find(freq);
                freq[i]++;
            }
        }
        return count;
    }


public:
    int numTilePossibilities(string tiles) {
        
        vector<int> freq(26, 0);
        for (char ch : tiles) {
            freq[ch - 'A']++;
        }

        return find(freq);
    }
};