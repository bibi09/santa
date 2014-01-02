#ifndef __PHYSICS_BOMBGIFT_H__
#define __PHYSICS_BOMBGIFT_H__

#include "MalusEntity.h"

class BombGift : public MalusEntity {
    public:
        /** @brief  Create a new BombGift with position and speed. */
        BombGift(float xPos, float yPos, float xSpeed, float ySpeed) ;

        /** @brief  Create a new BombGift with position and speed. */
        BombGift(Position pos, Speed speed) ;

        /** @brief  Destruction of a BombGift. */
        virtual ~BombGift() ;


    protected:
        /** @brief  Run additionnal operations on break. */
        virtual void additionnalStuffOnBreak() ;
} ;

#endif
