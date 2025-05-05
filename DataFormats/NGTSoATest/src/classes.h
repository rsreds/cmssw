#ifndef DataFormats_NGTSoATest_src_classes_h
#define DataFormats_NGTSoATest_src_classes_h

#include "DataFormats/NGTSoATest/interface/PortableCollectionSoATest.h"
#include "DataFormats/NGTSoATest/interface/SoALayoutTest.h"
#include "DataFormats/Common/interface/Wrapper.h"

struct SimplePhysicsObj {
    double x;
    double y;
    double z;
};
using AoSView = std::vector<SimplePhysicsObj>;

struct SimplePhysicsObj2 {
    double x;
    double y;
    float z;
};
using AoSView2 = std::vector<SimplePhysicsObj2>;

struct SimplePhysicsObj3 {
    double x;
    float y;
    double z;
};
using AoSView3 = std::vector<SimplePhysicsObj3>;

struct SimplePhysicsObj4 {
    float x;
    float y;
    float z;
};
using AoSView4 = std::vector<SimplePhysicsObj4>;

struct SimplePhysicsObj5 {
    short x;
    double y;
    float z;
};
using AoSView5 = std::vector<SimplePhysicsObj5>;

struct SimplePhysicsObj6 {
    int x;
    int y;
    int z;
};
using AoSView6 = std::vector<SimplePhysicsObj6>;


struct SimpleSoAPhysicsObj {
    SimpleSoAPhysicsObj() = default;
    SimpleSoAPhysicsObj (size_t elems){
        x.reserve(elems);
        y.reserve(elems);
        z.reserve(elems);
    }
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> z;
};

struct SimpleSoAPhysicsObj2 {
    SimpleSoAPhysicsObj2() = default;
    SimpleSoAPhysicsObj2 (size_t elems){
        x.reserve(elems);
        y.reserve(elems);
        z.reserve(elems);
    }
    std::vector<double> x;
    std::vector<double> y;
    std::vector<float> z;
};

struct SimpleSoAPhysicsObj3 {
    SimpleSoAPhysicsObj3() = default;
    SimpleSoAPhysicsObj3 (size_t elems){
        x.reserve(elems);
        y.reserve(elems);
        z.reserve(elems);
    }
    std::vector<double> x;
    std::vector<float> y;
    std::vector<double> z;
};

struct SimpleSoAPhysicsObj4 {
    SimpleSoAPhysicsObj4() = default;
    SimpleSoAPhysicsObj4 (size_t elems){
        x.reserve(elems);
        y.reserve(elems);
        z.reserve(elems);
    }
    std::vector<float> x;
    std::vector<float> y;
    std::vector<float> z;
};

struct SimpleSoAPhysicsObj5 {
    SimpleSoAPhysicsObj5() = default;
    SimpleSoAPhysicsObj5 (size_t elems){
        x.reserve(elems);
        y.reserve(elems);
        z.reserve(elems);
    }
    std::vector<short> x;
    std::vector<double> y;
    std::vector<float> z;
};

struct SimpleSoAPhysicsObj6 {
    SimpleSoAPhysicsObj6() = default;
    SimpleSoAPhysicsObj6 (size_t elems){
        x.reserve(elems);
        y.reserve(elems);
        z.reserve(elems);
    }
    std::vector<int> x;
    std::vector<int> y;
    std::vector<int> z;
};

#endif  // DataFormats_NGTSoATest_src_classes_h