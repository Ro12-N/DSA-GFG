/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
public:

bool isSubTreeEqual(Node *root1, Node *root2) {
    if(!root1 && !root2) {
        return true;
    }
    if(!root1 || !root2 || root1->data != root2->data) {
        return false;
    }
    
    return isSubTreeEqual(root1->left, root2->left) && isSubTreeEqual(root1->right, root2->right);
}

bool isSubTree(Node *root1, Node *root2) {
    if(!root1) {
        return false;
    }
    if(root1->data == root2->data && isSubTreeEqual(root1, root2)) {
        return true;
    }

    return isSubTree(root1->left, root2) || isSubTree(root1->right, root2);
}

};
// Time Complexity: O(N*M) where N is the number of nodes in the first tree and M is the number of nodes in the second tree.
// Space Complexity: O(H) where H is the height of the first tree. In the worst case, the space complexity can be O(N) if the first tree is skewed.