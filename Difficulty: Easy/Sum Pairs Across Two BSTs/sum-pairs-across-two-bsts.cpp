/* Binary Tree Node Structure
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
    void inorder(Node *root, vector<int> &ans){
        if(root == NULL) return;

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    int countPairs(Node* root1, Node* root2, int x) {
        // code here
        vector<int> arr1, arr2;
        inorder(root1, arr1);
        inorder(root2, arr2);
        
        unordered_map<int, int> freq;
        for(int num: arr1){
            freq[num]++;
        }
        
        int ans =0;
        for(int i=0; i<arr2.size(); i++){
            int required = x-arr2[i];
            
            if(freq.find(required) != freq.end()){
                ans += freq[required];
            }
        }
        
        return ans;
    }
};