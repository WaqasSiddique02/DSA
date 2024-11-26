#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
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
    cout << "Sorted numbers in ascending order: ";
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
    return 0;
}