#include "../include/SlaeSolver/lu_decomposition.h"

#include <math.h>

#define IDX2R(i, j, ncol) ((i) * (ncol) + (j))

/* INPUT: A - pointer to a square matrix having dimension N
 *        Tol - small tolerance number to detect failure when the matrix is near
 *        degenerate
 * OUTPUT: Matrix A is changed, it contains a copy of both matrices
 *         L-E and U as A=(L-E)+U such that P*A=L*U. The permutation matrix is not
 *         stored as a matrix, but in an integer vector P of size N+1 containing column
 *         indexes where the permutation matrix has "1". The last element P[N]=S+N,
 *         where S is the number of row exchanges needed for determinant
 *         computation, det(P)=(-1)^S
 */
int LUPDecompose(double *A, int N, int *P, double Tol) {
  int i, j, k, imax, m;
  double maxA, absA, tmp;

  for (i = 0; i <= N; i++)
    P[i] = i;  // Unit permutation matrix, P[N] initialized with N

  for (i = 0; i < N - 1; i++) {
    maxA = 0.;
    imax = i;

    // Find largest element below diagonal in i-th column
    for (k = i; k < N; k++)
      if ((absA = fabs(A[IDX2R(k, i, N)])) > maxA) {
        maxA = absA;
        imax = k;
      }

    if (maxA < Tol) return 1;  // failure, matrix is degenerate

    // Swap pivot row
    if (imax != i) {
      // pivoting P
      j = P[i];
      P[i] = P[imax];
      P[imax] = j;

      // pivoting rows of A
      for (m = 0; m < N; m++) {
        tmp = A[IDX2R(i, m, N)];
        A[IDX2R(i, m, N)] = A[IDX2R(imax, m, N)];
        A[IDX2R(imax, m, N)] = tmp;
      }

      // counting pivots starting from N (for determinant)
      P[N]++;
    }

    for (j = i + 1; j < N; j++) {
      // Compute multipliers
      A[IDX2R(j, i, N)] /= A[IDX2R(i, i, N)];

      // Update the remainder of the matrix
      for (k = i + 1; k < N; k++)
        A[IDX2R(j, k, N)] -= A[IDX2R(j, i, N)] * A[IDX2R(i, k, N)];
    }
  }

  return 0;  // decomposition done
}

/* INPUT: A,P filled in LUPDecompose; b - rhs vector; N - dimension
 * OUTPUT: x - solution vector of A*x=b
 */
void LUPSolve(double *A, int *P, double *b, int N, double *x) {
  for (int i = 0; i < N; i++) {
    x[i] = b[P[i]];

    for (int k = 0; k < i; k++) x[i] -= A[IDX2R(i, k, N)] * x[k];
  }

  for (int i = N - 1; i >= 0; i--) {
    for (int k = i + 1; k < N; k++) x[i] -= A[IDX2R(i, k, N)] * x[k];

    x[i] /= A[IDX2R(i, i, N)];
  }
}
