// Dear emacs, this is -*- c++ -*-
// $Id: ElectronNtupleObject.h 37457 2010-07-05 12:04:33Z mann $

// THIS FILE HAS BEEN GENERATED AUTOMATICALLY. DO NOT EDIT DIRECTLY, CHANGES WILL BE LOST UPON NEXT CODE GENERATION.
// Code produced by Id: CodeIt.py 494 2010-07-30 13:41:32Z svn 


#ifndef SFRAME_NtupleVARIABLES_ElectronNtupleObject_H
#define SFRAME_NtupleVARIABLES_ElectronNtupleObject_H

// Local include(s):
#include "NtupleObjectNames.h"

// STL include(s):
#include <vector>
#include <string>

// ROOT include(s):
#include <TString.h>

// SFrame include(s):
#include "core/include/SError.h"
#include "core/include/SCycleBaseNTuple.h"
#include "plug-ins/include/SInputVariables.h"

namespace Ntuple {

  /**
  *  @short Class that can read the variables produced by ElectronNtupleObject
  *
  *         This class can be used to read the offline muon information from
  *         an ntuple produced by the SingleTopDPDMaker code.
  *
  * @author Code produced by Id: CodeIt.py 494 2010-07-30 13:41:32Z svn   
  *
  */
  
  enum ElectronDetails {
    ElectronBoostedID = 1,
    ElectronIsolation = 2,
    ElectronAdvancedID = 4,
    ElectronBoostedIsolation = 8,
    ElectronBasic = 16,
    ElectronSuperCluster = 32,
    ElectronID = 64,
    ElectronAll = 127,

  };
  
  // forward declaration of NtupleObjectNames
  class NtupleObjectNames;
  class ElectronNtupleObject : public SInputVariables< SCycleBaseNTuple > {

    public:
    /// Constructor specifying the parent of the object
    ElectronNtupleObject( SCycleBaseNTuple* parent );

    /// remember if connect succeeded
    void setConnectSucceeded(const unsigned int index, const bool success);
    bool getConnectSucceeded(const unsigned int index) const {return m_connectsucceeded.at(index);}  

    /// Connect the variables to the input branches
    void ConnectVariables( const TString& treeName,
                           UInt_t detail_level = 0,
                           const TString& prefix = "Electron_",
                           const TString& ntupleType = "NtupleMakerNtuple" ) throw( SError );

    void ConnectVariables( const TString& treeName,
                           const TString& prefix = "Electron_",
                           const TString& ntupleType = "NtupleMakerNtuple" ) throw( SError );

    int getDetailLevel() const {return detailLevel;}   


    // particle vector size
    Int_t                   N;
   
    enum ConnectionIndex { 
     kpassConversionVeto=19, 
     kfull5x5_sigmaIetaIeta=20, 
     kfull5x5_r9=21, 
     kdEtaIn=22, 
     kdPhiIn=23, 
     khOverE=24, 
     krelIsoWithDBeta=25, 
     kooEmooP=26, 
     kexpectedMissingInnerHits=27, 
     kd0=28, 
     kdz=29, 
     kdr03EcalRecHitSumEt=30, 
     kdr03HcalDepth1TowerSumEt=31, 
     krho=32, 
     kecalDriven=33, 
     kdEtaInSeed=34, 
     kfull5x5_e2x5Max=35, 
     kfull5x5_e5x5=36, 
     kfull5x5_e1x5=37, 
     kdr03TkSumPt=38, 
     khadronicOverEm=39, 
     kpdgId=1, 
     kcharge=2, 
     ket=3, 
     kisVetoElectronBoosted=40, 
     kisMediumElectronBoosted=41, 
     kisTightElectronBoosted=42, 
     kisHeepElectronBoosted=43, 
     kisLooseElectronBoosted=44, 
     kpfRhoCorrRelIso03Boost=45, 
     kpfRhoCorrRelIso04Boost=46, 
     kpfDeltaCorrRelIsoBoost=47, 
     kpfRelIsoBoost=48, 
     kphotonIsoBoost=49, 
     kneutralHadIsoBoost=50, 
     kchargedHadIsoBoost=51, 
     kSemileptonicPFIso=52, 
     kSemileptonicCorrPFIso=53, 
     kisVetoElectron=4, 
     kisMediumElectron=5, 
     kisTightElectron=6, 
     kisHeepElectron=7, 
     kisLooseElectron=8, 
     kpfRhoCorrRelIso03=11, 
     kpfRhoCorrRelIso04=12, 
     kpfDeltaCorrRelIso=13, 
     kpfRelIso=14, 
     kphotonIso=15, 
     kneutralHadIso=16, 
     kchargedHadIso=17, 
     ktrackIso=18, 
     ksuperCluster_eta=9, 
     ksuperCluster_e=10, 
 
