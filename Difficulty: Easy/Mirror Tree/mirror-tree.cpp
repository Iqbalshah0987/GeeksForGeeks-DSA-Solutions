/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    void mirror(Node* root) {
        // code here
        
        if(!root) return;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node *temp = q.front();
            q.pop();
            
            swap(temp->left, temp->right);
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            
        }
    }
};