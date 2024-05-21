#include "libs/data_structures/matrix/matrix.h"

int main(){
    int nRows, nCols;
    scanf("%d %d", &nRows, &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(m);

    position p2 = getMaxValuePos(m);
    position p1 = getMinValuePos(m);
    swapRows(m, p1.rowIndex, p2.rowIndex);

    outputMatrix(m);

    return 0;
}
