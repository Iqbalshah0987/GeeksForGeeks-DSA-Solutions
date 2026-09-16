/* Linked List Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};
*/

class compare{
    public:
        bool operator()(Node *a, Node *b){
            return a->data > b->data;
        }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        
        priority_queue<Node*, vector<Node*>, compare> minHeap;

        // step 1: insert all link list first element in minheap
        int n = arr.size();
        for(int i=0; i<n; i++){
            minHeap.push(arr[i]);
            arr[i] = arr[i]->next;
        }
        
        Node *dummy = new Node(-1);
        Node *tail = dummy;
        // step 2:
        while(!minHeap.empty()){
            Node *temp = minHeap.top();
            minHeap.pop();
    
            tail->next = temp;
            tail = tail->next;
    
            if(temp->next){
                minHeap.push(temp->next);
            }
    
        }
    
        return dummy->next;
    }
};