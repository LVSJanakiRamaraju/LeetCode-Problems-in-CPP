/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> mp;
    void childToParent(TreeNode* root){
        if(!root)   return;
        if(root->left)  mp[root->left] = root;
        if(root->right) mp[root->right] = root;

        childToParent(root->left);
        childToParent(root->right);

    }


public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       
        childToParent(root);
        vector<int> result;
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> st;
        st.insert(target);

        while(k--){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && st.find(curr->left) == st.end()) {
                     q.push(curr->left);
                     st.insert(curr->left);
                }
                if(curr->right && st.find(curr->right) == st.end()) {
                    q.push(curr->right);
                    st.insert(curr->right);
                }

                if(mp.count(curr) && st.find(mp[curr]) == st.end())  {
                    q.push(mp[curr]);
                    st.insert(mp[curr]);
                }
            }
        }

        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};