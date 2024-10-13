#include <iostream>
#include <vector>
using namespace std;

// Ham thuc hien phep bien doi Arnold's Cat Map
void ArnoldTransform(vector<vector<int>>& matrix, int m) {
    vector<vector<int>> temp = matrix;
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            int newX = (2 * i + j) % m;
            int newY = (i + j) % m;
            matrix[newX][newY] = temp[i][j];
        }
    }
}

// Ham kiem tra xem ma tran hien tai co bang ma tran ban dau hay khong
bool isInitialState(const vector<vector<int>>& matrix, const vector<vector<int>>& initialMatrix) {
    int m = matrix.size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] != initialMatrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int m;
    cout << "Nhap kich thuoc ma tran (m): ";
    cin >> m;

    vector<vector<int>> matrix(m, vector<int>(m));
    vector<vector<int>> initialMatrix(m, vector<int>(m));

    cout << "Nhap ma tran:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            initialMatrix[i][j] = matrix[i][j];
        }
    }

    int k = 0;

    // Thuc hien phep bien doi va dem so lan cho den khi ma tran tro ve trang thai ban dau
    do {
        ArnoldTransform(matrix, m);
        ++k;
    } while (!isInitialState(matrix, initialMatrix));

    cout << "He so chu ky k: " << k << endl;

    return 0;
}
