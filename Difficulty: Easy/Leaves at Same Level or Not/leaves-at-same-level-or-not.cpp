/* Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool check(Node* root) {
        // code here
        queue<Node *> q;
        q.push(root);
        
        bool flag=false;
        while(!q.empty()){
            int n = q.size();
            
            for(int i=0; i<n; i++){
                Node *temp = q.front();
                q.pop();
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
                if(temp->left==NULL && temp->right==NULL){
                    flag=true;
                }
            }
            
            if(flag && !q.empty()){
                return false;
            }
        }
        
        return true;
    }
};