#ifndef Portable_Collection_SoA_Test_h
#define Portable_Collection_SoA_Test_h

#include "DataFormats/NGTSoATest/interface/SoALayoutTest.h"
#include "DataFormats/Portable/interface/PortableHostCollection.h"

using PhysicsObjCollection = PortableHostCollection<PhysicsObj>;
using PhysicsObj2Collection = PortableHostCollection<PhysicsObj2>;
using PhysicsObj3Collection = PortableHostCollection<PhysicsObj3>;
using PhysicsObj4Collection = PortableHostCollection<PhysicsObj4>;
using PhysicsObj5Collection = PortableHostCollection<PhysicsObj5>;
using PhysicsObj6Collection = PortableHostCollection<PhysicsObj6>;

// using SoAHostCollection2 = PortableHostCollection2<PhysicsObj, PhysicsObjExtra>;
// using SoAHostCollectionView1 = PortableHostCollection2<PhysicsObj, PhysicsObjExtra>::View<0>;
// using SoAHostCollectionView2 = PortableHostCollection2<PhysicsObj, PhysicsObjExtra>::View<1>;

using SoAHostPositionCollectionView = PortableHostCollection<PhysicsObj>::View;
using SoAHostPositionCollectionView2 = PortableHostCollection<PhysicsObj2>::View;
using SoAHostPositionCollectionView3 = PortableHostCollection<PhysicsObj3>::View;
using SoAHostPositionCollectionView4 = PortableHostCollection<PhysicsObj4>::View;
using SoAHostPositionCollectionView5 = PortableHostCollection<PhysicsObj5>::View;
using SoAHostPositionCollectionView6 = PortableHostCollection<PhysicsObj6>::View;

using SoAHostCollectionConstView = PortableHostCollection<PhysicsObj>::ConstView;
using SoAHostCollectionConstView2 = PortableHostCollection<PhysicsObj2>::ConstView;
using SoAHostCollectionConstView3 = PortableHostCollection<PhysicsObj3>::ConstView;
using SoAHostCollectionConstView4 = PortableHostCollection<PhysicsObj4>::ConstView;
using SoAHostCollectionConstView5 = PortableHostCollection<PhysicsObj5>::ConstView;
using SoAHostCollectionConstView6 = PortableHostCollection<PhysicsObj6>::ConstView;

#endif