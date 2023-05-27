//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file B1SteppingAction.hh
/// \brief Definition of the B1SteppingAction class

#ifndef B1SteppingAction_h
#define B1SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"

class B1EventAction;

class G4LogicalVolume;

/// Stepping action class
/// 

class B1SteppingAction : public G4UserSteppingAction
{
  public:
    B1SteppingAction(B1EventAction* eventAction);
    virtual ~B1SteppingAction();

    // method from the base class
    virtual void UserSteppingAction(const G4Step*);
    void SetMuPosition(G4ThreeVector muPosition, double energy) {has_mu=true; mu_pos = muPosition; mu_energy = energy;}
    void SetEPosition(G4ThreeVector EPosition, double energy) {has_e=true; e_pos = EPosition; e_energy=energy;}
    G4ThreeVector GetMuPosition() {return mu_pos;}
    G4ThreeVector GetEPosition() {return e_pos;}
    double GetMuEnergy() {return mu_energy;}
    double GetEEnergy() {return e_energy;}
    bool is_muon_e_event() {return has_mu && has_e;}
    void Reset() {has_mu=false; has_e=false;}


  private:
    B1EventAction*  fEventAction;
    G4LogicalVolume* fScoringVolume;
    bool has_mu;
    bool has_e;
    G4ThreeVector mu_pos;
    G4ThreeVector e_pos;
    double mu_energy, e_energy;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
