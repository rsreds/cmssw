// Necessary includes for an effective Producer file
#include "FWCore/MessageLogger/interface/MessageLogger.h"
//#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/global/EDProducer.h"

#include <iostream>

#include "DataFormats/NGTSoATest/src/classes.h"

class SoAIntegersProducer : public edm::global::EDProducer<> {
public:
  explicit SoAIntegersProducer(const edm::ParameterSet&);
  ~SoAIntegersProducer();

  void produce(edm::StreamID, edm::Event&, const edm::EventSetup&) const override;

private:

};

// Constructor
SoAIntegersProducer::SoAIntegersProducer(const edm::ParameterSet& iConfig) {

  produces<PhysicsObjCollection>("SoAProductDDD");
  produces<std::vector<SimplePhysicsObj>>("AoSProductDDD");
  produces<SimpleSoAPhysicsObj>("SimpleSoAProductDDD");
  
  produces<PhysicsObj2Collection>("SoAProductDDF");
  produces<std::vector<SimplePhysicsObj2>>("AoSProductDDF");
  produces<SimpleSoAPhysicsObj2>("SimpleSoAProductDDF");

  produces<PhysicsObj3Collection>("SoAProductDFD");
  produces<std::vector<SimplePhysicsObj3>>("AoSProductDFD");
  produces<SimpleSoAPhysicsObj3>("SimpleSoAProductDFD");

  produces<PhysicsObj4Collection>("SoAProductFFF");
  produces<std::vector<SimplePhysicsObj4>>("AoSProductFFF");
  produces<SimpleSoAPhysicsObj4>("SimpleSoAProductFFF");

  produces<PhysicsObj5Collection>("SoAProductSDF");
  produces<std::vector<SimplePhysicsObj5>>("AoSProductSDF");
  produces<SimpleSoAPhysicsObj5>("SimpleSoAProductSDF");

  produces<PhysicsObj6Collection>("SoAProductIII");
  produces<std::vector<SimplePhysicsObj6>>("AoSProductIII");
  produces<SimpleSoAPhysicsObj6>("SimpleSoAProductIII");

  // Producer that converts from double to float and back to double
  produces<PhysicsObjCollection>("SoAProductConvertDDD");
  produces<std::vector<SimplePhysicsObj>>("AoSProductConvertDDD");
  produces<SimpleSoAPhysicsObj>("SimpleSoAProductConvertDDD");

  // Split variables not in a struct
  produces<std::vector<double>>("vdouble");
  produces<std::vector<float>>("vfloat");
  produces<std::vector<int>>("vint");
  produces<std::vector<short>>("vshort");
}

// Destructor
SoAIntegersProducer::~SoAIntegersProducer() {}

// Macro to label the label the module
DEFINE_FWK_MODULE(SoAIntegersProducer);

