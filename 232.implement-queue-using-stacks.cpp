/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */
/*
basic o(n time complexity)
 o(2n time complexity)
step to this
push(x)

s1->s2 until s1 is empty

x->s1
s2->s1 until s2 is empty

*/
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class MyQueue {
    stack<int> input,output;
public:
    MyQueue(){

    }
    void push(int x) {
       input.push(x); 
    }
    
  int pop() {
      if(input.empty() && output.empty()){
          return -1;
      }
     int x =peek();
       output.pop();
    return x;
    }
    
    int peek() {
        if(output.empty())
        {
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 here push is have o(1 complexity)

 and pop is having 0(N complexity )

 top is having  o(n complexity) in some complexity

 so amortised complexity o(1)
 
 class MyQueue {
    stack<int> input,output;
public:
    MyQueue(){

    }
    void push(int x) {
       input.push(x); 
    }
    
  int pop() {
      if(input.empty() && output.empty()){
          return -1;
      }
     int x =peek();
       output.pop();
    return x;
    }
    
    int peek() {
        if(output.empty())
        {
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};




 */
// @lc code=end

