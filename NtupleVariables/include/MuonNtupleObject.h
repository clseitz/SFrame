// Dear emacs, this is -*- c++ -*-
// $Id: MuonNtupleObject.h 37457 2010-07-05 12:04:33Z mann $

// THIS FILE HAS BEEN GENERATED AUTOMATICALLY. DO NOT EDIT DIRECTLY, CHANGES WILL BE LOST UPON NEXT CODE GENERATION.
// Code produced by Id: CodeIt.py 494 2010-07-30 13:41:32Z svn 


#ifndef SFRAME_NtupleVARIABLES_MuonNtupleObject_H
#define SFRAME_NtupleVARIABLES_MuonNtupleObject_H

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
  *  @short Class that can read the variables produced by MuonNtupleObject
  *
  *         This class can be used to read the offline muon information from
  *         an ntuple produced by the SingleTopDPDMaker code.
  *
  * @author Code produced by Id: CodeIt.py 494 2010-07-30 13:41:32Z svn   
  *
  */
  
  enum MuonDetails {
    MuonTrack = 1,
    MuonIsolation = 2,
    MuonBoostedIsolation = 4,
    MuonID = 8,
    MuonBasic = 16,
    MuonAll = 31,

  };
  
  // forward declaration of NtupleObjectNames
  class NtupleObjectNames;
  class MuonNtupleObject : public SInputVariables< SCycleBaseNTuple > {

    public:
    /// Constructor specifying the parent of the object
    MuonNtupleObject( SCycleBaseNTuple* parent );

    /// remember if connect succeeded
    void setConnectSucceeded(const unsigned int index, const bool success);
    bool getConnectSucceeded(const unsigned int index) const {return m_connectsucceeded.at(index);}  

    /// Connect the variables to the input branches
    void ConnectVariables( const TString& treeName,
                           UInt_t detail_level = 0,
                           const TString& prefix = "Muon_",
                           const TString& ntupleType = "NtupleMakerNtuple" ) throw( SError );

    void ConnectVariables( const TString& treeName,
                           const TString& prefix = "Muon_",
                           const TString& ntupleType = "NtupleMakerNtuple" ) throw( SError );

    int getDetailLevel() const {return detailLevel;}   


    // particle vector size
    Int_t                   N;
   
    enum ConnectionIndex { 
     kcharge=1, 
     kpdgId=2, 
     kpfRhoCorrRelIso03Boost=35, 
     kpfRhoCorrRelIso04Boost=36, 
     kpfDeltaCorrRelIsoBoost=37, 
     kpfRelIsoBoost=38, 
     kphotonIsoBoost=39, 
     kneutralHadIsoBoost=40, 
     kchargedHadIsoBoost=41, 
     kSemileptonicPFIso=42, 
     kSemileptonicCorrPFIso=43, 
     kisHighPtMuon=3, 
     kisTightMuon=4, 
     kisMediumMuon=5, 
     kisLooseMuon=6, 
     kisPFMuon=7, 
     kisSoftMuon=8, 
     kisGlobalMuon=9, 
     kisTrackerMuon=10, 
     kisTrackerHighPtMuon=11, 
     kpfRhoCorrRelIso03=12, 
     kpfRhoCorrRelIso04=13, 
     kpfDeltaCorrRelIso=14, 
     kpfRelIso=15, 
     kphotonIso=16, 
     kneutralHadIso=17, 
     kchargedHadIso=18, 
     ktrackIso=19, 
     ktrackCorrIso=20, 
     kd0=21, 
     kdz=22, 
     kd0_allvertices=23, 
     kdz_allvertices=24, 
     kinnerTrack_pt=25, 
     kbestTrack_pt=26, 
     kbestTrack_ptErr=27, 
     ktunePTrack_pt=28, 
     ktunePTrack_ptErr=29, 
     ktrackerHits=30, 
     kmatchedStations=31, 
     kpixelHits=32, 
     kglobalHits=33, 
     knormChi2=34, 
 
      kEnd 
    }; 


    // vectors of properties defined in Particle.h
    std::vector< floatingnumber >  *e;
    std::vector< floatingnumber >  *pt;
    std::vector< floatingnumber >  *eta;
    std::vector< floatingnumber >  *phi;
    std::vector< floatingnumber >  *m;
    

    
    // vectors of object specific variables
    std::vector< floatingnumber >  *charge;
    std::vector< int >  *pdgId;
    std::vector< floatingnumber >  *pfRhoCorrRelIso03Boost;
    std::vector< floatingnumber >  *pfRhoCorrRelIso04Boost;
    std::vector< floatingnumber >  *pfDeltaCorrRelIsoBoost;
    std::vector< floatingnumber >  *pfRelIsoBoost;
    std::vector< floatingnumber >  *photonIsoBoost;
    std::vector< floatingnumber >  *neutralHadIsoBoost;
    std::vector< floatingnumber >  *chargedHadIsoBoost;
    std::vector< floatingnumber >  *SemileptonicPFIso;
    std::vector< floatingnumber >  *SemileptonicCorrPFIso;
    std::vector< int >  *isHighPtMuon;
    std::vector< int >  *isTightMuon;
    std::vector< int >  *isMediumMuon;
    std::vector< int >  *isLooseMuon;
    std::vector< int >  *isPFMuon;
    std::vector< int >  *isSoftMuon;
    std::vector< int >  *isGlobalMuon;
    std::vector< int >  *isTrackerMuon;
    std::vector< int >  *isTrackerHighPtMuon;
    std::vector< floatingnumber >  *pfRhoCorrRelIso03;
    std::vector< floatingnumber >  *pfRhoCorrRelIso04;
    std::vector< floatingnumber >  *pfDeltaCorrRelIso;
    std::vector< floatingnumber >  *pfRelIso;
    std::vector< floatingnumber >  *photonIso;
    std::vector< floatingnumber >  *neutralHadIso;
    std::vector< floatingnumber >  *chargedHadIso;
    std::vector< floatingnumber >  *trackIso;
    std::vector< floatingnumber >  *trackCorrIso;
    std::vector< floatingnumber >  *d0;
    std::vector< floatingnumber >  *dz;
    std::vector< floatingnumber >  *d0_allvertices;
    std::vector< floatingnumber >  *dz_allvertices;
    std::vector< floatingnumber >  *innerTrack_pt;
    std::vector< floatingnumber >  *bestTrack_pt;
    std::vector< floatingnumber >  *bestTrack_ptErr;
    std::vector< floatingnumber >  *tunePTrack_pt;
    std::vector< floatingnumber >  *tunePTrack_ptErr;
    std::vector< int >  *trackerHits;
    std::vector< int >  *matchedStations;
    std::vector< int >  *pixelHits;
    std::vector< int >  *globalHits;
    std::vector< floatingnumber >  *normChi2;


    std::vector<int> m_connectsucceeded;

    // save actual detail level and group
    Int_t detailLevel;
    std::string detailGroup;

  }; // class MuonNtupleObject

} // namespace Ntuple

#endif // SFRAME_NtupleVARIABLES_MuonNtupleObject_H
