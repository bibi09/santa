#ifndef __PHYSICS_ZUURSTOK_H__
#define __PHYSICS_ZUURSTOK_H__

#include "BonusEntity.h"
#include "../../../../tools/geometry/Position.h"

class Zuurstok : public BonusEntity {
    public:
        /** @brief  Create a new Zuurstok with position and speed. */
        Zuurstok(float xPos, float yPos, float xSpeed, float ySpeed) ;

        /** @brief  Create a new Zuurstok with position and speed. */
        Zuurstok(Position pos, Speed speed) ;

        /** @brief  Destruction of a Zuurstok. */
        virtual ~Zuurstok() ;
} ;

#endif
