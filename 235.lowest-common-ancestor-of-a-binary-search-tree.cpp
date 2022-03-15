/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL || root==p || root==q){
           return root;
       } 
       TreeNode* left=lowestCommonAncestor(root->left, p,q);
       TreeNode* right=lowestCommonAncestor(root->right,p,q);
       if(left==NULL){
           return right;
       }
       else if(right==NULL){
           return left;
       }
       else{
           return root;
       }
    }
};
// @lc code=end

