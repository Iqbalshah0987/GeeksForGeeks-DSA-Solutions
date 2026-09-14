/* Binary Tree Node Structure
class Node {
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
    void inorder(Node *root, vector<int> &ans){
        if(root == NULL) return;
        
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    bool findTarget(Node *root, int target) {
        // code here.
        vector<int> ans;
        inorder(root, ans);
        
        int low=0, high=ans.size()-1;
        while(low<high){
            int sum = ans[low]+ans[high];
            
            if(sum == target){
                return true;
            }else if(sum > target){
                high--;
            }else{
                low++;
            }
        }
        
        return false;
    }
};