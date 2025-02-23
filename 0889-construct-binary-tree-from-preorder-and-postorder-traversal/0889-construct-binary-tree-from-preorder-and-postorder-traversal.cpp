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
    TreeNode* inorder(int& postIndex, int& preIndex, vector<int>& preorder, vector<int>& postorder){
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;

        if(root->val != postorder[postIndex])   root->left = inorder(postIndex, preIndex, preorder, postorder);
        if(root->val != postorder[postIndex])   root->right = inorder(postIndex, preIndex, preorder, postorder);

        postIndex++;
        return root;
    }


public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int postIndex = 0;
        int preIndex =0;
        return inorder(postIndex, preIndex, preorder, postorder);
    }
};