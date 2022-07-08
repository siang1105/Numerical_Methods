#include <iostream>
#include <cmath>
#define PAI 3.14159265358979
using namespace std;

double A[12][4] = {
                {1, cos(0), sin(0), cos(0)},
                {1, cos(PAI/6), sin(PAI/6), cos(PAI/3)},
                {1, cos(PAI/3), sin(PAI/3), cos((2*PAI)/3)},
                {1, cos((3*PAI)/6), sin((3*PAI)/6), cos((3*PAI)/3)},
                {1, cos((4*PAI)/6), sin((4*PAI)/6), cos((4*PAI)/3)},
                {1, cos((5*PAI)/6), sin((5*PAI)/6), cos((5*PAI)/3)},
                {1, cos((6*PAI)/6), sin((6*PAI)/6), cos((6*PAI)/3)},
                {1, cos((7*PAI)/6), sin((7*PAI)/6), cos((7*PAI)/3)},
                {1, cos((8*PAI)/6), sin((8*PAI)/6), cos((8*PAI)/3)},
                {1, cos((9*PAI)/6), sin((9*PAI)/6), cos((9*PAI)/3)},
                {1, cos((10*PAI)/6), sin((10*PAI)/6), cos((10*PAI)/3)},
                {1, cos((11*PAI)/6), sin((11*PAI)/6), cos((11*PAI)/3)}
            };

double At[4][12] = {0};
double FA[4][4] = {0};
double Atb[4][1] = {0};
double b[12][1]= {
                6.224,
                6.665,
                6.241,
                5.302,
                5.073,
                5.127,
                4.994,
                5.012,
                5.108,
                5.377,
                5.510,
                6.372
            };
double p[4][4],L[4][4];
double c[4][1];
double pb[4][1];
double x[4][1];
int n = 4;

void change(int a, int b, double m[][4]){
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
            if(max < abs(FA[i][j])){
                max = abs(FA[i][j]);
                index = i;
            }
        }
        change(j, index, FA), change(j, index, p),change(j, index, L);
        for(int i = j + 1;i < n;i++){
            double tmp = FA[i][j];  
            for(int k = j;k < n;k++){
                FA[i][k] -= tmp * FA[j][k] / FA[j][j];
            }
            L[i][j] = tmp / FA[j][j];
        }
    }
}


