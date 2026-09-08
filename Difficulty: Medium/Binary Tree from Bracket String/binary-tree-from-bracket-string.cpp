/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
    Node *preorder(string &s, int &i){
        if(s[i]==')') return NULL;
        
        int val = 0;
        while(i<s.size() && s[i]!='(' && s[i]!=')'){
            val *= 10;
            val += s[i]-'0';
            i++;
        }
        
        Node *root = new Node(val);
        
        if(i<s.size() && s[i]=='('){
            i++;
            root->left = preorder(s, i);
            i++;
        }
        
        if(i<s.size() && s[i]=='('){
            i++;
            root->right = preorder(s, i);
            i++;
        }
        
        return root;
    }
    Node *treeFromString(string &s) {
        // code here
        int i=0;
        return preorder(s, i);
    }
};