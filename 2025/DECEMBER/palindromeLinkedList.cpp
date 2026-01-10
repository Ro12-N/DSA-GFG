/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        //  code here
        if(!head||!head->next) return true;
        Node*s=head;
        Node*f=head;
        while(f &&f->next){
            s=s->next;
            f=f->next->next;
        }
        Node*prev=NULL;
        Node*curr=s;
        while(curr){
            Node* nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        while(prev){
            if(prev->data!=head->data) return false;
            prev=prev->next;
            head=head->next;
        }
        return true;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)