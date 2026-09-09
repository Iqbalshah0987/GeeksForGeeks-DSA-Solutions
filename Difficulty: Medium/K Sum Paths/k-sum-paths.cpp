/* Structure of Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    void solve(Node *root, int k, vector<int> &paths, int &count){
        if(root==NULL){
            return;
        }
        
        paths.push_back(root->data);
        
        solve(root->left, k, paths, count);
        solve(root->right, k, paths, count);
        
        int n=paths.size();
        int sum=0;
        for(int i=n-1; i>=0; i--){
            sum += paths[i];
            
            if(sum==k){
                count++;
            }
        }
        
        paths.pop_back();
    }
    int countAllPaths(Node *root, int k) {
        // code here
        vector<int> paths;
        int count=0;
        solve(root, k, paths, count);
        
        return count;
    }
};