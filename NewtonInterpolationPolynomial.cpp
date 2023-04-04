#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> divided_difference_table(vector<double> x, vector<double> y) {
    int n = x.size();
    vector<vector<double>> table(n, vector<double>(n));

    for (int i = 0; i < n; i++) {
        table[i][0] = y[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            table[j][i] = (table[j + 1][i - 1] - table[j][i - 1]) / (x[j + i] - x[j]);
        }
    }

    return table;
}

double newton_interpolation(vector<double> x, vector<double> y, double value) {
    vector<vector<double>> table = divided_difference_table(x, y);
    int n = x.size();
    double result = table[0][0];
    double temp;

    for (int i = 1; i < n; i++) {
        temp = table[0][i];
        for (int j = 0; j < i; j++) {
            temp *= (value - x[j]);
        }
        result += temp;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);

    cout << "Enter the values of x:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter the values of y:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    double value;
    cout << "Enter the value for interpolation: ";
    cin >> value;

    double result = newton_interpolation(x, y, value);
    cout << "Using Newton's Divided Difference Interpolation, Value at " << value << " is = " << result << endl;

    return 0;
}
