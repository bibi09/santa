#include "Math.h"

Math Math::Singleton ;


Math::Math() throw() {}

Math::~Math() throw() {}


double Math::toRadian(double degree) {
    return degree * Singleton.rad_coeff ;
}


double Math::toDegree(double radian) {
    return radian * Singleton.deg_coeff ;
}
