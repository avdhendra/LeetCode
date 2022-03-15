/*
 * @lc app=leetcode id=805 lang=cpp
 *
 * [805] Split Array With Same Average
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
      if(nums.size()<=1)
            return false;
        long sum = 0;
        for(int i=0; i<nums.size(); ++i){
            sum += nums[i]; 
        }
        vector<unsigned int> dp(sum+1,0);
        /**
        sum = 0 set to 1 0th bit set to 1 it means there is 0 size              subset
        whose sum is 0 similarly if dp[i] = a then the bit wise 
        representation of a if jth bit is 1 it means there exist subset of 
        length j whose sum is i
        **/
        dp[0]=1;
        for(int i=0;i<nums.size(); ++i){
            for(int j=sum;j>=0;--j){
                if(dp[j]){
                    dp[j+nums[i]]|=(dp[j]<<1);
                }
            }
        }
        /** 
         * iterate through sum array and check if sum full fills the 
         * criteria
         ** */
        for(int i=1;i<sum+1;++i){
            if((i*nums.size())%sum == 0){
                int l = (i*nums.size())/sum;
                if(l && l<nums.size() && (dp[i]&(1<<l)))return true;
            }
        }
        return false;
    }
};
// @lc code=end

