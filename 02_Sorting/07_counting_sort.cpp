class Solution {
  public:
    void countSort(vector<int>& arr) {
        if (arr.empty()) {
            return;
        }

        int minimum = arr[0];
        int maximum = arr[0];
        for (int value : arr) {
            minimum = min(minimum, value);
            maximum = max(maximum, value);
        }

        long long range = static_cast<long long>(maximum) - minimum + 1;
        vector<int> frequency(static_cast<size_t>(range), 0);
        for (int value : arr) {
            frequency[static_cast<size_t>(static_cast<long long>(value) - minimum)]++;
        }

        int index = 0;
        for (long long offset = 0; offset < range; offset++) {
            while (frequency[static_cast<size_t>(offset)] > 0) {
                arr[index++] = static_cast<int>(offset + minimum);
                frequency[static_cast<size_t>(offset)]--;
            }
        }
    }
};