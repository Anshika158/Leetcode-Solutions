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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int , int>hash;
        for(int i=0  ;i<inorder.size(); i++){
            hash[inorder[i]]=i;
        }
        TreeNode* root = buildTree(postorder , 0 , postorder.size()-1 , inorder , 0 , inorder.size()-1 , hash);

        return root;
    }
    TreeNode* buildTree(vector<int>& postorder , int postS , int postE , vector<int>& inorder ,int inS , int inE , unordered_map<int , int>&hash){
        if(inS>inE || postS>postE) return nullptr;

        TreeNode* root = new TreeNode(postorder[postE]);
        int inRoot = hash[root->val];
        int numsLeft = inRoot-inS;

        root->left = buildTree(postorder , postS , postS+numsLeft-1  , inorder , inS , inRoot-1, hash);
        root->right= buildTree( postorder , postS+numsLeft,postE-1   , inorder , inRoot+1 , inE , hash);

        return root;

    }
};