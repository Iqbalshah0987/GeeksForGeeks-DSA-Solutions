/*Structure of binary tree Node 
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
    pair<int, int> diameterRecur(Node *root){
        if(root==NULL) return {0, 0};
        
        pair<int, int> left = diameterRecur(root->left);
        pair<int, int> right = diameterRecur(root->right);
        
        int height = max(left.first, right.first) +1;
        int currdiameter = left.first + right.first;
        
        return {height, max({currdiameter, left.second, right.second})};
    }
    int diameter(Node* root) {
        // code here
        return diameterRecur(root).second;
    }
};