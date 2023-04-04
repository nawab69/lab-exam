#include <iostream>
#include <cmath>

using namespace std;

// Define the function
double f(double x) {
    return (x * x) - (4 * x) - 10;
}

// Define the derivative of the function
double df(double x) {
    return (2 * x) - 4;
}

void newton_raphson(double x0, double error) {
    double x1;
    while (true) {
        x1 = x0 - (f(x0) / df(x0));
        if (abs(x1 - x0) < error) {
            break;
        }
        x0 = x1;
    }
    cout << "Using Newton-Raphson, Root is = " << x1 << endl;
}

int main() {
    double x0, error;

    cout << "Enter the initial guess x0: ";
    cin >> x0;

    cout << "Enter the error: ";
    cin >> error;

    newton_raphson(x0, error);

    return 0;
}
