class Solution {
  public:
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        return a.second < b.second;
    }
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        
        int n = start.size();
        
        vector<pair<int, int>> meetingsTime;
        for(int i=0; i<n; i++){
            meetingsTime.push_back({start[i], finish[i]});
        }
        
        sort(meetingsTime.begin(), meetingsTime.end(), comp);
        
        int count=1;
        int endTime = meetingsTime[0].second;
        
        for(int i=1; i<n; i++){
            
            if(endTime < meetingsTime[i].first){
                count++;
                endTime = meetingsTime[i].second;
            }
        }
        
        return count;
    }
};