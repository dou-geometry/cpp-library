#include"./sys.hh"

namespace d::dou::compact {
    sys::sys(double leftBoundary, double rightBoundary) { //bl, tr as template?
        // メルセンヌ・ツイスター法による擬似乱数生成器を、
        // ハードウェア乱数をシードにして初期化
        std::random_device seed_gen;
        std::mt19937 engine(seed_gen());

        // 一様実数分布
        // [-1.0, 1.0)の値の範囲で、等確率に実数を生成する
        std::uniform_real_distribution<> dist1(leftBoundary, rightBoundary);
        for(di i=0; i<amount; ++i) {
            //d[i].t=0.0;
            for(di j=0; j<dimension; ++j) {
                d[i][0][j]=dist1(engine); // Position
                d[i][1][j]=dist1(engine); // Velocity
            }
        }
    }
    d::dou::compact::mono<double, 2ul, dimension, true>& sys::operator()(const d::compact::coord<double, dimension>& i) {
    }
    d::dou::compact::mono<double, 2ul, dimension, true> sys::operator()(const d::compact::coord<double, dimension>& i) const {
    }
    d::compact::coord<double, dimension> sys::existence(int id) const {
        d::compact::coord<double, dimension> force;
        for(di i=0; i<particles; ++i) { // Accelerate toward high existence
        }
        return force;
    }
    bool sys::stable() {
        for(di i=0; i<particles; ++i)
            if(this->existence(i).norm2()!=0)
                return false;
        return true;
    }
    bool sys::confined() {
        d::compact::coord<double, dimension> force(0.);
        for(di i=0; i<particles; ++i)
            force+=this->existence(i);
        return (force.norm2())<1e-12;
    }
}
