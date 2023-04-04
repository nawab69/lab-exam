#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double u_cal(double u, int n) {
    double temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u - i);
    return temp;
}

int fact(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

void newton_forward(vector<double> x, vector<double> y, double value) {
    int n = x.size();
    vector<vector<double>> diff_y(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        diff_y[i][0] = y[i];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            diff_y[j][i] = diff_y[j + 1][i - 1] - diff_y[j][i - 1];
    }

    double sum = diff_y[0][0];
    double u = (value - x[0]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++) {
        sum += (u_cal(u, i) * diff_y[0][i]) / fact(i);
    }

    cout << "Using Newton Forward Interpolation, Value at " << value << " is = " << sum << endl;
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

    newton_forward(x, y, value);

    return 0;
}
