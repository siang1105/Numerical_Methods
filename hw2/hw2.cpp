#include <iostream>
#include <cmath>
using namespace std;

double fun1(double x)
{
    // return x*x*x*x*x + x - 1;
    // return exp(-1*x) - x;
    // return x*x*x + x*x - 1;
    return pow(x, 1.4) - pow(x, 0.5) + pow(x, -1) - 100;
}

double fun2(double x)//微分
{
    // return -1 * exp(-1*x) - 1;
    // return 3*x*x + 2*x;
    return 1.4*pow(x, 0.4)-0.5*pow(x, -0.5)-pow(x, -2);
}

double fun3(double x)
{
    return log(x) + x*x - 3;
}

double fun4(double x)//微分
{
    return (1/x) + 2*x;
}

int main(){
    double f1,f2,x,d;
    double f3,f4,x2,d2;
    int cnt = 0;
    int cnt2 = 0;
    x = 100;
    x2 = 100;
    do{
        f1 = fun1(x);//方程的值 
        f2 = fun2(x);//方程的導數 
        d = f1/f2;//"斜率" 
        x = x - d;//更新方程的值 
        cnt++;
    }while(fabs(d) > 1e-5);

    do{
        f3 = fun3(x2);//方程的值 
        f4 = fun4(x2);//方程的導數
        d2 = f3/f4;//"斜率" 
        x2 = x2 - d2;//更新方程的值 
        cnt2++;
    }while(fabs(d2) > 1e-5);

    cout<<"1.最終的近似根為:";
    printf("%lf\n",x);
    double g = fun1(x);
    printf("%lf\n",g);
    cout<<"2.最終的近似根為:";
    printf("%lf\n",x2);
    return 0;
}