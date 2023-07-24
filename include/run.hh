#ifndef run_h
#define run_h

#include "DetectorConstruction.hh"
#include "G4Run.hh"
#include <fstream>


class Run: public G4Run
{
  public:
    Run();
    ~Run();
    void addEnergy(int,G4double);
    G4double eSum();
    void setValues(double x, double y);
    void doMath();
    void endRun();
    G4double getTotalCounts();
    G4double getCurrentCount();
    void clearCurrent();
    void clearArray();
    void setBody(G4String);
    double getValueX();
    double getValueY();
    double calculateAverage();
    void saveNeutrons();
    void saveData();
    void setParticle(int id);
    void addDataRaw(const double& x, const double& y, const int copy);
    void addDataClean();
    G4double eventX;
    G4double eventY;
    G4double calcX;
    G4double calcY;
    bool event;
    int row;
    int total;
    G4double width;
    bool rawData;
    G4double countTotal;
    G4double countCurrent;
    G4String body;
    int part;
    G4double e1;
    G4double e2;
    G4double e3;
    std::vector<std::vector<int>> array;
    std::vector<std::vector<int>> array2;
    std::vector<double> sumX;
    std::vector<double> sumY;
    std::vector<double> gaussX;
  private:
    std::ofstream rawFile;
    std::ofstream lcFile;
};

#endif
