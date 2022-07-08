#include <iostream>
#include <stdio.h>
#include <stdint.h>
using namespace std;

int main(){
    int32_t n = 0;
    double x = 0;
    double answer = 1;
    int32_t coef[100];
    for(int32_t i = 0; i < 100; i++){
        coef[i] = 1;
    }
    cout<<"輸入最高項次：";
    cin>>n;
    cout<<"輸入帶入的x數值：";
    cin>>x;
    for(int32_t i = n-1; i >= 0; i--){
        answer = answer * x + coef[i];
    }
    cout<<answer<<endl;
    return 0;
}

// for(int i = 0; i <= n; i++){
//    cin>>coef[i];//由小到大
// }
// answer = answer * coef[n];
// for(int32_t i = n-1; i >= 0; i--){
//    answer = answer * x + coef[i];
// }

