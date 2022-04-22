#include <QtTest>

// add necessary includes here
#include "../../export/slaesolver.h"

Q_DECLARE_METATYPE(double *)

class TestSlaeSolver : public QObject
{
    Q_OBJECT

public:
    TestSlaeSolver();
    ~TestSlaeSolver();

private slots:
    void LUP_data();
    void LUP();

};

TestSlaeSolver::TestSlaeSolver()
{

}

TestSlaeSolver::~TestSlaeSolver()
{

}

void TestSlaeSolver::LUP_data()
{
    QTest::addColumn<double *>("matrixA");
    QTest::addColumn<double *>("vectorB");
    QTest::addColumn<double *>("vectorX");
    QTest::addColumn<int>("dim");
    QTest::addColumn<double *>("vectorResult");

    double matrixA0[] = {
        1, 2, -1,
        2, 5, -6,
        3, 8, -10
    };
    double vectorB0[] = {
        3, 1, 1
    };
    double vectorX0[] = {
        0, 0, 0
    };
    int dim0 = 3;
    double vectorResult0[] = {
        -1, 3, 2
    };

    QTest::newRow("SlaeSolver_data0") << (double *)matrixA0 << (double *)vectorB0 << (double *)vectorX0
                                      << dim0 << (double *)vectorResult0;
}

void TestSlaeSolver::LUP()
{
    QFETCH(double *, matrixA);
    QFETCH(double *, vectorB);
    QFETCH(double *, vectorX);
    QFETCH(int, dim);
    QFETCH(double *, vectorResult);

    SlaeSolver::LUP(matrixA ,vectorB, vectorX, dim);

    bool res = true;
    for (int i = 0; i < dim; i++) {
        if (qFabs(vectorX[i] - vectorResult[i]) > 1e-15) {
            res = false;
        }
    }

    QVERIFY(res);
}

QTEST_APPLESS_MAIN(TestSlaeSolver)

#include "tst_testslaesolver.moc"
