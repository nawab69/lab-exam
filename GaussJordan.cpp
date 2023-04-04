#include <iostream>
#include <vector>

using namespace std;

void print_matrix(vector<vector<double>> &matrix) {
    for (const auto &row : matrix) {
        for (const auto &element : row) {
            cout << element << "\t";
        }
        cout << endl;
    }
}

void gauss_jordan_elimination(vector<vector<double>> &matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        if (matrix[i][i] == 0) {
            cerr << "Error: Diagonal element can't be zero" << endl;
            return;
        }

        for (int j = 0; j < n; j++) {
            if (i != j) {
                double factor = matrix[j][i] / matrix[i][i];

                for (int k = i; k <= n; k++) {
                    matrix[j][k] -= factor * matrix[i][k];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        double factor = matrix[i][i];
        for (int j = 0; j <= n; j++) {
            matrix[i][j] /= factor;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n + 1));

    cout << "Enter the augmented matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> matrix[i][j];
        }
    }

    gauss_jordan_elimination(matrix);

    cout << "Solution:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << matrix[i][n] << endl;
    }

    return 0;
}
