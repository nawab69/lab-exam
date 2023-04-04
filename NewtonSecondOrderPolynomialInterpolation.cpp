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

double second_order_newton_interpolation(vector<double> x, vector<double> y, double value) {
    vector<vector<double>> table = divided_difference_table(x, y);
    int n = x.size();
    double result = table[0][0];

    double temp = (value - x[0]) * table[0][1];
    result += temp;

    temp = (value - x[0]) * (value - x[1]) * table[0][2];
    result += temp;

    return result;
}

int main() {
    int n;
    cout << "Enter the number of data points (minimum 3): ";
    cin >> n;

    if (n < 3) {
        cout << "At least 3 data points are required for second-order interpolation." << endl;
        return 1;
    }

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

    double result = second_order_newton_interpolation(x, y, value);
    cout << "Using Second-Order Newton's Divided Difference Interpolation, Value at " << value << " is = " << result << endl;

    return 0;
}
