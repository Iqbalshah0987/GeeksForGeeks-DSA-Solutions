/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    void solve(Node *root, int key, Node* &predecessor, Node* &successor){
        if(root == NULL){
            return;
        }
        
        if(root->data < key && (predecessor==NULL || predecessor->data < root->data)){
            predecessor = root;
        }
        if(root->data > key && (successor==NULL || successor->data > root->data)){
            successor = root;
        }
        
        solve(root->left, key, predecessor, successor   );
        solve(root->right, key, predecessor, successor);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node *predecessor=NULL, *successor=NULL;
        solve(root, key, predecessor, successor);
        
        return {predecessor, successor};
    }
};