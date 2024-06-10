/**
 * @file matrix.h
 * @brief This file contains multiple functions and methods required for various Matrix operations
 *
 * @author Bhamidipati Venkatakrishnasameer
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

private:

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

public:

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
			this->rows = (int)r;
			this->columns = (int)c;
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
vector<vector<float>> matrix_add(matrix * A, matrix * B);

/**
 * @brief Transposes a matrix.
 *
 * This function takes a matrix as input and returns its transpose.
 * The transpose of a matrix is obtained by swapping its rows with its columns.
 *
 * @param A Pointer to the matrix to be transposed.
 * @return The transpose of the input matrix as a 2D vector of floats.
 */

vector<vector<float>> transpose(matrix* A);

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

vector<vector<float>> matrix_product(matrix* A, matrix* B);

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

float determinant(matrix* A);  

/** 
 * @brief Calculates the adjoint of a given square matrix.
 *
 * This function takes a pointer to a matrix object and returns its adjoint as a 2D vector of floats.
 * The adjoint of a matrix is the transpose of its cofactor matrix.
 *
 * @param A A pointer to a matrix object.
 * @return A 2D vector of floats representing the adjoint of the input matrix.
 */

vector<vector<float>> adjoint(matrix* A);

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


vector<vector<float>> inverse(matrix* A);