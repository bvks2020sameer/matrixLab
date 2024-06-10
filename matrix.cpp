/**
 * @file matrix.cpp
 * @brief This file contains multiple functions and methods required for various Matrix operations
 *
 * @author Bhamidipati Venkatakrishnasameer
 *

 */


#include <vector>
#include <iostream>
#pragma once

using namespace std;

/**
 * @class matrix
 * @brief A class to represent a matrix of floating-point numbers.
 *
 * This class provides a simple implementation of a matrix with basic
 * functionality for initialization and storage of matrix data.
 */

class matrix {

	private :
		/**
		 * @brief 2D vector to store matrix elements.
		 */

		vector<vector<float>> Matrix;

		/**
		 * @brief Number of rows in the matrix.
		 */

		int rows;

		/**
		 * @brief Number of columns in the matrix.
		 */

		int columns;

	public :


		/**
		 * @brief Constructor to initialize a matrix with a 2D vector.
		 *
		 * This constructor takes a 2D vector of floats and initializes the
		 * matrix if the input vector represents a valid matrix (all rows
		 * have the same number of columns). If the input vector is not a
		 * valid matrix, an error message is displayed.
		 *
		 * @param M A 2D vector of floats representing the matrix.
		 */

		matrix(vector<vector<float>> M) {

			auto r = M.size();
			auto c = M[0].size();

			bool flag = true;

			for (int i = 0; i < r; i++) {

				if (M[i].size() != c) {
					flag = false;
					break;
				}
			}

			if (flag) {
				this->Matrix = M;
				this->rows = (int) r;
				this->columns = (int) c;
			}
			
			else {
				cout << "Not a matrix";
			}

		}

		/**
		 * @brief Get the dimensions of the matrix.
		 * @return A vector containing the number of rows and columns.
		 */

		vector<int> get_dimensions() {
			vector<int> out;
			out.push_back(this->rows);
			out.push_back(this->columns);

			return out;
		}

		/**
		 * @brief Get the matrix.
		 * @return The 2D vector representing the matrix.
		 */

		vector<vector<float>> get_matrix() {

			return this->Matrix;
		}

};

/**
 * @brief Adds two matrices.
 *
 * This function takes two matrices as input and returns their sum as a new matrix.
 * If the matrices do not have the same dimensions, an error message is displayed
 * and an empty matrix is returned.
 *
 * @param A Pointer to the first matrix.
 * @param B Pointer to the second matrix.
 * @return The sum of the two matrices as a 2D vector of floats.
 */

vector<vector<float>> matrix_add(matrix * A, matrix * B) { 

	vector<int> A_dims = A->get_dimensions();
	vector<int> B_dims = B->get_dimensions();
	
	vector<vector<float>> a = A->get_matrix();
	vector<vector<float>> b = B->get_matrix();
	vector<vector<float>> out;

	if (A_dims == B_dims) {

		int r = A_dims[0];
		int c = A_dims[1];

		for (int i = 0; i < r; i++) {

			vector<float> row;

			for (int j = 0; j < c; j++) {

				row.push_back( a[i][j] + b[i][j]);
			}

			out.push_back(row);
		}

	}
	else {
		cout << "Matrices must be of same size";
	}

	return out;
}

/**
 * @brief Transposes a matrix.
 *
 * This function takes a matrix as input and returns its transpose.
 * The transpose of a matrix is obtained by swapping its rows with its columns.
 *
 * @param A Pointer to the matrix to be transposed.
 * @return The transpose of the input matrix as a 2D vector of floats.
 */

vector<vector<float>> transpose(matrix* A) {

	vector<int> A_dims = A->get_dimensions();
	vector<vector<float>> a = A->get_matrix();
	vector<vector<float>> out;

	for (int i = 0; i < A_dims[0]; i++) {

		vector<float> row;
		for (int j = 0; j < A_dims[1]; j++) {
			row.push_back(a[j][i]);
		}
		out.push_back(row);
	}

	
	return out;
}

/**
 * @brief Multiplies two matrices.
 *
 * This function takes two matrices as input and returns their product.
 * Matrix multiplication is defined only if the number of columns in the
 * first matrix is equal to the number of rows in the second matrix.
 *
 * @param A Pointer to the first matrix.
 * @param B Pointer to the second matrix.
 * @return The product of the two matrices as a 2D vector of floats. If the
 * matrices cannot be multiplied, an error message is displayed and an empty
 * matrix is returned.
 */


vector<vector<float>> matrix_product(matrix* A, matrix* B) {

	vector<int> A_dims = A->get_dimensions();
	vector<int> B_dims = B->get_dimensions();

	vector<vector<float>> a = A->get_matrix();
	vector<vector<float>> b = B->get_matrix();
	vector<vector<float>> out;

	if (A_dims[0] == B_dims[1]) {

		int r = A_dims[1];
		int c = B_dims[0];
		int kernel_size = A_dims[0];

		for (int i = 0; i < r; i++) {

			vector<float> row;

			for (int j = 0; j < c; j++) {

				float sum = 0;

				for (int k = 0; k < kernel_size; k++) {
					sum += a[i][k] * b[k][j];
				}
				row.push_back(sum);
			}

			out.push_back(row);
		}

	}
	else {
		cout << "Matrices incompatible";
	}

	return out;
}

