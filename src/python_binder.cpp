

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include<iostream>
#include <vector>

#include <string>

namespace py = pybind11;

//local library import 

#include "vector.cpp"

#include "matrix.cpp"

#include "crammer.cpp"

#include "orthogonalization.cpp"

#include "eigen.cpp"




std::string doc_string = "Python Driver for matrixLab engine";



PYBIND11_MODULE(matrixLab, handle) {

	handle.doc() = doc_string;

	//vector
	
	handle.def("vector_magnitude", &vector_magnitude , "Calculates the magnitude of a vector.");
	handle.def("vector_add" , &vector_add ,"Adds multiple vectors element-wise.");
	handle.def("dot_product", &dot_product , "Calculates the dot product of two vectors");
	handle.def("vector_constant_multiplier", &vector_constant_multiplier , "Multiplies each element of a vector by a constant.");

	// matrix 

	py::class_<matrix>(handle, "matrix")
	.def(py::init<std::vector<std::vector<float>>>())
    .def("get_dimensions",&matrix::get_dimensions,"Get Dimensions Of the Matrix")
	.def("get_matrix",&matrix::get_matrix,"Get the matrix");
	

	handle.def("matrix_add",&matrix_add,"Add 2 matrices");
	handle.def("transpose",&transpose ,"Get transpose of a matrix");
	handle.def("matrix_product",&matrix_product ,"Get Product of 2 matrices");
	handle.def("determinant",&determinant ,"Get determinant of a matrix");
	handle.def("adjoint",&adjoint ,"Get adjoint of a matrix");
	handle.def("inverse",&inverse ,"Get inverse of a matrix");

	//crammer

	handle.def("crammer",&crammer ,"solve equations using crammer's rule");

	//orthogonalization

	handle.def("orthogonalization",&orthogonalization ,"Orthogonalize a given matrix");

	//eigen 

	handle.def("R_Matrix_calc",&R_Matrix_calc ,"Find upper triangular matrix R of a given matrix");
	handle.def("eigen_values",&eigen_values ,"Find eigen values of a matrix");
	
}

