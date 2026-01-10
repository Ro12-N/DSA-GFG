/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
       if(!head1||!head2) return NULL;
       Node*a=head1;
       Node*b=head2;
       while(a!=b){
         a=(a==NULL)?head2:a->next;
         b=(b==NULL)?head1:b->next;
       }
       return a;
    }
};
// Time Complexity: O(N+M)
// Space Complexity: O(1)