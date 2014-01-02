#ifndef __PHYSICS_ENTITY_H__
#define __PHYSICS_ENTITY_H__

#include "../../../tools/geometry/Math.h"
#include "Entity.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include <string>
#include <iostream>


/** @brief  A PhysicsEntity can be thrown and fall. */
class PhysicsEntity : public Entity {
    protected:
        /** @brief  Maximal speed when falling. */
        const unsigned char MAX_FALL_SPEED = 10 ;

        /** @brief  Step to rotate the sprite. */
        float m_angleStep ;
        /** @brief  Angle of the sprite. */
        float m_angle ;
        /** @brief  Speed of the PhysicsEntity on X and Y axis. */
        Speed m_speed ;


    public :
        /**
         * @brief   Create a new PhysicsEntity. Initial speed is null.
         * @param   sprite  Path to the sprite file.
         */
        PhysicsEntity(const std::string& sprite) ;

        /**
         * @brief   Create a new PhysicsEntity. Initial speed is null.
         * @param   sprite  Sprite to use as base sprite.
         */
        PhysicsEntity(const ALLEGRO_BITMAP* sprite) ;

        /** @brief  Destroy an PhysicsEntity. */
        virtual ~PhysicsEntity() ;


        /** @brief Display the item. */
        virtual void display() ;


        /** @brief  Update the PhysicsEntity. */
        virtual void update() ;


        /**
         * @brief   Set the initial speed of the PhysicsEntity.
         * @param   xSpeed  Initial speed of the entity on X axis.
         * @param   ySpeed  Initial speed of the entity on Y axis.
         */
        void setInitialSpeed(float xSpeed, float ySpeed) ;

        /**
         * @brief   Set the initial speed of the PhysicsEntity.
         * @param   speed   Initial speed.
         */
        void setInitialSpeed(const Speed& speed) ;


        /** @brief  Test if the entity is alive on screen (visible, etc). */
        virtual bool isAlive() ;
} ;

#endif
