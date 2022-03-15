/*The Meeting Rooms II LeetCode Solution – 
“Meeting Rooms II” states that you are given an array of 
meeting time intervals “intervals” where 
“intervals[i] = [ start[i], end[i] ]”, return the minimum number 
of conference rooms required.*/
/*
Approach
Idea:
Maintain two sorted arrays, one of which stores the starting time of the meetings and the other one stores the ending time. Then use the two-pointer ( let’s call the iterator for start array ‘i’ and for end array ‘j’) method to iterate over the start array and end array. We will also maintain a variable “curr”, which will store the current number of simultaneous meetings going on as we will need that many conference rooms.

If start[i] < end[j], it means that the jth meeting is still going and we need another room for the ith meeting, this is why we will increase ‘curr’ by one and we will also increase ‘i’, as we have started the ith meeting.
If start[i] >= end[j], it means that the jth meeting is over and that room is free now, this is why we will decrease ‘curr’ by one and we will increase ‘j’, as the jth meeting has ended.

*/
#include<bits/stdc++.h>
using namespace std;
int minMeetingRooms(vector<vector<int>>&intervals){
    vector<int> start;
    vector<int>end;
    for(int i=0;i<intervals.size();i++){
        start.push_back(intervals[i][0]); //start value in interval
        end.push_back(intervals[i][1]); //end value in interval
    }
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    int i=1,j=0,curr=1;
    int ans=1;
    while(i<start.size() && j<end.size()){
        if(start[i]<end[j]){
            curr++;
            i++;
        }
        else{
            curr--;
            j++;
        }
        ans=max(ans,curr);
    }
    return ans;
}
int main(){

return 0;
}