int main(){

    // for(int i = 0; i < 12; i++){
    //     for(int j = 0; j < 4; j++){
    //         printf("%f ",A[i][j]);
    //     }
    //     cout<<endl;
    // }
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 4; j++){
            At[j][i] = A[i][j];
        }
    }
    
    double sum = 0;
    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 4; k++){
            sum = 0;
            for(int j = 0; j < 12; j++){
                sum += At[i][j] * A[j][k];
            }
            FA[i][k] = sum;
        }
    }

    // for(int i = 0; i < 4; i++){
    //     for(int j = 0; j < 4; j++){
    //         printf("%f\t",FA[i][j]);
    //         // cout<<FA[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<"-----------"<<endl;

    for(int i = 0; i < 4; i++){
        sum = 0;
        for(int j = 0; j < 12; j++){
            sum += At[i][j] * b[j][0];
        }
        Atb[i][0] = sum;
    }


    //U = FA , b = Atb
    //hw4的code
    sum = 0;
    n = 4;
    LU();
    for(int i = 0;i < n;i++){
        L[i][i] = 1;
    }
    
    for(int i = 0; i < n; i++){//求Pb
        sum = 0;
        for(int j = 0; j < n; j++){
            sum += p[i][j] * Atb[j][0];
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
    x[n-1][0] = c[n-1][0] / FA[n-1][n-1];
    for(int i = n-2; i >= 0; i--){
        sum = 0;
        in = n-1;
        int j;
        for(j = n-1; j > i; j--){
            sum += FA[i][j] * x[in][0];
            in--;
        }
        x[i][0] = (c[i][0] - sum) / FA[i][j];
    }
    for(int i = 0;i < n;i++){
        printf("C%d = ",i);
        printf("%lf\n", x[i][0]);
    }

    return 0;

}



//-----------------------------------------
//expo
// #include <iostream>
// #include <cmath>
// #define PAI 3.14159265358979
// using namespace std;

// double A[4][2] = {
//                 {1, 0},
//                 {1, 1},
//                 {1, 2},
//                 {1, 3}
//             };

// double At[2][4] = {0};
// double FA[2][2] = {0};
// double Atb[2][1] = {0};
// double b[4][1]= {
//                 log(10),
//                 log(5),
//                 log(2),
//                 log(1)
//             };
// double p[2][2],L[2][2];
// double c[2][1];
// double pb[2][1];
// double x[2][1];
// int n = 2;

// void change(int a, int b, double m[][2]){
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
//             if(max < abs(FA[i][j])){
//                 max = abs(FA[i][j]);
//                 index = i;
//             }
//         }
//         change(j, index, FA), change(j, index, p),change(j, index, L);
//         for(int i = j + 1;i < n;i++){
//             double tmp = FA[i][j];  
//             for(int k = j;k < n;k++){
//                 FA[i][k] -= tmp * FA[j][k] / FA[j][j];
//             }
//             L[i][j] = tmp / FA[j][j];
//         }
//     }
// }


// int main(){

//     // for(int i = 0; i < 12; i++){
//     //     for(int j = 0; j < 4; j++){
//     //         printf("%f ",A[i][j]);
//     //     }
//     //     cout<<endl;
//     // }
//     for(int i = 0; i < 4; i++){
//         for(int j = 0; j < 2; j++){
//             At[j][i] = A[i][j];
//         }
//     }
    
//     double sum = 0;
//     for(int i = 0; i < 2; i++){
//         for(int k = 0; k < 2; k++){
//             sum = 0;
//             for(int j = 0; j < 4; j++){
//                 sum += At[i][j] * A[j][k];
//             }
//             FA[i][k] = sum;
//         }
//     }

//     // for(int i = 0; i < 4; i++){
//     //     for(int j = 0; j < 4; j++){
//     //         printf("%f\t",FA[i][j]);
//     //         // cout<<FA[i][j]<<" ";
//     //     }
//     //     cout<<endl;
//     // }

//     // cout<<"-----------"<<endl;

//     for(int i = 0; i < 2; i++){
//         sum = 0;
//         for(int j = 0; j < 4; j++){
//             sum += At[i][j] * b[j][0];
//         }
//         Atb[i][0] = sum;
//     }


//     //U = FA , b = Atb
//     //hw4的code
//     sum = 0;
//     n = 2;
//     LU();
//     for(int i = 0;i < n;i++){
//         L[i][i] = 1;
//     }
    
//     for(int i = 0; i < n; i++){//求Pb
//         sum = 0;
//         for(int j = 0; j < n; j++){
//             sum += p[i][j] * Atb[j][0];
//         }
//         pb[i][0] = sum;
//     }

//     int j;
//     c[0][0] = pb[0][0];
//     for(int i = 1; i < n; i++){
//         sum = 0;
//         for(j = 0; j < i; j++){
//             sum += L[i][j] * c[j][0];
//         }
//         c[i][0] = pb[i][0] - sum;
//     }
//     int in = n-1;
//     x[n-1][0] = c[n-1][0] / FA[n-1][n-1];
//     for(int i = n-2; i >= 0; i--){
//         sum = 0;
//         in = n-1;
//         int j;
//         for(j = n-1; j > i; j--){
//             sum += FA[i][j] * x[in][0];
//             in--;
//         }
//         x[i][0] = (c[i][0] - sum) / FA[i][j];
//     }
//     for(int i = 0;i < n;i++){
//         printf("C%d = ",i);
//         printf("%lf\n", x[i][0]);
//     }
//   cout<<exp(2.324899)<<endl;
//     return 0;

// }