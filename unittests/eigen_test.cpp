#include <iostream>
#include <vector>
#include "../eigen.h"
#include "../matrix.h"


void R_Matrix_calc_test() {
	vector<vector<float>> A = { {1,1,0},{1,0,1},{0,1,1} };
	matrix* a = new matrix(A);
	vector<vector<float>> out = R_Matrix_calc(a);
	for (int i = 0; i < out.size(); i++) {
		for (int j = 0; j < out[0].size(); j++) {
			cout << out[i][j] << "  ";
		}
		cout << endl;
	}
}

void eigen_values_test() {
	vector<vector<float>> A = { {1,1,0},{1,0,1},{0,1,1} };
	matrix* a = new matrix(A);
	
	vector<float> out = eigen_values(a);
	for (int i = 0; i < out.size(); i++) {
			cout << out[i] << "  ";
		cout << endl;
	}
	
}


int main() {

	R_Matrix_calc_test();


}