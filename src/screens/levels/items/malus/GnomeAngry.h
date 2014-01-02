#ifndef __PHYSICS_ANGRY_GNOME_H__
#define __PHYSICS_ANGRY_GNOME_H__

#include "MalusEntity.h"
#include "../../../../tools/geometry/Position.h"

class AngryGnome : public MalusEntity {
    public:
        /** @brief  Create a new AngryGnome with position and speed. */
        AngryGnome(float xPos,
                   float yPos,
                   float xSpeed,
                   float ySpeed) ;

        /** @brief  Create a new AngryGnome with position and speed. */
        AngryGnome(Position pos,
              Speed speed) ;

        /** @brief  Destruction of a AngryGnome. */
        virtual ~AngryGnome() ;


    protected:
        /** @brief  Run additionnal operations on break. */
        virtual void additionnalStuffOnBreak() ;
} ;

#endif
