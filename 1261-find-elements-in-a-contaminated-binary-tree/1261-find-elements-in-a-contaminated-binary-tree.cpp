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
class FindElements {
public:
    unordered_set<int> s;
    void dfs(TreeNode* node, int v){
        if(!node)   return;
        s.insert(v);
        dfs(node->left, v*2+1);
        dfs(node->right, v*2+2);
    }
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    bool find(int target) {
        return s.find(target) != s.end();
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */