/*
    Time Complexity : O(N * log(N))
    Space Complexity : O(N)

    Where N is the size of the input heap
 */

public class Solution {

	private static void heapify(long[] arr, int currentIndex, int n) {
		int leftChildIndex = 2 * currentIndex + 1;
		int rightChildIndex = 2 * currentIndex + 2;
		int largestIndex = currentIndex;

		// Find the largest element among current node and its children.
		if (leftChildIndex < n && arr[leftChildIndex] > arr[currentIndex]) {
			largestIndex = leftChildIndex;
		}
		if (rightChildIndex < n && arr[rightChildIndex] > arr[largestIndex]) {
			largestIndex = rightChildIndex;
		}

		// In case the current node is not the largest, swap the current and smallest
		// node.
		// Make a recursive call to the child which was the smallest after swapping.
		if (largestIndex != currentIndex) {
			// Swapping the value at current index and the largestIndex
			long temp = arr[currentIndex];
			arr[currentIndex] = arr[largestIndex];
			arr[largestIndex] = temp;

			// Making a recusrive call to the largest index.
			heapify(arr, largestIndex, n);
		}
	}

	private static void buildHeap(long[] arr, int n) {
		int nonLeafIndex = n / 2 - 1;
		while (nonLeafIndex >= 0) {
			heapify(arr, nonLeafIndex, n);
			nonLeafIndex--;
		}
	}

	// Converting the min heap to max heap
	public static void minHeapToMaxHeap(long[] arr, int n) {
		// Heapify all nodes from the bottom right
		long[] maxHeap = new long[n];

		for (int i = 0; i < n; i++) {
			maxHeap[i] = arr[i];
			buildHeap(maxHeap, i + 1);
		}

		for (int i = 0; i < n; ++i) {
			arr[i] = maxHeap[i];
		}

	}

}

/*
    Time Complexity - O(N)
    Space complexity - O(logN)
    where N is the size of the input array/list.
*/
public class Solution {

    // Converting the min heap to max heap
    public static void minHeapToMaxHeap(long[] arr) {
        // Heapifying all nodes from the bottom right
        for (int i = (arr.length) / 2; i >= 0; i--) {
            heapify(arr, i);
        }
    }

    private static void heapify(long[] arr, int currentIndex) {
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;
        int largestIndex = currentIndex;

        // Find the largest element among current node and its children.
        if (leftChildIndex < arr.length && arr[leftChildIndex] > arr[currentIndex])
            largestIndex = leftChildIndex;
        if (rightChildIndex < arr.length && arr[rightChildIndex] > arr[largestIndex])
            largestIndex = rightChildIndex;

        // In case the current node is not the largest, swap the current and smallest node.
        // Make a recursive call to the child which was the smallest after swapping.
        if (largestIndex != currentIndex) {
            // Swapping the value at current index and the largestIndex
            long temp = arr[currentIndex];
            arr[currentIndex] = arr[largestIndex];
            arr[largestIndex] = temp;

            // Making a recusrive call to the largest index.
            heapify(arr, largestIndex);
        }
    }


}