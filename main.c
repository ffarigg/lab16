#include "libs/data_structures/matrix/matrix.h"

int getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int max(int a, int b) {
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int n = m.nRows + m.nCols - 2;
    int maxesOfPseudoDiagonal[n];
    for (size_t i = 0; i < n; i++)
        maxesOfPseudoDiagonal[i] = 0;
    int indexPseudoDiagonalElement;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (j != i) {
                if (i > j)
                    indexPseudoDiagonalElement = j - i + m.nRows - 1;
                else
                    indexPseudoDiagonalElement = j - i + m.nRows - 2;
                maxesOfPseudoDiagonal[indexPseudoDiagonalElement] =
                        max(maxesOfPseudoDiagonal[indexPseudoDiagonalElement],
                            m.values[i][j]);
            }
    return getSum(maxesOfPseudoDiagonal, n);
}

int main() {
    int nRows1, nCols1;
    scanf("%d %d", &nRows1, &nCols1);
    matrix m = getMemMatrix(nRows1, nCols1);
    inputMatrix(m);
    printf("%lld", findSumOfMaxesOfPseudoDiagonal(m));
    return 0;
}



