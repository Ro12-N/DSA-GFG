/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    vector<int> solve(Node* root){
        if(!root) return {INT_MAX,INT_MIN,0};
        auto l=solve(root->left);
        auto r=solve(root->right);
        if(l[1]<root->data && root->data<r[0]){
            return {min(root->data,l[0]),max(root->data,r[1]),l[2]+r[2]+1};
            
        }
        
        return {INT_MIN,INT_MAX,max(l[2],r[2])};
    }
    int largestBst(Node *root) {
        // Your code here
        return solve(root)[2];
    }
};
// Time Complexity: O(N) where N is the number of nodes in the tree, as we visit each node once.
// Space Complexity: O(H) where H is the height of the tree, due to the recursion stack. In the worst case (skewed tree), H can be O(N).