#include <QCoreApplication>

#include "../../export/slaesolver.h"

int main(int argc, char *argv[])
{
    double matrixA[] = {
        1, 2, -1,
        2, 5, -6,
        3, 8, -10
    };
    double vectorB[] = {
        3, 1, 1
    };
    double vectorX[] = {
        0, 0, 0
    };
    int dim = 3;

    SlaeSolver::LUP(matrixA, vectorB, vectorX, dim);

    printf("%f\n", vectorX[0]);
    printf("%f\n", vectorX[1]);
    printf("%f\n", vectorX[2]);

    return 0;
}
