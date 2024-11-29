#include <iostream>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        
        if (arr[mid] < target)
            left = mid + 1;
        
        if (arr[mid] > target)
            right = mid - 1;
    }

    return -1;
}

int recursiveBinarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        
        if (arr[mid] > target)
            return recursiveBinarySearch(arr, left, mid - 1, target);
        
        return recursiveBinarySearch(arr, mid + 1, right, target);
    }

    return -1;
}

int main() {
    std::cout << __cplusplus << "\n";
    int arr[] = {2, 3, 4, 10, 40, 50, 60, 70};
    int size = std::size(arr);
    int target = 10;

    std::cout << "Iterative Binary Search:\n";
    int result = binarySearch(arr, size, target);
    if (result == -1)
        std::cout << "Element " << target << " not found in array\n";
    else
        std::cout << "Element " << target << " found at index " << result << "\n";
    
    std::cout << "\nRecursive Binary Search:\n";
    result = recursiveBinarySearch(arr, 0, size-1, target);
    if (result == -1)
        std::cout << "Element " << target << " not found in array\n";
    else
        std::cout << "Element " << target << " found at index " << result << "\n";
    
    target = 30;
    std::cout << "\nSearching for " << target << ":\n";
    result = binarySearch(arr, size, target);
    if (result == -1)
        std::cout << "Element " << target << " not found in array\n";
    else
        std::cout << "Element " << target << " found in array at index " << result << "\n";
    
    return 0;
}