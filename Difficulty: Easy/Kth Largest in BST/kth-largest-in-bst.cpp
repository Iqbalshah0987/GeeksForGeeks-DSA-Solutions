/* Structure of a Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int solve(Node *root, int &k){
        if(root == NULL){
            return -1;
        }
        
        int right = solve(root->right, k);
        if(right != -1){
            return right;
        }
        
        k--;
        if(k==0){
            return root->data;
        }
        
        return solve(root->left, k);
    }
    int kthLargest(Node *root, int k) {
        // code here
        return solve(root, k);
    }
};