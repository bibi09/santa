#ifndef __PHYSICS_COUNTING_GINGERBREADMAN_H__
#define __PHYSICS_COUNTING_GINGERBREADMAN_H__

#include "BonusEntity.h"
#include "../../../../tools/geometry/Position.h"

/**
 * @brief   Bonus whose cutted instances are counted.
 * @author  Denis CARLUS
 */
class GingerbreadMan : public BonusEntity {
    public:
        /** @brief  Create a new GingerbreadMan with position and speed. */
        GingerbreadMan(float xPos, float yPos, float xSpeed, float ySpeed) ;

        /** @brief  Create a new GingerbreadMan with position and speed. */
        GingerbreadMan(Position pos, Speed speed) ;

        /** @brief  Destruction of a GingerbreadMan. */
        virtual ~GingerbreadMan() ;
} ;

#endif
