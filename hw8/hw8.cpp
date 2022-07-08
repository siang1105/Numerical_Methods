#include <iostream>
#include <iomanip>
using namespace std;

// Function to find the product term
float proterm(int i, float value, float x[]){
    float pro = 1;
    for (int j = 0; j < i; j++) {
        pro = pro * (value - x[j]);
    }
    return pro;
}
  
// Function for calculating
// divided difference table
void dividedDiffTable(float x[], float y[][100], int n){
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
        }
    }
}
  
// Function for applying Newton's
// divided difference formula
float applyFormula(float value, float x[],float y[][100], int n){
    float sum = y[0][0];
    for(int i = 1; i < n; i++) {
      sum = sum + (proterm(i, value, x) * y[0][i]);
    }
    return sum;
}
  
// Function for displaying 
// divided difference table
void printDiffTable(float y[][100], int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout<<setprecision(4)<<y[i][j]<<"\t ";
        }
        cout<<"\n";
    }
}
  
// Driver Function
int main(){
    // number of inputs given
    int n = 4;
    float value;
    float sum;
    float y[100][100];
    //float x[] = { 1800, 1850, 1900, 2000 };
    //float x[] = {1, 2, 3, 4};
    float x[] = {1, 2, 3, 4};
  
    // y[][] is used for divided difference
    // table where y[][0] is used for input
    // y[0][0] = 280;
    // y[1][0] = 283;
    // y[2][0] = 291;
    // y[3][0] = 370;

    y[0][0] = 6;
    y[1][0] = 5;
    y[2][0] = 7;
    y[3][0] = 10;
    
    
    
    
    
  
    // calculating divided difference table
    dividedDiffTable(x, y, n);
  
    // displaying divided difference table
    printDiffTable(y,n);
  
    // value to be interpolated
    //value = 1950;
    value = 7;
  
    // printing the value
    cout<<"\nValue at "<<value<<" is "<<applyFormula(value, x, y, n)<<endl;



    double answer = 0;
    float coe[100];
    for(int32_t i = 0; i < n; i++){
        coe[i] = y[0][i];
    }
    for(int32_t i = n-1; i >= 0; i--){
        answer = answer * proterm(i, value, x) + coe[i];
    }
    printf("%.0f\n",answer);
    return 0;
}
