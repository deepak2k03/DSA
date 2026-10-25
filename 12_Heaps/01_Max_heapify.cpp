class Solution {
  public:
  
    void heapify(vector<int>&arr, int n, int i)
    {
        // Initialize largest as root
        int largest = i; 
        int l = 2 * i + 1; 
        int r = 2 * i + 2; 

        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }
    
    void buildHeap(vector<int>& arr) {
        // code here
        int n=arr.size();
            // Index of last non-leaf node

            int startIdx = (n / 2) - 1;

            // Perform reverse level order traversal
            // from last non-leaf node and heapify
            // each node
            for (int i = startIdx; i >= 0; i--) {
                heapify(arr, n, i);
            }
    }
};