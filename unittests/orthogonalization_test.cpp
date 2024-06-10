
#include <iostream>
#include <vector>
#include "../orthogonalization.h"
#include "../matrix.h"


void orthogonalization_test() {

	vector<vector<float>> mat = { {1,1,0},{1,0,1},{0,0,1}};
	matrix* m = new matrix(mat);
	vector<vector<float>> out = orthogonalization(m);
	
	for (int i = 0; i < out.size(); i++) {
		for (int j = 0; j < out[0].size(); j++) {
			cout << out[i][j] << "   ";
		}
		cout << endl;
	}
	
}

int main() {

	orthogonalization_test();
}