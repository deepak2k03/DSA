vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
    int n = a.size();

    // min-heap to keep track of the top k maximum pair sums
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // generate all possible pair sums from a[i] + b[j]
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int currSum = a[i] + b[j];

            // the heap has less than k elements, add the current sum
            if ((int)minHeap.size() < k) {
                minHeap.push(currSum);
            }
            // current sum is greater than the smallest in heap, replace it
            else if (currSum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(currSum);
            }
        }
    }

    // extract elements from the heap and store in result
    vector<int> res;
    while (!minHeap.empty()) {
        res.push_back(minHeap.top());
        minHeap.pop();
    }

    // convert to descending order as required
    reverse(res.begin(), res.end());
    return res;
}

