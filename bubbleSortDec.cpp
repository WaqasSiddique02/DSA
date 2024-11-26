#include <iostream>
using namespace std;

int main()
{
    const int size = 6;
    int arr[size] = {5, 3, 1, 2, 4, 6};
    int temp = 0;
    bool swap = false;

    for (int j = size - 1; j >= 0; j--)
    {
        swap = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i + 1] > arr[i])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap = true;
            }
        }

        if (!swap)
        {
            break;
        }
    }

    cout << "Sorted array in descending order: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
