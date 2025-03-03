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
 TreeNode* solve(vector<int>&inorder, int InStart, int InEnd, vector<int>& postorder, int PostStart, int PostEnd, map<int, int>&mpp){
    if(InStart>InEnd || PostStart> PostEnd) return NULL;

    TreeNode* node = new TreeNode(postorder[PostEnd]);

    int node_position = mpp[node->val];

    int leftLen = node_position - InStart;

    node->left = solve(inorder,InStart, node_position-1, postorder, PostStart, PostStart + leftLen-1, mpp);
    node->right = solve(inorder,node_position+1, InEnd, postorder, PostStart+leftLen, PostEnd-1, mpp);
    return node;
 }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int>mpp;
        for(int i=0;i<inorder.size();++i){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = solve(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mpp);
        return root;
    }
};
