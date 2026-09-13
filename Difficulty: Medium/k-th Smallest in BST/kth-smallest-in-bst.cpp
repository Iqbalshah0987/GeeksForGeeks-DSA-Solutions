/*
Definition for Node
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
    int solve(Node *root, int &k){
        if(root == NULL){
            return -1;
        }
        
        int left = solve(root->left, k);
        if(left != -1){
            return left;
        }
        
        k--;
        if(k==0){
            return root->data;
        }
        
        return solve(root->right, k);
    }
    int kthSmallest(Node *root, int k) {
        // code here
        return solve(root, k);
    }
};