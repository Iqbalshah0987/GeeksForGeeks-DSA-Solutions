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
    string dupsubrec(Node *root, unordered_map<string, int> &mp, vector<Node*> &ans){
        if(root==NULL){
            return "N";
        }

        string left = dupsubrec(root->left, mp, ans);
        string right = dupsubrec(root->right, mp, ans);

        string curr = to_string(root->data) + "*" + left + "*" + right;

        mp[curr]++;
        
        if(mp[curr] == 2){
            ans.push_back(root);
        }

        return curr;
    }
    vector<Node*> printAllDups(Node* root) {
        // Code here
        unordered_map<string, int> mp;
        vector<Node*> ans;
        
        dupsubrec(root, mp, ans);
        
        return ans;
    }
};