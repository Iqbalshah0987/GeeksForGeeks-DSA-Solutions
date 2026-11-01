class Node{
    public:
        int data;
        int firstIndex;
        Node* left;
        Node* right;
        
        Node(int d, int i){
            data = d;
            firstIndex = i;
            left = NULL;
            right = NULL;
        }
};
class cmp{
    public:
        bool operator()(Node *a, Node *b){
            if(a->data == b->data){
                return a->firstIndex > b->firstIndex;
            }
            return a->data > b->data;
        }
};

class Solution {
  public:
    void preOrderTraversal(Node *root, vector<string> &ans, string temp){
        
        if(root == NULL) return;
        
        // check leaf node
        if(root->left==NULL && root->right==NULL){
            ans.push_back(temp.empty()? "0": temp);
            return;
        }
        
        preOrderTraversal(root->left, ans, temp+'0');
        preOrderTraversal(root->right, ans, temp+'1');
    }
    vector<string> huffmanCodes(string &s, vector<int> f) {
        // code here
        
        priority_queue<Node*, vector<Node*>, cmp> pq;
        for(int i=0; i<f.size(); i++){
            Node *temp = new Node(f[i], i);
            pq.push(temp);
        }
        
        
        while(!pq.empty() && pq.size()>1){
            Node *left = pq.top();
            pq.pop();
            Node *right = pq.top();
            pq.pop();
            
            Node *newnode = new Node(left->data + right->data, min(left->firstIndex, right->firstIndex));
            newnode->left = left;
            newnode->right = right;
            pq.push(newnode);
        }
        
        
        Node *root = pq.top();
        vector<string> ans;
        string temp="";
        preOrderTraversal(root, ans, temp);
        
        return ans;
    }
};