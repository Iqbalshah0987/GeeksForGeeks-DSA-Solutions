/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    void inorderTraversal(Node *root, int level, map<int, vector<int>> &mp){
        if(root == NULL) return;
        
        mp[level].push_back(root->data);
        
        inorderTraversal(root->left, level+1, mp);
        inorderTraversal(root->right, level, mp);
    }
    vector<int> diagonal(Node *root) {
        // code here
        map<int, vector<int>> mp;
        inorderTraversal(root, 1, mp);
        
        vector<int> ans;
        for(auto it: mp){
            vector<int> temp = it.second;
            for(int num: temp){
                ans.push_back(num);
            }
        }
        
        return ans;
    }
};