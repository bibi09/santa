#ifndef __LOE_MATH_VALUES_H__
#define __LOE_MATH_VALUES_H__

#include "../patterns/NoCopy.h"
#include <cmath>


/**
 * @brief   Math singleton allows advanced mathematical computations.
 * @author  Denis CARLUS
 * @version 1.0     30/09/2013
 */
class Math : private NoCopy {
    private:
                                                                /* ** DATA ** */
        /** @brief  Autogenerated singleton at program launching. */
        static Math Singleton ;


        /** @brief  Value of PI. */
        const double pi = 4. * atan(1.) ;

        /** @brief  Coefficient used to convert degrees to radians. */
        const double rad_coeff = Math::pi / 180. ;
        /** @brief  Coefficient used to convert radians to degrees. */
        const double deg_coeff = 180. / Math::pi ;


                                                           /* ** FUNCTIONS ** */
        /** @brief Private constructor to avoid new instances. */
        Math() throw() ;

        /** @brief Destructor to delete dynamic instances. */
        ~Math() throw() ;


    public:
        /**
         * @brief   Convert a degree angle to radians.
         * @param   degree  The angle to convert.
         * @return  Angle expressed with radians.
         */
        static double toRadian(double degree) ;

        /**
         * @brief   Convert a degree angle to degrees.
         * @param   degree  The angle to convert.
         * @return  Angle expressed with degrees.
         */
        static double toDegree(double radian) ;
} ;

#endif
