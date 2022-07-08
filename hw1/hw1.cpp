#include <iostream>
#include <stdint.h>
#include <math.h>
#define PAI 3.14159265358979
using namespace std;

double func(double x){
    // return x - pow(x, 1.0/3.0) - 2;
    // return x*x*x + x*x - 1;
    // return exp(x)+pow(2, -x)+2*cos(x)-6;
    // return x*x*x-2*x*x-5;
    // return x*x-4*x+4-log(x);
    return exp(x) - x*x + 3*x - 2;
    // return x - 0.8 - 0.2*sin(x);
}

double func2(double x){
    return sin(x) - 6*x - 5;
}

double e = 0.0001;
double c;
 
void bisection(double a,double b){
    if(func(a) * func(b) >= 0){
        cout<<"Incorrect a and b";
        return;
    }
    c = a;
    while((b-a) >= 1e-6){
        c = (a+b) / 2;
        if (func(c) == 0.0){
            // cout << "Root = " << c<<endl;
            break;
        }
        else if(func(c)*func(a) < 0){
            // cout << "Root = " << c<<endl;
            b = c;
        }
        else{
            // cout << "Root = " << c<<endl;
            a = c;
        }
    }
}

void bisection2(double a,double b){
    if(func2(a) * func2(b) >= 0){
        cout<<"Incorrect a and b"<<endl;
        return;
    }
    c = a;
    while((b-a) >= 1e-6){
        c = (a+b) / 2;
        if (func2(c) == 0.0){
            // cout << "Root = " << c<<endl;
            break;
        }
        else if(func2(c)*func2(a) < 0){
            // cout << "Root = " << c<<endl;
            b = c;
        }
        else{
            // cout << "Root = " << c<<endl;
            a = c;
        }
    }
}
 
int main(){
    double a = 0.0;
    double b = 1;
    bisection(a,b);
    cout<<"1.Accurate Root calculated is = ";
    printf("%lf\n",c);
    double i = func(c);
    printf("%.lf\n",i);
    // cout<<i<<endl;
    // cout<<pow(2,-2)<<endl;
    a = -1.0;
    b = 1.0;
    bisection2(a,b);
    cout<<"2.Accurate Root calculated is = "<<c<<endl;
    return 0;
}