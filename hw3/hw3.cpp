#include <iostream>
#include <stdint.h>
#include <stdio.h>
using namespace std;

int main(){
    int32_t row = 0;
    int32_t col = 0;
    int32_t sum = 0;
    cout<<"Please enter the row:";
    cin>>row;
    cout<<"Please enter the column:";
    cin>>col;

    int32_t **L = (int32_t **)malloc(row * sizeof(int32_t *));
    for(int32_t i = 0; i < row; i++){
        L[i] = (int32_t *)malloc(col * sizeof(int32_t));
    }

    // for(int32_t i = 0; i < row; i++){
    //     for(int32_t j = 0; j < col; j++){
    //         if(i == j){
    //             L[i][j] = 1;
    //         }
    //     }
    // }

    int32_t **U = (int32_t **)malloc(row * sizeof(int32_t *));
    for(int32_t i = 0; i < row; i++){
        U[i] = (int32_t *)malloc(col * sizeof(int32_t));
    }
    cout<< "Please enter the value of matrix(一列一列輸):"<<endl;
    for(int32_t i = 0; i < row; i++){
        for(int32_t j = 0; j < col; j++){
            cin>>U[i][j];
        }
    }

    for(int i = 0; i < row-1; i++){
        for(int j = i+1; j < row; j++){
            int num = 0; 
            num = U[j][i] / U[i][i];
            L[j][i] = num;

            for(int k = i; k < col; k++){
                U[j][k] = U[j][k] - num * U[i][k];
            }
        }
    }

    for(int i = 0; i < row; i++){
        L[i][i] = 1;
    }

    cout<<"L:"<<endl;
    for(int32_t i = 0; i < row; i++){
        for(int32_t j = 0; j < col; j++){
            printf("%d\t",L[i][j]);
        }
        cout<<endl;
    }
    cout<<"U:"<<endl;
    for(int32_t i = 0; i < row; i++){
        for(int32_t j = 0; j < col; j++){
            printf("%d\t",U[i][j]);
        }
        cout<<endl;
    }
    return 0;
}


