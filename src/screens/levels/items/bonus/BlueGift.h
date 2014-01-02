#ifndef __PHYSICS_BLUEGIFT_H__
#define __PHYSICS_BLUEGIFT_H__

#include "BonusEntity.h"
#include "../../../../tools/geometry/Position.h"

class BlueGift : public BonusEntity {
    public:
        /** @brief  Create a new BlueGift with position and speed. */
        BlueGift(float xPos, float yPos, float xSpeed, float ySpeed) ;

        /** @brief  Create a new BlueGift with position and speed. */
        BlueGift(Position pos, Speed speed) ;

        /** @brief  Destruction of a BlueGift. */
        virtual ~BlueGift() ;
} ;

#endif
