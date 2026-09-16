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
    vector<int> findSmallestRange(vector<vector<int>>& mat) {
        // Code here
        int mini=INT_MAX, maxi=INT_MIN;
        priority_queue<node*, vector<node*>, compare> minHeap;

        int k = mat.size();
        int n = mat[0].size();
        
        for(int i=0; i<k; i++){
            int element = mat[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);

            node *temp = new node(element, i, 0);
            minHeap.push(temp);
        }

        int start=mini, end=maxi;
        // step 2:
        while(!minHeap.empty()){
            node *top = minHeap.top();
            minHeap.pop();

            mini = top->data;

            if(maxi-mini < end-start){
              start = mini;
              end = maxi;
            }

            if(top->col + 1 < n){
              maxi = max(maxi, mat[top->row][top->col+1]);
              node *temp = new node(mat[top->row][top->col+1], top->row, top->col+1);
              minHeap.push(temp);
            }else{
              break;
            }

        }
        
        return {start, end};
    }
};