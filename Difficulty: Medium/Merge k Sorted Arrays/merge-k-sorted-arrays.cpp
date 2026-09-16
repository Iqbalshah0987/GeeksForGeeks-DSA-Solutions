class node{
    public: 
        int data; int row; int col;
    
        node(int data, int row, int col){
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

class compare{
    public:
        bool operator()(node *a, node *b){
            return a->data > b->data;
        }
};

class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        priority_queue<node*, vector<node*>, compare> minHeap;
        
        // step 1: insert all arrays first element in heap
        int n = mat.size();
        for(int i=0; i<n; i++){
            node *temp = new node(mat[i][0], i, 0);
            minHeap.push(temp);
        }
        
        vector<int> ans;
        // step 2:
        while(!minHeap.empty()){
            node *temp = minHeap.top();
            minHeap.pop();
            
            ans.push_back(temp->data);
            
            int row = temp->row;
            int col = temp->col;
            
            if(col+1 < mat[row].size()){
                node *next = new node(mat[row][col+1], row, col+1);
                minHeap.push(next);
            }
            
        }
        
        return ans;
    }
};