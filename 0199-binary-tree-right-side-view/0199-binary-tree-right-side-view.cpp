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
    
   
    void traverse(TreeNode* root,int value,map<int,int>& mpp)
    {
        if(!root) return;
        if(mpp.find(value)==mpp.end()) mpp.insert({value,root->val});
        if(root && root->right) traverse(root->right,value+1,mpp);
        if(root && root->left) traverse(root->left,value+1,mpp);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int value=0;
         map<int,int> mpp;
       traverse(root,value,mpp);
       for(auto it: mpp)
       {
        res.push_back(it.second);
       }
       return res;
    }
};