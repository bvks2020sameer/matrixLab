/**
 * @file vector.h
 * @brief This file contains multiple functions and methods required for various Vector operations
 *
 * @author Bhamidipati Venkatakrishnasameer
 *
 */

#include <iostream>
#include <vector>
#include <math.h>

/**
 * @brief Calculates the magnitude of a vector.
 *
 * This function takes a vector of floats as input and returns its magnitude.
 * The magnitude (or length) of the vector is calculated using the Euclidean norm.
 *
 * @param V A vector of floats representing the vector.
 * @return The magnitude of the vector as a float.
 */

float vector_magnitude(std::vector<float> V); 

/**
 * @brief Adds multiple vectors element-wise.
 *
 * This function takes a vector of vectors as input and returns a single vector
 * representing the element-wise sum of the input vectors. All input vectors
 * must be of the same size.
 *
 * @param V_inp A vector of vectors of floats to be added.
 * @return A vector of floats representing the element-wise sum of the input vectors.
 * @throws std::invalid_argument if the input vectors are not all of the same size.
 */

std::vector<float> vector_add(std::vector<std::vector<float>> V_inp);

/**
 * @brief Calculates the dot product of two vectors.
 *
 * This function takes a vector of two vectors as input and returns the dot product.
 * Both vectors must be of the same size.
 *
 * @param V_inp A vector of two vectors of floats.
 * @return The dot product of the two vectors as a float.
 * @throws std::invalid_argument if there are not exactly two vectors or if the vectors are not of the same size.
 */

float dot_product(std::vector<std::vector<float>> V_inp);

/**
 * @brief Multiplies each element of a vector by a constant.
 *
 * This function takes a vector and multiplies each of its elements by a constant,
 * returning a new vector with the results.
 *
 * @param V The input vector.
 * @param k The constant to multiply each element by.
 * @return A new vector containing the result of the multiplication.
 */

std::vector<float> vector_constant_multiplier(std::vector<float> V, float k);
