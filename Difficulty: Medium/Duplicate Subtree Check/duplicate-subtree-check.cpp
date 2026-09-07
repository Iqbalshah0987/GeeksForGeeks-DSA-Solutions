/* Structure of a Tree Node
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
    string dupsubrec(Node *root, unordered_map<string, int> &mp){
        if(root==NULL){
            return "N";
        }
        
        if(root->left==NULL && root->right==NULL){
            return to_string(root->data);
        }
        
        string left = dupsubrec(root->left, mp);
        string right = dupsubrec(root->right, mp);
        
        string curr = to_string(root->data) + "*" + left + "*" + right;
        
        mp[curr]++;
        
        return curr;
    }
    bool dupSub(Node* root) {
        // code here
        unordered_map<string, int> mp;
        dupsubrec(root, mp);
        
        for(auto it: mp){
            if(it.second>1){
                return true;
            }
        }
        
        return false;
    }
};