      kEnd 
    }; 


    // vectors of properties defined in Particle.h
    std::vector< floatingnumber >  *e;
    std::vector< floatingnumber >  *pt;
    std::vector< floatingnumber >  *eta;
    std::vector< floatingnumber >  *phi;
    std::vector< floatingnumber >  *m;
    

    
    // vectors of object specific variables
    std::vector< int >  *passConversionVeto;
    std::vector< floatingnumber >  *full5x5_sigmaIetaIeta;
    std::vector< floatingnumber >  *full5x5_r9;
    std::vector< floatingnumber >  *dEtaIn;
    std::vector< floatingnumber >  *dPhiIn;
    std::vector< floatingnumber >  *hOverE;
    std::vector< floatingnumber >  *relIsoWithDBeta;
    std::vector< floatingnumber >  *ooEmooP;
    std::vector< int >  *expectedMissingInnerHits;
    std::vector< floatingnumber >  *d0;
    std::vector< floatingnumber >  *dz;
    std::vector< floatingnumber >  *dr03EcalRecHitSumEt;
    std::vector< floatingnumber >  *dr03HcalDepth1TowerSumEt;
    std::vector< floatingnumber >  *rho;
    std::vector< bool >  *ecalDriven;
    std::vector< floatingnumber >  *dEtaInSeed;
    std::vector< floatingnumber >  *full5x5_e2x5Max;
    std::vector< floatingnumber >  *full5x5_e5x5;
    std::vector< floatingnumber >  *full5x5_e1x5;
    std::vector< floatingnumber >  *dr03TkSumPt;
    std::vector< floatingnumber >  *hadronicOverEm;
    std::vector< int >  *pdgId;
    std::vector< floatingnumber >  *charge;
    std::vector< floatingnumber >  *et;
    std::vector< int >  *isVetoElectronBoosted;
    std::vector< int >  *isMediumElectronBoosted;
    std::vector< int >  *isTightElectronBoosted;
    std::vector< int >  *isHeepElectronBoosted;
    std::vector< int >  *isLooseElectronBoosted;
    std::vector< floatingnumber >  *pfRhoCorrRelIso03Boost;
    std::vector< floatingnumber >  *pfRhoCorrRelIso04Boost;
    std::vector< floatingnumber >  *pfDeltaCorrRelIsoBoost;
    std::vector< floatingnumber >  *pfRelIsoBoost;
    std::vector< floatingnumber >  *photonIsoBoost;
    std::vector< floatingnumber >  *neutralHadIsoBoost;
    std::vector< floatingnumber >  *chargedHadIsoBoost;
    std::vector< floatingnumber >  *SemileptonicPFIso;
    std::vector< floatingnumber >  *SemileptonicCorrPFIso;
    std::vector< int >  *isVetoElectron;
    std::vector< int >  *isMediumElectron;
    std::vector< int >  *isTightElectron;
    std::vector< int >  *isHeepElectron;
    std::vector< int >  *isLooseElectron;
    std::vector< floatingnumber >  *pfRhoCorrRelIso03;
    std::vector< floatingnumber >  *pfRhoCorrRelIso04;
    std::vector< floatingnumber >  *pfDeltaCorrRelIso;
    std::vector< floatingnumber >  *pfRelIso;
    std::vector< floatingnumber >  *photonIso;
    std::vector< floatingnumber >  *neutralHadIso;
    std::vector< floatingnumber >  *chargedHadIso;
    std::vector< floatingnumber >  *trackIso;
    std::vector< floatingnumber >  *superCluster_eta;
    std::vector< floatingnumber >  *superCluster_e;


    std::vector<int> m_connectsucceeded;

    // save actual detail level and group
    Int_t detailLevel;
    std::string detailGroup;

  }; // class ElectronNtupleObject

} // namespace Ntuple

#endif // SFRAME_NtupleVARIABLES_ElectronNtupleObject_H
