
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    TreeNode* solve(int i, int j, vector<int>&nums){
        if(i > j) return NULL;
        int mid = i + (j - i) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = solve(i, mid-1, nums);
        root->right = solve(mid+1, j, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       TreeNode* root = solve(0, nums.size() - 1, nums);
       return root;
    }
};
