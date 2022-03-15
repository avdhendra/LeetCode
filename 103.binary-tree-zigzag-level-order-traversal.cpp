/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
/**
 * basic point is take a flag and set it to zero and as the 
 * first level order traversal done than we can set flag to one
 * */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(root==NULL){
return result;

    }    
    queue<TreeNode*> nodequeue;
    nodequeue.push(root);
    bool lefttoright = true;
    while(!nodequeue.empty()){
        int size=nodequeue.size();
        vector<int>row(size);
        for(int i=0; i<size;i++){
            TreeNode* node = nodequeue.front();
            nodequeue.pop();
            //find position to fill nodes value;
            int index=(lefttoright)? i:(size-1-i);
            row[index] = node->val;
            if(node->left){
                nodequeue.push(node->left);
            }
            if(node->right){
                nodequeue.push(node->right);
            }
        }
        lefttoright=!lefttoright;
        result.push_back(row);
    }
    return result;
    }
};
// @lc code=end

