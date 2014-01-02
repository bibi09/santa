#ifndef __PHYSICS_ORANGEGIFT_H__
#define __PHYSICS_ORANGEGIFT_H__

#include "BonusEntity.h"
#include "../../../../tools/geometry/Position.h"

class OrangeGift : public BonusEntity {
    public:
        /** @brief  Create a new OrangeGift with position and speed. */
        OrangeGift(float xPos, float yPos, float xSpeed, float ySpeed) ;

        /** @brief  Create a new OrangeGift with position and speed. */
        OrangeGift(Position pos, Speed speed) ;

        /** @brief  Destruction of a OrangeGift. */
        virtual ~OrangeGift() ;
} ;

#endif
