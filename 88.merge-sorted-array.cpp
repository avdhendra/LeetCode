/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
int nextGap(int gap){
if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i,j,gap=n+m;
        for(gap=nextGap(gap/2);gap>0;gap=nextGap(gap/2)){

            for(i=0;i+gap<n;i++){
                if(nums1[i]>nums1[i+gap]){
                    swap(nums1[i],nums1[i+gap]);
                }

            }
            for(j=gap>n?gap-n:0;i<n && j<m;i++,j++){
                if(nums1[i]>nums2[j]){
                    swap(nums1[i],nums2[j]);
            }
        }
        if(j<m){
            for(j=0;j+gap<m;j++)
            {
                if(nums2[j]>nums2[j+gap]){
                    swap(nums2[j],nums2[j+gap]);
                }
            }
        }
    }
}
};
// @lc code=end

/*
#include <iostream>
#include <algorithm>
using namespace std;
 
// Utility function to print contents of an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
// Function to in-place merge two sorted arrays X[] and Y[]
// invariant: `X[]` and `Y[]` are sorted at any point
void merge(int X[], int Y[], int m, int n)
{
    // Consider each element `X[i]` of array `X` and ignore the element if it is
    // already in the correct order; otherwise, swap it with the next smaller
    // element, which happens to be the first element of `Y`.
    for (int i = 0; i < m; i++)
    {
        // compare the current element of `X[]` with the first element of `Y[]`
        if (X[i] > Y[0])
        {
            swap(X[i], Y[0]);
            int first = Y[0];
 
            // move `Y[0]` to its correct position to maintain the sorted
            // order of `Y[]`. Note: `Y[1…n-1]` is already sorted
            int k;
            for (k = 1; k < n && Y[k] < first; k++) {
                Y[k - 1] = Y[k];
            }
 
            Y[k - 1] = first;
        }
    }
}
 
int main()
{
    int X[] = { 1, 4, 7, 8, 10 };
    int Y[] = { 2, 3, 9 };
 
    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);
 
    merge(X, Y, m, n);
 
    cout << "X: "; printArray(X, m);
    cout << "Y: "; printArray(Y, n);
 
    return 0;
}




*/