/*
NAME - MEHUL MANGLA
SID - 21105043
BRANCH - ECE
*/

#include <iostream>
using namespace std;

// TIME COMPLEXITY OF BUBBLE SORT - O(n^2).
pair<int, int> bubbleSort(int *input, int size)
{
    int num_swaps = 0;       // to count the no. of swaps
    int num_comparisons = 0; // to count the no. of comparisons
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1 - j; i++)
        {
            if (input[i] > input[i + 1])
            {
                int temp = input[i];
                input[i] = input[i + 1];
                input[i + 1] = temp;
                num_swaps++;
            }
            num_comparisons++;
        }
    }
    pair<int, int> ans;
    ans.first = num_comparisons; // first will store the umber of comparisons.
    ans.second = num_swaps;      // second will store the number of swaps.
    return ans;
}

// TIME COMPLEXITY OF SELECTION SORT - O(n^2).
pair<int, int> selectionSort(int *input, int size)
{
    int min_index;
    int num_swaps = 0;
    int num_comparisons = 0;
    for (int i = 0; i < size; i++)
    {
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (input[j] < input[min_index])
            {
                min_index = j;
                num_swaps++;
            }
            num_comparisons++;
        }
        int temp = input[i];
        input[i] = input[min_index];
        input[min_index] = temp;
    }
    pair<int, int> ans;
    ans.first = num_comparisons; // first will store the umber of comparisons.
    ans.second = num_swaps;      // second will store the number of swaps.
    return ans;
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    pair<int, int> bubble = bubbleSort(arr, n);
    pair<int, int> selection = selectionSort(arr, n);

    cout << "Comparison b/w Selection and Bubble Sort. " << endl;
    cout << endl;

    //

    cout << "1. On the basis of number of comparisons : "
         << " ";
    if (bubble.second > selection.second)
    {
        cout << "More comparisons are required for Bubble Sort." << endl;
    }
    else if (bubble.second < selection.second)
    {
        cout << "More comparisons are required for Selection Sort." << endl;
    }
    else
    {
        cout << "Both require equal number of comparisons." << endl;
    }
    cout << endl;

    //

    cout << "2. On the basis of number of swaps : "
         << " ";
    if (bubble.first > selection.first)
    {
        cout << "More swaps are required for Bubble Sort." << endl;
    }
    else if (bubble.first < selection.first)
    {
        cout << "More swaps are required for Selection Sort." << endl;
    }
    else
    {
        cout << "Both require equal number of swaps." << endl;
    }
    cout << endl;

    cout << "3 . Since BubbleSort and SelectionSort both are In-place algorithms, their In-place Algorithms have been written above." << endl;
}