// Method to produce
void SoAIntegersProducer::produce(edm::StreamID iID, edm::Event& event, const edm::EventSetup& iSetup) const {
  size_t elems = 1000000;

  // SoA producer ddd input
  auto SoAProductDDD = std::make_unique<PhysicsObjCollection>(elems, cms::alpakatools::host());
  auto& SoAviewDDD = SoAProductDDD->view();
  auto AoSProductDDD = std::make_unique<AoSView>(elems);
  auto SimpleSoAProductDDD = std::make_unique<SimpleSoAPhysicsObj>(elems);

  // SoA producer ddf input
  auto SoAProductDDF = std::make_unique<PhysicsObj2Collection>(elems, cms::alpakatools::host());
  auto& SoAviewDDF = SoAProductDDF->view();
  auto AoSProductDDF = std::make_unique<AoSView2>(elems);
  auto SimpleSoAProductDDF = std::make_unique<SimpleSoAPhysicsObj2>(elems);

  // SoA producer dfd input
  auto SoAProductDFD = std::make_unique<PhysicsObj3Collection>(elems, cms::alpakatools::host());
  auto& SoAviewDFD = SoAProductDFD->view();
  auto AoSProductDFD = std::make_unique<AoSView3>(elems);
  auto SimpleSoAProductDFD = std::make_unique<SimpleSoAPhysicsObj3>(elems);
  
  // SoA producer fff input
  auto SoAProductFFF = std::make_unique<PhysicsObj4Collection>(elems, cms::alpakatools::host());
  auto& SoAviewFFF = SoAProductFFF->view();
  auto AoSProductFFF = std::make_unique<AoSView4>(elems);
  auto SimpleSoAProductFFF = std::make_unique<SimpleSoAPhysicsObj4>(elems);
  
  // SoA producer sdf input
  auto SoAProductSDF = std::make_unique<PhysicsObj5Collection>(elems, cms::alpakatools::host());
  auto& SoAviewSDF = SoAProductSDF->view();
  auto AoSProductSDF = std::make_unique<AoSView5>(elems);
  auto SimpleSoAProductSDF = std::make_unique<SimpleSoAPhysicsObj5>(elems);
  
  // SoA producer iii input
  auto SoAProductIII = std::make_unique<PhysicsObj6Collection>(elems, cms::alpakatools::host());
  auto& SoAviewIII = SoAProductIII->view();
  auto AoSProductIII = std::make_unique<AoSView6>(elems);
  auto SimpleSoAProductIII = std::make_unique<SimpleSoAPhysicsObj6>(elems);

  // Producer that converts from double to float and back to double
  auto SoAProductConvertDDD = std::make_unique<PhysicsObjCollection>(elems, cms::alpakatools::host());
  auto& SoAviewConvertDDD = SoAProductConvertDDD->view();
  auto AoSProductConvertDDD = std::make_unique<AoSView>(elems);
  auto SimpleSoAProductConvertDDD = std::make_unique<SimpleSoAPhysicsObj>(elems);

  // Reserve space for the split variables
  auto vdouble = std::make_unique<std::vector<double>>(elems);
  auto vfloat = std::make_unique<std::vector<float>>(elems);
  auto vint = std::make_unique<std::vector<int>>(elems);
  auto vshort = std::make_unique<std::vector<short>>(elems);

  for (size_t i = 0; i < elems; i++) {
    // Gerate x, y and z values randomly distributed gaussianly
    double x = i*1.;
    double y = i*2.;
    double z = i*3.;

    // Fill the SoA view
    SoAviewDDD.x()[i] = x;
    SoAviewDDD.y()[i] = y;
    SoAviewDDD.z()[i] = z;

    SoAviewDDF.x()[i] = x;
    SoAviewDDF.y()[i] = y;
    SoAviewDDF.z()[i] = static_cast<float>(z);

    SoAviewDFD.x()[i] = x;
    SoAviewDFD.y()[i] = static_cast<float>(y);
    SoAviewDFD.z()[i] = z;

    SoAviewFFF.x()[i] = static_cast<float>(x);
    SoAviewFFF.y()[i] = static_cast<float>(y);
    SoAviewFFF.z()[i] = static_cast<float>(z);

    SoAviewSDF.x()[i] = static_cast<short>(static_cast<int>(x) % 32767);
    SoAviewSDF.y()[i] = y;
    SoAviewSDF.z()[i] = static_cast<float>(z);

    SoAviewIII.x()[i] = static_cast<int>(x);
    SoAviewIII.y()[i] = static_cast<int>(y);
    SoAviewIII.z()[i] = static_cast<int>(z);

    SoAviewConvertDDD.x()[i] = static_cast<double>(static_cast<float>(x));
    SoAviewConvertDDD.y()[i] = static_cast<double>(static_cast<float>(y));
    SoAviewConvertDDD.z()[i] = static_cast<double>(static_cast<float>(z));

    // Fill the AoS
    (*AoSProductDDD)[i].x = x;
    (*AoSProductDDD)[i].y = y;
    (*AoSProductDDD)[i].z = z;
    
    (*AoSProductDDF)[i].x = x;
    (*AoSProductDDF)[i].y = y;
    (*AoSProductDDF)[i].z = static_cast<float>(z);

    (*AoSProductDFD)[i].x = x;
    (*AoSProductDFD)[i].y = static_cast<float>(y);
    (*AoSProductDFD)[i].z = z;

    (*AoSProductFFF)[i].x = static_cast<float>(x);
    (*AoSProductFFF)[i].y = static_cast<float>(y);
    (*AoSProductFFF)[i].z = static_cast<float>(z);

    (*AoSProductSDF)[i].x = static_cast<short>(static_cast<int>(x) % 32767);
    (*AoSProductSDF)[i].y = y;
    (*AoSProductSDF)[i].z = static_cast<float>(z);

    (*AoSProductIII)[i].x = static_cast<int>(x);
    (*AoSProductIII)[i].y = static_cast<int>(y);
    (*AoSProductIII)[i].z = static_cast<int>(z);

    (*AoSProductConvertDDD)[i].x = static_cast<double>(static_cast<float>(x));
    (*AoSProductConvertDDD)[i].y = static_cast<double>(static_cast<float>(y));
    (*AoSProductConvertDDD)[i].z = static_cast<double>(static_cast<float>(z));

    // Fill the SimpleSoAProduct
    SimpleSoAProductDDD->x.push_back(x);
    SimpleSoAProductDDD->y.push_back(y);
    SimpleSoAProductDDD->z.push_back(z);

    SimpleSoAProductDDF->x.push_back(x);
    SimpleSoAProductDDF->y.push_back(y);
    SimpleSoAProductDDF->z.push_back(static_cast<float>(z));

    SimpleSoAProductDFD->x.push_back(x);
    SimpleSoAProductDFD->y.push_back(static_cast<float>(y));
    SimpleSoAProductDFD->z.push_back(z);

    SimpleSoAProductFFF->x.push_back(static_cast<float>(x));
    SimpleSoAProductFFF->y.push_back(static_cast<float>(y));
    SimpleSoAProductFFF->z.push_back(static_cast<float>(z));

    SimpleSoAProductSDF->x.push_back(static_cast<short>(static_cast<int>(x) % 32767));
    SimpleSoAProductSDF->y.push_back(y);
    SimpleSoAProductSDF->z.push_back(static_cast<float>(z));

    SimpleSoAProductIII->x.push_back(static_cast<int>(x));
    SimpleSoAProductIII->y.push_back(static_cast<int>(y));
    SimpleSoAProductIII->z.push_back(static_cast<int>(z));

    SimpleSoAProductConvertDDD->x.push_back(static_cast<double>(static_cast<float>(x)));
    SimpleSoAProductConvertDDD->y.push_back(static_cast<double>(static_cast<float>(y)));
    SimpleSoAProductConvertDDD->z.push_back(static_cast<double>(static_cast<float>(z)));

    // Fill the split variables
    (*vdouble)[i] = x;
    (*vfloat)[i] = static_cast<float>(x);
    (*vint)[i] = static_cast<int>(x);
    (*vshort)[i] = static_cast<short>(static_cast<int>(x) % 32767);
  }

  // Put the product in the event
  event.put(std::move(SoAProductDDD), "SoAProductDDD");
  event.put(std::move(AoSProductDDD), "AoSProductDDD");
  event.put(std::move(SimpleSoAProductDDD), "SimpleSoAProductDDD");

  event.put(std::move(SoAProductDDF), "SoAProductDDF");
  event.put(std::move(AoSProductDDF), "AoSProductDDF");
  event.put(std::move(SimpleSoAProductDDF), "SimpleSoAProductDDF");

  event.put(std::move(SoAProductDFD), "SoAProductDFD");
  event.put(std::move(AoSProductDFD), "AoSProductDFD");
  event.put(std::move(SimpleSoAProductDFD), "SimpleSoAProductDFD");

  event.put(std::move(SoAProductFFF), "SoAProductFFF");
  event.put(std::move(AoSProductFFF), "AoSProductFFF");
  event.put(std::move(SimpleSoAProductFFF), "SimpleSoAProductFFF");

  event.put(std::move(SoAProductSDF), "SoAProductSDF");
  event.put(std::move(AoSProductSDF), "AoSProductSDF");
  event.put(std::move(SimpleSoAProductSDF), "SimpleSoAProductSDF");

  event.put(std::move(SoAProductIII), "SoAProductIII");
  event.put(std::move(AoSProductIII), "AoSProductIII");
  event.put(std::move(SimpleSoAProductIII), "SimpleSoAProductIII");

  event.put(std::move(SoAProductConvertDDD), "SoAProductConvertDDD");
  event.put(std::move(AoSProductConvertDDD), "AoSProductConvertDDD");
  event.put(std::move(SimpleSoAProductConvertDDD), "SimpleSoAProductConvertDDD");

  event.put(std::move(vdouble), "vdouble");
  event.put(std::move(vfloat), "vfloat");
  event.put(std::move(vint), "vint");
  event.put(std::move(vshort), "vshort");
}
