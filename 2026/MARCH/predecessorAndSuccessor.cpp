/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
       
        Node* p = NULL; // predecessor
        Node* s = NULL; // successor

            while(root){
                if(root->data > key){
                    s = root;
                    root = root->left;
                }
                else if(root->data < key){
                    p = root;
                    root = root->right;
                }
                else{
                    Node* temp = root->left;
                    while(temp){
                        p = temp;
                        temp = temp->right;
                    }
            
                    temp = root->right;
                    while(temp){
                        s = temp;
                        temp = temp->left;
                    }
                    break;
                }
            }
            return {p, s};
    }
};
// Time Complexity: O(H) where H is the height of the tree, as we traverse down the tree to find the key and its predecessor and successor.
// Space Complexity: O(1) as we are using only a constant amount of extra space for the predecessor and successor pointers.