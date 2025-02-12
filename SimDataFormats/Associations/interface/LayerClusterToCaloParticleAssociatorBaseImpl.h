#ifndef SimDataFormats_Associations_LayerClusterToCaloParticleAssociatorBaseImpl_h
#define SimDataFormats_Associations_LayerClusterToCaloParticleAssociatorBaseImpl_h

/** \class LayerClusterToCaloParticleAssociatorBaseImpl
 *
 * Base class for LayerClusterToCaloParticleAssociators.  Methods take as input
 * the handle of LayerClusters and the CaloParticle collections and return an
 * AssociationMap (oneToManyWithQuality)
 *
 *  \author Marco Rovere
 */

#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Common/interface/AssociationMap.h"
#include "DataFormats/CaloRecHit/interface/CaloClusterFloat.h"

#include "SimDataFormats/CaloAnalysis/interface/CaloParticleFwd.h"

namespace ticl {

  typedef edm::AssociationMap<
      edm::OneToManyWithQualityGeneric<CaloParticleCollection, reco::CaloClusterFloatCollection, std::pair<float, float>>>
      SimToRecoCollection;
  typedef edm::AssociationMap<
      edm::OneToManyWithQualityGeneric<reco::CaloClusterFloatCollection, CaloParticleCollection, float>>
      RecoToSimCollection;

  class LayerClusterToCaloParticleAssociatorBaseImpl {
  public:
    /// Constructor
    LayerClusterToCaloParticleAssociatorBaseImpl();
    /// Destructor
    virtual ~LayerClusterToCaloParticleAssociatorBaseImpl();

    /// Associate a LayerCluster to CaloParticles
    virtual ticl::RecoToSimCollection associateRecoToSim(const edm::Handle<reco::CaloClusterFloatCollection> &cCH,
                                                         const edm::Handle<CaloParticleCollection> &cPCH) const;

    /// Associate a CaloParticle to LayerClusters
    virtual ticl::SimToRecoCollection associateSimToReco(const edm::Handle<reco::CaloClusterFloatCollection> &cCH,
                                                         const edm::Handle<CaloParticleCollection> &cPCH) const;
  };
}  // namespace ticl

#endif
