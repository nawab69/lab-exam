#include <iostream>
#include <vector>

using namespace std;

double lagrange_interpolation(vector<double> x, vector<double> y, double value) {
    int n = x.size();
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];

        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (value - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
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

    double result = lagrange_interpolation(x, y, value);
    cout << "Using Lagrange Interpolation, Value at " << value << " is = " << result << endl;

    return 0;
}

