/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
    for(int i =0;i<nums.size();i++){
        if(nums[i]!=0){
            //Swapping the non zero element with index with value 0;
           int temp = nums[count];
            nums[count] = nums[i];
            nums[i] = temp;
            count++;
    }
    }
    }
};
// @lc code=end

