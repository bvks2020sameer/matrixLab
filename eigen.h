#include<vector>

#include "matrix.h"
#include "vector.h"
#include <iostream>
#include "orthogonalization.h"

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
vector<vector<float>> R_Matrix_calc(matrix* M);

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

vector<float> eigen_values(matrix* M);
