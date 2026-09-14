/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

class Solution {
  public:
    info solve(Node *root, int &maxsize){
        if(root == NULL){
            return {INT_MIN, INT_MAX, true, 0};
        }
        
        info left = solve(root->left, maxsize);
        info right = solve(root->right, maxsize);
        
        info curr;
        curr.size = left.size + right.size + 1;
        curr.maxi = max(root->data, right.maxi);
        curr.mini = min(root->data, left.mini);
        
        if(left.isBST && right.isBST && (left.maxi<root->data && root->data<right.mini)){
            curr.isBST = true;
        }else{
            curr.isBST = false;
        }
        
        if(curr.isBST){
            maxsize = max(maxsize, curr.size);
        }
        
        return curr;
    }
    int largestBst(Node *root) {
        // code here
        int maxsize=0;
        solve(root, maxsize);
        return maxsize;
    }
};