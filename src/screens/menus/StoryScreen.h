#ifndef __STORY_SCREEN_H__
#define __STORY_SCREEN_H__

#include "../gui/AlAbstractAction.h"
#include "MenuScreen.h"
#include <string>

/**
 * @brief   Menu where is explained the "story" of the game.
 * @author  Denis CARLUS
 */
class StoryScreen : public MenuScreen {
    public:
        /** @brief  Create a StoryScreen. */
        StoryScreen() ;

        /** @brief  Destruction of a StoryScreen. */
        virtual ~StoryScreen() ;


    protected:
        /**
         * @brief   Action to go to the gameplay explanations.
         * @author  Denis CARLUS
         */
        class GoToGameplayAction : public AlAbstractAction {
            /** @brief  Run the action. */
            virtual void run() ;
        } ;

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
