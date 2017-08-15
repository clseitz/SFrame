
// THIS FILE HAS BEEN GENERATED AUTOMATICALLY. DO NOT EDIT DIRECTLY, CHANGES WILL BE LOST UPON NEXT CODE GENERATION.
// Code produced by Id: CodeIt.py 494 2010-07-30 13:41:32Z svn 

#include "../include/Muon.h"

using namespace std;
using namespace UZH;

Muon::Muon() {
  
}


Muon::Muon( const Ntuple::MuonNtupleObject* ana, const Int_t idx ) 
: Basic( idx )
 , Particle() 


{
  m_ana=ana;
  // copy variables defined in Particle.h
    m_e = &((*ana->e)[idx]); 
    m_pt = &((*ana->pt)[idx]); 
    m_eta = &((*ana->eta)[idx]); 
    m_phi = &((*ana->phi)[idx]); 
    m_m = &((*ana->m)[idx]); 

  m_lvl    = ana->detailLevel;


  // copy rest of variables
  /*${ {AllNoBools:    printf("acc#name#\n"); if (ana->m_connectsucceeded[#index#]) 
         {printf("?\n"); m_#name# = &((*ana->#name#)[idx]);}
    else {printf("fak\n"); m_#name# = new #type#(); *m_#name# = #default#; } }}
  */
if(  ((ana->detailLevel & Ntuple::MuonBasic) == Ntuple::MuonBasic)  ) {
     if (ana->m_connectsucceeded[1]) m_charge = &((*ana->charge)[idx]); else m_charge = 0; 
    if (ana->m_connectsucceeded[2]) m_pdgId = &((*ana->pdgId)[idx]); else m_pdgId = 0; 
} // end of detail level Basic

if(  ((ana->detailLevel & Ntuple::MuonBoostedIsolation) == Ntuple::MuonBoostedIsolation)  ) {
     if (ana->m_connectsucceeded[35]) m_pfRhoCorrRelIso03Boost = &((*ana->pfRhoCorrRelIso03Boost)[idx]); else m_pfRhoCorrRelIso03Boost = 0; 
    if (ana->m_connectsucceeded[36]) m_pfRhoCorrRelIso04Boost = &((*ana->pfRhoCorrRelIso04Boost)[idx]); else m_pfRhoCorrRelIso04Boost = 0; 
    if (ana->m_connectsucceeded[37]) m_pfDeltaCorrRelIsoBoost = &((*ana->pfDeltaCorrRelIsoBoost)[idx]); else m_pfDeltaCorrRelIsoBoost = 0; 
    if (ana->m_connectsucceeded[38]) m_pfRelIsoBoost = &((*ana->pfRelIsoBoost)[idx]); else m_pfRelIsoBoost = 0; 
    if (ana->m_connectsucceeded[39]) m_photonIsoBoost = &((*ana->photonIsoBoost)[idx]); else m_photonIsoBoost = 0; 
    if (ana->m_connectsucceeded[40]) m_neutralHadIsoBoost = &((*ana->neutralHadIsoBoost)[idx]); else m_neutralHadIsoBoost = 0; 
    if (ana->m_connectsucceeded[41]) m_chargedHadIsoBoost = &((*ana->chargedHadIsoBoost)[idx]); else m_chargedHadIsoBoost = 0; 
    if (ana->m_connectsucceeded[42]) m_SemileptonicPFIso = &((*ana->SemileptonicPFIso)[idx]); else m_SemileptonicPFIso = 0; 
    if (ana->m_connectsucceeded[43]) m_SemileptonicCorrPFIso = &((*ana->SemileptonicCorrPFIso)[idx]); else m_SemileptonicCorrPFIso = 0; 
} // end of detail level BoostedIsolation

if(  ((ana->detailLevel & Ntuple::MuonID) == Ntuple::MuonID)  ) {
     if (ana->m_connectsucceeded[3]) m_isHighPtMuon = &((*ana->isHighPtMuon)[idx]); else m_isHighPtMuon = 0; 
    if (ana->m_connectsucceeded[4]) m_isTightMuon = &((*ana->isTightMuon)[idx]); else m_isTightMuon = 0; 
    if (ana->m_connectsucceeded[5]) m_isMediumMuon = &((*ana->isMediumMuon)[idx]); else m_isMediumMuon = 0; 
    if (ana->m_connectsucceeded[6]) m_isLooseMuon = &((*ana->isLooseMuon)[idx]); else m_isLooseMuon = 0; 
    if (ana->m_connectsucceeded[7]) m_isPFMuon = &((*ana->isPFMuon)[idx]); else m_isPFMuon = 0; 
    if (ana->m_connectsucceeded[8]) m_isSoftMuon = &((*ana->isSoftMuon)[idx]); else m_isSoftMuon = 0; 
    if (ana->m_connectsucceeded[9]) m_isGlobalMuon = &((*ana->isGlobalMuon)[idx]); else m_isGlobalMuon = 0; 
    if (ana->m_connectsucceeded[10]) m_isTrackerMuon = &((*ana->isTrackerMuon)[idx]); else m_isTrackerMuon = 0; 
    if (ana->m_connectsucceeded[11]) m_isTrackerHighPtMuon = &((*ana->isTrackerHighPtMuon)[idx]); else m_isTrackerHighPtMuon = 0; 
} // end of detail level ID

if(  ((ana->detailLevel & Ntuple::MuonIsolation) == Ntuple::MuonIsolation)  ) {
     if (ana->m_connectsucceeded[12]) m_pfRhoCorrRelIso03 = &((*ana->pfRhoCorrRelIso03)[idx]); else m_pfRhoCorrRelIso03 = 0; 
    if (ana->m_connectsucceeded[13]) m_pfRhoCorrRelIso04 = &((*ana->pfRhoCorrRelIso04)[idx]); else m_pfRhoCorrRelIso04 = 0; 
    if (ana->m_connectsucceeded[14]) m_pfDeltaCorrRelIso = &((*ana->pfDeltaCorrRelIso)[idx]); else m_pfDeltaCorrRelIso = 0; 
    if (ana->m_connectsucceeded[15]) m_pfRelIso = &((*ana->pfRelIso)[idx]); else m_pfRelIso = 0; 
    if (ana->m_connectsucceeded[16]) m_photonIso = &((*ana->photonIso)[idx]); else m_photonIso = 0; 
    if (ana->m_connectsucceeded[17]) m_neutralHadIso = &((*ana->neutralHadIso)[idx]); else m_neutralHadIso = 0; 
    if (ana->m_connectsucceeded[18]) m_chargedHadIso = &((*ana->chargedHadIso)[idx]); else m_chargedHadIso = 0; 
    if (ana->m_connectsucceeded[19]) m_trackIso = &((*ana->trackIso)[idx]); else m_trackIso = 0; 
    if (ana->m_connectsucceeded[20]) m_trackCorrIso = &((*ana->trackCorrIso)[idx]); else m_trackCorrIso = 0; 
} // end of detail level Isolation

if(  ((ana->detailLevel & Ntuple::MuonTrack) == Ntuple::MuonTrack)  ) {
     if (ana->m_connectsucceeded[21]) m_d0 = &((*ana->d0)[idx]); else m_d0 = 0; 
    if (ana->m_connectsucceeded[22]) m_dz = &((*ana->dz)[idx]); else m_dz = 0; 
    if (ana->m_connectsucceeded[23]) m_d0_allvertices = &((*ana->d0_allvertices)[idx]); else m_d0_allvertices = 0; 
    if (ana->m_connectsucceeded[24]) m_dz_allvertices = &((*ana->dz_allvertices)[idx]); else m_dz_allvertices = 0; 
    if (ana->m_connectsucceeded[25]) m_innerTrack_pt = &((*ana->innerTrack_pt)[idx]); else m_innerTrack_pt = 0; 
    if (ana->m_connectsucceeded[26]) m_bestTrack_pt = &((*ana->bestTrack_pt)[idx]); else m_bestTrack_pt = 0; 
    if (ana->m_connectsucceeded[27]) m_bestTrack_ptErr = &((*ana->bestTrack_ptErr)[idx]); else m_bestTrack_ptErr = 0; 
    if (ana->m_connectsucceeded[28]) m_tunePTrack_pt = &((*ana->tunePTrack_pt)[idx]); else m_tunePTrack_pt = 0; 
    if (ana->m_connectsucceeded[29]) m_tunePTrack_ptErr = &((*ana->tunePTrack_ptErr)[idx]); else m_tunePTrack_ptErr = 0; 
    if (ana->m_connectsucceeded[30]) m_trackerHits = &((*ana->trackerHits)[idx]); else m_trackerHits = 0; 
    if (ana->m_connectsucceeded[31]) m_matchedStations = &((*ana->matchedStations)[idx]); else m_matchedStations = 0; 
    if (ana->m_connectsucceeded[32]) m_pixelHits = &((*ana->pixelHits)[idx]); else m_pixelHits = 0; 
    if (ana->m_connectsucceeded[33]) m_globalHits = &((*ana->globalHits)[idx]); else m_globalHits = 0; 
    if (ana->m_connectsucceeded[34]) m_normChi2 = &((*ana->normChi2)[idx]); else m_normChi2 = 0; 
}




 //Set ptMS and ptID
 //if( (ana->detailLevel & Ntuple::MuonAnalysis) == Ntuple::MuonAnalysis ) {
 //   if(me_qoverp()!=0) m_ptMS = 1./std::fabs(me_qoverp()) * std::sin(me_theta()); else m_ptMS = 0; 
 //	  if(id_qoverp()!=0) m_ptID = 1./std::fabs(id_qoverp()) * std::sin(id_theta()); else m_ptID = 0; 
 //}





}


