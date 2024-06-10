#include "../vector.h"
#include <vector>
using namespace std;


void magnitude_test() {
	vector<float> F = { 1,2,3,4,5 };
	cout<<vector_magnitude(F);
}


void add_test() {
	vector<float> a = { 1,2,3 };
	vector<float> b = { 4,5,6 };

	vector<vector<float>> V;
	V.push_back(a);
	V.push_back(b);

	vector<float> ans = vector_add(V);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}



void dot_product_test() {
	vector<float> a = { 1,2,3 };
	vector<float> b = { 4,5,6 };

	vector<vector<float>> V;
	V.push_back(a);
	V.push_back(b);
	cout << dot_product(V);
}

void vector_constant_multiplier_test() {
	vector<float> a = { 1,2,3 };

	vector<float> ans = vector_constant_multiplier(a,5);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}


int main() {
	
	vector_constant_multiplier_test();

	return 0;
}