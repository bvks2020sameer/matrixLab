/**
 * @file eigen.cpp
 * @brief This file contains methods for finding eigen values
 *
 * @author Bhamidipati Venkatakrishnasameer
 *

 */

#include <vector>
#include "matrix.cpp"
#include "vector.cpp"
#include <iostream>
#include "orthogonalization.cpp"

#pragma once

using namespace std;

/**
 * @brief Rounds each element of a matrix to a specified number of decimal places.
 *
 * This function takes a matrix of floating-point numbers and rounds each element
 * to a specified number of decimal places (default is 5).
 *
 * @param M The input matrix of floating-point numbers to be rounded.
 * @return A new matrix where each element is rounded to the specified number of decimal places.
 */

vector<vector<float>> rounder(vector<vector<float>> M)
{

	vector<vector<float>> out;
	const int decimal_place = 5;
	auto decimal_values = pow(10, decimal_place);

	for (int i = 0; i < M.size(); i++)
	{
		vector<float> row;
		for (int j = 0; j < M[0].size(); j++)
		{
			row.push_back(round(M[i][j] * decimal_values) / decimal_values);
		}

		out.push_back(row);
	}

	return (out);
}
/**
 * @brief Calculates the R matrix in the QR decomposition of a given matrix.
 *
 * This function performs the following steps:
 * 1. Orthogonalizes the given matrix M to obtain an orthogonal matrix.
 * 2. Transposes the orthogonal matrix.
 * 3. Multiplies the transposed orthogonal matrix with the original matrix.
 * 4. Rounds the resulting matrix to a specified number of decimal places.
 *
 * @param M The input matrix for which the R matrix is to be calculated.
 * @return A matrix representing the R matrix in the QR decomposition, with each element rounded to a specified number of decimal places.
 */

vector<vector<float>> R_Matrix_calc(matrix *M)
{

	auto ortho_mat = orthogonalization(M);
	matrix *O = new matrix(ortho_mat);
	auto trans_mat = transpose(O);
	matrix *T = new matrix(trans_mat);
	auto prod = matrix_product(T, M);
	delete O;
	delete T;
	return (rounder(prod));
}

/**
 * @brief Calculates whether a given vector is an eigenvector for a given matrix.
 *
 * This function performs matrix-vector multiplication of the input matrix `M` and vector `V`,
 * and then checks if the result is a scalar multiple of the original vector `V`.
 * If the result is a scalar multiple, the function returns the original vector, indicating it is an eigenvector.
 * Otherwise, the function returns a null vector (a vector of zeroes), indicating that `V` is not an eigenvector of `M`.
 *
 * The function uses a tolerance to account for floating-point precision errors while comparing the ratios
 * of the resulting vector and the original vector.
 *
 * @param M A reference to a 2D vector (matrix) for which the eigenvector check will be performed.
 * @param V A reference to a 1D vector that is tested to see if it is an eigenvector of matrix `M`.
 * @return A vector containing the original vector `V` if it is an eigenvector, or a null vector (all zeroes) if not.
 */

vector<float> eigenVectorCalc(const vector<vector<float>> &M, const vector<float> &V)
{
	int rows = M.size();
	int cols = M[0].size();

	// Step 1: Matrix-Vector Multiplication
	vector<float> result(rows, 0.0f);
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			result[i] += M[i][j] * V[j];
		}
	}

	// Step 2: Check if the result is a scalar multiple of the original vector
	float ratio = 0.0f;
	bool initialized = false;
	for (int i = 0; i < V.size(); ++i)
	{
		if (V[i] != 0)
		{
			float currentRatio = result[i] / V[i];
			if (!initialized)
			{
				ratio = currentRatio; // Set the initial ratio
				initialized = true;
			}
			else if (fabs(currentRatio - ratio) > 1e-5)
			{
				// If ratios are not equal, return a null vector (not an eigenvector)
				return vector<float>(V.size(), 0.0f);
			}
		}
	}

	// If all components are scalar multiples, return the original vector (it is an eigenvector)
	return V;
}

/**
 * @brief Calculates the eigenvalues of a given matrix using the QR algorithm.
 *
 * This function iteratively applies the QR algorithm to compute the eigenvalues of the input matrix.
 * The QR algorithm decomposes the input matrix into an orthogonal matrix and an upper triangular matrix (R matrix),
 * and then updates the input matrix with the product of R and Q (the transposed orthogonal matrix).
 * This process is repeated a fixed number of iterations (3 in this implementation) to converge to the eigenvalues.
 *
 * @param M Pointer to the input matrix for which the eigenvalues are to be computed.
 * @return A vector containing the eigenvalues of the input matrix, rounded to a specified number of decimal places.
 */

vector<float> eigen_values(matrix *M)
{

	auto mat = M;

	for (int _ = 0; _ < 3; _++)
	{

		matrix *R = new matrix(R_Matrix_calc(mat));
		matrix *Q = new matrix(orthogonalization(mat));
		auto prod = matrix_product(R, Q);
		mat = new matrix(prod);
		delete R;
		delete Q;
	}

	auto Mat = rounder(mat->get_matrix());

	vector<float> eigen_values;

	const int decimal_place = 2;
	auto decimal_value = pow(10, decimal_place);
	for (int i = 0; i < Mat.size(); i++)
	{
		eigen_values.push_back(round(Mat[i][i] * decimal_value) / decimal_value);
	}

	return (eigen_values);
}
