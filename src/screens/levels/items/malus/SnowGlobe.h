#ifndef __PHYSICS_SNOWGLOBE_H__
#define __PHYSICS_SNOWGLOBE_H__

#include "../../../../tools/geometry/Position.h"
#include "MalusEntity.h"

class SnowGlobe : public MalusEntity {
    public:
        /** @brief  Create a new BombGift with position and speed. */
        SnowGlobe(float xPos, float yPos, float xSpeed, float ySpeed) ;

        /** @brief  Create a new SnowGlobe with position and speed. */
        SnowGlobe(Position pos, Speed speed) ;

        /** @brief  Destruction of a SnowGlobe. */
        virtual ~SnowGlobe() ;


    protected:
        /** @brief  Run additionnal operations on break. */
        virtual void additionnalStuffOnBreak() ;
} ;

#endif
