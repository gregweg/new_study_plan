#include <iostream>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];
    
    // merge arrays back into arr[left...right]
    int i = 0;          // Index of first subarray
    int j = 0;          // Index of second subararay
    int k = left;       // Index of merged array

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of leftArray if any
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // copy remaining elemtents of rightArray if any
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    // free allocated memory
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = std::size(arr);

    std::cout << "Original array: ";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    std::cout << "Sorted array: ";
    printArray(arr, arr_size);

    return 0;   
}