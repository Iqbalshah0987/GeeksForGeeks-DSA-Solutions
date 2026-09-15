/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int countNodes(Node *root) {
            // code here
        Node *curr = root;
        int count=0;
        while(curr != NULL){

            if(curr->left == NULL){
                // print element
                count++;

                curr = curr->right;
            }else{
                // find inorder predecessor in curr
                Node *pre = curr->left;
                while(pre!=NULL && pre->right!=NULL && pre->right!=curr){
                    pre = pre->right;
                }

                if(pre->right == NULL){
                    pre->right = curr;
                    curr = curr->left;
                }else{
                    // print element
                    count++;

                    pre->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return count;
    }
    bool isCBT(Node *root, int index, int &totalNodes){
        if(root==NULL){
            return true;
        }
        
        if(index >= totalNodes){
            return false;
        }else{
            bool left = isCBT(root->left, 2*index+1, totalNodes);
            bool right = isCBT(root->right, 2*index+2, totalNodes);
            
            return left && right;
        }
    }
    bool isMaxOrder(Node *root){
        if(root == NULL) return true;
        
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        
        if(root->right == NULL){
            return root->data > root->left->data;
        }
        
        return root->data > root->left->data &&
               root->data > root->right->data &&
               isMaxOrder(root->left) &&
               isMaxOrder(root->right);
    }
    bool isHeap(Node* root) {
        // code here
        int index=0;
        int totalNodes = countNodes(root);
        
        if(isCBT(root, index, totalNodes) && isMaxOrder(root)){
            return true;
        }
        
        return false;
    }
};