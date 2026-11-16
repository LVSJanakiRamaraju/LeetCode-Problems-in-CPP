#include <algorithm>
#include <string>
#include <utility>

class Solution {
public:
    std::string digitSum(std::string s, int k) {
        while (static_cast<int>(s.size()) > k) {
            std::string next;
            next.reserve(s.size() / k + 1);
            for (std::size_t start = 0; start < s.size(); start += k) {
                std::size_t end = std::min(start + static_cast<std::size_t>(k), s.size());
                int groupSum = 0;
                for (std::size_t i = start; i < end; ++i) {
                    groupSum += s[i] - '0';
                }
                next += std::to_string(groupSum);
            }
            s = std::move(next);
        }
        return s;
    }
};