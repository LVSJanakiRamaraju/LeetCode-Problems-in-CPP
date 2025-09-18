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

    TreeNode* solve(vector<int>& nums, int i, int j){
        if(i > j)    return nullptr;
        int max = INT_MIN, idx = -1;
        for(int x = i; x <=j; x++){
            if(max < nums[x]){
                max = nums[x];
                idx = x;
            }
        }

        TreeNode *root = new TreeNode(max);
        root->left = solve(nums, i, idx-1);
        root->right = solve(nums, idx+1, j);
        return root;
    }


public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};