// #include <iostream>
// #include <stdint.h>
// #include <stdio.h>
// #include <math.h>
// #define PAI 3.14159265358979
// using namespace std;
 
// int n = 4;
// double U[4][4] =  {
//                     {1, 0.5, 0.333333333333, 0.25},
//                     {0.5, 0.33333333333, 0.25, 0.2},
//                     {0.333333333333, 0.25, 0.2, 0.166666666666},
//                     {0.25, 0.2, 0.1666666666666, 0.142857},
//                    };
// double p[4][4],L[4][4];
// double b[4][1] = {0.16666666666, 0.142857, 0.125, 0.11111111111};
// double c[4][1];
// double pb[4][1];
// double x[4][1];



// void change(int a, int b, double m[][4]){
//     for(int i = 0;i < n;i++){
//         swap(m[a][i], m[b][i]);
//     }
// }

// void LU(){
//     for(int i = 0;i < n;i++){
//         p[i][i] = 1;
//     }
//     for(int j = 0;j < n - 1;j++){
//         double max = -1000;
//         double index = j;
//         for(int i = j;i < n;i++){
//             if(max < abs(U[i][j])){
//                 max = abs(U[i][j]);
//                 index = i;
//             }
//         }
//         change(j, index, U), change(j, index, p),change(j, index, L);
//         for(int i = j + 1;i < n;i++){
//             double tmp = U[i][j];  
//             for(int k = j;k < n;k++){
//                 U[i][k] -= tmp * U[j][k] / U[j][j];
//             }
//             L[i][j] = tmp / U[j][j];
//         }
//     }
// }

// int main(){
//     double sum = 0;
//     n = 4;
//     LU();
//     for(int i = 0;i < n;i++){
//         L[i][i] = 1;
//     }
//     printf(" L:\n");
//     for(int i = 0;i < n;i++){
//         for(int j = 0;j < n;j++){
//             printf("%lf\t ", L[i][j]);
//         }
//         printf("\n");
//     }
//     printf(" U:\n");
//     for(int i = 0;i < n;i++){
//         for(int j = 0;j < n;j++){
//             printf("%lf\t ", U[i][j]);
//         }
//         printf("\n");
//     }
//     printf(" P:\n");
//     for(int i = 0;i < n;i++){
//         for(int j = 0;j < n;j++){
//             printf("%lf\t ", p[i][j]);
//         }
//         printf("\n");
//     }

//     //Ax = b
//     //PAx = Pb 同乘P
//     //LUx = Pb 因為PA = LU，把PA換成LU
//     //令Ux = c -> Lc = Pb
//     //求出c ->就可以解 Ux = c
//     //求出x


//     for(int i = 0; i < n; i++){//求Pb
//         sum = 0;
//         for(int j = 0; j < n; j++){
//             sum += p[i][j] * b[j][0];
//         }
//         pb[i][0] = sum;
//     }
//     // printf(" Pb:\n");
//     // for(int i = 0;i < n;i++){
//     //         printf("%lf\t ", pb[i][0]);
//     // }
//     // printf("\n");

//     //令Ux = c -> Lc = Pb
//     //求ｃ
//     int j;
//     c[0][0] = pb[0][0];
//     for(int i = 1; i < n; i++){
//         sum = 0;
//         for(j = 0; j < i; j++){
//             sum += L[i][j] * c[j][0];
//         }
//         c[i][0] = pb[i][0] - sum;
//     }
//     // printf(" c:\n");
//     // for(int i = 0;i < n;i++){
//     //         printf("%lf\t ", c[i][0]);
//     // }
//     // printf("\n");

//     //求出c ->就可以解 Ux = c
//     //求出x
//     int in = n-1;
//     x[n-1][0] = c[n-1][0] / U[n-1][n-1];
//     for(int i = n-2; i >= 0; i--){
//         sum = 0;
//         in = n-1;
//         int j;
//         for(j = n-1; j > i; j--){
//             sum += U[i][j] * x[in][0];
//             in--;
//         }
//         x[i][0] = (c[i][0] - sum) / U[i][j];
//     }
    
//     printf(" x:\n");
//     for(int i = 0;i < n;i++){
//         printf("%lf\t ", x[i][0]);
//     }
    
//     printf("\n");
//     // double s = x[0][0] + 0.5*x[1][0] + 0.33333*x[2][0] + 0.25 * x[3][0];
//     // printf("%lf\n",s);
//     // double y = -1*x[0][0] - x[1][0] + x[2][0] - sqrt(5)*x[3][0];
//     // cout<<y<<endl;
    
// }






//---------------------------------------------





#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#define PAI 3.14159265358979
using namespace std;
 
int n = 2;
double U[2][2] =  {
                    {0.775506 ,-0.41132},
                    {-0.41132 ,2.22449},
                    
                   };
double p[2][2],L[2][2];
double b[2][1] = {-2.21603 ,2.44185};
double c[2][1];
double pb[2][1];
double x[2][1];



void change(int a, int b, double m[][2]){
    for(int i = 0;i < n;i++){
        swap(m[a][i], m[b][i]);
    }
}

void LU(){
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
    cout<<"b"<<endl;
    for(int i = 0; i < 2; i++){
        cout<<b[i][0]<<" ";
    }
    cout<<endl;
    double sum = 0;
    n = 2;
    // for(int i = 0; i < n; i++){
    //       for(int j = 0; j < n; j++){
    //         p[i][j] = 0;
    //       }
    //     }
    
    LU();
    for(int i = 0;i < n;i++){
        L[i][i] = 1;
    }
    printf(" L:\n");
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%lf\t ", L[i][j]);
        }
        printf("\n");
    }
    printf(" U:\n");
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%lf\t ", U[i][j]);
        }
        printf("\n");
    }
    printf(" P:\n");
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%lf\t ", p[i][j]);
        }
        printf("\n");
    }

    //Ax = b
    //PAx = Pb 同乘P
    //LUx = Pb 因為PA = LU，把PA換成LU
    //令Ux = c -> Lc = Pb
    //求出c ->就可以解 Ux = c
    //求出x
cout<<"b"<<endl;
    for(int i = 0; i < 2; i++){
        cout<<b[i][0]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < n; i++){//求Pb
        sum = 0;
        for(int j = 0; j < n; j++){
            sum += p[i][j] * b[j][0];
        }
        pb[i][0] = sum;
    }
    printf(" Pb:\n");
    for(int i = 0;i < n;i++){
            printf("%lf\t ", pb[i][0]);
    }
    printf("\n");

    //令Ux = c -> Lc = Pb
    //求ｃ
    int j;
    c[0][0] = pb[0][0];
    for(int i = 1; i < n; i++){
        sum = 0;
        for(j = 0; j < i; j++){
            sum += L[i][j] * c[j][0];
        }
        c[i][0] = pb[i][0] - sum;
    }
    printf(" c:\n");
    for(int i = 0;i < n;i++){
            printf("%lf\t ", c[i][0]);
    }
    printf("\n");

    //求出c ->就可以解 Ux = c
    //求出x
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
    
    printf(" x:\n");
    for(int i = 0;i < n;i++){
        printf("%lf\t ", x[i][0]);
    }
    
    printf("\n");
    // double s = x[0][0] + 0.5*x[1][0] + 0.33333*x[2][0] + 0.25 * x[3][0];
    // printf("%lf\n",s);
    // double y = -1*x[0][0] - x[1][0] + x[2][0] - sqrt(5)*x[3][0];
    // cout<<y<<endl;
    
}