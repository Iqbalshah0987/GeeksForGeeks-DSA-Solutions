class Node
{
  public:
    Node *child[2];
    bool isEnd;

    Node()
    {
        child[0] = child[1] = nullptr;
        isEnd = false;
    }
};
class Solution {
  public:
    vector<vector<int>> uniqueRow(vector<vector<int>>& mat) {
        // code here
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>> result;
        Node *root = new Node();
        
        for(int i=0; i<row; i++){
            
            Node *curr = root;
            for(int j=0; j<col; j++){
                
                int bit = mat[i][j];
                
                if(curr->child[bit] == nullptr){
                    curr->child[bit] = new Node();
                }
                
                curr = curr->child[bit];
            }
            
            if(!curr->isEnd){
                curr->isEnd = true;
                result.push_back(mat[i]);
            }
        }
        
        return result;
    }
};