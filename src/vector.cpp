/**
 * @file vector.cpp
 * @brief This file contains multiple functions and methods required for various Vector operations
 *
 * @author Bhamidipati Venkatakrishnasameer
 *
 */

#include <vector>
#include <iostream>
#include <math.h>
#pragma once

using namespace std;


/**
 * @brief Calculates the magnitude of a vector.
 *
 * This function takes a vector of floats as input and returns its magnitude.
 * The magnitude (or length) of the vector is calculated using the Euclidean norm.
 *
 * @param V A vector of floats representing the vector.
 * @return The magnitude of the vector as a float.
 */


float vector_magnitude(vector<float> V) {

	auto size = V.size();
	float sum = 0;

	for (int i = 0; i < size; i++) {
		sum += V[i] * V[i];
	}

	return (float) abs(sqrt(sum));
}

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


vector<float> vector_add(vector<vector<float>> V_inp) {
	
	auto inp_size = V_inp.size();
	auto vector_size = V_inp[0].size();
	vector<float> ans(vector_size, 0);

	for (int i = 0; i < inp_size; i++) {

		
		if (V_inp[i].size() != vector_size) {
			cout << "All inner vectors must be of the same size.";
			break;
		}
		
		else {

			auto V = V_inp[i];


			for (int j = 0; j < V.size(); j++) {
				ans[j] += V[j];
			}

		}
	
	}

	return ans;
}

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

float dot_product(vector<vector<float>> V_inp) {

	auto inp_size = V_inp.size();
	auto vector_size = V_inp[0].size();
	vector<float> ans(vector_size, 1);
	float final_ans = 0;

	for (int i = 0; i < inp_size; i++) {


		if (V_inp[i].size() != vector_size) {
			cout << "All inner vectors must be of the same size.";
			break;
		}

		else {

			auto V = V_inp[i];


			for (int j = 0; j < V.size(); j++) {
				ans[j] *= V[j];
			}

		}

	}

	for (int i = 0; i < ans.size(); i++) {
		final_ans += ans[i];
	}

	return final_ans;
}

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

vector<float> vector_constant_multiplier(vector<float> V, float k) {
	vector<float> out;

	for (int i = 0; i < V.size(); i++) {

		out.push_back(k * V[i]);
	}

	return out;
}
