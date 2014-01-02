#ifndef __GAMEPLAY_SCREEN_H__
#define __GAMEPLAY_SCREEN_H__

#include "../gui/AlAbstractAction.h"
#include "MenuScreen.h"
#include <string>

/**
 * @brief   Screen where the gameplay and the goals are explained.
 * @author  Denis CARLUS
 */
class GameplayScreen : public MenuScreen {
    public:
        /** @brief  Create a GameplayScreen. */
        GameplayScreen() ;

        /** @brief  Destruction of a GameplayScreen. */
        virtual ~GameplayScreen() ;


    protected:
        /** @brief  Draw examples of hitable entities. */
        virtual void additionnalDisplay() ;

        /**
         * @brief   Action to go to the Level1 (rule screen first!).
         * @author  Denis CARLUS
         */
        class GoToLevel1Action : public AlAbstractAction {
            /** @brief  Run the action. */
            virtual void run() ;
        } ;
} ;

#endif
