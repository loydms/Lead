#ifndef _MATERIALSMANAGER_H_
#define _MATERIALSMANAGER_H_
// MPND
// Geant4
#include "G4Material.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalSkinSurface.hh"
// ROOT
// std
#include <string>
#include <array>


//   * Material::NAME, e.g. Material::Vacuum. */
  namespace Material {
    /*! Number of custom materials. */
    int const NMATERIALS = 10;
    /*! Enum list of materials. */
    enum Type {Air, Teflon, Quartz, PWO, Lead_glass, GS20, Diff, Silicone, SiPM, Galactic};
    /*! String list of materials. */
    std::string const TypeString[NMATERIALS] = {
      "air", "teflon", "quartz", "pwo", "lead_glass", "gs20", "diff", "silicone", "sipm", "galactic"
    };
    // /*! Number of custom reflectors. */
    // int const NREFLECTORS = 2;
    // /*! Enum list of reflectors. */
    // enum ReflectorType {Teflon, ESR};
    // /*! String list of reflectors. */
    // std::string const ReflectorTypeString[NREFLECTORS] = {"teflon", "esr"};
  }
  /*! \class MaterialsManager
   * Singleton that manages all custom materials and reflectors. */
  class MaterialsManager {
    public:
      /*! Globally access the instance of this singleton. */
      static MaterialsManager& get() {
        static MaterialsManager manager;
        return manager;
      }
      /*! Destructor. */
      ~MaterialsManager();
      /*! Copy constructor - deleted. */
      MaterialsManager(MaterialsManager const&) = delete;
      /*! Assignment operator - deleted. */
      void operator=(MaterialsManager const&) = delete;

      /*! Get the pointer to a material. */
      G4Material* get(Material::Type const& a_type) const;
      // /*! Get the pointer to a reflector. */
      //G4OpticalSurface* get(G4String const& a_name,
      //                      ReflectorType const& a_ref_type,
      //                      G4OpticalSurfaceFinish const& a_finish);

    private:
      /*! Constructor. */
      MaterialsManager();
      /*! List of materials. */
      std::array<G4Material*, Material::NMATERIALS> m_materials;
      /*! Top level build function. */
      void buildAll();
      /*! Build custom isotopes and elements. */
      void buildElements();
      /*! Build air - uses G4_AIR. */
      void buildAir();
      /* teflon, duh */
      void buildTeflon();
      /* Sandwich materials */
      void buildQuartz();
      void buildPWO();
      void buildLeadGlass();
      /*! Build GS20 - 6Li-enriched glass scintillator. */
      void buildGS20();
      /*! Build SiPM - just Si */
      void buildSiPM();
      /*! Build Diffuser*/
      void buildDiff();
      /*! Build Silicone*/
      void buildSilicone();
      /*! Build Galactic*/
      void buildGalactic();
    };

#endif
