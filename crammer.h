/**
 * @file crammer.h
 * @brief This file contains implementation of crammers rule tpo solve a set of linear equations
 *
 * @author Bhamidipati Venkatakrishnasameer
 *

 */


#include <vector>
#include "matrix.h"
#include <iostream>

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

vector<float> crammer(matrix* eqn, matrix* sol);