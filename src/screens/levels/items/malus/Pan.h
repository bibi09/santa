#ifndef __PHYSICS_PAN_H__
#define __PHYSICS_PAN_H__

#include "MalusEntity.h"
#include "../../../../tools/geometry/Position.h"

class Pan : public MalusEntity {
    public:
        /** @brief  Create a new Pan with position and speed. */
        Pan(float xPos, float yPos, float xSpeed, float ySpeed) ;

        /** @brief  Create a new Pan with position and speed. */
        Pan(Position pos, Speed speed) ;

        /** @brief  Destruction of a Pan. */
        virtual ~Pan() ;


    protected:
        /** @brief  Run additionnal operations on break. */
        virtual void additionnalStuffOnBreak() ;
} ;

#endif
