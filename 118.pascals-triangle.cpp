/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows); /*We now create a vector of vector with size
                                            equal to row.*/
        for(int i=0;i<numRows;i++){
            r[i].resize(i+1); //resize the number of rows
            r[i][0]=r[i][i]=1;
         for(int j=1;j<i;j++){
          r[i][j]=r[i-1][j-1]+r[i-1][j];
         } 
              
        }     
        return r;                
    }
};
// @lc code=end

