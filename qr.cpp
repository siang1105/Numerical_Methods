#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(){
	//change here!!!
	double a[5][3] = {{3,-1,2},
                            {4,1,0},
                            {-3,2,1},
                            {1,1,5},
                            {-2,0,3}};
	//行
	uint8_t row = 5;
	//列
	uint8_t col = 3;

	double q[5][3] = {0};     //跟A矩陣一樣
	double r[3][3] = {0};

	for(size_t i = 0 ; i < col ; i++){
		for(size_t j = 0 ; j < row ; j++){
			q[j][i] = a[j][i];
		
		}

		for(size_t j = 0 ; j < i ; j++){
			for(size_t k = 0 ; k < row ; k++){
				r[j][i] += q[k][j]*a[k][i];
			}
			for(size_t k = 0 ; k < row ; k++){
				q[k][i] -= q[k][j]*r[j][i];
			}

		}
			
		for(size_t j = 0 ; j < row ; j++){
			r[i][i] +=  q[j][i]*q[j][i];
		}
		r[i][i] = sqrt(r[i][i]);

		for(size_t j = 0 ; j < row ; j++){
			q[j][i] /= r[i][i];
		}
	}
	printf("Q:\n");
	for(size_t i = 0 ; i < row ; i++){
		for(size_t j = 0 ; j < col ; j++){
			printf("%.4lf    ",q[i][j]);
		}
		printf("\n");

	}

	printf("R:\n");
	for(size_t i = 0 ; i < col ; i++){
		for(size_t j = 0 ; j < col ; j++){
			printf("%.4lf    ",r[i][j]);
		}
		printf("\n");
	}
	return 0;
}

