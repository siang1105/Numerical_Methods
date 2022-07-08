#include <iostream>
#include <cmath>
using namespace std;

    
    double b[3][1];
    double pb[3][1];
    double c[3][1];
    double x[3][1];
    double L[3][3];
    double U[3][3];
    double p[3][3];
    double h = -1;
    double k = -2;
    double r = 1;
    double preh = 0;
    double prek = 0;
    double prer = 0;
    double difh = 0;
    double difk = 0;
    double difr = 0;
    int n = 3;
    

    
void change(int a, int b, double m[][3]){
    for(int i = 0;i < n;i++){
        swap(m[a][i], m[b][i]);
    }
}

void LU(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            p[i][j] = 0;
        }
    }
    for(int i = 0;i < n;i++){
        p[i][i] = 1;
    }
    for(int j = 0;j < n - 1;j++){
        double max = -1000;
        double index = j;
        for(int i = j;i < n;i++){
            if(max < abs(U[i][j])){
                max = abs(U[i][j]);
                index = i;
            }
        }
        change(j, index, U), change(j, index, p),change(j, index, L);
        for(int i = j + 1;i < n;i++){
            double tmp = U[i][j];  
            for(int k = j;k < n;k++){
                U[i][k] -= tmp * U[j][k] / U[j][j];
            }
            L[i][j] = tmp / U[j][j];
        }
    }
}


int main(){

    double Df[3][3];
    
    double fun[3][1];
    int d = 20;
    int n = 3;
    do{
        Df[0][0] = 3*h*h + 2*k*h - r;
        Df[0][1] = h*h;
        Df[0][2] = -1*h;
        Df[1][0] = exp(h);
        Df[1][1] = exp(k);
        Df[1][2] = -1;
        Df[2][0] = -2*r;
        Df[2][1] = 2*k;
        Df[2][2] = -2*h;
        fun[0][0] = -1*(h*h*h + h*h*k - h*r + 6);
        fun[1][0] = -1*(exp(h) + exp(k) - r);
        fun[2][0] = -1*(k*k - 2*h*r - 4);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                U[i][j] = Df[i][j];
            }
        }
        // for(int i = 0; i < 3; i++){
        //     for(int j = 0; j < 3; j++){
        //         cout<<U[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i = 0; i < 3; i++){
            b[i][0] = fun[i][0];
        }
        // for(int j = 0; j < 3; j++){
        //         cout<<b[j][0]<<" ";
        //     }
        //     cout<<endl;
        LU();
        for(int i = 0;i < n;i++){
        L[i][i] = 1;
        }
        // cout<<"U"<<endl;
        // for(int i = 0; i < 3; i++){
        //     for(int j = 0; j < 3; j++){
        //         cout<<U[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"L"<<endl;
        // for(int i = 0; i < 3; i++){
        //     for(int j = 0; j < 3; j++){
        //         cout<<L[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"P"<<endl;
        // for(int i = 0; i < 3; i++){
        //     for(int j = 0; j < 3; j++){
        //         cout<<p[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        double sum = 0;
        for(int i = 0; i < n; i++){//求Pb
            sum = 0;
            for(int j = 0; j < n; j++){
                sum += p[i][j] * b[j][0];
            }
            pb[i][0] = sum;
        }
        int j;
        c[0][0] = pb[0][0];
        for(int i = 1; i < n; i++){
            sum = 0;
            for(j = 0; j < i; j++){
                sum += L[i][j] * c[j][0];
            }
            c[i][0] = pb[i][0] - sum;
        }
        int in = n-1;
        x[n-1][0] = c[n-1][0] / U[n-1][n-1];
        for(int i = n-2; i >= 0; i--){
            sum = 0;
            in = n-1;
            int j;
            for(j = n-1; j > i; j--){
                sum += U[i][j] * x[in][0];
                in--;
            }
            x[i][0] = (c[i][0] - sum) / U[i][j];
        }
        // cout<<"x"<<endl;
        // for(int i = 0; i < 3; i++){
        //     cout<<x[i][0]<<" ";
        // }
        // cout<<endl;
        preh = h;
        prek = k;
        prer = r;
        h = h + x[0][0];
        k = k + x[1][0];
        r = r + x[2][0];
        // cout<<"h"<<h<<endl;
        // cout<<"k"<<k<<endl;
        // cout<<"r"<<r<<endl;
        difh = preh - h;
        difk = prek - k;
        difr = prer - r;
        // cout<<"---"<<difh<<endl;
        // cout<<"---"<<difk<<endl;
        // cout<<"---"<<difr<<endl;
        // d--;
        
    // }while(d > 0);
    }while(fabs(difh) > 1e-5 || fabs(difk) > 1e-5 || fabs(difr) > 1e-5);
    printf("h = %lf\n",h);
    printf("k = %lf\n",k);
    printf("r = %lf\n",r);

    // cout<<"h = "<<h<<endl;
    // cout<<"k = "<<k<<endl;
    // cout<<"r = "<<r<<endl;
    double x1 = h*h*h + h*h*k - h*r + 6;
    double x2 = exp(h) + exp(k) - r;
    double x3 = k*k - 2*h*r - 4;
    printf("%lf\n",x1);
    printf("%lf\n",x2);
    printf("%lf\n",x3);
    // cout<<(h*h)+(k*k)-2*k+2*r*r<<endl;
}



