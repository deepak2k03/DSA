class Solution {
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> merged;
        merged.reserve(right - left + 1);

        int i = left;
        int j = mid + 1;
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                merged.push_back(arr[i++]);
            } else {
                merged.push_back(arr[j++]);
            }
        }

        while (i <= mid) {
            merged.push_back(arr[i++]);
        }
        while (j <= right) {
            merged.push_back(arr[j++]);
        }

        for (int k = 0; k < static_cast<int>(merged.size()); k++) {
            arr[left + k] = merged[k];
        }
    }

  public:
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            sortRange(arr, left, right);
        }
    }

  private:
    void sortRange(vector<int>& arr, int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;
        sortRange(arr, left, mid);
        sortRange(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
};