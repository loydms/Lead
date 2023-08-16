#include "DetectorConstruction.hh"
#include "materialsmanager.hh"
#include "param.hh"
#include "Writer.hh"
//Instanciated here because Detector construction only called once

#include "G4RunManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemofUnits.hh"
#include "G4VisAttributes.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4SubtractionSolid.hh"

G4int DetectorConstruction::nArrays = 2;
G4int DetectorConstruction::nPixels = 8;
Writer* DetectorConstruction::writer = new Writer;
G4double DetectorConstruction::pixelWidth = 0.63;
G4double DetectorConstruction::gapWidth = 0.085;

DetectorConstruction::DetectorConstruction(){
  G4cout << "DC - Construct" << G4endl;
}

DetectorConstruction::~DetectorConstruction(){delete writer;}

int DetectorConstruction::GetPixels(){return nPixels;}
Writer* DetectorConstruction::GetWriter(){return writer;}

int DetectorConstruction::GetArrays(){return nArrays;}
int DetectorConstruction::GetTotal(){return nPixels*nPixels*nArrays*nArrays;}
double DetectorConstruction::GetWidth(){return pixelWidth;}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  G4double scintWidth = 0.05;
  G4double scintGap = 0.1;
  G4double diffWidth = 0.38;
  //G4double squareSide = 15.7;
  G4double squareSide = nArrays*nPixels*(pixelWidth + gapWidth);
  G4bool checkOverlaps = true;
  // World

  //Half of size of cube- 20 x 20 x 20 cm world
  G4double worldSizeXYZ = 10 * cm;

  auto airM = Material::Type::Galactic;
  G4Material* air = MaterialsManager::get().get(airM);

  G4Box* solidWorld =
    new G4Box("World",
        worldSizeXYZ,
        worldSizeXYZ,
        worldSizeXYZ);

  G4LogicalVolume* logicWorld =
    new G4LogicalVolume(solidWorld, //solid
                        air,  //material
                        "World");   //name

  G4VPhysicalVolume* physWorld =
    new G4PVPlacement(0,                //rotation
                      G4ThreeVector(),  //location (0,0,0)
                      logicWorld,       //logical volume
                      "World",          //name
                      0,                //mother volume
                      false,            //no boolean operation
                      0,                //copy number
                      checkOverlaps);

  // GS20 Scintillator
  auto material = Material::Type::GS20;
  G4Material* gs20 = MaterialsManager::get().get(material);



  // have to half the side lengths
  G4Box* scint1 =
    new G4Box("Scintillator1",
              0.5 * squareSide*cm, 0.5 * squareSide*cm, 0.5 * scintWidth * cm);


    G4LogicalVolume* logicScint1 =
    new G4LogicalVolume(scint1,
                        gs20,
                        "Scint1");
  //Vis Settings
  G4Colour blue(0, 0, 1);
  G4VisAttributes* scintColor = new G4VisAttributes(blue);
  logicScint1->SetVisAttributes(scintColor);
  // Back scintillator
  G4VPhysicalVolume* scintPhys1 = new G4PVPlacement(0,
                    G4ThreeVector(0,0,-(scintGap + scintWidth)*cm),
                    logicScint1,
                    "Scint1",
                    logicWorld,
                    false,
                    0,
                    checkOverlaps);

  // Sandwich spacer
  //auto sM = Material::Type::Quartz;
  //auto sM = Material::Type::PWO;
  auto sM = Material::Type::Lead_glass;
  G4Material* spacermat = MaterialsManager::get().get(sM);

  if (scintGap){
  G4Box* spacer =
    new G4Box("spacer",
              0.5 * squareSide*cm, 0.5 * squareSide*cm, 0.5 * scintGap*cm);

  G4LogicalVolume* logicSpacer =
    new G4LogicalVolume(spacer,
                        spacermat,
                        "spacer");

  G4VPhysicalVolume* spacerPhys = new G4PVPlacement(0,
                    G4ThreeVector(0,0,-0.5*(scintGap+scintWidth)*cm),
                    logicSpacer,
                    "Spacer",
                    logicWorld,
                    false,
                    0,
                    checkOverlaps);
}
  // GS20 Scintillator 2


  // have to half the side lengths
  G4Box* scint2 =
    new G4Box("Scintillator2",
              0.5 * squareSide*cm, 0.5 * squareSide*cm, 0.5 * scintWidth * cm);


    G4LogicalVolume* logicScint2 =
    new G4LogicalVolume(scint2,
                        gs20,
                        "Scint2");

  //Vis Settings
  logicScint2->SetVisAttributes(scintColor);
  if (scintGap){
  G4VPhysicalVolume* scintPhys2 = new G4PVPlacement(0,
                    G4ThreeVector(0,0,0),
                    logicScint2,
                    "Scint2",
                    logicWorld,
                    false,
                    0,
                    checkOverlaps);
    }
