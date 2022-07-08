#include <iostream>
#include <cmath> 
#include <string.h>
using namespace std;

int n, m;
double A[2][2], r[4], b[4], v[2];
double R[4] = {1,2,1,4}, d[4][2], dt[2][4];
double pre[2], now[2] = {1, 9};
double x[4] = {2,5,5,8}, y[4] = {1,3,-3, -10};

bool check(){
    return abs(now[0] - pre[0]) > 1e-6 && abs(now[1] - pre[1]) > 1e-6;
}

void cal_D(){
    for(int i = 0;i < n;i++){
        d[i][0] = (now[0] - x[i]) / sqrt((now[0] - x[i]) * (now[0] - x[i]) + (now[1] - y[i]) * (now[1] - y[i]));
        d[i][1] = (now[1] - y[i]) / sqrt((now[0] - x[i]) * (now[0] - x[i]) + (now[1] - y[i]) * (now[1] - y[i]));
    }
}

void cal_DT(){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) dt[j][i] = d[i][j];
    }
}

void cal_r(){
    for(int i = 0;i < n;i++){
        r[i] = sqrt((now[0] - x[i]) * (now[0] - x[i]) + (now[1] - y[i]) * (now[1] - y[i])) - R  [i];
    }
}

void cal_A(){
  	for(int i = 0;i < m;i++){
        for(int j = 0;j < m;j++){
    		A[i][j] = 0;
		}
	}
    for(int i = 0;i < m;i++){
        for(int j = 0;j < m;j++){
            for(int k = 0;k < n;k++){
                A[i][j] += dt[i][k] * d[k][j];
            }
        }
    }
}

void cal_b(){
    for(int i = 0;i < m;i++){
    	b[i] = 0;
	}
    for(int i = 0;i < m;i++){
        for(int k = 0;k < n;k++){
            b[i] -= dt[i][k] * r[k];
        }
    }
}

double det(double m[][2]){
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

void cramer(){
    double d = det(A);
    double tmp[2][2];
    for(int i = 0;i < m;i++){
        memcpy(tmp, A, sizeof(A));
        for(int j = 0;j < m;j++) tmp[j][i] = b[j];
        v[i] = det(tmp) / d;
    }
}

int main(){
    
    n = 4, m = 2;
    while(check()){
        cal_D(), cal_DT(), cal_r();
        cal_A(), cal_b();
        cramer();
        for(int i = 0;i < m;i++){
            pre[i] = now[i];
            now[i] += v[i];
        }
    }
    printf("%lf\n%lf\n", now[0], now[1]);
    return 0;
}
