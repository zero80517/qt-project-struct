#ifndef LU_DECOMPOSITION_H
#define LU_DECOMPOSITION_H

int LUPDecompose(double *A, int N, int *P, double Tol);
void LUPSolve(double *A, int *P, double *b, int N, double *x);

#endif // LU_DECOMPOSITION_H
