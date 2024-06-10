#include <iostream>

using namespace std;

void clear_screen() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}


void docs() {

    std::cout << "\033[32m";
    std::cout << "                 _        _        __       _     \n";
    std::cout << " _ __ ___   __ _| |_ _ __(_)_  __ / /  __ _| |__  \n";
    std::cout << "| '_ ` _ \\ / _` | __| '__| \\ \\/ // /  / _` | '_ \\ \n";

    std::cout << "\033[34m";

    std::cout << "| | | | | | (_| | |_| |  | |>  </ /__| (_| | |_) |\n";

    std::cout << "\033[32m";

    std::cout << "|_| |_| |_|\\__,_|\\__|_|  |_/_/\\_\\____/\\__,_|_.__/ \n";
    std::cout << "                                                  \n";
    std::cout << "\033[31m";

    cout << endl << endl << endl << "Welcome To Matrix Lab";
    cout << endl<<endl<<endl;

    std::cout << "\033[36m";
    cout << "Authored and maintained by" <<"  " << "\"Bhamidipati Venkatakrishnasameer\"";
    cout << endl;

    cout << "Contact developer" << " " << "\"sameer2020bvks@gmail.com\"";
    cout << endl ;
 
    cout<< "github" << "\t" << "";
    cout << endl << endl;

    std::cout << "\033[31m";

    char key = 'B';

    while (toupper(key) != 'X') {
        cout << "Select the library you want to know more about" << endl << endl;
        cout << "1. vector.h" << endl << "2. matrix.h" << endl << "3. crammer.h" << endl << "4. orthogonalization.h" << endl << "5. eigen.h" << endl;
        cout << "Press 'X' to exit" << endl << endl;
        cin >> key;
        cout << endl << endl;
        key = toupper(key);
        switch (key) {
        case '1':     cout << "Add this to your code" << '\t' << "\033[36m" << "#include \"vector.h\"" << "\033[32m" << endl;
            cout << "This Library enables the user to perform most commonly used vector operations on a list of vectors" << endl << endl;
            cout << "\033[31m" << "float vector_magnitude(std::vector<float> V)" << "\033[32m" << endl;
            cout << "It is used to calculated the magnitude of a vector" << endl << "It takes a vector as an input and gives a float quantity as an output" << endl << endl;
            cout << "\033[31m" << "std::vector<float> vector_add(std::vector<std::vector<float>> V_inp)" << "\033[32m" << endl;
            cout << "It is used to add a set of vectors" << endl << "It takes a vector of vectors as an input and gives a vector as an output" << endl << endl;
            cout << "\033[31m" << "float dot_product(std::vector<std::vector<float>> V_inp)" << "\033[32m" << endl;
            cout << "It is used to compute dot product of vectors" << endl << "It takes a vector of vectors as an input and gives a float quantity as an output" << endl << endl;
            cout << "\033[31m" << "std::vector<float> vector_constant_multiplier(std::vector<float> V, float k)" << "\033[32m" << endl;
            cout << "It is used to multiply a vector with a constant" << endl << "It takes a vector as an input and gives a vector as an output" << endl << endl;
            break;

        case '2': cout << "Add this to your code" << '\t' << "\033[36m" << "#include \"matrix.h\"" << "\033[32m" << endl;
            cout << "This library consists of all the commonly used methods in matrix operations" << endl << endl;
            cout << "\033[35m" << "matrix class" << "\033[32m" << endl;
            cout << "It is used to validate a 2D array as a matrix" << endl << "It takes a vector of vectors as input. Method get_matrix() gives vector of vectors as output and method get_dimensions() gives vector as output " << endl << endl;
            cout << "\033[31m" << "vector<vector<float>> matrix_add(matrix * A, matrix * B)" << "\033[32m" << endl;
            cout << "It is used to add 2 matrices" << endl << "It takes matrix object A and matrix object B as an input and gives a vector of vectors as an output" << endl << endl;
            cout << "\033[31m" << "vector<vector<float>> transpose(matrix* A)" << "\033[32m" << endl;
            cout << "It is used to find transpose of a matrix" << endl << "It takes matrix object A  as an input and gives a vector of vectors as an output" << endl << endl;
            cout << "\033[31m" << "vector<vector<float>> matrix_product(matrix* A, matrix* B);" << "\033[32m" << endl;
            cout << "It is used to find matrix product of 2 matrices" << endl << "It takes matrix object A and matrix object B  as an input and gives a vector of vectors as an output" << endl << endl;
            cout << "\033[31m" << "float determinant(matrix* A) " << "\033[32m" << endl;
            cout << "It is used to find determinant of a matrix" << endl << "It takes matrix object A as an input and gives a float value as an output" << endl << endl;
            cout << "\033[31m" << "vector<vector<float>> adjoint(matrix* A) " << "\033[32m" << endl;
            cout << "It is used to find adjoint of a matrix" << endl << "It takes matrix object A as an input and gives a vector of vectors as an output" << endl << endl;
            cout << "\033[31m" << "vector<vector<float>> inverse(matrix* A) " << "\033[32m" << endl;
            cout << "It is used to find inverse of a matrix" << endl << "It takes matrix object A as an input and gives a vector of vectors as an output" << endl << endl;

            break;

        case '3': cout << "Add this to your code" << '\t' << "\033[36m" << "#include \"crammer.h\"" << "\033[32m" << endl;
            cout << "This library consists of implementations of crammers rule to solve a set of linear equations" << endl << endl;
            cout << "\033[31m" << "vector<float> crammer(matrix* eqn, matrix* sol)" << "\033[32m" << endl;
            cout << "It is used to solve a set of linear equations using crammers rule" << endl << "It takes a matrix object A and matrix object B as input and gives a vector as output " << endl << endl;
            break;

        case '4':  cout << "Add this to your code" << '\t' << "\033[36m" << "#include \"orthogonalization.h\"" << "\033[32m" << endl;
            cout << "This library consists of methods to perform orthogonalization on matrix" << endl << endl;
            cout << "\033[31m" << "vector < vector<float>> orthogonalization(matrix* A)" << "\033[32m" << endl;
            cout << "It is used to orthogonalize a matrix" << endl << "It takes a matrix object A as input and gives a vector of vectors as output " << endl << endl;
            break;

        case '5': cout << "Add this to your code" << '\t' << "\033[36m" << "#include \"eigen.h\"" << "\033[32m" << endl;
            cout << "This library consists of methods to perform eigen operations on matrix" << endl << endl;
            cout << "\033[31m" << "vector<vector<float>> R_Matrix_calc(matrix* M)" << "\033[32m" << endl;
            cout << "It is used to upper triangular matrix R for a given matrix" << endl << "It takes a matrix object A as input and gives a vector of vectors as output " << endl << endl;
            cout << "\033[31m" << "vector<float> eigen_values(matrix* M)" << "\033[32m" << endl;
            cout << "It is used to eigen values of a given matrix" << endl << "It takes a matrix object A as input and gives a vector as output " << endl << endl;
            break;

        case 'X': clear_screen();
            break;
        default: cout << "Please Enter valid option";
        }

        std::cout << "\033[31m";
    }

    std::cout << "\033[0m";
}

int main() {

    docs();
    return 0;
}