class Solution {
private:
    long long atleast(string word, int k){
        long long result=0;
        unordered_map<char, int> vowels;
        int consonants = 0, left =0, right=0;
        while(right < word.size()){
            if(word[right] == 'a' || word[right] == 'e' || word[right] == 'i' || word[right] == 'o' || word[right] == 'u')
                vowels[word[right]]++;
            else
                consonants++;
            while(vowels.size() == 5 && consonants >= k){
                result += word.size() - right;
                if(word[left] == 'a' || word[left] == 'e' || word[left] == 'i' || word[left] == 'o' || word[left] == 'u'){
                    vowels[word[left]]--;
                    if(vowels[word[left]] == 0) vowels.erase(word[left]);
                }
                else    consonants--;
                left++;
            }
            right++;
        }
        return result;
    }




public:
    long long countOfSubstrings(string word, int k) {
        return atleast(word, k) - atleast(word, k+1);
    }
};