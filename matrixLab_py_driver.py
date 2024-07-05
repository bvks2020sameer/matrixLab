import sys
path = r".\build\Debug"
sys.path.append(path)

import matrixLab


class vector(object):

    def vector_magnitude(v : list) -> float :
        return matrixLab.vector_magnitude(v)
    
    def vector_add(v: list[list[float]]) -> list :
        return matrixLab.vector_add(v)
    
    def dot_product(v : list[list[float]]) -> float :
        return matrixLab.dot_product(v)
    
    def vector_constant_multiplier(v : list, k: float) -> list :
        return matrixLab.vector_constant_multiplier(v, k)



class matrix_object(object):

    def __init__(self, m:list[list[float]]) ->None :

        self.matrix = matrixLab.matrix(m)

    def get_dimensions(self):
        return self.matrix.get_dimensions()

    def get_matrix(self):
        return self.matrix.get_matrix()
    
   


class matrix(object):

    def matrix_add(A:matrix_object,B:matrix_object) -> list[list[float]]:
        return matrixLab.matrix_add(A, B)

    def matrix_product(A:matrix_object,B:matrix_object) -> list[list[float]]:
        return matrixLab.matrix_product(A, B)
    
    def transpose(A:matrix_object) -> list[list[float]] :
        return matrixLab.transpose(A)
    
    def adjoint(A:matrix_object) -> list[list[float]] :
        return matrixLab.adjoint(A)
    
    def determinant(A:matrix_object) -> float :
        return matrixLab.determinant(A)
    
    def inverse(A:matrix_object) -> float :
        return matrixLab.inverse(A)


class eqn_solver(object) :

    def crammer(eqn:matrix_object,sol:matrix_object) -> list:

        return matrixLab.crammer(eqn,sol)


class orthogonalization(object) :

    def orthogonalization(A:matrix_object) -> list[list[float]] :
        return matrixLab.orthogonalization(A)



class eigen(object) :

    def R_matrix_calc(A:matrix_object) -> list[list[float]] :
        return matrixLab.R_Matrix_calc(A)
    
    def eigen_values(A:matrix_object) ->  list :
        return matrixLab.eigen_values(A)