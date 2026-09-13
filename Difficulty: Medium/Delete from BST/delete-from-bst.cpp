/* Structure of a Binary Search Tree node
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
}; */

class Solution {
  public:
    int minValue(Node *root){
        while(root!=NULL && root->left != NULL){
            root = root->left;
        }
        return root->data;
    }
    Node* delNode(Node* root, int x) {
        // code here
        if(root==NULL){
            return root;
        }
        
        if(root->data == x){
            // 0 child
            if(root->left == NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            
            // 1 child
            // when only right child exist
            if(root->left==NULL && root->right!=NULL){
                Node *temp = root->right;
                delete root;
                return temp;
            }
            // when only left child exist
            if(root->left!=NULL && root->right==NULL){
                Node *temp = root->left;
                delete root;
                return temp;
            }
            
            // 2 child
            if(root->left!=NULL && root->right!=NULL){
                int min = minValue(root->right);
                root->data = min;
                root->right = delNode(root->right, min);
                return root;
            }
        }else if(root->data > x){
            root->left = delNode(root->left, x);
            return root;
        }else{
            root->right = delNode(root->right, x);
            return root;
        }
    }
};