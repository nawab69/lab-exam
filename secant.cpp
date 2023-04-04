#include <iostream>
#include <cmath>

using namespace std;

// Define the function
double f(double x) {
    return (x * x) - (4 * x) - 10;
}

void secant(double x0, double x1, double error) {
    double x2;
    while (true) {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
        if (abs(x2 - x1) < error) {
            break;
        }
        x0 = x1;
        x1 = x2;
    }
    cout << "Using Secant method, Root is = " << x2 << endl;
}

int main() {
    double x0, x1, error;

    cout << "Enter the first initial guess x0: ";
    cin >> x0;

    cout << "Enter the second initial guess x1: ";
    cin >> x1;

    cout << "Enter the error: ";
    cin >> error;

    secant(x0, x1, error);

    return 0;
}
