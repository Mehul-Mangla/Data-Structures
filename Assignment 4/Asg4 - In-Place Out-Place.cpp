/*
NAME - MEHUL MANGLA
SID - 21105043
BRANCH - ECE
*/

// Question 1

/*
We can say an in-place algorithm is an algorithm that does require any
extra space and produces an output in the same memory that
contains the data to be sorted by transforming the input ‘in-place’.
The space complexity of an "In-Place" sorting algorithm
lies between O(1) and O(logn) both included.

Where as an "Out-Place" sorting algorithm is algorithm that requires
some extra memory to produce an output.
The space complexity of an "Out-Place" algorithm is
generally greater than O(logn).
*/

// Question 2

// Insertion Sort Using In-Place Algorithm
#include <iostream>
using namespace std;

void in_place_insertion_sort(int arr[], int n)
{
    int p = 0, q = p + 1;

    while (q <= n - 1)
    {
        int temp = arr[q];
        while (p >= 0)
        {
            if (arr[p] > temp)
            {
                arr[p + 1] = arr[p];
                p--;
            }
            if (p == -1)
            {
                arr[0] = temp;
                break;
            }
            if (arr[p] <= temp)
            {
                arr[p + 1] = temp;
                break;
            }
        }
        q++;
        p = q - 1;
    }
    return;
}

// Insertion Sort Using Out-Place Algorithm
void out_place_insertion_sort(int arr[], int s, int e)
{
    // s = starting index
    // e = ending index
    if (s == e)
    {
        return;
    }
    int q = s + 1;
    int temp = arr[q];
    while (s >= 0)
    {
        if (arr[s] > temp)
        {
            arr[s + 1] = arr[s];
            s--;
        }
        if (s == -1)
        {
            arr[0] = temp;
            break;
        }
        if (arr[s] <= temp)
        {
            arr[s + 1] = temp;
            break;
        }
    }
    out_place_insertion_sort(arr, s + 1, e);
}

// Function to print array
void print_arr(int arr[], int n)
{
    for (int p = 0; p < n; p++)
    {
        cout << arr[p] << " ";
    }
}
int main()
{
    int n;
    // Taking input from user for number of elements
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[1000], arr2[1000];

    // Taking input from user of array elements
    cout << "Enter the elements: ";
    for (int p = 0; p < n; p++)
    {
        cin >> arr[p];
    }

    // Creating a duplicate copy
    for (int p = 0; p < n; p++)
    {
        arr2[p] = arr[p];
    }
    cout << endl;

    cout << "Before Sorting: " << endl;
    print_arr(arr, n);

    // In-Place Insertion Sort algorithm
    in_place_insertion_sort(arr, n);
    cout << "Using In-Place Insertion Sort: " << endl;
    print_arr(arr, n);
    cout << endl;

    // Out-Place Insertion Sort algorithm
    out_place_insertion_sort(arr2, 0, n - 1);
    cout << "Using Out-Place Insertion Sort: " << endl;
    print_arr(arr, n);
    cout << endl;
}

// Question 3

/*
In-place techniques have lesser space complexity but are difficult to
apply in algorithm whereas out-place techniques are easy to apply but
increases the space complexity of algorithm.

Eg. If we want to reverse an array, then its in-place algorithm
will swap the first and last element of the array until we reach the
middle of array.

If we want to solve the same problem using out-place
algorithm we need to create an extra array of the same size and copy all the
elements of original array to a new array like done in the question above.
This algorithm increases the space complexity to O(n) as we have created an
extra array.

IN-PLACE algorithm are used in Bubble sort, Selection Sort, Insertion Sort, Heapsort.
NOT IN-PLACE/ OUT-PLACE algorithm is used in Merge Sort, Because merge sort requires O(n) extra space
*/
