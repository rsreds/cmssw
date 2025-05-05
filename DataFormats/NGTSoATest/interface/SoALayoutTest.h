#ifndef SoA_Layout_Test_h
#define SoA_Layout_Test_h

#include <Eigen/Core>
#include <Eigen/Dense>

#include "DataFormats/SoATemplate/interface/SoALayout.h"
#include "DataFormats/SoATemplate/interface/SoAView.h"
#include <iostream>

GENERATE_SOA_LAYOUT(PhysicsObjTemplate,
                    SOA_COLUMN(double, x),
                    SOA_COLUMN(double, y),
                    SOA_COLUMN(double, z))
using PhysicsObj = PhysicsObjTemplate<>;
using PhysicsObjView = PhysicsObj::View;

GENERATE_SOA_LAYOUT(PhysicsObj2Template,
                    SOA_COLUMN(double, x),
                    SOA_COLUMN(double, y),
                    SOA_COLUMN(float, z))
using PhysicsObj2 = PhysicsObj2Template<>;
using PhysicsObj2View = PhysicsObj2::View;

GENERATE_SOA_LAYOUT(PhysicsObj3Template,
                    SOA_COLUMN(double, x),
                    SOA_COLUMN(float, y),
                    SOA_COLUMN(double, z))
using PhysicsObj3 = PhysicsObj3Template<>;  
using PhysicsObj3View = PhysicsObj3::View;

GENERATE_SOA_LAYOUT(PhysicsObj4Template,
                    SOA_COLUMN(float, x),
                    SOA_COLUMN(float, y),
                    SOA_COLUMN(float, z))
using PhysicsObj4 = PhysicsObj4Template<>;
using PhysicsObj4View = PhysicsObj4::View;

GENERATE_SOA_LAYOUT(PhysicsObj5Template,
                    SOA_COLUMN(short, x),
                    SOA_COLUMN(double, y),
                    SOA_COLUMN(float, z))
using PhysicsObj5 = PhysicsObj5Template<>;
using PhysicsObj5View = PhysicsObj5::View;

GENERATE_SOA_LAYOUT(PhysicsObj6Template,
                    SOA_COLUMN(int, x),
                    SOA_COLUMN(int, y),
                    SOA_COLUMN(int, z))
using PhysicsObj6 = PhysicsObj6Template<>;
using PhysicsObj6View = PhysicsObj6::View;

#endif
