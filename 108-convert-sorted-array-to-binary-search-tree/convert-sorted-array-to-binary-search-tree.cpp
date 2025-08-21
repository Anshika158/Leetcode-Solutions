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
    TreeNode* sortedArray(vector<int>&nums , int low , int high){
        if(low>high) return nullptr;
            int mid=(low+high)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->val=nums[mid];
            root->left=sortedArray(nums , low , mid-1);
            root->right=sortedArray(nums , mid+1 , high);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int high=nums.size()-1;
        int low=0;
        return sortedArray(nums , low , high);
    }
};