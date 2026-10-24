class Solution {
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int smaller = low;

        for (int i = low; i < high; i++) {
            if (arr[i] <= pivot) {
                swap(arr[i], arr[smaller]);
                smaller++;
            }
        }

        swap(arr[smaller], arr[high]);
        return smaller;
    }

  public:
    void quickSort(vector<int>& arr, int low, int high) {
        while (low < high) {
            int pivotIndex = partition(arr, low, high);

            // Recurse into the smaller partition to keep stack usage bounded.
            if (pivotIndex - low < high - pivotIndex) {
                quickSort(arr, low, pivotIndex - 1);
                low = pivotIndex + 1;
            } else {
                quickSort(arr, pivotIndex + 1, high);
                high = pivotIndex - 1;
            }
        }
    }
};