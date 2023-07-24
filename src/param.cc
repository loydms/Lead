#include "param.hh"
#include "G4PVPlacement.hh"
#include "G4PVParameterised.hh"
#include "G4SystemOfUnits.hh"

MakePixels::MakePixels
          (G4int       NbOfChambers,
           G4double    firstPositionY,
           G4double    firstPositionX,
           G4double    pixelSize,
           G4double    pixelWidth,
           G4int       nArrays,
           G4int       nPixels,
           G4double    gapWidth)
           {
            cFirstPositionX = firstPositionX;
            cFirstPositionY = firstPositionY;
            cPixelWidth = pixelWidth;
            cPixelSize = pixelSize;
            cGapWidth = gapWidth;
            cArrays = nArrays;
            cPixels = nPixels;

            G4cout << "Making an array of:" << G4endl;
            G4cout << nArrays * nArrays << " detectors and" << G4endl;
            G4cout << nPixels * nPixels << " pixels per detector" << G4endl;
            G4cout << "for a total of " << NbOfChambers << " Pixels" << G4endl;

           }
MakePixels::~MakePixels(){}


void MakePixels::ComputeTransformation
  (const G4int copyNo, G4VPhysicalVolume* physVol) const
{
  int xCol = copyNo % (cPixels * cArrays);
  int yRow = copyNo / (cPixels * cArrays);
  G4double Xposition = (cPixelSize + cGapWidth) * xCol + cFirstPositionX;
  G4double Yposition = (cPixelSize + cGapWidth) * yRow + cFirstPositionY;
  // Gap between arrays
  if (false){
  for (int count{1}; count <= cArrays; ++ count)
  {
  if (xCol > count * cPixels -1) {Xposition += cGapWidth;}
  if (yRow > count * cPixels - 1)  {Yposition += cGapWidth;}
  }}
  else if(false){Xposition +=cGapWidth;}
  else if(false){Yposition +=cGapWidth;}
  G4ThreeVector origin(Xposition*cm, Yposition*cm, 0);
  physVol->SetTranslation(origin);
  physVol->SetRotation(0);
}

void MakePixels::ComputeDimensions
  (G4Box& trackerChamber, const G4int copyNo,
   const G4VPhysicalVolume* physVol) const
{
  trackerChamber.SetXHalfLength(0.5 * cPixelSize*cm);
  trackerChamber.SetYHalfLength(0.5 * cPixelSize*cm);
  trackerChamber.SetZHalfLength(0.5 * cPixelWidth*cm);
}
