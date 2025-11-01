/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* res = new ListNode();
        ListNode* resCurr = res;
        ListNode* curr = head;
        unordered_set<int> s(nums.begin(), nums.end());

        while(curr){
            if(s.find(curr->val) == s.end()){
                resCurr->next = new ListNode(curr->val);
                resCurr = resCurr->next;
            }
            curr = curr->next;
        }
        return res->next;
    }
};