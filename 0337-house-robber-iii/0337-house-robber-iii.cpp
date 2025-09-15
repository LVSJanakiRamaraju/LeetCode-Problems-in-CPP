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

private:
    pair<int,int> travel(TreeNode* root){
        if(!root)   return {0, 0};
        pair<int, int> left = travel(root->left), right = travel(root->right);
        int pick = root->val + left.second + right.second;
        int not_pick = max(left.first, left.second) + max(right.first, right.second);
        return {pick, not_pick};
    }

public:
    int rob(TreeNode* root) {
        pair<int, int> result = travel(root);
        return max(result.first, result.second);
    }
};