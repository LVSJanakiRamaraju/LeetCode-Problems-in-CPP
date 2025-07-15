/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool evenLevel = true;
        while(!q.empty()){
            int n = q.size();
            TreeNode* prev = q.front();
            if(evenLevel){
                if(prev->val%2 == 0)    return false;
            }
            else{
                if(prev->val%2) return false;
            }
            q.pop();
            if(prev->left)  q.push(prev->left);
            if(prev->right)  q.push(prev->right);
            for(int i=1; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left)  q.push(curr->left);
                if(curr->right) q.push(curr->right);
                if(evenLevel){
                    if(curr->val%2 == 0)    return false;
                    if(prev->val >= curr->val)  return false;
                }
                else{
                    if(curr->val%2) return false;
                    if(prev->val <= curr->val)  return false;
                }
                prev = curr;

            }
            evenLevel = !evenLevel;
        }


        return true;
    }
};