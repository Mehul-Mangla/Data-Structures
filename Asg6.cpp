/*
NAME - MEHUL MANGLA
SID - 21105043
BRANCH - ECE
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

template <typename T>

// Creating a Class of Binary Tree
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

// Converting a sorted array to a binary search tree
BinaryTreeNode<int> *createBST(int arr[], int si, int ei) // si = starting index, ei = ending index
{
    if (si > ei)
    {
        return NULL;
    }
    int mid = (si + ei) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);

    root->left = createBST(arr, si, mid - 1);
    root->right = createBST(arr, mid + 1, ei);
    return root;
}

// Checking the Binary Search Tree

int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL) // Empty Set
    {
        return INT32_MAX; // If a set is empty then the smallest number can be only be INT MAX
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL) // Empty Set
    {
        return INT32_MIN; // If a set is empty then the largest number can be only be INT MIN
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root) // will return a bool value after checking the maximum and minimum conditions
{
    if (root == NULL)
    {
        return true;
    }

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}

BinaryTreeNode<int> *minValueNode(BinaryTreeNode<int> *node)
{
    BinaryTreeNode<int> *current = node;

    // Loop to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

BinaryTreeNode<int> *deleteNode(BinaryTreeNode<int> *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL)
        {
            BinaryTreeNode<int> *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            BinaryTreeNode<int> *temp = root->left;
            free(root);
            return temp;
        }
        BinaryTreeNode<int> *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to delete an element from an array
void del_from_arr(int arr[], int n, int k)
{
    // Search element(k) in array
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == k)
            break;

    // If k is found in array
    if (i < n)
    {
        // reduce size of array by 1 and move all elements, ahead of k, back by 1 position
        n = n - 1;
        for (int j = i; j < n; j++)
            arr[j] = arr[j + 1];
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++) // Creating an array
    {
        cin >> arr[i];
    }

    sort(arr, arr + n); // Sorting the array.

    BinaryTreeNode<int> *root = createBST(arr, 0, n - 1);
    cout << isBST(root) << endl;

    int data;
    cin >> data;
    root = deleteNode(root, data); // new node after deletion;
}

/*
--Space complexity of a BST = O(n)
--Space complexity of an array = O(n)
--A binary tree has the benefits of both an ordered/ sorted array
  as search is as quick as in a sorted array and insertion or deletion operations are also as fast
*/
