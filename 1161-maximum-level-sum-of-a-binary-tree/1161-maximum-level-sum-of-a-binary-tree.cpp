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
    struct TreeNode* q[100000];
    int front=0, back=0;

    int maxLevelSum(TreeNode* root) {
        int idx=0, sum=INT_MIN;
        front=back=0;
        q[back++]=root;
        int level=1;
        for( ; front<back; level++){
            const int qz=back-front;
            int curSum=0;
            for (int i=0; i<qz; i++) {
                struct TreeNode* Node=q[front++];
                curSum+=Node->val;
                if (Node->left) q[back++]=Node->left;
                if (Node->right) q[back++]=Node->right;
            }
            if(curSum>sum) idx=level, sum=curSum;
        } 
        return idx;
    }
};