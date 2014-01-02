#ifndef __SCREEN_MANAGER_H__
#define __SCREEN_MANAGER_H__

#include "../../screens/GameScreen.h"
#include "../patterns/NoCopy.h"
#include <assert.h>
#include <stack>
#include <iostream>

/**
 * @brief   Allows the screens to be displayed, updated and go back to previous
 *          screen easily.
 * @author  Denis CARLUS
 */
class ScreenManager : private NoCopy {
    private:
        /** @brief Singleton of the ScreenManager handler. */
        static ScreenManager* Singleton ;

        /** @brief  Screens. */
         std::stack<GameScreen*> m_screens ;


                                            /** CONSTRUCTION AND DESTRUCTION **/
        /** @brief Construction of a ScreenManager handler. */
        ScreenManager() ;

        /** @brief Destruction of the ScreenManager handler. */
        ~ScreenManager() throw() ;

    public:
        /**
         * @brief Get the unique instance of ScreenManager.
         * @return  The unique instance of ScreenManager.
         */
        static ScreenManager* getInstance() ;

        /**
         * @brief  Set the active screen.
         * @param   screen  Screen to put on top of the screens stack.
         */
        void pushScreen(GameScreen* screen) ;

        /** @brief  Go to the previous screen. */
        void previousScreen() ;

        /**
         * @brief  Change the active screen.
         * @param   screen  Screen to put on top of the screens stack.
         */
        void replaceScreen(GameScreen* screen) ;


        /** @brief  Display the active screen. */
        void display() ;

        /** @brief  Update the active screen. */
        void update() ;


        /** @brief  Get the running screen. */
        GameScreen* getCurrentScreen() ;
} ;

#endif
