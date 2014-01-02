#ifndef __PHYSICS_COUNTING_SPECIALGIFT_H__
#define __PHYSICS_COUNTING_SPECIALGIFT_H__

#include "BonusEntity.h"
#include "../../../../tools/geometry/Position.h"

/**
 * @brief   Gift whose cutted instances are counted.
 * @author  Denis CARLUS
 */
class SpecialGift : public BonusEntity {
    public:
        /** @brief  Create a new CountingOrangeGift with position and speed. */
        SpecialGift(float xPos, float yPos, float xSpeed, float ySpeed) ;

        /** @brief  Create a new CountingOrangeGift with position and speed. */
        SpecialGift(Position pos, Speed speed) ;

        /** @brief  Destruction of a OrangeGift. */
        virtual ~SpecialGift() ;
} ;

#endif
