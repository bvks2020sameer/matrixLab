# CMakeList.txt : CMake project for MatrixLab, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("matrixLab")

# Add source to this project's executable.

add_executable (Vector "vector.cpp" "vector.h" "unittests/vector_test.cpp") 

add_executable (Matrix "matrix.cpp" "matrix.h" "unittests/matrix_test.cpp") 

add_executable (Crammer "crammer.cpp" "crammer.h" "unittests/crammer_test.cpp") 

add_executable (Orthogonalization "orthogonalization.cpp" "orthogonalization.h" "unittests/orthogonalization_test.cpp") 

add_executable (Eigen "eigen.cpp" "eigen.h" "unittests/eigen_test.cpp")

add_executable (matrixLab "matrixLab.cpp" "matrixLab.h" )

