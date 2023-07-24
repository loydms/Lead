#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"
#include <random>

using std::mt19937;

class G4ParticleGun;
class G4Event;
class G4Box;


class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction() override;

    void GeneratePrimaries(G4Event*) override;

    const G4ParticleGun* GetPArticleGun() const {return fParticleGun;}
    int num;
    bool loop1;
    bool loop2;
    bool going;
    double totalWidth;

  private:
    G4ParticleGun* fParticleGun = nullptr;
    mt19937 generator;
};

#endif
