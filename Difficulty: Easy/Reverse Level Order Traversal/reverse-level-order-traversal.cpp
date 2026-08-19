/* Structure of Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right; 
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        
        stack<int> st;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node *temp = q.front();
            q.pop();
            
            st.push(temp->data);
            
            if(temp->right) q.push(temp->right);
            if(temp->left) q.push(temp->left);
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};