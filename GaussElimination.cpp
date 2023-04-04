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

void gauss_elimination(vector<vector<double>> &matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        if (matrix[i][i] == 0) {
            cerr << "Error: Diagonal element can't be zero" << endl;
            return;
        }

        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];

            for (int k = i; k <= n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
}

vector<double> back_substitution(vector<vector<double>> &matrix) {
    int n = matrix.size();
    vector<double> x(n);

    for (int i = n - 1; i >= 0; i--) {
        x[i] = matrix[i][n];

        for (int j = i + 1; j < n; j++) {
            x[i] -= matrix[i][j] * x[j];
        }

        x[i] /= matrix[i][i];
    }

    return x;
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

    gauss_elimination(matrix);
    vector<double> solution = back_substitution(matrix);

    cout << "Solution:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}
