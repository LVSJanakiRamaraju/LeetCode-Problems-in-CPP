class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, queue<pair<string, int>>> buckets;
        int count = 0;

        for (auto& word : words) {
            buckets[word[0]].push({word, 0});
        }
        for (char c : s) {
            auto& q = buckets[c];
            int size = q.size();

            while (size--) {
                auto [word, idx] = q.front(); q.pop();
                idx++;
                if (idx == word.size()) count++;
                else buckets[word[idx]].push({word, idx});
            }
        }
        return count;
    }
};