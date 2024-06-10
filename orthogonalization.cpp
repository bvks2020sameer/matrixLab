/**
 * @file orthogonalization.cpp
 * @brief This file contains implementation of Gramm-Schmidt Orthogonalization technique
 *
 * @author Bhamidipati Venkatakrishnasameer
 */

#include <iostream>
#include <vector>
#include "vector.cpp"
#include "matrix.cpp"
#pragma once

using namespace std;

/**
 * @brief Calculates the projection constant for orthogonalization.
 *
 * This function computes the projection constant used in the Gram-Schmidt
 * process. It calculates the dot product of vector V and V1, then divides
 * it by the magnitude of V1 squared. The result is the constant needed to
 * project V onto V1.
 *
 * @param V The vector to be projected.
 * @param V1 The vector onto which V is projected.
 * @return The projection constant.
 */


float constant_calculator(vector<float> V, vector<float> V1) {
	
	vector<vector<float>> inps;
	inps.push_back(V);
	inps.push_back(V1);
	float deno = vector_magnitude(V1) * vector_magnitude(V1);
	float nume = dot_product(inps);
	float ans = -1 * (nume / deno);
	return(ans);
}

/**
 * @brief Applies the Gram-Schmidt process to orthogonalize the columns of a matrix.
 *
 * This function takes a matrix, transposes it, and then applies the Gram-Schmidt
 * process to orthogonalize its columns. The resulting orthogonal vectors are stored
 * and returned in a new matrix.
 *
 * @param A Pointer to the input matrix to be orthogonalized.
 * @return A vector of vectors representing the orthogonalized columns of the input matrix.
 */

vector<vector<float>>preprocessing(matrix* A) {
	
	vector<vector<float>> a = transpose(A);

	vector<vector<float>> out;

	vector<float> V1 = a[0];
	out.push_back(V1);

	for (int i = 1; i < a.size(); i++) {
		vector<vector<float>> inps = { a[i] };
		for (int j = 1; j <= i; j++) {
			vector<float> V = a[j];
			vector<float> V_prev = out[j - 1];
			float constant = constant_calculator(V, V_prev);
			inps.push_back(vector_constant_multiplier(V_prev, constant));
		}
		
		out.push_back(vector_add(inps));
	}
	return out;

}


/**
 * @brief Performs orthogonalization on the columns of a matrix using the Gram-Schmidt process.
 *
 * This function takes a matrix, applies the Gram-Schmidt process to orthogonalize its columns,
 * and returns the orthogonalized matrix. It first preprocesses the matrix to obtain the orthogonal
 * vectors, transposes the result, and then returns it in the original orientation.
 *
 * @param A Pointer to the input matrix to be orthogonalized.
 * @return A vector of vectors representing the orthogonalized matrix.
 */


vector < vector<float>> orthogonalization(matrix * A) {

	
	vector<vector<float>> a = preprocessing(A);
	vector<vector<float>> out;
	for (int i = 0; i < a.size(); i++) {
		vector<float> row = vector_constant_multiplier(a[i], 1 / vector_magnitude(a[i]));
		out.push_back(row);
	}
	matrix* M = new matrix(out);
	vector<vector<float>> ans = transpose(M);
	delete M;

	return ans;
}

