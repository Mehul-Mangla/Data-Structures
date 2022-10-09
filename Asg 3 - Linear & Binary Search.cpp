/*
NAME - MEHUL MANGLA
SID - 21105043
BRANCH - ECE
*/

#include <iostream>
using namespace std;

// LINEAR SEARCH
int linear_search(int arr[], int x)
{

    for (int i = 0;; i++) // no condition on the traversing index
                          // i.e. loop will not stop until element is found
    {
        if (arr[i] == x)
        {
            return i;
            break; // if element is found then, return the index and break out of the loop
        }
    }
}

// BINARY SEARCH
int normal_binary_search(int arr[], int l, int r, int x)
// normal binary search code which will be used
// once we get the right index from binary_prerequisite function
{
    int start, mid, end;
    start = l;
    end = r;
    if (start > end)
    {
        return -1;
    }
    else
    {
        mid = ((start + end) / 2);

        if (x == arr[mid])
        {
            return mid;
        }
        else if (x < arr[mid])
        {
            end = mid - 1;
            normal_binary_search(arr, 0, mid - 1, x);
            // repeat the process for array to the left of mid
        }
        else if (x > arr[mid])
        {
            start = mid + 1;
            normal_binary_search(arr, mid + 1, r, x);
            // repeat the process for array to the right of mid
        }
    }
}
int binary_prerequisite(int arr[], int x)
{
    if (arr[0] == x)
    {
        return 0;
        // if element is present at the 0th index, then return 0
    }
    else
    {
        int i = 1; // we start from the 1st index and
        // check if element to be found is greater than element present at that index
        while (x > arr[i])
        {
            i *= 2; // we try to increase our range as well as reduce the time complexity
        }
        return normal_binary_search(arr, 0, i, x);
        // since elements are sorted in the array, if x<= arr[i], we stop the loop
        // as the element is surely present to the left of index i and
        // call normal_binary_search on the part of array to the left of index i
    }
}
int main()
{
    int *arr = new int[1000]; // declaring an array of random size using starting index of array
    int n;
    cin >> n; // asking size just to take input array

    for (int i = 0; i < n; i++) // running for loop to input elements into an array
    {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the element you want to search: "; // asking user for element to be searched
    cin >> x;

    cout << "Index of Element using Linear Search : " << linear_search(arr, x) << "\n";
    cout << "Index of Element using Binary Search : " << binary_prerequisite(arr, x) << "\n";

    delete[] arr; // clearing the memory
}