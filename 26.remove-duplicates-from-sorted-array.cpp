/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
// brute force approach is use hash set
/*
in hashset copy all the element in the array
set contain only unique elements
so we just set the all element in array
back 0(nlog(n))+0(n)

*/

/*
Two Pointer approach
set i and j point in array if i and j are same then move the j pointer if
i and j are different move i and copy j element in it


*/
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
// @lc code=end
