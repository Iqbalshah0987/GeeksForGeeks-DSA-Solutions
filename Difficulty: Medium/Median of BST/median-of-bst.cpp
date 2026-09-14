/* Binary Tree Node Structure
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
    int countNodes(Node *root){
        int nodes=0;
        Node *curr = root;
        
        while(curr != NULL){
            if(curr->left == NULL){
                nodes++;
                curr = curr->right;
            }else{
                // inorder predecessor
                Node *pre = curr->left;
                while(pre!=NULL && pre->right!=NULL && pre->right!=curr){
                    pre = pre->right;
                }
                
                if(pre->right == NULL){
                    pre->right = curr;
                    curr = curr->left;
                }else{
                    nodes++;
                    
                    pre->right = NULL;
                    curr = curr->right;
                }
            }
        }
        
        return nodes;
    }
    
    int kthSmallest(Node *root, int k) {
        Node *curr = root;

        while(curr != NULL){

            if(curr->left == NULL){
                // print element
                k--;
                if(k==0) return curr->data;

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
                    k--;
                    if(k==0) return curr->data;

                    pre->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return -1;
    }
    
    int findMedian(Node* root) {
        // Code here
        int n = countNodes(root);
        int medianIndex=0;
        
        if(n%2==0){
            medianIndex = n/2;
        }else{
            medianIndex = (n+1)/2;
        }
        
        return kthSmallest(root, medianIndex);
    }
};