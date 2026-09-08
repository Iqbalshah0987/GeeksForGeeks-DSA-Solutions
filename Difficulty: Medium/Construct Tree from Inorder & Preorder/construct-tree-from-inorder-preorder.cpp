/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    Node *solve(unordered_map<int, int> &mp, vector<int> &preorder, int &preIndex, int left, int right){
        if(left > right) return NULL;
        
        int rootVal = preorder[preIndex];
        preIndex++;
        
        Node *root = new Node(rootVal);
        
        int index = mp[rootVal];
        
        root->left = solve(mp, preorder, preIndex, left, index-1);
        root->right = solve(mp, preorder, preIndex, index+1, right);
        
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n = inorder.size();
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        
        int preIndex=0;
        return solve(mp, preorder, preIndex, 0, n-1);
    }
};