/* Binary Tree Node Structure
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
};
*/

class Solution {
  public:
    void inorder(Node *root, vector<int> &in){
        if(root==NULL){
            return;
        }
        
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
    void postOrder(Node *root, vector<int> &in, int &index){
        if(root==NULL) return;
        
        if(index >= in.size()){
            return;
        }
        
        postOrder(root->left, in, index);
        postOrder(root->right, in, index);
        
        root->data = in[index++];
    }
    void convertToMaxHeap(Node* root) {
        // code here
        vector<int> in;
        inorder(root, in);
        
        int index=0;
        postOrder(root, in, index);
    }
};
