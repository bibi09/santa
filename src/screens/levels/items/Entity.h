#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "../../../constants.h"
#include "../../../tools/geometry/Rectangle2D.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <map>
#include <string>


/** @brief  An Entity can be displayed on screen at a given position. */
class Entity {
    protected:
        /** @brief  Sprites used to display the entity. */
        std::map<std::string, ALLEGRO_BITMAP*> m_sprites ;

        /** @brief  Sprite used to display the entity. */
        ALLEGRO_BITMAP* m_sprite ;

        /** Bounds of the entity on screen. */
        Rectangle2D m_bounds ;


    public :
        /** @brief  Create a new Entity. */
        Entity(const std::string& sprite) ;

        /** @brief  Create a new Entity. */
        Entity(const ALLEGRO_BITMAP* sprite) ;

        /** @brief  Destroy an Entity. */
        virtual ~Entity() ;


        /** @brief Display the item. */
        virtual void display() ;

        /** @brief  Update the Entity. */
        virtual void update() = 0 ;


        /** @brief  Test if the entity is alive on screen (visible, etc). */
        virtual bool isAlive() ;


        /**
         * @brief   Tests if the specified point is inside this entity.
         * @param   p   Point to test.
         * @return  true if the given point is in this entity; false otherwise.
         */
        virtual bool isTouched(Position& p) ;

        /**
         * @brief   Tests if the specified entity is inside this one.
         * @param   other   The entity to test.
         * @return  true if the given entity is in this entity; false otherwise.
         */
        virtual bool isTouched(Entity* other) ;

        /**
         * @brief   Test if the entity is cutted by a line.
         * @param   p1  Start point of the line segment.
         * @param   p2  End point of the line segment.
         * @return  true if the specified line intersects the interior of this
         *          entity; false otherwise.
         */
        virtual bool isCutted(Position& p1, Position& p2) ;


        /** @brief  Set the sprite to display when the entity is cutted. */
        virtual void setCuttedSprite(const std::string& sprite) ;

        /** @brief  Set the sprite to display when the entity is touched. */
        virtual void setTouchedSprite(const std::string& sprite) ;

        /** Set the position of the Entity. */
        virtual void setPosition(float x, float y, bool center = false) ;

        /** Set the position of the Entity. */
        virtual void setPosition(const Position& pos, bool center = false) ;


        /** @brief  Get the position of the entity. */
        float getX() ;

        /** @brief  Get the position of the entity. */
        float getY() ;
} ;

#endif
