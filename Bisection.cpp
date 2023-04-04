#include <iostream>

using namespace std;

// Define the function

double f(double x) {
    return (x*x) - (4 * x) -10;
}

void bisection(double x1, double x2, double error) {

    if(f(x1) * f(x2) > 0) {
        cout<<"Don't bracket any root"<<endl;
    }else{
        double x0;
        while(true) {
            x0 = (x1+x2) /2;
            if(abs(f(x0)) < error){
                break;
            }
            if(f(x0) * f(x1) < 0) {
                x2 = x0;
            }else{
                x1 = x0;
            }
        }
        cout<<"Using Bisection , Root is = "<<x0<<endl;
    }
}

int main() {
    double x1, x2, error;

    cout<<"Enter the value of x1 : ";
    cin>>x1;

    cout<<"Enter the value of x2 : ";
    cin>>x2;

    cout<<"Enter the error : ";
    cin>>error;

    bisection(x1,x2,error);

    return 0;
}

