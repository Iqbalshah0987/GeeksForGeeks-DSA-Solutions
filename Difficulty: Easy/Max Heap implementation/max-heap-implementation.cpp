class maxHeap {
  private:
    // Initialize your data members
    vector<int> arr;
    
    void heapify(vector<int> &arr, int n, int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i+1;
        
        if(left<n && arr[largest]<arr[left]){
            largest = left;
        }
        if(right<n && arr[largest]<arr[right]){
            largest = right;
        }
        
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    
  public:

    void push(int x) {
        // Insert x into the heap
        arr.push_back(x);
        
        int n = arr.size();
        for(int i=n/2; i>=0; i--){
            heapify(arr, n, i);
        }
    }

    void pop() {
        // Remove the top (maximum) element
        if(arr.size()==0){
            return;
        }
        
        int n = arr.size();
        arr[0] = arr[n-1];
        arr.pop_back();
        n = arr.size();
        
        for(int i=n/2; i>=0; i--){
            heapify(arr, n, i);
        }
    }

    int peek() {
        // Return the top element or -1 if empty
        
        if(arr.size()==0){
            return -1;
        }
        
        return arr[0];
    }

    int size() {
        // Return the number of elements in the heap
        return arr.size();
    }
};