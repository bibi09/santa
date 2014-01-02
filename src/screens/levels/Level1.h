#ifndef __LEVEL_ONE_H__
#define __LEVEL_ONE_H__

#include "Level.h"
#include "items/bonus/BlueGift.h"
#include "items/bonus/RedGift.h"
#include "items/bonus/OrangeGift.h"
#include "items/bonus/Zuurstok.h"
#include "items/malus/BombGift.h"
#include "items/malus/Gnome.h"
#include "items/malus/Pan.h"
#include "items/malus/SnowGlobe.h"


/**
 * @brief   First (and unique) level of the game.
 * @author  Denis CARLUS
 */
class Level1 : public Level {
    public:
        /** @brief  Create a new level. */
        Level1() ;

        /** @brief  Destroy the level. */
        virtual ~Level1() ;


    protected:
        /**
         * @brief  Test if the goal of the level is reached and do the
         * corresponding action.
         */
        virtual void levelEnd() ;

        /** @brief  Create a random item available in the level. */
        virtual ScoringEntity* pickRandomItem(Position pos, Speed speed) ;
} ;

#endif
