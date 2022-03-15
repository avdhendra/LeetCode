/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars) {
         int n = chars.size();
        int i = 0;
        int index = 0;
        
        while(i < n){
            int j = i + 1;
            
            while(j<n && chars[i]==chars[j])
                j++;
            
            chars[index++] = chars[i];
            int count = j - i;
            
            if(count > 1){
                string str = to_string(count);
                for(char ch : str)
                    chars[index++] = ch;
            }
            i = j;
        }
        return index;   
    }
};
// @lc code=end

