#ifndef __LEVEL_TWO_H__
#define __LEVEL_TWO_H__

#include "Level.h"


/**
 * @brief   Second level of the game.
 * @author  Denis CARLUS
 */
class Level2 : public Level {
    public:
        /** @brief  Create a new level. */
        Level2() ;

        /** @brief  Destroy the level. */
        virtual ~Level2() ;


    protected:
        /** @brief  Preload media used by the screen. */
        virtual void preload() ;

        /**
         * @brief  Test if the goal of the level is reached and do the
         * corresponding action.
         */
        virtual void levelEnd() ;

        /** @brief  Create a random item available in the level. */
        virtual ScoringEntity* pickRandomItem(Position pos, Speed speed) ;
} ;

#endif
