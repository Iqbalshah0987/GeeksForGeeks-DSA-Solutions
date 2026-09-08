/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
    void inorder(Node *root, Node* &head, Node* &prev){
        if(root == NULL) return;
        
        inorder(root->left, head, prev);
        
        if(head==NULL){
            head = root;
        }
        if(prev){
            prev->right = root;
            root->left  = prev;
        }
        prev = root;
        
        inorder(root->right, head, prev);
    }
    Node* treeToDLL(Node* root) {
        // code here
        Node *head = NULL;
        Node *prev = NULL;
        
        inorder(root, head, prev);
        
        return head;
    }
};