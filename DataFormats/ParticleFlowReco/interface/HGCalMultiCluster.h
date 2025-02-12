#ifndef DataFormats_ParticleFlowReco_HGCalMultiCluster
#define DataFormats_ParticleFlowReco_HGCalMultiCluster

#include <vector>
#include <limits>

#include "DataFormats/Common/interface/PtrVector.h"
#include "DataFormats/CaloRecHit/interface/CaloClusterFloat.h"
#include "DataFormats/ParticleFlowReco/interface/PFCluster.h"

namespace reco {
  class HGCalMultiCluster : public reco::PFCluster {
  public:
    typedef edm::PtrVector<reco::CaloClusterFloat>::const_iterator component_iterator;
    typedef edm::PtrVector<reco::CaloClusterFloat> ClusterCollection;

    HGCalMultiCluster() : PFCluster() { this->setLayer(PFLayer::HGCAL); }

    HGCalMultiCluster(double energy, double x, double y, double z, ClusterCollection& thecls);

    void push_back(const edm::Ptr<reco::CaloClusterFloat>& b) { myclusters.push_back(b); }

    const edm::PtrVector<reco::CaloClusterFloat>& clusters() const { return myclusters; }

    unsigned int size() const { return myclusters.size(); }
    component_iterator begin() const { return myclusters.begin(); }
    component_iterator end() const { return myclusters.end(); }

    bool operator>(const HGCalMultiCluster& rhs) const { return (energy() > rhs.energy()); }

  private:
    edm::PtrVector<reco::CaloClusterFloat> myclusters;
  };

  typedef std::vector<HGCalMultiCluster> HGCalMultiClusterCollection;
}  // namespace reco
#endif
