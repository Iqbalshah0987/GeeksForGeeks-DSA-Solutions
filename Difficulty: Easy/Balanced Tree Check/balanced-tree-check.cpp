/* Structure of binary tree node
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
    pair<int, bool> isBalancedRec(Node *root){
        if(root == NULL) return {-1, true};
        
        pair<int, bool> left = isBalancedRec(root->left);
        pair<int, bool> right = isBalancedRec(root->right);
        
        int height = max(left.first, right.first)+1;
        bool isBalance = left.second && right.second && abs(left.first-right.first) <=1;
        
        return {height, isBalance};
    }
    bool isBalanced(Node* root) {
        // code here
        return isBalancedRec(root).second;
    }
};