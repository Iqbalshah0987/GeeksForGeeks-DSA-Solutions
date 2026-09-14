/* Structure of a Binary Search Tree node
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
    void inorder(Node *root, Node *&prev){
        if(root == NULL) return;
        
        inorder(root->left, prev);
        
        prev->left=NULL;
        prev->right = root;
        prev = root;
        
        inorder(root->right, prev);
    }
    Node *flattenBST(Node *root) {
        // code here
        Node *dummy = new Node(-1);
        Node *prev=dummy;
        
        inorder(root, prev);
        
        prev->left = NULL;
        prev->right = NULL;
        
        Node *newNode = dummy->right;
        delete dummy;
        return newNode;
    }
};