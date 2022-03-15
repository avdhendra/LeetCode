/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;
map<int, string> m = {
{1000000000, "Billion"}, {1000000,"Million"}, {1000, "Thousand"}, {100, "Hundred"}, 

{90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {10, "Ten"}, 
    
{19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, 
      
{9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}, {0, "Zero"}
};

class Solution {
public:
    string numberToWords(int num) {
         //if num < 20 then return the value of num in map;
        if(num<=20){
            return m[num];
        }
        
        string pre = "", suf ="";
        //remove the upper _bound value of the number in map (suppose number is 412 then remove it upper value(1000) index it give only (100) value index)
        auto it = m.upper_bound(num);
        it--;
        // after got the perfect index check these method (suppose number is 412 then (it->first = 100)) 
        //it follow the first condition in first we got 412/100 = 4 and check 4 string in map and (pre = four).. 
        if(it->first>=100)
            pre = numberToWords(num/it->first) + " ";
        // after then we just find the remender value string in map 412%100 = 12 and it return (suf = Twelve) 
        if(num%it->first!=0)
            suf = " " + numberToWords(num%it->first);
        // after got pre and suf return it with it ->second -  pre+" "+(it->second)+" "+suf = four hundred twelve....
        return pre+(it->second)+suf;
    }
};
// @lc code=end

