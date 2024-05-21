#include "libs/data_structures/matrix/matrix.h"

int getMin(int *a, int left, int right) {
 int min = a[left];
    for (int i = left + 1; i <= right; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

int getMinInArea(matrix m) {
    int minInArea;
    position maxElement = getMaxValuePos(m);
    int left = maxElement.colIndex;
    int right = maxElement.colIndex;
    for (int i = maxElement.rowIndex; i >= 0; i--) {
        int minInRow = getMin(m.values[i], left, right);
        if (i == maxElement.rowIndex || minInRow < minInArea)
            minInArea = minInRow;
        if (right < m.nCols - 1)
            right++;
        if (left > 0)
            left--;
    }
    return minInArea;
}

int main() {
    int nRows1, nCols1;
    scanf("%d %d", &nRows1, &nCols1);
    matrix m1 = getMemMatrix(nRows1, nCols1);
    inputMatrix(m1);
    printf("%d", getMinInArea(m1));
    return 0;
}
