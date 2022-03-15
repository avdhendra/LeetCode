/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        helper(answer,0,0,n,"");
        return answer;
    }
    void helper(vector<string>&ans,int open,int close,int n,string curr_str){
        if(curr_str.size()==2*n){
            ans.push_back(curr_str);
            return;
        }
        if(open<n){
            helper(ans,open+1,close,n,curr_str+"(");
        }
        if(close<open){
            helper(ans,open,close+1,n,curr_str+")");
        }
    }
};
// @lc code=end

