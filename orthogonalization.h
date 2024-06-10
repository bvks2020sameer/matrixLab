/**
 * @file orthogonalization.h
 * @brief This file contains implementation of Gramm-Schmidt Orthogonalization technique
 *
 * @author Bhamidipati Venkatakrishnasameer
 */

#include <iostream>
#include <vector>
#include "vector.h"
#include "matrix.h"
#pragma once


using namespace std;

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

vector < vector<float>> orthogonalization(matrix* A);