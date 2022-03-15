/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
//time complexity:0(N)
//space complexity:0(N)
/*
Optimal : take unordered map and store check the target-num[i] value present in map or not
if present and push the index of target-num[i] and current element in vector if not
then push the element with its index
*/
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>answer;
        unordered_map<int,int> mpp;

        for(int i=0;i<nums.size();i++) {
            if(mpp.find(target-nums[i])!=mpp.end()) {
                answer.push_back(mpp[target-nums[i]]); //index of target-num[i] 
                answer.push_back(i);//index of current 
                return answer;
            }
            mpp[nums[i]] = i;
        }
        return answer;
    }
};
// @lc code=end

