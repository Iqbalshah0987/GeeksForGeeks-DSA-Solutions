/* Structure of a Tree Node
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* solve(vector<int> &pre, int &i, int min, int max){
        if(i>=pre.size()){
            return NULL;
        }
        
        if(min > pre[i] || pre[i] > max){
            return NULL;
        }
        
        Node *root = new Node(pre[i++]);
        root->left = solve(pre, i, min, root->data);
        root->right = solve(pre, i, root->data, max);
        
        return root;
    }
    Node* preToBST(vector<int>& pre) {
        // code here
        int min = INT_MIN, max = INT_MAX, i=0;
        return solve(pre, i, min, max);
    }
};