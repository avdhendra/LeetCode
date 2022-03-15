/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        //Create a maximum to left vector
        int maxleft=height[0];
        vector<int>maxtoleft(n);
        maxtoleft[0]=maxleft; //starting block is max itself
        for (int i=1;i<n;i++){
            maxtoleft[i]=max(maxleft,height[i]);
            if(height[i]>maxleft)maxleft=height[i];
        }
        //creating a maximum to right vector
        int maxright=height[n-1];
        vector<int>maxtoright(n);
        maxtoright[n-1]=maxright;
        for(int i=n-2;i>=0;i--){
            maxtoright[i]=max(maxright,height[i]);
            if(height[i]>maxright) {
                maxright=height[i];
            }
        }
        int result=0;
        for(int i=0;i<n;i++){
            result+=min(maxtoleft[i],maxtoright[i])-height[i];
        }
        return result;
    }
};
// @lc code=end

