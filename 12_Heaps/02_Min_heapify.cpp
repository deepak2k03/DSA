/*
    Time Complexity  : O(N) 
    Space Complexity: O(log(N))

    where 'N' is the number of elements in the array.
*/

// Recursive function to heapify ith node
void heapify(vector<int> &arr, int n, int i)
{
    // Defining the pointer the index of node having smallest value among node and its children
    int smallestNode = i;

    // Finding left and right child of current node
    int left = 2 * i + 1, right = 2 * i + 2;

    // Checking if left child is smaller than the current node
    if (left < n && arr[left] < arr[smallestNode])
    {
        smallestNode = left;
    }

    // Checking if right child is smaller than the current node
    if (right < n && arr[right] < arr[smallestNode])
    {
        smallestNode = right;
    }

    // Checking if the current node has the smallest value
    if (smallestNode != i)
    {
        swap(arr[smallestNode], arr[i]);
        heapify(arr, n, smallestNode);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();

    // Finding the firt non - leaf node from right
    int firstNonLeaf = (n / 2) - 1;

    // Heapifying every non-leaf node
    for (int i = firstNonLeaf; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    return arr;
}
