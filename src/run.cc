#include "run.hh"
#include "DetectorConstruction.hh"
#include "Writer.hh"
#include "gaussfit.hh"
#include <string>
#include <math.h>
#include <numeric>
#include <iostream>


Run::Run() {
  G4cout << "Creating Run..." << G4endl;
  event = true;
  countTotal = 0;
  rawData = false;
  part = 0;
  row = DetectorConstruction::GetPixels() * DetectorConstruction::GetArrays();
  width = DetectorConstruction::GetWidth();
  e1 = 0;
  e2 = 0;
  e3 = 0;
  //array = std::vector<std::vector<int>>(row, std::vector<int>(row, 0));
  //array2 = std::vector<std::vector<int>>(row, std::vector<int>(row, 0));
  //lcFile.open("lightcone.txt");
  //if (!lcFile.good()){std::cerr << "Run::Run() unable to open lightcone.txt" << std::endl;}
  if(rawData)
  {
    rawFile.open("raw.txt");
    if (!rawFile.good()) {
      std::cerr << "Run::Run(): unable to open raw.txt" << std::endl;}
  }
  G4cout << "...done." << G4endl << G4endl;
}

Run::~Run()
{
  //endRun();
  //if (countTotal > 10)
  //saveNeutrons();
  if(rawData)
  rawFile.close();
  G4cout << "Deleting Run..." << G4endl;

  G4cout << "...done." << G4endl;
}

G4double Run::getTotalCounts(){return countTotal;}
G4double Run::getCurrentCount(){return countCurrent;}
void Run::clearCurrent()
{
  countCurrent = 0;
  e1 = 0;
  e2 = 0;
  e3 = 0;
}
void Run::setParticle(int id){part = id;}
/*
void Run::clearArray()
{
  G4cout << "Clearing Array" << G4endl;
  countTotal = 0;
  array = std::vector<std::vector<int>>(row, std::vector<int>(row, 0));
}
*/
/*
void Run::endRun()
{
  doMath();
  if (event)
  {
    for (int i=0; i < row; i ++)
    {
      rawFile << sumX[i] << " " << sumY[i] << std::endl;
    }
  }
}
*/
double Run::calculateAverage()
{
  auto writer = DetectorConstruction::GetWriter();
  double average = countTotal/writer->getScint();
  countTotal = 0;
  return average;
}

void Run::saveNeutrons()
{
  for (int i=0; i < row; i ++)
  {
    lcFile << sumX[i] << " " << sumY[i] << ' ' << body << std::endl;
  }
}


void Run::addEnergy(int id, G4double energy)
{
  if (id == 1){e1 += energy;}
  if (id == 2){e2 += energy;}
  if (id == 3){e3 += energy;}
  //std::cout << "e1 : " << e1 <<std::endl;
  //std::cout << "e3 : " << e3 <<std::endl;
  //if ((e1 > 5) || (e2 > 5) || (e3 > 5))
  //{std::cout << "Value too high" << std::endl;}
}
/*
void Run::increment2(int i, int j)
{
  array2[i][j] ++;
  countTotal ++;
  countCurrent ++;
}
*/
//Location of Actual Scintillation Event
void Run::setValues(double x, double y)
{
  eventX = x;
  eventY = y;
}
double Run::getValueX(){return eventX;}
double Run::getValueY(){return eventY;}
/*
void Run::doMath()
{
  event = false;
  total = 0;
  int xS{};
  int yS{};
  for (int i = 0; i < row; i++)
  {
    xS = 0;
    yS = 0;
    for (int j = 0; j < row; j++)
    {
      xS += array[i][j];
      yS += array[j][i];
    }
    total += xS;
    sumX.push_back(xS);
    sumY.push_back(yS);
    if(total)
    {
      event=true;
    }
  }
}
*/
void Run::setBody(G4String name)
{
  body = name;
}

void Run::saveData()
{
  auto writer = DetectorConstruction::GetWriter();
  // 0 is first, 1 is second (on diffuser)
  writer->write(part, e1, e2, e3);
}

G4double Run::eSum(){return e1 + e2 + e3;}
void Run::addDataRaw(const double& x, const double& y, const int copy)
{
  rawFile << x << " " << y << " " << copy << std::endl;
  return;
}
/*
void Run::addDataClean()
{
  calcX = 0;
  calcY = 0;


  outFile << eventX << " " << eventY << " "
          << calcX << " " << calcY << std::endl;
  return;
}
*/
