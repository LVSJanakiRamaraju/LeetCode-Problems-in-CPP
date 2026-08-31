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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* nxt = curr->next;
        int prevCritical = -1;
        int firstCritical = -1;
        int ctr = 0;
        vector<int> sol = {INT_MAX, -1};
        while(nxt != NULL){
            if((curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && curr->val < nxt->val)){
                if(prevCritical != -1){
                    sol[0] = min(sol[0], ctr - prevCritical);
                    sol[1] = ctr - firstCritical;
                }else{
                    firstCritical = ctr;
                }
                prevCritical = ctr;
            }
            prev = curr;
            curr = nxt;
            nxt = nxt -> next;
            ctr++;
        }
        if(sol[0] == INT_MAX){
            sol[0] = -1;
        }
        return sol;
    }
};