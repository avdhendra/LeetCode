/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */
/**

*/
#include<bits/stdc++.h>
// @lc code=start
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
         int n=rowIndex;
    vector<int>res(n+1,1);
    
    for(int i=2;i<n+1;i++)
    {
        for(int j=1;j<i;j++)
        res[i-j]=res[i-j]+res[i-j-1];
    }
    return res;
    }
};
// @lc code=end

