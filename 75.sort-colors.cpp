/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
/*Dutch national  Flag Algorithm*/
/*
/*Dutch national  Flag Algorithm*/
/*3check we have take in case
when mid is 0 1 and 2
if(mid==0) 
we swap(mid and low)
and move low++ and mid++

if(mid==1)
just mid++

if(mid==2)
just decrement high not change


*/

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
  int low=0;
  int high=nums.size()-1;
  int mid=0;
  while(mid<=high){
      switch(nums[mid]){
          //If the element is 0
          case 0:
          swap(nums[low++],nums[mid++]);
          break;

          //if the element is 1
          case 1:
          mid++;
          break;
          //If the element is 2
          case 2:
          swap(nums[mid],nums[high--]);
          break;

      }
  }      
    }
};
// @lc code=end

