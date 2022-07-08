#include <iostream>
using namespace std;

// int main(){
//     double x[4] = {1, 1.05, 1.10, 1.15};
//     double y[4] = {0.1924, 0.2414, 0.2933, 0.3492};
//     double input = 1.09;
//     double sum = 0;
//     double tmp = 1;
//     double tmp2 = 1;
//     int n = 4;
//     for(int i = 0; i < n; i++){
//         tmp = 1;
//         tmp2 = 1;
//         for(int j = 0; j < n; j++){
//             if(j != i){
//                 tmp *= x[i]-x[j];
//                 tmp2 *= input - x[j];
//             }  
//         }
//         sum += y[i]*(tmp2/tmp);
//     }
//     cout<<sum<<endl;
//     return 0;
// }

int main(){
    double x[6] = {1, 2, 3, 4, 5, 6};
    double y[6] = {10, 10, 10, 10, 10, 15};
    double input = 7;
    double sum = 0;
    double tmp = 1;
    double tmp2 = 1;
    int n = 6;
    for(int i = 0; i < n; i++){
        tmp = 1;
        tmp2 = 1;
        for(int j = 0; j < n; j++){
            if(j != i){
                tmp *= x[i]-x[j];
                tmp2 *= input - x[j];
            }  
        }
        sum += y[i]*(tmp2/tmp);
    }
    cout<<sum<<endl;
    return 0;
}