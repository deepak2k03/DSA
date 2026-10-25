bool isMaxHeap(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Parent must be >= left child
        if (arr[i] < arr[left]) {
            return false;
        }

        // Check right child only if it exists
        if (right < n && arr[i] < arr[right]) {
            return false;
        }
    }

    return true;
}