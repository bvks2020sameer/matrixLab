import sys
path = r".\build\Debug"
sys.path.append(path)

import matrixLab

# Vector operations

print("vector ops")
v1 = [1.0, 2.0, 3.0]
v2 = [4.0, 5.0, 6.0]
print(matrixLab.vector_magnitude(v1))
print(matrixLab.vector_add([v1, v2]))
print(matrixLab.dot_product([v1, v2]))
print(matrixLab.vector_constant_multiplier(v1, 2.0))


# Matrix operations

print()
print("matrix ops")
m = matrixLab.matrix([[1.0, 2.0], [3.0, 4.0]])
print(m.get_dimensions())
print(m.get_matrix())
print(matrixLab.matrix_add(m, m))
print(matrixLab.transpose(m))
print(matrixLab.matrix_product(m, m))
print(matrixLab.determinant(m))
print(matrixLab.adjoint(m))
print(matrixLab.inverse(m))

print()

print("Crammer's rule")

s = matrixLab.matrix([[1.0, 2.0]])
print(matrixLab.crammer(m,s))

print()

print("Orthogonalization")

print(matrixLab.orthogonalization(m))

print()
print("eigen ops")

print(matrixLab.R_Matrix_calc(m))
print(matrixLab.eigen_values(m))