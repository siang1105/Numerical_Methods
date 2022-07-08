#include "fin.h"
#include <iostream>

using namespace std;
double A[MAXLEN][MAXLEN] = {
                            {3,-1,2},
                            {4,1,0},
                            {-3,2,1},
                            {1,1,5},
                            {-2,0,3}};
double q[MAXLEN][MAXLEN], r[MAXLEN][MAXLEN];

int main(){
    QRfactorization(A, q, r, 5, 3);
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 3;j++) printf("%lf ", q[i][j]);
        printf("\n");
    }
    cout<<"----"<<endl;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++) printf("%lf ", r[i][j]);
        printf("\n");
    }
    
}

// #include "fin.h"

// double A[MAXLEN][MAXLEN] = {{2,-1,0,-1},{2,2,1,0},{0,0,0,0},{2,-1,1,1},{1,1,0,1}};
// double q[MAXLEN][MAXLEN], r[MAXLEN][MAXLEN];

// int main(){
//     QRfactorization(A, q, r, 5, 4);
//     for(int i = 0;i < 5;i++){
//         for(int j = 0;j < 4;j++) printf("%lf ", q[i][j]);
//         printf("\n");
//     }
//     printf("---\n");

//     for(int i = 0;i < 4;i++){
//         for(int j = 0;j < 4;j++) printf("%lf ", r[i][j]);
//         printf("\n");
//     }
    
// }