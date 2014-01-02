#ifndef __END_SCREEN_H__
#define __END_SCREEN_H__

#include "../gui/AlAbstractAction.h"
#include "MenuScreen.h"
#include <string>

/**
 * @brief   End game screen.
 * @author  Denis CARLUS
 */
class EndScreen : public MenuScreen {
    public:
        /** @brief  Create a EndScreen. */
        EndScreen() ;

        /** @brief  Destruction of a EndScreen. */
        virtual ~EndScreen() ;


    protected:
        /**
         * @brief   Action to go back to the main menu.
         * @author  Denis CARLUS
         */
        class GoToMainMenuAction : public AlAbstractAction {
            /** @brief  Run the action. */
            virtual void run() ;
        } ;
} ;

#endif
