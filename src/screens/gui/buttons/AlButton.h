#ifndef __ALLEGRO_BUTTON_H__
#define __ALLEGRO_BUTTON_H__

#include "../AlComponent.h"
#include "../AlAbstractAction.h"
/**
 * @brief   Button that can be clicked to trigger an action.
 * @author  Denis CARLUS
 */
class AlButton : public AlComponent {
    protected:
        /** @brief  Action to do when the button is pressed. */
        AlAbstractAction* m_action ;


    public:
        /** @brief  Create a new AlButton. */
        AlButton(const Position& pos, AlAbstractAction* action) ;

        /** @brief  Destruction of an AlButton. */
        virtual ~AlButton() ;

        /** @brief  Trigger the button action. */
        virtual void trigger() ;


    protected:
        /** @brief  Action to perform when component is in active state. */
        virtual void actionOnActive() ;
} ;

#endif
