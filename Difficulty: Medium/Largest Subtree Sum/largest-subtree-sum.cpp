/* structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    int solve(Node *root, int &ans){
        if(root == NULL){
            return 0;
        }
        
        int leftsum = solve(root->left, ans);
        int rightsum = solve(root->right, ans);
        
        int curr = root->data + leftsum + rightsum;
        
        ans = max(ans, curr);
        
        return curr;
    }
    int maxSubtreeSum(Node* root) {
        // code here
        int ans = INT_MIN;
        solve(root, ans);
        
        return ans==INT_MIN ?0 :ans;
    }
};
