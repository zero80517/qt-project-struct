#ifndef SLAESOLVER_H
#define SLAESOLVER_H

#include "./SlaeSolver_global.h"

class SLAESOLVER_EXPORT SlaeSolver
{
public:
    SlaeSolver();
    static constexpr double absTol_ = 1e-15;
    static int LUP(double *matrixA, double *vectorB, double *vectorX, int dim);
};

#endif // SLAESOLVER_H
