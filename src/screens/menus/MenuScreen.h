#ifndef __MENU_SCREEN_H__
#define __MENU_SCREEN_H__

#include "../GameScreen.h"
#include "../gui/AlComponent.h"
#include "../gui/AlAbstractAction.h"
#include "../../constants.h"
#include "../../tools/Allegro.h"
#include "../../tools/geometry/Position.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>
#include <vector>

/**
 * @brief   An menu screen is used to display texts and explanation on
 *          the game, making menu with buttons and GUI elements, etc.
 * @author  Denis CARLUS
 */
class MenuScreen : public GameScreen {
    private:
        /** @brief  Fonts used on the screen. */
        std::map<std::string, ALLEGRO_FONT*> m_fonts ;
        /** @brief  Colors used on the screen. */
        std::map<std::string, ALLEGRO_COLOR> m_colors ;
        /** @brief  GUI components on the screen. */
        std::vector<AlComponent*> m_guiComponents ;
        /** @brief  Actions on the screen. */
        std::vector<AlAbstractAction*> m_actions ;

    protected:
        /** @brief  Title of the screen. */
        std::string m_title ;


    public:
        /** @brief  Create an MenuScreen. */
        MenuScreen(const std::string& background,
                   const std::string& bgm = "",
                   bool stopBGMOnEnd = true,
                   const std::string& title = "") ;

        /** @brief  Destroy an IntroScreen. */
        virtual ~MenuScreen() ;


        /** @brief  Move the cursor and test the buttons. */
        virtual void update() ;


    protected:
        /**
         * @brief  Display the screen.
         * @warning The fonts must have been defined for title and texts.
         */
        virtual void additionnalDisplay() ;


        /**
         * @brief  Add a text to display.
         * @param   text    The text to display.
         * @param   pos     Position of the text. If the screen already has a
         *                  text, the position is computed relatively to the
         *                  previously one.
         * @param   width   Width of the text. If null, take the right border
         *                  of the window.
         * @warning Font must be defined for text before calling this function.
         */
        void addText(const std::string& text,
                     const Position& pos) ;

        /**
         * @brief   Add a GUI component.
         * @param   component   Component to add to the screen.
         */
        void addComponent(AlComponent* component) ;


        /** @brief  Set the buttons font. */
        void setButtonsFont(const std::string& path, unsigned char size) ;

        /** @brief  Set the title font. */
        void setTitleFont(const std::string& path, unsigned char size) ;

        /** @brief  Set the title color. */
        void setTitleColor(unsigned char red,
                           unsigned char green,
                           unsigned char blue,
                           unsigned char alpha) ;

        /** @brief  Set the text font. */
        void setTextFont(const std::string& path, unsigned char size) ;

        /** @brief  Set the text color. */
        void setTextColor(unsigned char red,
                          unsigned char green,
                          unsigned char blue,
                          unsigned char alpha) ;
}  ;

#endif
