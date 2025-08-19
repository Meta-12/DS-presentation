#include <iostream>
using namespace std;

int main()
{
    system("cls");

    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // -----------------step 1-----------
    int pivot = arr[n - 1];
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        // find ascending
        if (pivot > arr[i])
        {
            index++;
            swap(arr[i], arr[index]);
        }
    }
    index++;
    swap(arr[index], arr[n - 1]);

    // ---------step 2 -------------
    // -----------------------partition on left side
    int j = -1;
    int leftHight = index - 1;
    pivot = arr[leftHight];

    for (int i = 0; i < leftHight; i++)
    {
        if (pivot > arr[i])
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    j++;
    swap(arr[j], arr[leftHight]);

    //---------------------------- partition on right side
    int rightLow = index + 1;
    pivot = arr[n - 1];
    int k = rightLow - 1;

    for (int i = rightLow; i < n - 1; i++)
    {
        if (arr[i] < pivot)
        {
            k++;
            swap(arr[i], arr[k]);
        }
    }
    k++;
    swap(arr[k], arr[n - 1]);

    // display result
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
