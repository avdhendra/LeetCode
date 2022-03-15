/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
class comp{
public:
int operator()(const pair<int,ListNode*>&p1,const pair<int,ListNode*>&p2)
{
    return p1.second->val>p2.second->val;
}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //Min Heap
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,comp>pq;
        int n=lists.size();
        if(n==0){
            return NULL;
        }
        for(int i=0;i<n;i++){
            if(lists[i]){
                pq.push({i,lists[i]});
            }
        }
        ListNode*dummy=new ListNode(0);
        ListNode*head=dummy;
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            int i=tp.first;
            ListNode*n=tp.second;
            head->next=n;
            head=head->next;
            if(n->next){
                pq.push({i,n->next});
            }
        }
        if(head){
            head->next=NULL;
        }
        return dummy->next;
    }
};
// @lc code=end

