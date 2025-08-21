#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int partition(int arr[], int low, int hight)
{
    int pivot = arr[hight];
    int j = low - 1;

    for (int i = low; i < hight; i++)
    {
        if (arr[i] <= pivot)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    j++;
    swap(arr[j], arr[hight]);

    return j;
}
void quickSort(int arr[], int low, int hight)
{

    if (low < hight)
    {
        // partition index
        int pi = partition(arr, low, hight);

        // partition left
        quickSort(arr, low, pi - 1);

        // partition rigth
        quickSort(arr, pi + 1, hight);
    }
}
int main()
{
    int arr[] = {10, 20, 50, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before Sort : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // quick sort function
    quickSort(arr, 0, n - 1);

    cout << "Array after Sort : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}