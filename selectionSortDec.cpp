#include <iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[max_index])
            {
                max_index = j;
            }
        }
        swap(arr[i], arr[max_index]);
    }
}

int main()
{
    const int size = 10;
    int numbers[size];
    cout << "Enter 10 numbers: ";
    for (int i = 0; i < size; i++)
    {
        cin >> numbers[i];
    }
    selectionSort(numbers, size);
    cout << "Sorted numbers in descending order: ";
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    return 0;
}