/*

#include "pixels.hh"
#include "materialsmanager.hh"

#include "G4Box.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

PixelArrayDetector::PixelArrayDetector(G4String const& a_name):
  BaseVolume(a_name)
{
  setDefaults();
  m_vis = new G4VisAttributes;
  m_vis->SetForceWireframe(true);
  m_vis->SetColor(G4Color::White());
}

PixelArrayDetector::~PixelArrayDetector()
{
  delete m_vis;
}

int const& PxeilArrayDetector::getNX() const { return m_nX;}

void PixelArrayDetector::setNX(int const& a_nx)
{
  m_nX = a_nX;
  return;
}

int const& PixelArrayDetector::getNY() const { return m_nY;}

void PixelArrayDetector::setNY(int const& a_nY)
{
  m_nY = a_nY;
  return;
}

void PixelArrayDetector::setDefaults()
{
  m_position = G4ThreeVector(0., 0., 0.);
  m_dimensions = G4ThreeVector(2.*mm, 2.*mm, 2.*mm);
  m_material = Material::Type::SiPM;
  m_nX = 8;
  m_nY = 8;
  return;
}

void PixelArrayDetector::build(BaseVolue* mother)
{
  auto sname = m_name + "_sipm_solid"
*/
