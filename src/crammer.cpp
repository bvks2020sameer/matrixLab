/**
 * @file crammer.cpp
 * @brief This file contains implementation of crammers rule tpo solve a set of linear equations
 *
 * @author Bhamidipati Venkatakrishnasameer
 *

 */

#include <vector>
#include "matrix.cpp"
#include <iostream>
#pragma once

/**
 * @brief Checks if a matrix is square.
 *
 * This function checks if the given matrix is square, i.e., if it has the same number of rows and columns.
 *
 * @param A Pointer to the matrix to be checked.
 * @return True if the matrix is square, false otherwise.
 */

bool square_matrix_checker(matrix* A) {

	vector<int> A_dims = A->get_dimensions();
	if (A_dims[0] == A_dims[1]) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * @brief Checks if a given solution vector is valid for a system of equations.
 *
 * This function checks if the given solution vector is valid for a system of equations represented by a matrix.
 *
 * @param eqn Pointer to the matrix representing the system of equations.
 * @param sol Pointer to the matrix representing the solution vector.
 * @return True if the solution vector is valid, false otherwise.
 */

bool solution_vector_checker(matrix* eqn, matrix* sol) {

	vector<int> eqn_dims = eqn->get_dimensions();
	vector<int> sol_dims = sol->get_dimensions();
	if (square_matrix_checker(eqn)) {

		if (sol_dims[1] == 1 && sol_dims[0] == eqn_dims[0]) {
			return true;
		}

		else {
			return false;
		}
	}
	else {
		return false;
	}
}


/**
 * @brief Creates a new matrix by replacing a column of one matrix with a column from another matrix.
 *
 * This function creates a new matrix by replacing the specified column of the first matrix
 * with the column vector from the second matrix.
 * Helper function for crammer function
 *
 * @param eqn Pointer to the matrix from which the column will be replaced.
 * @param sol Pointer to the matrix containing the column vector to replace with.
 * @param j Index of the column to be replaced in the first matrix.
 * @return Pointer to the newly created matrix.
 */

matrix* matrix_maker(matrix* eqn, matrix* sol , int j) {

	int n = eqn->get_dimensions()[0];
	vector<vector<float>> M = eqn->get_matrix();
	vector<vector<float>> S = sol->get_matrix();


	for (int i = 0; i < n; i++) {

		M[i][j] = S[i][0];

	}
		
	matrix* mat = new matrix(M);

	return(mat);

}


/**
 * @brief Solves a system of linear equations using Cramer's rule.
 *
 * This function solves a system of linear equations represented by a matrix
 * and a solution vector using Cramer's rule.
 *
 * @param eqn_mat Pointer to the matrix representing the system of linear equations.
 * @param sol Pointer to the matrix representing the solution vector.
 * @return A vector containing the solutions for each variable.
 */

vector<float> crammer(matrix* eqn_mat, matrix* sol) {
	
	vector<float> out;

	vector<vector<float>> Eqn = transpose(eqn_mat);
	matrix* eqn = new matrix(Eqn);


	if (solution_vector_checker(eqn, sol)) {

		int n = eqn->get_dimensions()[0];

		float A = determinant(eqn);

		for (int i = 0; i < n; i++) {

			float Ai = determinant(matrix_maker(eqn, sol, i));
			out.push_back(Ai/A);
		}

	}
	else {
		cout << "Invalid equations";
	}

	return out;
}