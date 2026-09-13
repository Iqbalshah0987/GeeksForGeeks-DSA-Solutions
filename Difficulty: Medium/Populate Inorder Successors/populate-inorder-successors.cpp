/* Binary Tree Node Structure
class Node {
    public:
    int data;
     Node *left;
     Node *right;
     Node *next;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void solve(Node *root, Node *&next){
        if(root == NULL){
            return;
        }
        
        solve(root->right, next);
        
        root->next = next;
        next = root;
        
        solve(root->left, next);
    }
    void populateNext(Node *root) {
        // code here
        // tranverse reverse inorder;
        Node *next=NULL;
        solve(root, next);
    }
};