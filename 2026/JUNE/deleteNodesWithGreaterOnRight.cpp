/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *compute(Node *head) {
        // code here
        stack<Node*> s;
        
        while(head != nullptr) {
            if(s.empty() || head->data < s.top()->data) {
                if(!s.empty()) {
                    s.top()->next = head;   
                }
                s.push(head);
            } else {
                while(!s.empty() && head->data > s.top()->data) {
                    s.pop();
                }
                if(!s.empty()) {
                    s.top()->next = head;   
                }
                s.push(head);
            }
            head = head->next;
        }
        
        Node* ans = nullptr;
        while(!s.empty()) {
            ans = s.top();
            s.pop();
        }
        
        return ans;
    }
};


// Time Complexity: O(N) where N is the number of nodes in the linked list. We traverse the linked list once and each node is pushed and popped from the stack at most once.
// Space Complexity: O(N) in the worst case when the linked list is strictly decreasing, all nodes will be pushed onto the stack. In the best case when the linked list is strictly increasing, the space complexity will be O(1) as only one node will be on the stack at any time.