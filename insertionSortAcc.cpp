#include <iostream>
using namespace std;
int main()
{
    int n = 7;
    int key, j = 0;
    int A[7];
    cout << "\nEnter 7 values.\n";
    for (int a = 0; a < n; a++)
        cin >> A[a];
    for (int i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
    cout << "\n\t\t=== Sorted Values in Ascending order ===\n";
    for (int x = 0; x < n; x++)
        cout << "\t" << A[x];
    return 0;
}