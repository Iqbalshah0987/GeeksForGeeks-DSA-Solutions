/* BST Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    void inorder(Node *root, vector<int> &ans){
        if(root == NULL) return;

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    Node *inorderToBST(vector<int> &in, int start, int end){
        if(start > end){
            return NULL;
        }
        
        int mid = (start+end)/2;
        Node *root = new Node(in[mid]);
        
        root->left = inorderToBST(in, start, mid-1);
        root->right = inorderToBST(in, mid+1, end);
        
        return root;
    }
    Node* balanceBST(Node* root) {
        // Code here
        vector<int> in;
        inorder(root, in);
        
        return inorderToBST(in, 0, in.size()-1);
    }
};