Muon::~Muon() {

}

ostream& operator<<( ostream& out,
                     const Muon& rhs ) {
  
   out << "Muon -" << ( Basic) rhs; 
   out << "Muon -" << ( Particle ) rhs; 


  ;
if(  ((rhs.getLvl() & Ntuple::MuonBasic) == Ntuple::MuonBasic)  ) {
   out << " charge " << rhs.charge();
  out << " pdgId " << rhs.pdgId();
;
} // end of detail level Basic

if(  ((rhs.getLvl() & Ntuple::MuonBoostedIsolation) == Ntuple::MuonBoostedIsolation)  ) {
   out << " pfRhoCorrRelIso03Boost " << rhs.pfRhoCorrRelIso03Boost();
  out << " pfRhoCorrRelIso04Boost " << rhs.pfRhoCorrRelIso04Boost();
  out << " pfDeltaCorrRelIsoBoost " << rhs.pfDeltaCorrRelIsoBoost();
  out << " pfRelIsoBoost " << rhs.pfRelIsoBoost();
  out << " photonIsoBoost " << rhs.photonIsoBoost();
  out << " neutralHadIsoBoost " << rhs.neutralHadIsoBoost();
  out << " chargedHadIsoBoost " << rhs.chargedHadIsoBoost();
  out << " SemileptonicPFIso " << rhs.SemileptonicPFIso();
  out << " SemileptonicCorrPFIso " << rhs.SemileptonicCorrPFIso();
;
} // end of detail level BoostedIsolation

if(  ((rhs.getLvl() & Ntuple::MuonID) == Ntuple::MuonID)  ) {
   out << " isHighPtMuon " << rhs.isHighPtMuon();
  out << " isTightMuon " << rhs.isTightMuon();
  out << " isMediumMuon " << rhs.isMediumMuon();
  out << " isLooseMuon " << rhs.isLooseMuon();
  out << " isPFMuon " << rhs.isPFMuon();
  out << " isSoftMuon " << rhs.isSoftMuon();
  out << " isGlobalMuon " << rhs.isGlobalMuon();
  out << " isTrackerMuon " << rhs.isTrackerMuon();
  out << " isTrackerHighPtMuon " << rhs.isTrackerHighPtMuon();
;
} // end of detail level ID

if(  ((rhs.getLvl() & Ntuple::MuonIsolation) == Ntuple::MuonIsolation)  ) {
   out << " pfRhoCorrRelIso03 " << rhs.pfRhoCorrRelIso03();
  out << " pfRhoCorrRelIso04 " << rhs.pfRhoCorrRelIso04();
  out << " pfDeltaCorrRelIso " << rhs.pfDeltaCorrRelIso();
  out << " pfRelIso " << rhs.pfRelIso();
  out << " photonIso " << rhs.photonIso();
  out << " neutralHadIso " << rhs.neutralHadIso();
  out << " chargedHadIso " << rhs.chargedHadIso();
  out << " trackIso " << rhs.trackIso();
  out << " trackCorrIso " << rhs.trackCorrIso();
;
} // end of detail level Isolation

if(  ((rhs.getLvl() & Ntuple::MuonTrack) == Ntuple::MuonTrack)  ) {
   out << " d0 " << rhs.d0();
  out << " dz " << rhs.dz();
  out << " d0_allvertices " << rhs.d0_allvertices();
  out << " dz_allvertices " << rhs.dz_allvertices();
  out << " innerTrack_pt " << rhs.innerTrack_pt();
  out << " bestTrack_pt " << rhs.bestTrack_pt();
  out << " bestTrack_ptErr " << rhs.bestTrack_ptErr();
  out << " tunePTrack_pt " << rhs.tunePTrack_pt();
  out << " tunePTrack_ptErr " << rhs.tunePTrack_ptErr();
  out << " trackerHits " << rhs.trackerHits();
  out << " matchedStations " << rhs.matchedStations();
  out << " pixelHits " << rhs.pixelHits();
  out << " globalHits " << rhs.globalHits();
  out << " normChi2 " << rhs.normChi2();
;
}


  return out;
}



bool sortMuonPt::operator()( const Muon& e1,
                                 const Muon& e2 ) {
  return ( e1.pt() > e2.pt() ) ? true : false;
}

bool operator<<( const Muon& e1, const Muon& e2 ) {
  sortMuonPt sort;
  return sort( e1, e2 );
}




TLorentzVector* Muon::getTLV() const {

  TLorentzVector* tlv = new TLorentzVector();
  tlv->SetPtEtaPhiE(*(m_pt), *(m_eta), *(m_phi), *(m_e));
  return tlv;

}


TLorentzVector Muon::tlv() const {

  TLorentzVector tlv;
  tlv.SetPtEtaPhiE(*(m_pt), *(m_eta), *(m_phi), *(m_e));
  return tlv;

}