/*
  auto boroM = Material::Type::Diff;
  G4Material* boro = MaterialsManager::get().get(boroM);
  // Diffuser

  G4Box* glass =
    new G4Box("Glass",
              0.5 * squareSide*cm, 0.5 * squareSide*cm, 0.5 * diffWidth*cm);


  G4LogicalVolume* logicGlass =
    new G4LogicalVolume(glass,
                        boro,
                        "Glass");

  G4VPhysicalVolume* diffPhys = new G4PVPlacement(0,
                    G4ThreeVector(0,0,(0.5 * (diffWidth+scintWidth))*cm),
                    logicGlass,
                    "Diffuser",
                    logicWorld,
                    false,
                    0,
                    checkOverlaps);
*/
  //Silicone Cookie

  // Teflon edge
  /*
  auto tefm = Material::Type::Teflon;
  G4Material* tef = MaterialsManager::get().get(tefm);

  G4double wrapWidth = (0.5*(diffWidth+scintWidth*2+scintGap)+0.2);
  G4Box* outer = new G4Box("out",
                          (0.5*squareSide + 0.1)*cm, (0.5*squareSide + 0.1)*cm,
                          wrapWidth * cm);
  G4Box* inner = new G4Box("in",
                          (0.5*squareSide)*cm, (0.5*squareSide)*cm,
                          wrapWidth * cm);

  G4SubtractionSolid* wrap = new G4SubtractionSolid("wrap",outer,inner);

  G4LogicalVolume* logicWrap = new G4LogicalVolume(wrap, tef, "wrap");

  G4VPhysicalVolume* wrapPhys = new G4PVPlacement(0,
                      G4ThreeVector(0,0,
                       -(wrapWidth - 0.5*scintWidth - diffWidth - 0.05)*cm),
                      logicWrap,
                      "Wrap",
                      logicWorld,
                      false,
                      0,
                      checkOverlaps);

  //Vis Settings
  G4Colour wrapColor(0,1,1);
  G4VisAttributes* wrapVis = new G4VisAttributes(wrapColor);
  logicWrap->SetVisAttributes(wrapVis);
  logicWrap->SetVisAttributes(false);

  //Teflonback



  G4Box* cap = new G4Box("cap",
            0.5 * squareSide * cm, 0.5 * squareSide*cm,
                         0.5 *  0.1 * cm);

  G4LogicalVolume* logicCap = new G4LogicalVolume(cap, tef, "cap");

  G4VPhysicalVolume* capPhys = new G4PVPlacement(0,
                      G4ThreeVector(0,0,
                       -(1.5*scintWidth + scintGap + 0.5* 0.1) * cm),
                      logicCap,
                      "Cap",
                      logicWorld,
                      false,
                      0,
                      checkOverlaps);

  //Vis Settings
  G4Colour capColour(0,1,1);
  G4VisAttributes* capVis = new G4VisAttributes(capColour);
  logicCap->SetVisAttributes(capVis);
  logicCap->SetVisAttributes(false);
  */
  /*
   * Single Detector
  //SiPM Detector - just a single surface for now
  */
  auto siM = Material::Type::SiPM;
  G4Material* Si = MaterialsManager::get().get(siM);
  /*
  G4Box* det =
    new G4Box("SiPM",
              0.5 * squareSide*cm, 0.5 * squareSide*cm, 0.5 * cm);


    G4LogicalVolume* logicSi =
    new G4LogicalVolume(det,
                        Si,
                        "Detector");

  //Vis Settings
  G4Colour red(1, 0, 0);
  G4VisAttributes* siColor = new G4VisAttributes(red);
  logicSi->SetVisAttributes(siColor);

  G4VPhysicalVolume* siPhys = new G4PVPlacement(0,
                    G4ThreeVector(0,0,
                      (0.5*(scintWidth + 1)+diffWidth+cookieWidth)*cm),
                    logicSi,
                    "Det",
                    logicWorld,
                    false,
                    0,
                    checkOverlaps);
  */
  // Pixel array
  //Parameters
  G4double detectorWidth = 0.1;
  G4double positionZ = 0.5 * (scintWidth + detectorWidth)+diffWidth;
  //G4int NbOfPixelsX = nPixels * nArrays;
  //G4int NbOfPixelsY = nPixels * nArrays;
  //G4double gapWidth = 0.1;
  //G4double firstPositionX = -squareSide / 2 + (pixelWidth + gapWidth) / 2;
  //G4double firstPositionY = -squareSide / 2 + (pixelWidth + gapWidth) / 2;
  //Mother volume for pixels.  Only pixels can be in this volume
  // Air and invisible. Should not affect photons
