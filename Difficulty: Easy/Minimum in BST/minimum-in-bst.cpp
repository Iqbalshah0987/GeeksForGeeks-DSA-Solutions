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
    int minValue(Node* root) {
        // code here
        if(root == NULL) return -1;
        
        if(root->left == NULL) return root->data;
        
        return minValue(root->left);
    }
};