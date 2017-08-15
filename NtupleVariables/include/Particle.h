#ifndef __UZH_PARTICLE_H__
#define __UZH_PARTICLE_H__

#include "../include/Basic.h"
#include "TLorentzVector.h"
#include "core/include/SError.h"
#include "../include/ContainerBase.h"

namespace UZH {

  /**
 *  @short Basic particle class providing some functionality 
 *
 *         This class can be used to obtain some basic kinematics. 
 *         Some helper functions are available.
 *
 * @author Clemens Lange <Clemens.Lange@desy.de>
 *
 * $Rev: 41226 $
 * $Date: 2013-10-15 23:33:04 +0200 (Tue, 15 Oct 2013) $
   */

  class Particle {

  public:

    /// default c'tor with index of this particle
    Particle();

    /// default d'tor
    ~Particle();

    floatingnumber e()   const;
    floatingnumber pt()  const;
    floatingnumber eta() const;
    floatingnumber phi() const;
    floatingnumber m()   const;
    void e(   floatingnumber val ){ *(m_e)   = val;  }
    void pt(  floatingnumber val ){ *(m_pt)  = val;  }
    void eta( floatingnumber val ){ *(m_eta) = val;  }
    void phi( floatingnumber val ){ *(m_phi) = val;  }
    void m(   floatingnumber val ){ *(m_m)   = val;  }

    TLorentzVector* getTLV() const;
    floatingnumber DeltaR(const Particle* p) const;
    floatingnumber DeltaR(const Particle p) const;
    
    floatingnumber* m_e;
    floatingnumber* m_pt;
    floatingnumber* m_eta;
    floatingnumber* m_phi;
    floatingnumber* m_m;
  };

  inline floatingnumber Particle::e() const       { return m_e   ? *(m_e)   : 0; }
  inline floatingnumber Particle::pt() const      { return m_pt  ? *(m_pt)  : 0; }
  inline floatingnumber Particle::eta() const     { return m_eta ? *(m_eta) : 0; }
  inline floatingnumber Particle::phi() const     { return m_phi ? *(m_phi) : 0; }
  inline floatingnumber Particle::m() const       { return m_m   ? *(m_m)   : 0; }

  /// sort particles by pT
  bool operator<( const Particle& p1, const Particle& p2 );

  /// function class to sort ElectronList contents first by Et
  class sortParticlePt
  {
  public:
    bool operator()( const Particle& p1,
                     const Particle& p2 );
  };

}

/// output operator for particles
std::ostream& operator<<( std::ostream& out,
                          const UZH::Particle& rhs );

#endif //__UZH_PARTICLE_H__
