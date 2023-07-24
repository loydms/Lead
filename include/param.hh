#ifndef param_h
#define param_h

#include "param.hh"
#include "G4PVPlacement.hh"
#include "G4VPVParameterisation.hh"
#include "G4PVParameterised.hh"
#include "G4Box.hh"



class MakePixels : public G4VPVParameterisation
{
  public:
     MakePixels(G4int       NbOfChambers,
                G4double    firstPositionY,
                G4double    firstPositionX,
                G4double    pixelSize,
                G4double    pixelWidth,
                G4int       nArrays,
                G4int       nPixels,
                G4double    gapWidth);
     ~MakePixels();
     void ComputeTransformation(const G4int copyNo,
                                G4VPhysicalVolume* physVol) const;
     void ComputeDimensions(G4Box& trackerChamber, const G4int copyNo,
                            const G4VPhysicalVolume* physVol) const;
  private:
    G4double cFirstPositionX;
    G4double cFirstPositionY;
    G4double cPixelSize;
    G4double cPixelWidth;
    G4double cGapWidth;
    G4int cArrays;
    G4int cPixels;

};

#endif
