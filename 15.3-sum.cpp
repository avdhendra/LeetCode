/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 * Time Complexity is 0(N*N)
 *
 */
/**
first sort the array and
a+b+c=0
b+c=-a

we need two pointer low and high

b+c=2
let say


*/
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        // Moves for a
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i == 0 || (i > 0 and nums[i] != nums[i - 1]))
            {
                int low = i + 1, high = nums.size() - 1, sum = 0 - nums[i]; //b+c=-a
                while (low < high)
                {
                    if (nums[low] + nums[high] == sum)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        res.push_back(temp);
//remove duplicacy
                        while (low < high && nums[low] == nums[low + 1])
                        {
                            low++;
                        }
                        while (low < high && nums[high] == nums[high - 1])
                        {
                            high--;
                        }
                        //when the low+high =sum
                        //increase both
                        low++;
                        high--;
                    }
                    else if (nums[low] + nums[high] > sum)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
