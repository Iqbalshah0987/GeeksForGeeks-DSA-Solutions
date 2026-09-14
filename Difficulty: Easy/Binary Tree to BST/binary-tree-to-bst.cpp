/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void inorder(Node *root, vector<int> &ans){
        if(root == NULL) return;

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    
    void constructBST(Node *root, vector<int> &in, int &index){
        if(root == NULL){
            return;
        }
        
        constructBST(root->left, in, index);
        root->data = in[index++];
        constructBST(root->right, in, index);
    }
    
    Node *binaryTreeToBST(Node *root) {
        // code here
        vector<int> in;
        inorder(root, in);
        
        sort(in.begin(), in.end());
        
        int index=0;
        constructBST(root, in, index);
        
        return root;
    }
};