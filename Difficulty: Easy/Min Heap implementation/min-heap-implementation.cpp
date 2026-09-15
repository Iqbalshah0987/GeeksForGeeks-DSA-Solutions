class minHeap {
  private:
    // Initialize your data members
    vector<int> arr;

    void heapify(vector<int> &arr, int n, int i){
        int smallest = i;
        int left = 2*i;
        int right = 2*i+1;

        if(left<n && arr[smallest]>arr[left]){
            smallest = left;
        }
        if(right<n && arr[smallest]>arr[right]){
            smallest = right;
        }

        if(smallest != i){
            swap(arr[smallest], arr[i]);
            heapify(arr, n, smallest);
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
        // Remove the top (minimum) element
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