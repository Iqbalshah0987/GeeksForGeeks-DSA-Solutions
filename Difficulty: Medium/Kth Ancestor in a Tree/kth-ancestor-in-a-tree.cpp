/* Definition for Node
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
    bool solve(Node *root, int node, vector<int> &paths){
        if(root==NULL){
            return false;
        }

        paths.push_back(root->data);
        
        if(root->data==node){
            return true;
        }

        if (solve(root->left, node, paths) ||
            solve(root->right, node, paths)){
            return true;
        }

        paths.pop_back();
        return false;
    }
    int kthAncestor(Node *root, int k, int node) {
        // code here
        vector<int> paths;
        
        if(!solve(root, node, paths)){
            return -1;
        }
        
        int index = paths.size()-k-1;
        
        if(index<0){
            return -1;
        }

        return paths[index];
    }
};
