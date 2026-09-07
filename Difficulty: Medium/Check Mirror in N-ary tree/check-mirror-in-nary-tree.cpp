class Solution {
  public:
    bool checkMirrorTree(int e, vector<int>& t1, vector<int>& t2) {
        // code here
        
        unordered_map<int, stack<int>> mp;
        for(int i=0; i<e; i++){
            mp[t1[2*i]].push(t1[(2*i)+1]);
        }
        
        
        for(int i=0; i<e; i++){
            int parent = t2[2*i];
            int child = t2[(2*i)+1];
            
            if(mp.find(parent)==mp.end() || mp[parent].empty()){
                return false;
            }
            
            if(mp[parent].top() != child){
                return 0;
            }
            
            mp[parent].pop();
        }
        
        return 1;
    }
};