/**
* @brief Used to find determinant of 2X2 Matrix
* Used as an intermediatory step to find the determinant of the matrix
* @param A 2D vector of float representing a matrix
* @return a float value
*/

float det_2X2(vector<vector<float>> V) {
	float out = V[0][0] * V[1][1] - V[0][1] * V[1][0];
	return out;
}


/**
 * @brief Calculates the determinant of a matrix.
 *
 * This function takes a matrix as input and returns its determinant.
 * The determinant is defined only for square matrices (matrices with
 * the same number of rows and columns).
 *
 * @param A Pointer to the matrix whose determinant is to be calculated.
 * @return The determinant of the matrix as a float. If the matrix is
 * not square, an error message is displayed and 0.0 is returned.
 */

float determinant(matrix* A) {
	vector<int> A_dims = A->get_dimensions();
	vector<vector<float>> a = A->get_matrix();
	float out = 0;

	if (A_dims[0] == A_dims[1]) {
		if (A_dims[0] == 1) {
			return a[0][0];
		}
		else if (A_dims[0] == 2) {
			return det_2X2(a);
		}
		else {
			int n = A_dims[0];
			for (int i = 0; i < n; i++) {
				vector<vector<float>> submatrix;

				for (int r = 1; r < n; r++) {
					vector<float> row;
					for (int c = 0; c < n; c++) {
						if (c != i) {
							row.push_back(a[r][c]);
						}
					}
					submatrix.push_back(row);
				}

				int cofactor = (i % 2 == 0) ? 1 : -1;
				matrix* sub = new matrix(submatrix);
				out += cofactor * a[0][i] * determinant(sub);
				delete sub; // Avoid memory leak
			}
		}
	}
	else {
		cout << "Matrix must be a square matrix";
	}

	return out;
}

/**
 * @brief Constructs a submatrix by removing the specified row and column.
 *
 * This function takes a matrix and removes the i-th row and j-th column to construct a submatrix.
 * This is a helper function for adjoint function
 *
 * @param M A 2D vector of floats representing the original matrix.
 * @param i The index of the row to remove.
 * @param j The index of the column to remove.
 * @param n The size of the original matrix (number of rows/columns).
 * @return A pointer to a new matrix object representing the submatrix.
 */


matrix * Submatrix_builder(vector<vector<float>> M, int i, int j, int n) {

	vector<vector<float>> submatrix;

	for (int r = 0; r < n; r++) {
		
		if (r != i) {
			vector<float> row;
			for (int c = 0; c < n; c++) {

				if (c != j) {
					row.push_back(M[r][c]);
				}
			}
			submatrix.push_back(row);
		}
	}

	matrix* Sub = new matrix(submatrix);
	return Sub;
}

/**
 * @brief Calculates the adjoint of a given square matrix.
 *
 * This function takes a pointer to a matrix object and returns its adjoint as a 2D vector of floats.
 * The adjoint of a matrix is the transpose of its cofactor matrix.
 *
 * @param A A pointer to a matrix object.
 * @return A 2D vector of floats representing the adjoint of the input matrix.
 */


vector<vector<float>> adjoint(matrix* A) {

	vector<int> A_dims = A->get_dimensions();
	vector<vector<float>> a = A->get_matrix();
	vector<vector<float>> out;

	if (A_dims[0] == A_dims[1]) {
		if (A_dims[0] == 1) {
			return a;
		}
		else if (A_dims[0] == 2)
		{
			vector<vector<float>> Out = { {a[1][1],-a[1][0]},{-a[0][1],a[0][0]} };

			return Out;
		}

		else {
			int n = A_dims[0];

			for (int i = 0; i < n; i++) {

				vector<float> row;

				for (int j = 0; j < n; j++) {

						matrix * S = Submatrix_builder(a, i, j, n);

						int i_cofactor = (i % 2 == 0) ? 1 : -1;
						int j_cofactor = (j % 2 == 0) ? 1 : -1;
						row.push_back(i_cofactor * j_cofactor * determinant(S));
					}
				out.push_back(row);
			}
			
		}

	}
	else {
		cout << "Matrix must be a square matrix";
	}

	return out;
}


/**
 * @brief Calculates the inverse of a given square matrix.
 *
 * This function takes a pointer to a matrix object and returns its inverse as a 2D vector of floats.
 * The inverse is calculated using the adjoint and the determinant of the matrix.
 *
 * @param A A pointer to a matrix object.
 * @return A 2D vector of floats representing the inverse of the input matrix.
 * @throws std::invalid_argument if the matrix is not square or if its determinant is zero (singular matrix).
 */

vector<vector<float>> inverse(matrix* A) {

	vector<vector<float>> adj = adjoint(A);
	vector<vector<float>> out;

	float det = determinant(A);

	if (det == 0) {
		cout << "Matrix not invertible";
	}

	else {
		for (int i = 0; i < adj.size(); i++) {
			vector<float> row;
			for (int j = 0; j < adj[0].size(); j++) {
				row.push_back((1 / det) * adj[i][j]);
			}
			out.push_back(row);
		}
	}
	return out;
}