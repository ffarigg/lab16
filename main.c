#include "libs/data_structures/matrix/matrix.h"

long long max(long long a, long long b) {
    return a > b ? a : b;
}

int getNSpecialElement(matrix m) {
    int countSpecialEl = 0;
    for (int i = 0; i < m.nCols; i++) {
        long long sumCol = 0;
        long long maxInCol = m.values[0][i];
        for (int j = 0; j < m.nRows; j++) {
            sumCol += m.values[j][i];
            if (maxInCol < m.values[j][i])
                maxInCol = m.values[j][i];
        }
        if (maxInCol > sumCol - maxInCol)
            countSpecialEl += 1;
    }
    return countSpecialEl;
}

int main() {
    int nRows1, nCols1;
    scanf("%d %d", &nRows1, &nCols1);
    matrix m1 = getMemMatrix(nRows1, nCols1);
    inputMatrix(m1);
    printf("%d", getNSpecialElement(m1));
    return 0;
}

