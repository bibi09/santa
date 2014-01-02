#ifndef __PHYSICS_GNOME_H__
#define __PHYSICS_GNOME_H__

#include "MalusEntity.h"
#include "../../../../tools/geometry/Position.h"

class Gnome : public MalusEntity {
    public:
        /** @brief  Create a new Gnome with position and speed. */
        Gnome(float xPos,
              float yPos,
              float xSpeed,
              float ySpeed) ;

        /** @brief  Create a new Gnome with position and speed. */
        Gnome(Position pos,
              Speed speed) ;

        /** @brief  Destruction of a Gnome. */
        virtual ~Gnome() ;


    protected:
        /** @brief  Run additionnal operations on break. */
        virtual void additionnalStuffOnBreak() ;
} ;

#endif
