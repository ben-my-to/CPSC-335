#include <vector>

using namespace std;

typedef vector<vector<size_t>> mat;

mat MatrixMultiplication(const mat& A, const mat& B) {
    mat C = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    for (size_t i = 0; i < A.size(); i++) {
        for (size_t j = 0; j < B.size(); j++) {
            for (size_t k = 0; k < A.size(); k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}