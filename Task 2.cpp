#include <iostream>
using namespace std;

int main() {
    const int row = 4;
    const int col = 4;
    int arr[row][col] = { {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}};
    int transArray[row][col];

    cout << "Sum of rows: " << endl;
    for (int i = 0; i < row; i++) {
        int rowSum = 0; 
        for (int j = 0; j < col; j++) {
            rowSum += arr[i][j];
        }
        cout << "Row " << i + 1 << ": " << rowSum << endl;
    }

    cout << "Sum of columns: " << endl;
    for (int j = 0; j < col; j++) {
        int colSum = 0;  
        for (int i = 0; i < row; i++) {
            colSum += arr[i][j];
        }
        cout << "Column " << j + 1 << ": " << colSum << endl;
    }

    cout << "Transposing the matrix: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transArray[i][j] = arr[j][i];
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << transArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
