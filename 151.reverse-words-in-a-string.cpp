/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
     string result;
     int i=0;
     int n=s.length();
     while(i<n){
         while(i<n && s[i] ==' ')i++;
         if(i>=n) break;
         int j=i+1;
          while(j<n && s[j]!=' ') j++;
          string sub=s.substr(i,j-i);
          if(result.length()==0) result=sub;
          else result=sub+' '+result;
          i=j+1;

     }
     return result;
    }
};
// @lc code=end

