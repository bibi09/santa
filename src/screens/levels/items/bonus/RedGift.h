#ifndef __PHYSICS_REDGIFT_H__
#define __PHYSICS_REDGIFT_H__

#include "BonusEntity.h"
#include "../../../../tools/geometry/Position.h"

class RedGift : public BonusEntity {
    public:
        /** @brief  Create a new RedGift with position and speed. */
        RedGift(float xPos, float yPos, float xSpeed, float ySpeed) ;

        /** @brief  Create a new RedGift with position and speed. */
        RedGift(Position pos, Speed speed) ;

        /** @brief  Destruction of a RedGift. */
        virtual ~RedGift() ;
} ;

#endif