/*
  G4Box* pixelMother = new G4Box("pMother", (squareSide / 2)*cm,
                                            (squareSide / 2)*cm,
                                            (detectorWidth / 2)   *cm);

  auto galM = Material::Type::Galactic;
  G4Material* galactic = MaterialsManager::get().get(galM);

  auto logicPixelMother = new G4LogicalVolume(pixelMother, Si,
                                              "pMotherLogic");

  G4VPhysicalVolume* pMotherPhys = new G4PVPlacement(0,
              G4ThreeVector(0,0,positionZ*cm),
              logicPixelMother,
              "Det",
              logicWorld,
              false,
              0,
              checkOverlaps);
              */
/*
  //G4Box* pixelS = new G4Box("pixel", 1*cm, 1*cm, 1*cm);
  //auto logicChamber = new G4LogicalVolume(pixelS, Si, "pixelLogic");

  //G4VPVParameterisation* chamberParam =
  //  new MakePixels(NbOfPixelsX * NbOfPixelsY, firstPositionY, firstPositionX,
                   pixelWidth, detectorWidth, nArrays, nPixels,
                   gapWidth);

  //G4VPhysicalVolume* physArray =
  // new G4PVParameterised( "Det", logicChamber, logicPixelMother,
                          kUndefined,
                          NbOfPixelsX*NbOfPixelsY, chamberParam, false);
  //G4Colour red(1, 0, 0);
  //G4VisAttributes* siColor = new G4VisAttributes(red);
  //logicChamber->SetVisAttributes(siColor);

*/
  //Surfaces
  //Between scintillator and world - reflective teflon like
  /*
  G4OpticalSurface* ScintWrap1 = new G4OpticalSurface("Wrap1");
  new G4LogicalBorderSurface("Wrap1", scintPhys1, capPhys, ScintWrap1);
  G4OpticalSurface* ScintWrap2 = new G4OpticalSurface("Wrap2");
  new G4LogicalBorderSurface("Wrap2", scintPhys1, wrapPhys, ScintWrap2);
  G4OpticalSurface* ScintWrap3 = new G4OpticalSurface("Wrap1");
  new G4LogicalBorderSurface("Wrap3", scintPhys2, wrapPhys, ScintWrap3);
  G4OpticalSurface* GapWrap = new G4OpticalSurface("Wrap2");
  new G4LogicalBorderSurface("Wrap4", spacerPhys, wrapPhys, GapWrap);
  ScintWrap1->SetModel(glisur);
  ScintWrap1->SetType(dielectric_LUT);
  ScintWrap1->SetFinish(polishedtioair);
  ScintWrap2->SetModel(glisur);
  ScintWrap2->SetType(dielectric_LUT);
  ScintWrap2->SetFinish(polishedtioair);
  ScintWrap3->SetModel(glisur);
  ScintWrap3->SetType(dielectric_LUT);
  ScintWrap3->SetFinish(polishedtioair);
  GapWrap->SetModel(glisur);
  GapWrap->SetType(dielectric_LUT);
  GapWrap->SetFinish(polishedtioair);
  G4double energy[2] = {1*eV, 10*eV};
  G4double reflectivity[2] = {1,1};
  G4double reflectivity2[2] = {0.5,0.5};
  G4MaterialPropertiesTable *SMPT = new G4MaterialPropertiesTable();
  G4MaterialPropertiesTable *SMPT2 = new G4MaterialPropertiesTable();

  SMPT->AddProperty("REFLECTIVITY",energy,reflectivity,2);
  SMPT2->AddProperty("REFLECTIVITY",energy,reflectivity2,2);
  ScintWrap1->SetMaterialPropertiesTable(SMPT);
  ScintWrap2->SetMaterialPropertiesTable(SMPT2);
  ScintWrap3->SetMaterialPropertiesTable(SMPT2);
  GapWrap->SetMaterialPropertiesTable(SMPT2);
  */
