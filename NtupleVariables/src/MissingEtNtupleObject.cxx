
// THIS FILE HAS BEEN GENERATED AUTOMATICALLY. DO NOT EDIT DIRECTLY, CHANGES WILL BE LOST UPON NEXT CODE GENERATION.
// Code produced by Id: CodeIt.py 494 2010-07-30 13:41:32Z svn 

// Local include(s):
#include "../include/MissingEtNtupleObject.h"

namespace Ntuple {

  MissingEtNtupleObject::MissingEtNtupleObject( SCycleBaseNTuple* parent )
    : SInputVariables< SCycleBaseNTuple >( parent ) {
      m_connectsucceeded.resize(kEnd);
  }

  void MissingEtNtupleObject::setConnectSucceeded(const unsigned int index, const bool success) {
    if (m_connectsucceeded.size() < index+1)  m_connectsucceeded.resize(index+1);
    m_connectsucceeded.at(index) = success;
  }

  void MissingEtNtupleObject::ConnectVariables( const TString& treeName,
                                         const TString& prefix,
                                         const TString& ntupleType ) throw( SError ) {
   
     MissingEtNtupleObject::ConnectVariables( treeName, Ntuple::MissingEtAll, prefix, ntupleType);
                                         
  }                                         

  void MissingEtNtupleObject::ConnectVariables( const TString& treeName,
                                         UInt_t detail_level,
                                         const TString& prefix,
                                         const TString& ntupleType ) throw( SError ) {
                                         
    // get instance of NtupleObjectNames
    NtupleObjectNames m_objectNames(ntupleType);
    
    
    // connect variables that are defined in Particle.cxx
        
    

    // connect object specific variables
if(  ((detail_level & Ntuple::MissingEtAnalysis) == Ntuple::MissingEtAnalysis)  ) {
     setConnectSucceeded(4, ConnectVariable( treeName, prefix + m_objectNames.getName("corrPx"), corrPx)); 
    setConnectSucceeded(5, ConnectVariable( treeName, prefix + m_objectNames.getName("corrPy"), corrPy)); 
    setConnectSucceeded(6, ConnectVariable( treeName, prefix + m_objectNames.getName("significance"), significance)); 
    setConnectSucceeded(7, ConnectVariable( treeName, prefix + m_objectNames.getName("cov00"), cov00)); 
    setConnectSucceeded(8, ConnectVariable( treeName, prefix + m_objectNames.getName("cov10"), cov10)); 
    setConnectSucceeded(9, ConnectVariable( treeName, prefix + m_objectNames.getName("cov11"), cov11)); 
} // end of detail level Analysis

if(  ((detail_level & Ntuple::MissingEtBasic) == Ntuple::MissingEtBasic)  ) {
     setConnectSucceeded(1, ConnectVariable( treeName, prefix + m_objectNames.getName("et"), et)); 
    setConnectSucceeded(2, ConnectVariable( treeName, prefix + m_objectNames.getName("phi"), phi)); 
    setConnectSucceeded(3, ConnectVariable( treeName, prefix + m_objectNames.getName("sumEt"), sumEt)); 
}


        
    // save actual detail_level
    detailLevel = detail_level;

    return;

  }

} // namespace Ntuple
