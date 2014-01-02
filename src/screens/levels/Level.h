#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "../GameScreen.h"
#include "../gui/AlAbstractAction.h"
#include "../../constants.h"
#include "../../tools/managers/ConfettiManager.h"
#include "items/ScoringEntity.h"

#include <string>
#include <list>

/**
 * @brief   A level contains elements to cut, bonus, malus... and manages game
 *          logic.
 * @author  Denis CARLUS
 */
class Level : public GameScreen {
    protected:
        /** @brief  Active items that are spawned and that can be broken. */
        std::list<ScoringEntity*> m_items ;

        /** @brief  Tic to wait before new item spawn. */
        int m_waitSpawn ;
        /** @brief  Maximal amount of items on screen. */
        unsigned int m_maxItems ;


    public:
        /** @brief  Create a new level. */
        Level(const std::string& background,
              const std::string& bgm = "") ;

        /** @brief  Destroy the level! */
        virtual ~Level() ;

        /** @brief  Update the bots on the map. */
        virtual void update() ;

        /**
         * @brief   Make explode all the alive entities...
         * @param   source  Source entity of the explosion.
         */
        void explodeAll(ScoringEntity* source) ;

    protected:
        /** @brief  Display the whole level: map, characters, other stuff. */
        virtual void additionnalDisplay() ;

        /**
         * @brief  Test if the goal of the level is reached and do the
         * corresponding action.
         */
        virtual void levelEnd() = 0 ;

        /** @brief  Add new items on screen. */
        void addScoringItem() ;


        /** @brief  Create a random item available in the level. */
        virtual ScoringEntity* pickRandomItem(Position pos, Speed speed) = 0 ;


        /** @brief  Update all the alive physics entities. */
        void updatePhysicsEntities() ;
} ;

#endif