/*
  G4OpticalSurface* ScintCap = new G4OpticalSurface("Cap");
  new G4LogicalBorderSurface("Cap", capPhys, scintPhys1, ScintCap);
  ScintWrap->SetModel(glisur);
  ScintWrap->SetType(dielectric_dielectric);
  ScintWrap->SetFinish(groundtioair);
  G4MaterialPropertiesTable *CPT = new G4MaterialPropertiesTable();

  CPT->AddProperty("REFLECTIVITY",energy,reflectivity,2);
  ScintCap->SetMaterialPropertiesTable(CPT);



  G4OpticalSurface* ScintWrap2 = new G4OpticalSurface("Wrap2");
  new G4LogicalBorderSurface("Wrap2", wrapPhys, scintPhys2, ScintWrap2);
  ScintWrap2->SetModel(glisur);
  ScintWrap2->SetType(dielectric_dielectric);
  ScintWrap2->SetFinish(polishedtioair);
  G4MaterialPropertiesTable *SMPT2 = new G4MaterialPropertiesTable();

  SMPT2->AddProperty("REFLECTIVITY",energy,reflectivity,2);
  ScintWrap->SetMaterialPropertiesTable(SMPT2);

  //Between diffuser and world - ground

  G4OpticalSurface* diffEdge = new G4OpticalSurface("edge");
  new G4LogicalBorderSurface("edge", physWorld, diffPhys, diffEdge);
  new G4LogicalBorderSurface("spacerWorld",spacerPhys, physWorld,diffEdge);
  diffEdge->SetModel(glisur);
  diffEdge->SetType(dielectric_dielectric);
  diffEdge->SetFinish(groundteflonair);
  G4double reflectivityDiff[2] = {0.5,0.5};
  G4MaterialPropertiesTable *DiffTable = new G4MaterialPropertiesTable();

  DiffTable->AddProperty("REFLECTIVITY",energy,reflectivityDiff,2);
  diffEdge->SetMaterialPropertiesTable(DiffTable);


  G4OpticalSurface* sipmFace = new G4OpticalSurface("sipmFace");
  new G4LogicalBorderSurface("sipmFace", physArray, diffPhys, sipmFace);
sipmFace->SetModel(glisur);
sipmFace->SetType(dielectric_metal);
sipmFace->SetFinish(polished);
G4double reflectivitySipm[2] = {0,0};
G4MaterialPropertiesTable *SipmTable = new G4MaterialPropertiesTable();

SipmTable->AddProperty("REFLECTIVITY",energy,reflectivitySipm,2);
sipmFace->SetMaterialPropertiesTable(SipmTable);
*/

  return physWorld;

}
