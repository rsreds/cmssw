#include "DataFormats/CaloRecHit/interface/CaloClusterFloat.h"

#include <sstream>
#include <iostream>

using namespace std;
using namespace reco;

void CaloClusterFloat::reset() {
  position_ = math::XYZPointF();
  energy_ = 0;
  hitsAndFractions_.clear();
}

string CaloClusterFloat::printHitAndFraction(unsigned i) const {
  ostringstream out;
  if (i >= hitsAndFractions().size())  // i >= 0, since i is unsigned
    out << "out of range " << i;
  else
    out << "( " << hitsAndFractions()[i].first << ", " << hitsAndFractions()[i].second << " )";
  return out.str();
}

std::ostream& reco::operator<<(std::ostream& out, const CaloClusterFloat& cluster) {
  if (!out)
    return out;

  const math::XYZPointF& pos = cluster.position();

  out << "CaloClusterFloat , algoID=" << cluster.algoID() << ", " << cluster.caloID() << ", E=" << cluster.energy();
  if (cluster.correctedEnergy() != -1.0) {
    out << ", E_corr=" << cluster.correctedEnergy();
  }
  out << ", eta,phi=" << pos.eta() << "," << pos.phi() << ", nhits=" << cluster.hitsAndFractions().size() << endl;
  for (unsigned i = 0; i < cluster.hitsAndFractions().size(); i++) {
    out << "" << cluster.printHitAndFraction(i) << ", ";
  }

  return out;
}
