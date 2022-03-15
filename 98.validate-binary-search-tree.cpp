/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
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
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
      TreeNode* prev = NULL;
        return validate(root, prev);

    }
    bool validate(TreeNode* node, TreeNode* &prev){
        if(node==NULL){
            return true;
        }
       if(!validate(node->left, prev)){
           return false;
       }
       if(prev!=NULL && prev->val>=node->val){
           return false;
    }

    prev=node;
    return validate(node->right, prev);
}
};
// @lc code=end
