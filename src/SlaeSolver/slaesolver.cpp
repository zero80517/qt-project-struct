#include "../../export/slaesolver.h"
#include "../include/SlaeSolver/lu_decomposition.h"

SlaeSolver::SlaeSolver()
{
}

int SlaeSolver::LUP(double *matrixA, double *vectorB, double *vectorX, int dim)
{
    int *vectorP = new int[dim + 1];
    int error = LUPDecompose(matrixA, dim, vectorP, absTol_);
    if (!error) {
        LUPSolve(matrixA, vectorP, vectorB, dim, vectorX);
    }

    delete[] vectorP;

    return error;
}
