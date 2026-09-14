/* Structure of a Binary Search Tree node
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
}; */

class Solution {
  public:
    void inorder(Node *root, vector<int> &ans){
        if(root == NULL) return;

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    // Node *inorderToBST(vector<int> &in, int start, int end){
    //     if(start > end){
    //         return NULL;
    //     }

    //     int mid = (start+end)/2;
    //     Node *root = new Node(in[mid]);

    //     root->left = inorderToBST(in, start, mid-1);
    //     root->right = inorderToBST(in, mid+1, end);

    //     return root;
    // }
    vector<int> mergeArrays(vector<int> &arr1, vector<int> &arr2){
        int i=0, j=0;
        vector<int> ans;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i] < arr2[j]){
                ans.push_back(arr1[i++]);
            }else{
                ans.push_back(arr2[j++]);
            }
        }
        
        while(i<arr1.size()){
            ans.push_back(arr1[i++]);
        }
        while(j<arr2.size()){
            ans.push_back(arr2[j++]);
        }
        
        return ans;
    }
    vector<int> merge(Node *r1, Node *r2) {
        // code here
        vector<int> arr1, arr2;
        inorder(r1, arr1);
        inorder(r2, arr2);
        
        vector<int> mergeArray = mergeArrays(arr1, arr2);
        
        // return inorderToBST(mergeArray, 0, mergeArray.size());
        
        return mergeArray;
    }
};