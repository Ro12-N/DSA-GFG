class Solution {
  public:
  
    class Node{
      public:
        int f;
        int idx;
        Node *left, *right;
        
        Node(int f, int idx){
            this->f = f;
            this->idx = idx;
            left = right = NULL;
        }
    };
    
    struct cmp{
        bool operator()(Node* a, Node* b){
            if(a->f == b->f)
                return a->idx > b->idx;
            return a->f > b->f;
        }
    };
    
    void dfs(Node* root, string s, vector<string> &ans){
        
        if(!root) return;
        
        if(!root->left && !root->right){
            ans.push_back(s);
            return;
        }
        
        dfs(root->left, s + "0", ans);
        dfs(root->right, s + "1", ans);
    }

    vector<string> huffmanCodes(string &s, vector<int> f) {
        
        priority_queue<Node*, vector<Node*>, cmp> pq;
        
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            pq.push(new Node(f[i], i));
        }
        
        if(n == 1) return {"0"};
        
        while(pq.size() > 1){
            
            Node* l = pq.top();
            pq.pop();
            
            Node* r = pq.top();
            pq.pop();
            
            Node* parent = new Node(l->f + r->f, min(l->idx, r->idx));
            parent->left = l;
            parent->right = r;
            
            pq.push(parent);
        }
        
        vector<string> ans;
        dfs(pq.top(), "", ans);
        
        return ans;
    }
};
// Time Complexity: O(nlogn) where n is the number of characters in the string.
// Space Complexity: O(n) where n is the number of characters in the string.
//topic : Huffman Encoding, priority queue, binary tree, depth first search.