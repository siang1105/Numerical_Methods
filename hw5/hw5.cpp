#include <iostream>
#include <cmath>
#include <stdio.h>
#define PAI 3.14159265358979
using namespace std;

int main(){
    int n = 3;
    //對角線記得改0啦 不然會爆掉喔
    double LU[3][3] = {
                        {0, -1, 0},
                        {-1, 0, -1},
                        {0, -1, 0},
                        
                    };
    
    
    double DI[3][3] = {
                        {2, 0, 0},
                        {0, 2, 0},
                        {0, 0, 2},
                    };
    for(int i = 0; i < n; i++){
        DI[i][i] = 1/DI[i][i];
    }
    double u[3][1] = {
                        {0},
                        {0},
                        {0},
                        
                    };
    double tmp[3][1] = {
                        {0},
                        {0},
                        {0},
                        
                        
                    };
    double b[3][1] = {
                        {0},
                        {2},
                        {0},
                        
                    };
    double x, x2, x3, x4, x5, x6;
    do{
        double sum = 0;
        for(int i = 0; i < n; i++){
            sum = 0;
            for(int j = 0; j < n; j++){
                sum += LU[i][j] * u[j][0];
            }
            tmp[i][0] = sum;
        }
        for(int i = 0; i < n; i++){
            tmp[i][0] = b[i][0] - tmp[i][0];
        }
        
        for(int i = 0; i < n; i++){
            sum = 0;
            for(int j = 0; j < n; j++){
                sum += DI[i][j] * tmp[j][0];
            }
            tmp[i][0] = sum;
        }
        //記得三個條件都要判斷啦
        x = u[0][0] - tmp[0][0];
        x2 = u[1][0] - tmp[1][0];
        x3 = u[2][0] - tmp[2][0];
        // x4 = u[3][0] - tmp[3][0];
        // x5 = u[4][0] - tmp[4][0];
        // x6 = u[5][0] - tmp[5][0];
        for(int i = 0; i < n; i++){
            u[i][0] = tmp[i][0];
        }
        for(int i = 0; i < n; i++){
        printf("u%d = %.10lf\n", i+1, u[i][0]);
        }
        cout<<"--------------------"<<endl;
    }while(fabs(x) > 1e-5 || fabs(x2) > 1e-5 || fabs(x3) > 1e-5 );
        cout<<"跳出迴圈"<<endl;
    for(int i = 0; i < n; i++){
        printf("u%d = %.10lf\n", i+1, u[i][0]);
    }
    double xo = 3*u[0][0]-1*u[1][0]+1*u[2][0];
    double xt = 3*u[0][0]+6*u[1][0]+2*u[2][0];
    double xth = 3*u[0][0]+3*u[1][0]+7*u[2][0];
    // int xo = 3*u[0][0]-1*u[1][0]+1*u[2][0];
    // int xt = 3*u[0][0]+6*u[1][0]+2*u[2][0];
    // int xth = 3*u[0][0]+3*u[1][0]+7*u[2][0];

    // printf("%.4lf\n",xo);
    // printf("%.4lf\n",xt);
    // printf("%.4lf\n",xth);
    // cout<<"---------"<<endl;
    // cout<<xo<<endl;
    // cout<<xt<<endl;
    // cout<<xth<<endl;
    return 0;
}

//---------------------下面是課堂寫ㄉ
// #include <iostream>
// #include <cmath>
// #include <stdio.h>
// using namespace std;

// int main(){
//     double LU[6][6] = {
//                         {0, -1, 0, 0, 0, 0.5},
//                         {-1, 0, -1, 0, 0.5, 0},
//                         {0, -1, 0, -1, 0, 0},
//                         {0, 0, -1, 0, -1, 0},
//                         {0, 0.5, 0, -1, 0, -1},
//                         {0.5, 0, 0, 0, -1, 0},
//                     };
    
    
//     double DI[6][6] = {
//                         {3, 0, 0, 0, 0, 0},
//                         {0, 3, 0, 0, 0, 0},
//                         {0, 0, 3, 0, 0, 0},
//                         {0, 0, 0, 3, 0, 0},
//                         {0, 0, 0, 0, 3, 0},
//                         {0, 0, 0, 0, 0, 3},
//                     };
//     for(int i = 0; i < 6; i++){
//         DI[i][i] = 1/DI[i][i];
//     }
//     // for(int i = 0; i < 6; i++){
//     //     cout<<DI[i][i]<<" ";
//     // }
//     // cout<<endl;

//     double u[6][1] = {
//                         {0},
//                         {0},
//                         {0},
//                         {0},
//                         {0},
//                         {0},
//                     };
//     double tmp[6][1] = {
//                         {0},
//                         {0},
//                         {0},
//                         {0},
//                         {0},
//                         {0},
//                     };
//     double b[6][1] = {
//                         {2.5},
//                         {1.5},
//                         {1},
//                         {1},
//                         {1.5},
//                         {2.5},
//                     };
//     double x;

//     do{
//         double sum = 0;
//         for(int i = 0; i < 6; i++){
//             sum = 0;
//             for(int j = 0; j < 6; j++){
//                 sum += LU[i][j] * u[j][0];
//             }
//             tmp[i][0] = sum;
//         }
//         for(int i = 0; i < 6; i++){
//             tmp[i][0] = b[i][0] - tmp[i][0];
//         }
        
//         for(int i = 0; i < 6; i++){
//             sum = 0;
//             for(int j = 0; j < 6; j++){
//                 sum += DI[i][j] * tmp[j][0];
//             }
//             tmp[i][0] = sum;
//         }
//         x = u[1][0] - tmp[1][0];
//         for(int i = 0; i < 6; i++){
//             u[i][0] = tmp[i][0];
//         }
//     }while(fabs(x) > 1e-5);

//     for(int i = 0; i < 6; i++){
//         printf("u%d = %lf\n", i+1, u[i][0]);
//     }
//     return 0;
// }