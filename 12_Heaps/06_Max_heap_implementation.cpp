
class maxHeap {
  private:
    vector<int> heap;

  public:

    void push(int x) {
        heap.push_back(x);

        int i = heap.size() - 1;

        // Heapify up
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (heap[parent] >= heap[i]) {
                break;
            }

            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    void pop() {
        if (heap.empty()) {
            return;
        }

        // Replace root with the last element
        heap[0] = heap.back();
        heap.pop_back();

        int n = heap.size();
        int i = 0;

        // Heapify down
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && heap[left] > heap[largest]) {
                largest = left;
            }

            if (right < n && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest == i) {
                break;
            }

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

    int peek() {
        if (heap.empty()) {
            return -1;
        }

        return heap[0];
    }

    int size() {
        return heap.size();
    }
};
