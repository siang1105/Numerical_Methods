#include <iostream>
#include <cmath>
using namespace std;

    
    double r[3][1];
    double b[3][1];
    double pb[2][1];
    double c[2][1];
    double fx[2][1];
    double L[2][2];
    double p[2][2];
    double At[2][3];
    double Atb[2][1];
    double A[3][2];
    double FA[2][2];
    double Dr[3][2];
    double x = 7;
    double y = 6;
    //xy不要猜相同數字或0
    double prex = 0;
    double prey = 0;
    double difx = 0;
    double dify = 0;
    int n = 2;
    

    
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
            if(max < abs(FA[i][j])){
                max = abs(FA[i][j]);
                index = i;
            }
        }
        change(j, index, FA), change(j, index, p),change(j, index, L);
        for(int i = j + 1; i < n; i++){
            double tmp = FA[i][j];  
            for(int k = j;k < n;k++){
                FA[i][k] -= tmp * FA[j][k] / FA[j][j];
            }
            L[i][j] = tmp / FA[j][j];
        }
    }
}


int main(){

    do{
        Dr[0][0] = (x+1)/sqrt((x+1)*(x+1) + y*y);
        Dr[0][1] = y / sqrt((x+1)*(x+1) + y*y);
        Dr[1][0] = (x-1)/sqrt((x-1)*(x-1) + (y-1)*(y-1));
        Dr[1][1] = (y-1)/sqrt((x-1)*(x-1) + (y-1)*(y-1));
        Dr[2][0] = (x-1)/sqrt((x-1)*(x-1) + (y+1)*(y+1));
        Dr[2][1] = (y+1)/sqrt((x-1)*(x-1) + (y+1)*(y+1));
        r[0][0] = -1*(sqrt((x+1)*(x+1) + (y*y)) - 1);
        r[1][0] = -1*(sqrt((x-1)*(x-1) + (y-1)*(y-1)) - 1);
        r[2][0] = -1*(sqrt((x-1)*(x-1) + (y+1)*(y+1)) - 1);
//         cout<<"Dr"<<endl;

// for(int i = 0; i < 3; i++){
//           for(int j = 0; j < 2; j++){
//             cout<<Dr[i][j]<<" ";
//           }
//           cout<<endl;
//         }
//         cout<<"---------"<<endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 2; j++){
                At[j][i] = Dr[i][j];
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 2; j++){
                A[i][j] = Dr[i][j];
            }
        }
        for(int i = 0; i < 3; i++){
            b[i][0] = r[i][0];
        }
        // cout<<"b"<<endl;
        // for(int i = 0; i < 3; i++){
        //   cout<<b[i][0]<<" ";
        // }
        // cout<<endl;
        double sum = 0;
        for(int i = 0; i < 2; i++){
            for(int k = 0; k < 2; k++){
                sum = 0;
                for(int j = 0; j < 3; j++){
                    sum += At[i][j] * A[j][k];
                }
                FA[i][k] = sum;
            }
        }
        // for(int i = 0; i < 2; i++){
        //   for(int j = 0; j < 2; j++){
        //     cout<<FA[i][j]<<" ";
        //   }
        //   cout<<endl;
        // }
        // cout<<"-----"<<endl;
        for(int i = 0; i < 2; i++){
            sum = 0;
            for(int j = 0; j < 3; j++){
                sum += At[i][j] * b[j][0];
            }
            Atb[i][0] = sum;
        }
        
        sum = 0;
        n = 2;
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
        fx[n-1][0] = c[n-1][0] / FA[n-1][n-1];
        for(int i = n-2; i >= 0; i--){
            sum = 0;
            in = n-1;
            int j;
            for(j = n-1; j > i; j--){
                sum += FA[i][j] * fx[in][0];
                in--;
            }
            fx[i][0] = (c[i][0] - sum) / FA[i][j];
        }
        prex = x;
        prey = y;
        // cout<<"fx "<<fx[0][0]<<endl;
        // cout<<"fy "<<fx[1][0]<<endl;
        x = x + fx[0][0];
        y = y + fx[1][0];
        difx = prex - x;
        dify = prey - y;
        // cout<<"x "<<x<<endl;
        // cout<<"y "<<y<<endl;
        // cout<<"difx "<<difx<<endl;
        // cout<<"dify "<<dify<<endl;
        for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
            p[i][j] = 0;
          }
        }
        for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
            L[i][j] = 0;
          }
        }
    }while(fabs(difx) > 1e-5 || fabs(dify) > 1e-5);
    printf("x = %lf\n",x);
    printf("y = %lf\n",y);

}



