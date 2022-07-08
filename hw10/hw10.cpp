// #include <iostream>
// #include <cmath>
// using namespace std;

// int main(){
//     double A[2][2] = {
//                         {4, 0},
//                         {3, 1}
//                     };
//     double Q[2][2];
//     double R[2][2];
//     int n = 2;
//     double sum = 0;
//     for(int i = 0; i < n; i++){
//         sum += A[i][0] * A[i][0];
//     }
//     sum = sqrt(sum);
//     R[0][0] = sum;
//     for(int i = 0; i < n; i++){
//         Q[i][0] = A[i][0] / sum;
//     }
//     double tmp = 0;
//     for(int i = 0; i < n; i++){
//         tmp += Q[i][0] * A[i][1];
//     }
//     R[0][1] = tmp;
//     for(int i = 0; i < n; i++){
//         Q[i][1] = A[i][1] - Q[i][0]*tmp;
//     }
//     sum = 0;
//     for(int i = 0; i < n; i++){
//         sum += Q[i][1] * Q[i][1];
//     }
//     sum = sqrt(sum);
//     R[1][1] = sum;
//     for(int i = 0; i < n; i++){
//         Q[i][1] = Q[i][1] / sum;
//     }
//     R[1][0] = 0;
//     cout<<"Q: "<<endl;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             cout<<Q[i][j]<<"   ";
//         }
//         cout<<endl;
//     }
//     cout<<"R: "<<endl;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             cout<<R[i][j]<<"   ";
//         }
//         cout<<endl;
//     }

// }

//-------------------------------模組化

#include<iostream>
#include <math.h>
using namespace std;

//接下來把一般實矩陣的QR分解按函數的形式稍稍改寫一下，輸入是一般mxn實矩陣A，以及矩陣的行數m列數n，輸出是QR形式的正交矩陣和上三角矩陣的乘積，

void Maqr(double ** A, int m, int n)//進行一般實矩陣QR分解的函數
{
	int i, j, k, nn, jj;
	double u, alpha, w, t;
	double** Q = new double*[m];   //動態分配內存空間
	for (i = 0; i<m; i++) Q[i] = new double[m];
	if (m < n)
	{
		cout << "\nQR分解失敗" << endl;
		exit(1);
	}
	//保證列數>行數，才實現QR分解，所以在
	for (i = 0; i <= m - 1; i++)
		for (j = 0; j <= m - 1; j++)
		{
			Q[i][j] = 0.0;
			if (i == j) Q[i][j] = 1.0;
		}
		//初始的Q矩陣就是一個單位的m階方陣
		nn = n;
	if (m == n) nn = m - 1;
	for (k = 0; k <= nn - 1; k++)//在大循環k：0~m當中，進行H矩陣的求解，左乘Q，以及左乘A
	{

		u = 0.0;
		for (i = k; i <= m - 1; i++)
		{
			w = fabs(A[i][k]);
			if (w > u) u = w;
		}
		alpha = 0.0;
		for (i = k; i <= m - 1; i++)
		{
			t = A[i][k] / u; alpha = alpha + t * t;
		}
		if (A[k][k] > 0.0) u = -u;
		alpha = u * sqrt(alpha);
		if (fabs(alpha) + 1.0 == 1.0)
		{
			cout << "\nQR分解失敗" << endl;
			exit(1);
		}

		u = sqrt(2.0*alpha*(alpha - A[k][k]));
		if ((u + 1.0) != 1.0)
		{
			A[k][k] = (A[k][k] - alpha) / u;
			for (i = k + 1; i <= m - 1; i++) A[i][k] = A[i][k] / u;
			
			//以上就是H矩陣的求得，實際上程序並沒有設置任何數據結構來存儲H矩
			//陣，而是直接將u向量的元素賦值給原A矩陣的原列向量相應的位置，這樣做
			//這樣做是爲了計算左乘矩陣Q和A
			for (j = 0; j <= m - 1; j++)
			{
				t = 0.0;
				for (jj = k; jj <= m - 1; jj++)
					t = t + A[jj][k] * Q[jj][j];
				for (i = k; i <= m - 1; i++)
					Q[i][j] = Q[i][j] - 2.0*t*A[i][k];
			}
//左乘矩陣Q，循環結束後得到一個矩陣，再將這個矩陣轉置一下就得到QR分解中的Q矩陣
//也就是正交矩陣

			for (j = k + 1; j <= n - 1; j++)
			{
				t = 0.0;
				for (jj = k; jj <= m - 1; jj++)
					t = t + A[jj][k] * A[jj][j];
				for (i = k; i <= m - 1; i++)
					A[i][j] = A[i][j] - 2.0*t*A[i][k];
			}
			//H矩陣左乘A矩陣，循環完成之後，其上三角部分的數據就是上三角矩陣R
			A[k][k] = alpha;
			for (i = k + 1; i <= m - 1; i++)  A[i][k] = 0.0;
		}
	}
	for (i = 0; i <= m - 2; i++)
		for (j = i + 1; j <= m - 1; j++)
		{
			t = Q[i][j]; Q[i][j] = Q[j][i]; Q[j][i] = t;
		}
	//QR分解完畢，然後在函數體裏面直接將Q、R矩陣打印出來
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			cout << "    " << Q[i][j];
		}
		cout << endl;
	}
	cout << endl;
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			cout << "    " << A[i][j];
		}
		cout << endl;
	}
}

int main()//主函數的調用
{
	int m, n;
	cout << "輸入矩陣的行數m，列數n" << endl;
	cin >> m >> n;
	double** A = new double* [m];
	for (int i = 0; i < m; i++)A[i] = new double[n];
	cout << "輸入矩陣A的每一個元素" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	Maqr(A, m, n);

	system("pause");
	return 0;
}