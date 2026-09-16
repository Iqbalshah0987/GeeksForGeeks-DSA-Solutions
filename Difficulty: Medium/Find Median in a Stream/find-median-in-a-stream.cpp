class Solution {
  public:
    int signum(int a, int b){
      if(a==b)
        return 0;
      else if(a>b)
        return 1;
      else
        return -1;
    }
    void callMedian(double element, priority_queue<double> &maxheap, priority_queue<double, vector<double>, greater<double>> &minheap, double &median){
      
      switch(signum(maxheap.size(), minheap.size()) ){
        case 0: if(element > median){
                  minheap.push(element);
                  median = minheap.top();
                }else{
                  maxheap.push(element);
                  median = maxheap.top();
                }
            break;
        case 1: if(element > median){
                  minheap.push(element);
                  median = (minheap.top()+maxheap.top())/2;
                }else{
                  minheap.push(maxheap.top());
                  maxheap.pop();
                  maxheap.push(element);
                  median = (minheap.top()+maxheap.top())/2;
                }
            break;
        case -1: if(element > median){
                  maxheap.push(minheap.top());
                  minheap.pop();
                  minheap.push(element);
                  median = (minheap.top()+maxheap.top())/2;
                }else{
                  maxheap.push(element);
                  median = (minheap.top()+maxheap.top())/2;
                }
            break;
      }
    }


    vector<double> getMedian(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<double> ans;

        priority_queue<double> maxheap;
        priority_queue<double, vector<double>, greater<double>> minheap;
        double median = -1.0;

        for(int i=0; i<n; i++){
          callMedian((double)arr[i], maxheap, minheap, median);
          ans.push_back(median);
        }

        return ans;
    }
};
