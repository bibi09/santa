#ifndef __RULE_SCREEN_H__
#define __RULE_SCREEN_H__

#include "../../../tools/geometry/Position.h"
#include "../../../constants.h"
#include "../../GameScreen.h"
#include "../../gui/labels/AlLabel.h"
#include "../../gui/buttons/AlButton.h"
#include "../../gui/AlAbstractAction.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

/**
 * @brief   A RuleScreen is used to display the rules of a level before it
 *          starts.
 * @author  Denis CARLUS
 */
class RuleScreen : public GameScreen {
    private:
        /** @brief  Font used on the title of the screen. */
        static ALLEGRO_FONT* TitleFont ;
        /** @brief  Font used on the text rule of the screen. */
        static ALLEGRO_FONT* TextFont ;

        /** @brief  Title of the rule screen. */
        AlLabel* m_title ;
        /** @brief  Label containing the rules of the level. */
        AlLabel* m_rule ;
        /** @brief  Button to go to the next screen. */
        AlButton* m_button ;

        /** @brief  Countdown to avoid passing through the level to fast... */
        short m_countdown ;

    public:
        /** @brief  Create a RuleScreen. */
        RuleScreen(const std::string& title,
                   const std::string& rule) ;

        /** @brief  Destroy a RuleScreen. */
        virtual ~RuleScreen() ;

        /** @brief  Update the screen. */
        virtual void update() ;

    protected:
        /** @brief  Preload media used by the screen. */
        virtual void preload() ;

        /** @brief  Custom display function adapted to the screen. */
        virtual void additionnalDisplay() ;

        /** @brief  Set the action of the button to play. */
        void setButtonAction(AlAbstractAction* action) ;
} ;

#endif
