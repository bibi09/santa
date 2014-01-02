#ifndef __ALLEGRO_BUTTON_BITMAP_H__
#define __ALLEGRO_BUTTON_BITMAP_H__

#include "AlButton.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>

/**
 * @brief   A button using a bitmap as representation.
 * @author  Denis CARLUS
 */
class AlButtonBitmap : public AlButton {
    protected:
        /** @brief  Sprite used to display the button. */
        ALLEGRO_BITMAP* m_sprite ;

    public:
        /** @brief  Create a new AlButtonBitmap. */
        AlButtonBitmap(const Position& pos,
                       std::string& sprite,
                       AlAbstractAction* action) ;

        /** @brief  Destruction of an AlButtonBitmap. */
        virtual ~AlButtonBitmap() ;


        /** @brief  Display the button. */
        virtual void display() ;

        /** @brief  Update the button. */
        virtual void update() ;
} ;

#endif
