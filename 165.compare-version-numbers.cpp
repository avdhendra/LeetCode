/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0,ver1=version1.size(),ver2=version2.size(),n1,n2;
        while(i<ver1||j<ver2){
            n1=0;
            n2=0;
            while(i<ver1 && version1[i]!='.'){
                n1=n1*10+(version1[i]-'0');
                i++;
            }
            while(j<ver2 && version2[j]!='.'){
                n2=n2*10+(version2[j]-'0');
                j++;
            }
            if(n1<n2) return -1;
            else if(n1>n2) return 1;
i++;j++;

        }
        return 0;
    }
};
// @lc code=end

