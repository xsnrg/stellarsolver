#ifndef EXTERNALSEXTRACTORSOLVER_H
#define EXTERNALSEXTRACTORSOLVER_H

#include "sexysolver.h"
#include <QProcess>
#include <QPointer>

class ExternalSextractorSolver : public SexySolver
{
    Q_OBJECT
public:
    explicit ExternalSextractorSolver(Statistic imagestats, uint8_t *imageBuffer, QObject *parent);

    bool sextract(bool justSextract);
    bool solveField();
    QStringList getSolverArgsList();

    QString fileToSolve;
    int selectedStar;

    //System File Paths
    QString dirPath = QDir::homePath();
    QString tempPath = QDir::tempPath();
    QStringList indexFilePaths;
    QString sextractorBinaryPath;
    QString confPath;
    QString solverPath;
    QString wcsPath;

    QString sextractorFilePath;
    QString basePath = QDir::tempPath();

    void logSolver();
    void logSextractor();
    void runExternalSextractorAndSolver();
    void abort();

    void printSextractorOutput();
    bool getSextractorTable();
    bool getSolutionInformation();

private:
    QPointer<QProcess> solver;
    QPointer<QProcess> sextractorProcess;
    // This is information about the image
    Statistic stats;

};

#endif // EXTERNALSEXTRACTORSOLVER_H
