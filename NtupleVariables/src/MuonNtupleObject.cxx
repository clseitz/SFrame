
// THIS FILE HAS BEEN GENERATED AUTOMATICALLY. DO NOT EDIT DIRECTLY, CHANGES WILL BE LOST UPON NEXT CODE GENERATION.
// Code produced by Id: CodeIt.py 494 2010-07-30 13:41:32Z svn 

// Local include(s):
#include "../include/MuonNtupleObject.h"

namespace Ntuple {

  MuonNtupleObject::MuonNtupleObject( SCycleBaseNTuple* parent )
    : SInputVariables< SCycleBaseNTuple >( parent ) {
      m_connectsucceeded.resize(kEnd);
  }

  void MuonNtupleObject::setConnectSucceeded(const unsigned int index, const bool success) {
    if (m_connectsucceeded.size() < index+1)  m_connectsucceeded.resize(index+1);
    m_connectsucceeded.at(index) = success;
  }

  void MuonNtupleObject::ConnectVariables( const TString& treeName,
                                         const TString& prefix,
                                         const TString& ntupleType ) throw( SError ) {
   
     MuonNtupleObject::ConnectVariables( treeName, Ntuple::MuonAll, prefix, ntupleType);
                                         
  }                                         

  void MuonNtupleObject::ConnectVariables( const TString& treeName,
                                         UInt_t detail_level,
                                         const TString& prefix,
                                         const TString& ntupleType ) throw( SError ) {
                                         
    // get instance of NtupleObjectNames
    NtupleObjectNames m_objectNames(ntupleType);
    

    // particle vector size
    ConnectVariable( treeName, prefix + m_objectNames.getName("N"), N );
    
    // connect variables that are defined in Particle.cxx
    ConnectVariable( treeName, prefix + m_objectNames.getName("e"), e );
    ConnectVariable( treeName, prefix + m_objectNames.getName("pt"), pt );
    ConnectVariable( treeName, prefix + m_objectNames.getName("eta"), eta );
    ConnectVariable( treeName, prefix + m_objectNames.getName("phi"), phi );
    ConnectVariable( treeName, prefix + m_objectNames.getName("m"), m );
        
    

    // connect object specific variables
if(  ((detail_level & Ntuple::MuonBasic) == Ntuple::MuonBasic)  ) {
     setConnectSucceeded(1, ConnectVariable( treeName, prefix + m_objectNames.getName("charge"), charge)); 
    setConnectSucceeded(2, ConnectVariable( treeName, prefix + m_objectNames.getName("pdgId"), pdgId)); 
} // end of detail level Basic

if(  ((detail_level & Ntuple::MuonBoostedIsolation) == Ntuple::MuonBoostedIsolation)  ) {
     setConnectSucceeded(35, ConnectVariable( treeName, prefix + m_objectNames.getName("pfRhoCorrRelIso03Boost"), pfRhoCorrRelIso03Boost)); 
    setConnectSucceeded(36, ConnectVariable( treeName, prefix + m_objectNames.getName("pfRhoCorrRelIso04Boost"), pfRhoCorrRelIso04Boost)); 
    setConnectSucceeded(37, ConnectVariable( treeName, prefix + m_objectNames.getName("pfDeltaCorrRelIsoBoost"), pfDeltaCorrRelIsoBoost)); 
    setConnectSucceeded(38, ConnectVariable( treeName, prefix + m_objectNames.getName("pfRelIsoBoost"), pfRelIsoBoost)); 
    setConnectSucceeded(39, ConnectVariable( treeName, prefix + m_objectNames.getName("photonIsoBoost"), photonIsoBoost)); 
    setConnectSucceeded(40, ConnectVariable( treeName, prefix + m_objectNames.getName("neutralHadIsoBoost"), neutralHadIsoBoost)); 
    setConnectSucceeded(41, ConnectVariable( treeName, prefix + m_objectNames.getName("chargedHadIsoBoost"), chargedHadIsoBoost)); 
    setConnectSucceeded(42, ConnectVariable( treeName, prefix + m_objectNames.getName("SemileptonicPFIso"), SemileptonicPFIso)); 
    setConnectSucceeded(43, ConnectVariable( treeName, prefix + m_objectNames.getName("SemileptonicCorrPFIso"), SemileptonicCorrPFIso)); 
} // end of detail level BoostedIsolation

if(  ((detail_level & Ntuple::MuonID) == Ntuple::MuonID)  ) {
     setConnectSucceeded(3, ConnectVariable( treeName, prefix + m_objectNames.getName("isHighPtMuon"), isHighPtMuon)); 
    setConnectSucceeded(4, ConnectVariable( treeName, prefix + m_objectNames.getName("isTightMuon"), isTightMuon)); 
    setConnectSucceeded(5, ConnectVariable( treeName, prefix + m_objectNames.getName("isMediumMuon"), isMediumMuon)); 
    setConnectSucceeded(6, ConnectVariable( treeName, prefix + m_objectNames.getName("isLooseMuon"), isLooseMuon)); 
    setConnectSucceeded(7, ConnectVariable( treeName, prefix + m_objectNames.getName("isPFMuon"), isPFMuon)); 
    setConnectSucceeded(8, ConnectVariable( treeName, prefix + m_objectNames.getName("isSoftMuon"), isSoftMuon)); 
    setConnectSucceeded(9, ConnectVariable( treeName, prefix + m_objectNames.getName("isGlobalMuon"), isGlobalMuon)); 
    setConnectSucceeded(10, ConnectVariable( treeName, prefix + m_objectNames.getName("isTrackerMuon"), isTrackerMuon)); 
    setConnectSucceeded(11, ConnectVariable( treeName, prefix + m_objectNames.getName("isTrackerHighPtMuon"), isTrackerHighPtMuon)); 
} // end of detail level ID

if(  ((detail_level & Ntuple::MuonIsolation) == Ntuple::MuonIsolation)  ) {
     setConnectSucceeded(12, ConnectVariable( treeName, prefix + m_objectNames.getName("pfRhoCorrRelIso03"), pfRhoCorrRelIso03)); 
    setConnectSucceeded(13, ConnectVariable( treeName, prefix + m_objectNames.getName("pfRhoCorrRelIso04"), pfRhoCorrRelIso04)); 
    setConnectSucceeded(14, ConnectVariable( treeName, prefix + m_objectNames.getName("pfDeltaCorrRelIso"), pfDeltaCorrRelIso)); 
    setConnectSucceeded(15, ConnectVariable( treeName, prefix + m_objectNames.getName("pfRelIso"), pfRelIso)); 
    setConnectSucceeded(16, ConnectVariable( treeName, prefix + m_objectNames.getName("photonIso"), photonIso)); 
    setConnectSucceeded(17, ConnectVariable( treeName, prefix + m_objectNames.getName("neutralHadIso"), neutralHadIso)); 
    setConnectSucceeded(18, ConnectVariable( treeName, prefix + m_objectNames.getName("chargedHadIso"), chargedHadIso)); 
    setConnectSucceeded(19, ConnectVariable( treeName, prefix + m_objectNames.getName("trackIso"), trackIso)); 
    setConnectSucceeded(20, ConnectVariable( treeName, prefix + m_objectNames.getName("trackCorrIso"), trackCorrIso)); 
} // end of detail level Isolation

if(  ((detail_level & Ntuple::MuonTrack) == Ntuple::MuonTrack)  ) {
     setConnectSucceeded(21, ConnectVariable( treeName, prefix + m_objectNames.getName("d0"), d0)); 
    setConnectSucceeded(22, ConnectVariable( treeName, prefix + m_objectNames.getName("dz"), dz)); 
    setConnectSucceeded(23, ConnectVariable( treeName, prefix + m_objectNames.getName("d0_allvertices"), d0_allvertices)); 
    setConnectSucceeded(24, ConnectVariable( treeName, prefix + m_objectNames.getName("dz_allvertices"), dz_allvertices)); 
    setConnectSucceeded(25, ConnectVariable( treeName, prefix + m_objectNames.getName("innerTrack_pt"), innerTrack_pt)); 
    setConnectSucceeded(26, ConnectVariable( treeName, prefix + m_objectNames.getName("bestTrack_pt"), bestTrack_pt)); 
    setConnectSucceeded(27, ConnectVariable( treeName, prefix + m_objectNames.getName("bestTrack_ptErr"), bestTrack_ptErr)); 
    setConnectSucceeded(28, ConnectVariable( treeName, prefix + m_objectNames.getName("tunePTrack_pt"), tunePTrack_pt)); 
    setConnectSucceeded(29, ConnectVariable( treeName, prefix + m_objectNames.getName("tunePTrack_ptErr"), tunePTrack_ptErr)); 
    setConnectSucceeded(30, ConnectVariable( treeName, prefix + m_objectNames.getName("trackerHits"), trackerHits)); 
    setConnectSucceeded(31, ConnectVariable( treeName, prefix + m_objectNames.getName("matchedStations"), matchedStations)); 
    setConnectSucceeded(32, ConnectVariable( treeName, prefix + m_objectNames.getName("pixelHits"), pixelHits)); 
    setConnectSucceeded(33, ConnectVariable( treeName, prefix + m_objectNames.getName("globalHits"), globalHits)); 
    setConnectSucceeded(34, ConnectVariable( treeName, prefix + m_objectNames.getName("normChi2"), normChi2)); 
}


        
    // save actual detail_level
    detailLevel = detail_level;

    return;

  }

} // namespace Ntuple
