#include <vector>
#include "../crammer.h"
#include "../matrix.h"


void crammer_test() {

	std::vector<std::vector<float>> eqn = { {2, -1, 0}, {-1, 2, -1}, {0, -1, 2} };
	std::vector<std::vector<float>> sol = { {1}, {0}, {1} };

	matrix* Eqn = new matrix(eqn);
	matrix* Sol = new matrix(sol);
	vector<float> ans = crammer(Eqn, Sol);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\t";
	}


}

int main() {

	crammer_test();

}

