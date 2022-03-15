/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*
Optimise approach
1. create copy node of all the node

and point the next node of all node to the copy of node

1 |next->1'(copy)|next->2

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node*current=head;
        //add Duplicate node in the same list
        while(current!=null){
            //New Node duplicate //1 step
            Node*temp=new Node(current->value); //copy the value of linked list
            temp->next=current->next;
            current->next=temp;
            current=current->next->next;
        }
        current=head;
        //random pointer linked 
        while(current!=null){
            current->next->random=current->random?current->random->next:current->random;
            current=current->next->next;
        }
        Node*original=head;
        Node*copy=head->next;
        Node*copyHead=copy;
        //segregate copy and original nodes
        while(original!=null && copy!=NULL){
            original->next=original->next->next;
            copy->next=copy->next?copy->next->next:copy->next;
            original=original->next;
            copy=copy->next;
        }
        return copyHead;
    }
};
// @lc code=end

