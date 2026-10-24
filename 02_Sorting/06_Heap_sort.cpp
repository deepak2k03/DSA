class Solution {
    void heapify(vector<int>& arr, int heapSize, int root) {
        int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;

        if (left < heapSize && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < heapSize && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != root) {
            swap(arr[root], arr[largest]);
            heapify(arr, heapSize, largest);
        }
    }

  public:
    void heapSort(vector<int>& arr) {
        int n = static_cast<int>(arr.size());

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        for (int end = n - 1; end > 0; end--) {
            swap(arr[0], arr[end]);
            heapify(arr, end, 0);
        }
    }
};