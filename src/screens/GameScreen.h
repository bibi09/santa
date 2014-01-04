#ifndef __GAME_SCREEN_H__
#define __GAME_SCREEN_H__

#include "levels/items/CursorEntity.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>


/**
 * @brief   A level contains a background, and displays different informations.
 */
class GameScreen {
    protected:
        /** @brief  Cursor of the player. */
        CursorEntity* m_cursor ;
        /** Background image of the screen. */
        ALLEGRO_BITMAP* m_background ;
        /** @brief  Stop the BGM when the screen is gone. */
        bool m_stopBGMOnEnd ;

    public:
        /** @brief  Create a GameScreen. */
        GameScreen(const std::string& background,
                   const std::string& bgm = "",
                   bool stopBGMOnEnd = false) ;


        /** @brief  Destroy the GameScreen. */
        virtual ~GameScreen() ;


        /** @brief  Display the game screen. */
        void display() ;

        /** @brief  Update the game screen. */
        virtual void update() = 0 ;

        /** @brief  Cache media used by the screen. */        
        void cache() ;

    protected:
        /** @brief  Preload media used by the screen. */
        virtual void preload() = 0 ;

        /** @brief  Custom display function adapted to the screen. */
        virtual void additionnalDisplay() = 0 ;
} ;

#endif
