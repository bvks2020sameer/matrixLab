#include "../matrix.h"
#include <vector>
using namespace std;

void matrix_add_test() {

	vector<vector<float>> A = { {1,2,3},{4,5,6},{7,8,9} };
	matrix* a = new matrix(A);
	vector<vector<float>> B = { {9,8,7},{6,5,4},{3,2,1} };
	matrix* b = new matrix(B);

	vector<vector<float>> out = matrix_add(a, b);

	for (int i = 0; i < out.size(); i++) {
		for (int j = 0; j < out[0].size(); j++) {
			cout << out[i][j] << "  ";
		}
		cout << endl;
	}

}

void matrix_product_test() {

	vector<vector<float>> A = { {1,2,3},{4,5,6},{7,8,9} };
	matrix* a = new matrix(A);
	vector<vector<float>> B = { {9,8,7},{6,5,4},{3,2,1} };
	matrix* b = new matrix(B);

	vector<vector<float>> out = matrix_product(a, b);
	
	for (int i = 0; i < out.size(); i++) {
		for (int j = 0; j < out[0].size(); j++) {
			cout << out[i][j] << "  ";
		}
		cout << endl;
	}
	
}

void transpose_test() {
	vector<vector<float>> A = { {1,2,3},{4,5,6},{7,8,9} };
	matrix* a = new matrix(A);
	vector<vector<float>> out = transpose(a);
	for (int i = 0; i < out.size(); i++) {
		for (int j = 0; j < out[0].size(); j++) {
			cout << out[i][j] << "  ";
		}
		cout << endl;
	}
}

void determinant_test() {
	vector<vector<float>> A = { {1,-1,0},{0,2,-1},{1,-1,2} };
	matrix* a = new matrix(A);
	float out = determinant(a);
	cout << out;
}


void adjoint_test() {
	vector<vector<float>> A = { {1,2,3},{4,5,6},{7,8,9} };
	//vector<vector<float>> A = { {1,2},{3,4} };
	matrix* a = new matrix(A);
	vector<vector<float>> out = adjoint(a);
	for (int i = 0; i < out.size(); i++) {
		for (int j = 0; j < out[0].size(); j++) {
			cout << out[i][j] << "  ";
		}
		cout << endl;
	}
}

void inverse_test() {
	vector<vector<float>> A = { {1,0,0},{0,1,0},{0,0,1} };
	matrix* a = new matrix(A);
	vector<vector<float>> out = inverse(a);
	for (int i = 0; i < out.size(); i++) {
		for (int j = 0; j < out[0].size(); j++) {
			cout << out[i][j] << "  ";
		}
		cout << endl;
	}
}


int main() {
	
	return 0; 
}


