#pragma once
#include <math.h>
#include <stdio.h>
#include <string.h>
// #include <bits/stdc++.h>
#define MAXLEN (10 + 5)

using namespace std;

void gauss(double tmpA[MAXLEN][MAXLEN], double tmpb[MAXLEN], double x[MAXLEN], int n, int m){
    double A[MAXLEN][MAXLEN], b[MAXLEN];
    memcpy(A, tmpA, sizeof(A)), memcpy(b, tmpb, sizeof(b));
    for(int c = 0;c < m - 1;c++){
        //find max row
        double ma = -1;
        int idx;
        for(int r = c;r < n;r++){
            if(ma < abs(A[r][c])) ma = abs(A[r][c]), idx = r;
        }
        //swap row
        for(int e = 0;e < m;e++) swap(A[c][e], A[idx][e]);
        swap(b[c], b[idx]);
        //elimination
        for(int r = c + 1;r < n;r++){
            if(A[c][c]){
                double mul = A[r][c] / A[c][c];
                for(int e = c;e < m;e++) A[r][e] -= A[c][e] * mul;
                b[r] -= b[c] * mul;
            }
        }
    }
    for(int r = n - 1;r >= 0;r--){
        x[r] = b[r];
        for(int c = m - 1;c > r;c--) x[r] -= A[r][c] * x[c];
        x[r] /= A[r][r];
    } 
}

double lagrange(double x[MAXLEN][2], int n, double t){
    double ans = 0;
    for(int i = 0;i < n;i++){
        double tmp = x[i][1];
        for(int j = 0;j < n;j++){
            if(i == j) continue;
            tmp *= (t - x[j][0]) / (x[i][0] - x[j][0]);
        }
        ans += tmp;
    }
    return ans;
}

double newtonDD_recur(double dp[MAXLEN][MAXLEN], double x[MAXLEN][2], int x1, int x2){
    if(x1 == x2) return dp[x1][x1] = x[x1][1];
    return (dp[x1][x2] ? dp[x1][x2] : dp[x1][x2] = ((newtonDD_recur(dp, x, x1+1, x2) - newtonDD_recur(dp, x, x1, x2-1)) / (x[x2][0] - x[x1][0])));
}

double newtonDD(double x[MAXLEN][2], int n, double t){
    double dp[MAXLEN][MAXLEN] = {0};
    newtonDD_recur(dp, x, 0, n-1);
    double ans = 0;
    for(int i = n - 1;i >= 0;i--){
        ans += dp[0][i];
        if(i > 0) ans *= (t - x[i-1][0]);
    }
    return ans;
}

void transpose(double A[MAXLEN][MAXLEN], double At[MAXLEN][MAXLEN], int n, int m){
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++) At[i][j] = A[j][i];
    }
}

void multiply_mat(double a[MAXLEN][MAXLEN], double b[MAXLEN][MAXLEN], double res[MAXLEN][MAXLEN], int n, int m, int p){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < p;j++){
            for(int k = 0;k < m;k++) res[i][j] += a[i][k] * b[k][j];
        }
    }
}

void multiply_vec(double a[MAXLEN][MAXLEN], double b[MAXLEN], double res[MAXLEN], int n, int m){
    for(int i = 0;i < n;i++){
        for(int k = 0;k < m;k++) res[i] += a[i][k] * b[k];
    }
}

void least_square(double x[MAXLEN][2], double v[MAXLEN], int n, int m){
    //init
    double A[MAXLEN][MAXLEN], At[MAXLEN][MAXLEN], b[MAXLEN];
    double r1[MAXLEN][MAXLEN] = {0}, r2[MAXLEN] = {0};
    for(int i = 0;i < n;i++){
        //coefficient(to be modified)
        A[i][0] = 1, A[i][1] = cos(2 * M_PI * x[i][0]), A[i][2] = sin(2 * M_PI * x[i][0]), A[i][3] = cos(4 * M_PI * x[i][0]);
        b[i] = x[i][1];
    }
    transpose(A, At, n, m);
    multiply_mat(At, A, r1, m, n, m), multiply_vec(At, b, r2, m, n);
    gauss(r1, r2, v, m, m);
}

double QR_calR(double A[MAXLEN][MAXLEN], double q[MAXLEN][MAXLEN], double r[MAXLEN][MAXLEN], int i, int j, int n, int m){
    if(i == j){
        double ans = 0;
        for(int k = 0;k < n;k++) ans += q[k][i] * q[k][i];
        return r[i][i] = sqrt(ans);
    }
    double ans = 0;
    for(int k = 0;k < n;k++) ans += q[k][i] * A[k][j];
    return r[i][j] = ans;
}

void QRfactorization(double A[MAXLEN][MAXLEN], double q[MAXLEN][MAXLEN], double r[MAXLEN][MAXLEN], int n, int m){
    memcpy(q, A, sizeof(double) * MAXLEN * MAXLEN);
    for(int i = 0;i < m;i++){
        // calculate y
        for(int j = 0;j < i;j++){
            for(int k = 0;k < n;k++) q[k][i] -= q[k][j] * QR_calR(A, q, r, j, i, n, m);
        }
        // calculate q
        double norm = QR_calR(A, q, r, i, i, n, m);
        for(int j = 0;j < n;j++){
            q[j][i] /= norm;
        }
    }
}