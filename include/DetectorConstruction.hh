#ifndef DetectorConstruction_h
#define DetectorConstruction_h

#include "G4VUserDetectorConstruction.hh"
#include "materialsmanager.hh"
#include "Writer.hh"
#include "globals.hh"

/// Detector Construction class to define materials and geomatery


  class DetectorConstruction : public G4VUserDetectorConstruction
  {
    public:
      DetectorConstruction();
      ~DetectorConstruction() override;

      G4VPhysicalVolume* Construct() override;
      static Writer* GetWriter();
      static int GetPixels();
      static int GetArrays();
      static int GetTotal();
      static double GetWidth();
      static int nPixels;
      static int nArrays;
      static G4double pixelWidth;
      static G4double gapWidth;
      static Writer* writer;
  };


#endif
