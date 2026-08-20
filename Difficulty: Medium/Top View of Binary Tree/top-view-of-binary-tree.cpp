/*
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
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        
        if(root==NULL) return ans;
        
        // <hd, data> hd = horizontal distance, node value
        map<int, int> mp;
        // <hd, node> hd = horizontal distance
        queue<pair<int, Node*>> q;
        q.push({0, root});
        
        while(!q.empty()){
            pair<int, Node*> p = q.front();
            q.pop();
            int hd = p.first;
            Node *temp = p.second;
            
            if(mp.find(hd) == mp.end()){
                mp[hd] = temp->data;
            }
            
            if(temp->left) q.push({hd-1, temp->left});
            if(temp->right) q.push({hd+1, temp->right});
        }
        
        for(auto it: mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};