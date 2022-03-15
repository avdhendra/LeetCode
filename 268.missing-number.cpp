/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */
/*
we can do this by using a set where we store all the value in and iterate all
and said if !set.contain(i) then we return it

other wise we return -1

other approach is to sum all the value  and substract it with the value of n*(n-1)/2 so we get the element which is missing



*/

#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int sum=0;
    for(int i:nums){
        sum+=i;
    }

    int n=nums.size()+1; //that one number is missing we add 
    return (n*(n-1)/2)-sum;

    }
};
// @lc code=end

