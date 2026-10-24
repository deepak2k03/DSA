class Solution {
    void sortNonNegative(vector<long long>& values) {
        long long maximum = 0;
        for (long long value : values) {
            maximum = max(maximum, value);
        }

        for (long long place = 1; maximum / place > 0; place *= 10) {
            vector<int> count(10, 0);
            vector<long long> output(values.size());

            for (long long value : values) {
                count[static_cast<int>((value / place) % 10)]++;
            }
            for (int digit = 1; digit < 10; digit++) {
                count[digit] += count[digit - 1];
            }
            for (int i = static_cast<int>(values.size()) - 1; i >= 0; i--) {
                int digit = static_cast<int>((values[i] / place) % 10);
                output[--count[digit]] = values[i];
            }

            values.swap(output);
        }
    }

  public:
    void radixSort(vector<int>& arr) {
        vector<long long> negative;
        vector<long long> nonNegative;

        for (int value : arr) {
            if (value < 0) {
                negative.push_back(-static_cast<long long>(value));
            } else {
                nonNegative.push_back(value);
            }
        }

        sortNonNegative(negative);
        sortNonNegative(nonNegative);

        int index = 0;
        for (int i = static_cast<int>(negative.size()) - 1; i >= 0; i--) {
            arr[index++] = static_cast<int>(-negative[i]);
        }
        for (long long value : nonNegative) {
            arr[index++] = static_cast<int>(value);
        }
    }
};