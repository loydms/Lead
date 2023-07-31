#include "DetectorConstruction.hh"
#include "run.hh"
#include "Writer.hh"

#include <iostream>
#include "G4SystemOfUnits.hh"

Writer::Writer()
{
  row = DetectorConstruction::GetPixels() * DetectorConstruction::GetArrays();
  //G4double back = 0;
  //G4double front = 0;
  n = 0;
  s = 0;
  lcFile.open("lightcone.txt");
  if (!lcFile.good()){std::cerr << "Run::Run() unable to open lightcone.txt" << std::endl;}
    G4cout << "Writer Opened" << G4endl;
    outFile.open("results.txt");
    if (!outFile.good()) {
      std::cerr << "Run::Run(): unable to open results.txt" << std::endl;}
    outFile << "Particle Energy1 Energy2 Energy3" << std::endl;
}

Writer::~Writer()
{
  G4cout << "Writer Closed" << G4endl;
  //doMath();
  //saveLightCone();
  lcFile.close();
  outFile.close();
}

void Writer::write(int particle, G4double e1, G4double e2, G4double e3)
{
  /*
  outFile << "Particle: " << particle << " ";
  outFile << "Energy 1: " << e1 << " ";
  outFile << "Energy 2: " << e2 << " ";
  outFile << "Energy 3: " << e3 << " ";
  */
  outFile << particle << " " << e1 << " " << e2 << " " << e3 << " ";
  outFile << std::endl;
}

void Writer::saveLightCone()
{
  for (int i=0; i < row; i ++)
  {
    lcFile << sumX[i] << " " << sumB[i] << " " << sumX[i] + sumB[i] << std::endl;
  }
}
/*
void Writer::increment()
{
  back ++;
}

void Writer::incrementB()
{
  front ++;
}
*/
/*
void Writer::doMath()
{

  int xS{};
  int xB{};
  for (int i = 0; i < row; i++)
  {
    xS = 0;
    xB = 0;
    for (int j = 0; j < row; j++)
    {
      xS += array[i][j];
      xB += arrayB[i][j];
    }
    sumX.push_back(xS);
    sumB.push_back(xB);

  }

}
*/
/*
*/
void Writer::addRun()
{
//outFile << "Writing from run " << n << std::endl;
n++;
};

void Writer::addScint()
{
s++;
}

G4double Writer::getScint(){return s;}
G4double Writer::getRun(){return n;}
