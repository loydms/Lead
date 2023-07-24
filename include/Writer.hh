#ifndef Writer_h
#define Writer_h

#include "DetectorConstruction.hh"
#include "run.hh"
#include <iostream>


class Writer
{
  public:
    Writer();
    ~Writer();

    void addRun();
    G4double getRun();
    void addScint();
    G4double getScint();
    void increment();
    void incrementB();
    void saveLightCone();
    void doMath();
    //std::vector<std::vector<int>> array;
    //std::vector<std::vector<int>> arrayB;
    std::vector<double> sumX;
    std::vector<double> sumB;
    int row;
    void write(int particle, G4double, G4double, G4double);
    G4int n;
    G4int s;
  private:
    std::ofstream outFile;
    std::ofstream lcFile;
};

#endif
