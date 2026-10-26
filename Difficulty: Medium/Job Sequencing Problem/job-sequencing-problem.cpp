class Solution {
  public:
    vector<int> solve1(vector<int> &deadline, vector<int> &profit){
        
        int n = profit.size();
        vector<pair<int, int>> jobs;
        for(int i=0; i<n; i++){
            jobs.push_back({profit[i], deadline[i]});
        }
        
        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());
        
        int totalProfit=0, jobCount=0;
        
        vector<int> slots(n, 0);
        for(int i=0; i<n; i++){
            
            int startTime = min(n, jobs[i].second);
            for(int j=startTime-1; j>=0; j--){
                
                if(slots[j] == 0){
                    slots[j] = 1;
                    jobCount++;
                    totalProfit += jobs[i].first;
                    break;
                }
            }
        }
        
        return {jobCount, totalProfit};
    }
    
    vector<int> solve2(vector<int> &deadline, vector<int> &profit){
        
        int n = profit.size();
        vector<pair<int, int>> jobs;
        for(int i=0; i<n; i++){
            jobs.push_back({deadline[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<n; i++){
            
            if(jobs[i].first > pq.size()){
                pq.push(jobs[i].second);
            }else if(!pq.empty() && pq.top() < jobs[i].second){
                pq.pop();
                pq.push(jobs[i].second);
            }
        }
        
        int totalProfit=0, jobCount=0;
        while(!pq.empty()){
            totalProfit += pq.top();
            pq.pop();
            jobCount++;
        }
        
        return {jobCount, totalProfit};
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        
        // deadline means, you can execute job in between any time of 1 to deadline[i],
        // this means we can execute in any slot and 
        // slots are 0 to n-1;
        
    //   return solve1(deadline, profit);
    
       return solve2(deadline, profit);
    }
};