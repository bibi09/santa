#ifndef __HUD_SCORE_H__
#define __HUD_SCORE_H__

#include "../../../constants.h"
#include "../../../tools/patterns/NoCopy.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>

class Score : private NoCopy {
    private:
        /** @brief Singleton of the Allegro. */
        static Score* Singleton ;

        /** @brief  Font used to display the score. */
        ALLEGRO_FONT* m_font ;

        /** @brief  Score of the player. */
        int m_score ;


                                            /** CONSTRUCTION AND DESTRUCTION **/
        /**
         * @brief Construction of a Score handler.
         */
        Score() ;

        /** @brief Destruction of the Score handler. */
        ~Score() throw() ;


    public:
        /**
         * @brief Get the unique instance of Score.
         * @return  The unique instance of Score.
         */
        static Score* getInstance() ;

        /** @brief  Add a value to the score. */
        void addScore(int value) ;

        /** @brief  Display the score on screen. */
        void display() ;

        /** @brief  Reset the score. */
        void reset() ;

        /** @brief  Get the player's score. */
        int getScore() ;
} ;

#endif
