#ifndef __CONFETTI_ENTITY_H__
#define __CONFETTI_ENTITY_H__

#include "../PhysicsEntity.h"

class ConfettiEntity : public PhysicsEntity {
    protected:
        /** @brief   Amount of frame the confetti is displayed before fading out. */
        unsigned int m_frameDisplay ;
        /** @brief   Steps to sample the fade out. */
        unsigned short m_stepFadeOut ;
        /** @brief  Alpha channel value. */
        unsigned char m_alpha ;


    public:
        /**
         * @brief   Create a new ConfettiEntity.
         * @param   sprite      Path to the sprite file.
         * @param   displayTime Time before the sprite is faded out in seconds.
         * @param   fadeOutTime Time to fade out the confetti in seconds.
         */
        ConfettiEntity(const std::string& sprite,
                       unsigned char displayTime,
                       unsigned char fadeOutTime) ;

        /**
         * @brief   Create a new ConfettiEntity.
         * @param   sprite      Path to the sprite file.
         * @param   displayTime Time before the sprite is faded out in seconds.
         * @param   fadeOutTime Time to fade out the confetti in seconds.
         */
        ConfettiEntity(ALLEGRO_BITMAP* sprite,
                       unsigned char displayTime,
                       unsigned char fadeOutTime) ;


        /** @brief  Destroy a ConfettiEntity. */
        virtual ~ConfettiEntity() ;


        /** @brief Display the item. */
        virtual void display() ;

        /** @brief  Update the ConfettiEntity. */
        virtual void update() ;

        /** @brief  Update the display of the confetti (fade out, etc). */
        virtual void updateDisplay() ;
} ;

#endif
