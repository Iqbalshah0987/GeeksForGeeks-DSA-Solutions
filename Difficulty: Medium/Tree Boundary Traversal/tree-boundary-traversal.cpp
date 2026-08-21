/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
    bool isLeaf(Node *root){
        return root->left==NULL && root->right==NULL;
    }
    void leftBoundary(Node *root, vector<int> &ans){
        if(root == NULL || isLeaf(root)) return;
        
        ans.push_back(root->data);
        
        if(root->left) leftBoundary(root->left, ans);
        else leftBoundary(root->right, ans);
    }
    void rightBoundary(Node *root, vector<int> &ans){
        if(root == NULL || isLeaf(root)) return;
        
        if(root->right) rightBoundary(root->right, ans);
        else rightBoundary(root->left, ans);
        
        ans.push_back(root->data);
    }
    void leafBoundary(Node *root, vector<int> &ans){
        if(root==NULL) return;
        
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        
        leafBoundary(root->left, ans);
        leafBoundary(root->right, ans);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        
        if(root==NULL) return ans;
        
        ans.push_back(root->data);
        
        leftBoundary(root->left, ans);
        leafBoundary(root->left, ans);
        leafBoundary(root->right, ans);
        rightBoundary(root->right, ans);
        
        return ans;
    }
}; 