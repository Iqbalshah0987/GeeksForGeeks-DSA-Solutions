/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void solve(Node *root, int level, int sum, int &longLevel, int &maxSum){
        if(root == NULL){
            if(longLevel < level){
                longLevel = level;
                maxSum = sum;
            }else if(longLevel == level){
                maxSum = max(maxSum, sum);
            }
            return;
        }
        
        sum += root->data;
        solve(root->left, level+1, sum, longLevel, maxSum);
        solve(root->right, level+1, sum, longLevel, maxSum);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int level=0, longLevel=0, sum=0, maxSum=0;
        solve(root, level, sum, longLevel, maxSum);
        
        return maxSum;
    }
};