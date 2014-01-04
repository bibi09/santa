#ifndef __LEVEL_THREE_H__
#define __LEVEL_THREE_H__

#include "Level.h"


/**
 * @brief   Third level of the game.
 * @author  Denis CARLUS
 */
class Level3 : public Level {
    public:
        /** @brief  Create a new level. */
        Level3() ;

        /** @brief  Destroy the level. */
        virtual ~Level3() ;


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
