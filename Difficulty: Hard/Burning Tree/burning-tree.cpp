/* Structure of binary tree Node
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
    void childToParent(Node *root, unordered_map<Node*, Node*> &mp, Node *prev, int target, Node* &targetNode){
        if(root==NULL){
            return;
        }
        
        if(root->data == target){
            targetNode = root;
        }
        
        mp[root] = prev;
        prev = root;
        
        childToParent(root->left, mp, prev, target, targetNode);
        childToParent(root->right, mp, prev, target, targetNode);
        
    }
    int minTime(Node* root, int target) {
        // code here
        // <childe, parent>
        unordered_map<Node*, Node*> mp;
        Node *targetNode = NULL;
        childToParent(root, mp, NULL, target, targetNode);
        
        
        
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        
        int timeToBurn=0;
        while(!q.empty()){
            
            bool isNewToBurn = false;
            int size = q.size();
            for(int i=0; i<size; i++){
                Node *temp = q.front();
                q.pop();
                
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left] = true;
                    isNewToBurn = true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right] = true;
                    isNewToBurn = true;
                }
                if(mp[temp] && !visited[mp[temp]]){
                    q.push(mp[temp]);
                    visited[mp[temp]] = true;
                    isNewToBurn = true;
                }
            }
            
            if(isNewToBurn){
                timeToBurn++;
            }
        }
        
        return timeToBurn;
    }
};